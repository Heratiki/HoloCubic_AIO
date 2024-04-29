#ifndef INTERFACE_H
#define INTERFACE_H

// Enumeration of different types of application messages
enum APP_MESSAGE_TYPE
{
    APP_MESSAGE_WIFI_CONN = 0, // Open connection
    APP_MESSAGE_WIFI_AP,       // Open AP event
    APP_MESSAGE_WIFI_ALIVE,    // Heartbeat maintenance for wifi switch
    APP_MESSAGE_WIFI_DISCONN,  // Connection disconnected
    APP_MESSAGE_UPDATE_TIME,   // Update time
    APP_MESSAGE_MQTT_DATA,     // MQTT client received message
    APP_MESSAGE_GET_PARAM,     // Get parameters
    APP_MESSAGE_SET_PARAM,     // Set parameters
    APP_MESSAGE_READ_CFG,      // Read parameters from disk
    APP_MESSAGE_WRITE_CFG,     // Write parameters to disk

    APP_MESSAGE_NONE
};

// Enumeration of different types of applications
enum APP_TYPE
{
    APP_TYPE_REAL_TIME = 0, // Real-time application
    APP_TYPE_BACKGROUND,    // Background application

    APP_TYPE_NONE
};

// Forward declaration of classes and structures
class AppController;
struct ImuAction;

// Structure representing an application
struct APP_OBJ
{
    // Application name and title
    const char *app_name;

    // Path to the image representing the application (128*128)
    const void *app_image;

    // Other information about the application, such as author and version number
    const char *app_info;

    // Initialization function for the application (can be empty)
    int (*app_init)(AppController *sys);

    // Main program function for the application
    void (*main_process)(AppController *sys,
                         const ImuAction *act_info);

    // Task function for the application (usually called once every minute)
    void (*background_task)(AppController *sys,
                            const ImuAction *act_info);

    // Callback function to be executed before exiting (can be empty)
    int (*exit_callback)(void *param);

    // Message handling function
    void (*message_handle)(const char *from, const char *to,
                           APP_MESSAGE_TYPE type, void *message,
                           void *ext_info);
};

#endif