#include "app_controller.h"
#include "app_controller_gui.h"
#include "common.h"
#include "interface.h"
#include "Arduino.h"

// Array to store the names of different app event types
const char *app_event_type_info[] = {"APP_MESSAGE_WIFI_CONN", "APP_MESSAGE_WIFI_AP",
                                     "APP_MESSAGE_WIFI_ALIVE", "APP_MESSAGE_WIFI_DISCONN",
                                     "APP_MESSAGE_UPDATE_TIME", "APP_MESSAGE_MQTT_DATA",
                                     "APP_MESSAGE_GET_PARAM", "APP_MESSAGE_SET_PARAM",
                                     "APP_MESSAGE_READ_CFG", "APP_MESSAGE_WRITE_CFG",
                                     "APP_MESSAGE_NONE"};

// Flag to indicate if the event deal is running
volatile static bool isRunEventDeal = false;

// Timer callback function for event deal
void eventDealHandle(TimerHandle_t xTimer)
{
    isRunEventDeal = true;
}

// Constructor for AppController class
AppController::AppController(const char *name)
{
    strncpy(this->name, name, APP_CONTROLLER_NAME_LEN);
    app_num = 0;
    app_exit_flag = 0;
    cur_app_index = 0;
    pre_app_index = 0;
    m_wifi_status = false;
    m_preWifiReqMillis = GET_SYS_MILLIS();

    // Create and start the event deal timer
    xTimerEventDeal = xTimerCreate("Event Deal",
                                   300 / portTICK_PERIOD_MS,
                                   pdTRUE, (void *)0, eventDealHandle);
    xTimerStart(xTimerEventDeal, 0);
}

// Initialize the AppController
void AppController::init(void)
{
    // Set CPU frequency based on power mode
    if (1 == this->sys_cfg.power_mode)
    {
        setCpuFrequencyMhz(240);
    }
    else
    {
        setCpuFrequencyMhz(80);
    }

    // Print CPU frequency
    Serial.print(F("CpuFrequencyMhz: "));
    Serial.println(getCpuFrequencyMhz());

    // Initialize app control GUI
    app_control_gui_init();

    // Create a loading app and display it
    appList[0] = new APP_OBJ();
    appList[0]->app_image = &app_loading;
    appList[0]->app_name = "Loading...";
    appTypeList[0] = APP_TYPE_REAL_TIME;
    app_control_display_scr(appList[cur_app_index]->app_image,
                            appList[cur_app_index]->app_name,
                            LV_SCR_LOAD_ANIM_NONE, true);
}

// Display the current app
void AppController::Display()
{
    app_control_display_scr(appList[cur_app_index]->app_image,
                            appList[cur_app_index]->app_name,
                            LV_SCR_LOAD_ANIM_NONE, true);
}

// Destructor for AppController class
AppController::~AppController()
{
    rgb_stop();
}

// Check if the app is legal
int AppController::app_is_legal(const APP_OBJ *app_obj)
{
    if (NULL == app_obj)
        return 1;
    if (APP_MAX_NUM <= app_num)
        return 2;
    return 0;
}

// Install an app into the app_controller
int AppController::app_install(APP_OBJ *app, APP_TYPE app_type)
{
    int ret_code = app_is_legal(app);
    if (0 != ret_code)
    {
        return ret_code;
    }

    appList[app_num] = app;
    appTypeList[app_num] = app_type;
    ++app_num;
    return 0;
}

// Remove the background task of an app from the task queue
int AppController::remove_backgroud_task(void)
{
    return 0;
}

// Uninstall an app from the app_controller
int AppController::app_uninstall(const APP_OBJ *app)
{
    // todo
    return 0;
}

// Auto start an app
int AppController::app_auto_start()
{
    int index = this->getAppIdxByName(sys_cfg.auto_start_app.c_str());
    if (index < 0)
    {
        return 0;
    }
    app_exit_flag = 1;
    cur_app_index = index;
    (*(appList[cur_app_index]->app_init))(this);
    return 0;
}

// Main process of the AppController
int AppController::main_process(ImuAction *act_info)
{
    if (ACTIVE_TYPE::UNKNOWN != act_info->active)
    {
        Serial.print(F("[Operate]\tact_info->active: "));
        Serial.println(active_type_info[act_info->active]);
    }

    if (isRunEventDeal)
    {
        isRunEventDeal = false;
        this->req_event_deal();
    }

    if (0 == sys_cfg.power_mode && true == m_wifi_status && doDelayMillisTime(WIFI_LIFE_CYCLE, &m_preWifiReqMillis, false))
    {
        send_to(CTRL_NAME, CTRL_NAME, APP_MESSAGE_WIFI_DISCONN, 0, NULL);
    }

    if (0 == app_exit_flag)
    {
        lv_scr_load_anim_t anim_type = LV_SCR_LOAD_ANIM_NONE;
        if (ACTIVE_TYPE::TURN_LEFT == act_info->active)
        {
            anim_type = LV_SCR_LOAD_ANIM_MOVE_RIGHT;
            pre_app_index = cur_app_index;
            cur_app_index = (cur_app_index + 1) % app_num;
            Serial.println(String("Current App: ") + appList[cur_app_index]->app_name);
        }
        else if (ACTIVE_TYPE::TURN_RIGHT == act_info->active)
        {
            anim_type = LV_SCR_LOAD_ANIM_MOVE_LEFT;
            pre_app_index = cur_app_index;
            cur_app_index = (cur_app_index - 1 + app_num) % app_num;
            Serial.println(String("Current App: ") + appList[cur_app_index]->app_name);
        }
        else if (ACTIVE_TYPE::GO_FORWORD == act_info->active)
        {
            app_exit_flag = 1;
            if (NULL != appList[cur_app_index]->app_init)
            {
                (*(appList[cur_app_index]->app_init))(this);
            }
        }

        if (ACTIVE_TYPE::GO_FORWORD != act_info->active)
        {
            app_control_display_scr(appList[cur_app_index]->app_image,
                                    appList[cur_app_index]->app_name,
                                    anim_type, false);
            vTaskDelay(200 / portTICK_PERIOD_MS);
        }
    }
    else
    {
        app_control_display_scr(appList[cur_app_index]->app_image,
                                appList[cur_app_index]->app_name,
                                LV_SCR_LOAD_ANIM_NONE, false);
        (*(appList[cur_app_index]->main_process))(this, act_info);
    }
    act_info->active = ACTIVE_TYPE::UNKNOWN;
    act_info->isValid = 0;
    return 0;
}

// Get an app by its name
APP_OBJ *AppController::getAppByName(const char *name)
{
    for (int pos = 0; pos < app_num; ++pos)
    {
        if (!strcmp(name, appList[pos]->app_name))
        {
            return appList[pos];
        }
    }

    return NULL;
}

// Get the index of an app by its name
int AppController::getAppIdxByName(const char *name)
{
    for (int pos = 0; pos < app_num; ++pos)
    {
        if (!strcmp(name, appList[pos]->app_name))
        {
            return pos;
        }
    }

    return -1;
}

// Send a message to an app or the control center
int AppController::send_to(const char *from, const char *to,
                           APP_MESSAGE_TYPE type, void *message,
                           void *ext_info)
{
    APP_OBJ *fromApp = getAppByName(from);
    APP_OBJ *toApp = getAppByName(to);
    if (type <= APP_MESSAGE_MQTT_DATA)
    {
        if (eventList.size() > EVENT_LIST_MAX_LENGTH)
        {
            return 1;
        }
        EVENT_OBJ new_event = {fromApp, type, message, 3, 0, 0};
        eventList.push_back(new_event);
        Serial.print("[EVENT]\tAdd -> " + String(app_event_type_info[type]));
        Serial.print(F("\tEventList Size: "));
        Serial.println(eventList.size());
    }
    else
    {
        if (NULL != toApp)
        {
            Serial.print("[Massage]\tFrom " + String(fromApp->app_name) + "\tTo " + String(toApp->app_name) + "\n");
            if (NULL != toApp->message_handle)
            {
                toApp->message_handle(from, to, type, message, ext_info);
            }
        }
        else if (!strcmp(to, CTRL_NAME))
        {
            Serial.print("[Massage]\tFrom " + String(fromApp->app_name) + "\tTo " + CTRL_NAME + "\n");
            deal_config(type, (const char *)message, (char *)ext_info);
        }
    }
    return 0;
}

// Request event deal
int AppController::req_event_deal(void)
{
    for (std::list<EVENT_OBJ>::iterator event = eventList.begin(); event != eventList.end();)
    {
        if ((*event).nextRunTime > GET_SYS_MILLIS())
        {
            ++event;
            continue;
        }
        bool ret = wifi_event((*event).type);
        if (false == ret)
        {
            (*event).retryCount += 1;
            if ((*event).retryCount >= (*event).retryMaxNum)
            {
                Serial.print("[EVENT]\tDelete -> " + String(app_event_type_info[(*event).type]));
                event = eventList.erase(event);
                Serial.print(F("\tEventList Size: "));
                Serial.println(eventList.size());
            }
            else
            {
                (*event).nextRunTime = GET_SYS_MILLIS() + 4000;
                ++event;
            }
            continue;
        }

        if (NULL != (*event).from && NULL != (*event).from->message_handle)
        {
            (*((*event).from->message_handle))(CTRL_NAME, (*event).from->app_name,
                                               (*event).type, (*event).info, NULL);
        }
        Serial.print("[EVENT]\tDelete -> " + String(app_event_type_info[(*event).type]));
        event = eventList.erase(event);
        Serial.print(F("\tEventList Size: "));
        Serial.println(eventList.size());
    }
    return 0;
}

// Handle wifi events
bool AppController::wifi_event(APP_MESSAGE_TYPE type)
{
    switch (type)
    {
    case APP_MESSAGE_WIFI_CONN:
    {
        if (false == m_wifi_status)
        {
            g_network.start_conn_wifi(sys_cfg.ssid_0.c_str(), sys_cfg.password_0.c_str());
            m_wifi_status = true;
        }
        m_preWifiReqMillis = GET_SYS_MILLIS();
        if ((WiFi.getMode() & WIFI_MODE_STA) == WIFI_MODE_STA && CONN_SUCC != g_network.end_conn_wifi())
        {
            return false;
        }
    }
    break;
    case APP_MESSAGE_WIFI_AP:
    {
        g_network.open_ap(AP_SSID);
        m_wifi_status = true;
        m_preWifiReqMillis = GET_SYS_MILLIS();
    }
    break;
    case APP_MESSAGE_WIFI_ALIVE:
    {
        m_wifi_status = true;
        m_preWifiReqMillis = GET_SYS_MILLIS();
    }
    break;
    case APP_MESSAGE_WIFI_DISCONN:
    {
        g_network.close_wifi();
        m_wifi_status = false;
    }
    break;
    case APP_MESSAGE_UPDATE_TIME:
    {
    }
    break;
    case APP_MESSAGE_MQTT_DATA:
    {
        Serial.println("APP_MESSAGE_MQTT_DATA");
        if (app_exit_flag == 1 && cur_app_index != getAppIdxByName("Heartbeat"))
        {
            app_exit_flag = 0;
            (*(appList[cur_app_index]->exit_callback))(NULL);
        }
        if (app_exit_flag == 0)
        {
            app_exit_flag = 1;
            cur_app_index = getAppIdxByName("Heartbeat");
            (*(getAppByName("Heartbeat")->app_init))(this);
        }
    }
    break;
    default:
        break;
    }

    return true;
}

// Exit the current app
void AppController::app_exit()
{
    app_exit_flag = 0;

    for (std::list<EVENT_OBJ>::iterator event = eventList.begin(); event != eventList.end();)
    {
        if (appList[cur_app_index] == (*event).from)
        {
            event = eventList.erase(event);
        }
        else
        {
            ++event;
        }
    }

    if (NULL != appList[cur_app_index]->exit_callback)
    {
        (*(appList[cur_app_index]->exit_callback))(NULL);
    }
    app_control_display_scr(appList[cur_app_index]->app_image,
                            appList[cur_app_index]->app_name,
                            LV_SCR_LOAD_ANIM_NONE, true);

    RgbConfig *cfg = &rgb_cfg;
    RgbParam rgb_setting = {LED_MODE_HSV,
                            cfg->min_value_0, cfg->min_value_1, cfg->min_value_2,
                            cfg->max_value_0, cfg->max_value_1, cfg->max_value_2,
                            cfg->step_0, cfg->step_1, cfg->step_2,
                            cfg->min_brightness, cfg->max_brightness,
                            cfg->brightness_step, cfg->time};
    set_rgb_and_run(&rgb_setting);

    if (1 == this->sys_cfg.power_mode)
    {
        setCpuFrequencyMhz(240);
    }
    else
    {
        setCpuFrequencyMhz(80);
    }
    Serial.print(F("CpuFrequencyMhz: "));
    Serial.println(getCpuFrequencyMhz());
}
