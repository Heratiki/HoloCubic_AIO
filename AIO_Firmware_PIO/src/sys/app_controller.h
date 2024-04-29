#ifndef APP_CONTROLLER_H
#define APP_CONTROLLER_H

#include "Arduino.h"
#include "interface.h"
#include "driver/imu.h"
#include "common.h"
#include <list>

#define CTRL_NAME "AppCtrl"
#define APP_MAX_NUM 20             // Maximum number of runnable apps
#define WIFI_LIFE_CYCLE 60000      // Wi-Fi lifecycle (60s)
#define MQTT_ALIVE_CYCLE 1000      // MQTT reconnection cycle
#define EVENT_LIST_MAX_LENGTH 10   // Capacity of the message queue
#define APP_CONTROLLER_NAME_LEN 16 // Length of the app controller name

// Structure to represent an event
struct EVENT_OBJ
{
    const APP_OBJ *from;       // App that sends the request
    APP_MESSAGE_TYPE type;     // Type of the event
    void *info;                // Information carried by the request
    uint8_t retryMaxNum;       // Maximum number of retries
    uint8_t retryCount;        // Retry count
    unsigned long nextRunTime; // Timestamp for the next run
};

class AppController
{
public:
    AppController(const char *name = CTRL_NAME);
    ~AppController();
    void init(void);
    void Display(void); // Display interface
    int app_auto_start();
    // Register an app to the app_controller
    int app_install(APP_OBJ *app,
                    APP_TYPE app_type = APP_TYPE_REAL_TIME);
    // Uninstall (delete) an app from the app_controller
    int app_uninstall(const APP_OBJ *app);
    // Remove the background task of an app from the task queue
    // (Can only be called by the app itself when exiting)
    int remove_backgroud_task(void);
    int main_process(ImuAction *act_info);
    void app_exit(void); // System call for app exit
    // Send a message
    int send_to(const char *from, const char *to,
                APP_MESSAGE_TYPE type, void *message,
                void *ext_info);
    void deal_config(APP_MESSAGE_TYPE type,
                     const char *key, char *value);
    // Event handling
    int req_event_deal(void);
    bool wifi_event(APP_MESSAGE_TYPE type); // Wi-Fi event handling
    void read_config(SysUtilConfig *cfg);
    void write_config(SysUtilConfig *cfg);
    void read_config(SysMpuConfig *cfg);
    void write_config(SysMpuConfig *cfg);
    void read_config(RgbConfig *cfg);
    void write_config(RgbConfig *cfg);

private:
    APP_OBJ *getAppByName(const char *name);
    int getAppIdxByName(const char *name);
    int app_is_legal(const APP_OBJ *app_obj);

private:
    char name[APP_CONTROLLER_NAME_LEN]; // Name of the app controller
    APP_OBJ *appList[APP_MAX_NUM];      // Reserved slots for APP_MAX_NUM apps
    APP_TYPE appTypeList[APP_MAX_NUM];  // Corresponding app types
    // std::list<const APP_OBJ *> app_list; // Reserved slots for apps (using a list for C portability)
    std::list<EVENT_OBJ> eventList;   // List to store events
    boolean m_wifi_status;            // Indicates Wi-Fi status (true for on, false for off)
    unsigned long m_preWifiReqMillis; // Stores the timestamp of the last request
    unsigned int app_num;
    boolean app_exit_flag; // Indicates whether the app should exit
    int cur_app_index;     // Index of the currently running app
    int pre_app_index;     // Index of the previously running app

    TimerHandle_t xTimerEventDeal; // Timer for event handling

public:
    SysUtilConfig sys_cfg;
    SysMpuConfig mpu_cfg;
    RgbConfig rgb_cfg;
};

#endif
