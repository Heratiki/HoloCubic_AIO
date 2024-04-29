#ifndef COMMON_H
#define COMMON_H

// Define the AIO version
#define AIO_VERSION "2.1.10"

// Define a macro to get the system milliseconds
#define GET_SYS_MILLIS xTaskGetTickCount // Get system milliseconds
// #define GET_SYS_MILLIS millis            // Get system milliseconds

// Include necessary libraries
#include "Arduino.h"              // Arduino core library
#include "driver/rgb_led.h"       // RGB LED driver
#include "driver/flash_fs.h"      // Flash file system driver
#include "driver/sd_card.h"       // SD card driver
#include "driver/display.h"       // Display driver
#include "driver/ambient.h"       // Ambient light sensor driver
#include "driver/imu.h"           // IMU (Inertial Measurement Unit) driver
#include "network.h"              // Network library

// Define pin numbers for RGB LED
#define RGB_LED_PIN 27

// Define pin numbers for SD card
#define SD_SCK 14
#define SD_MISO 26
#define SD_MOSI 13
#define SD_SS 15

// Define pin numbers for IMU (MPU6050)
#define IMU_I2C_SDA 32
#define IMU_I2C_SCL 33

// Declare external objects and variables
extern IMU mpu;                   // IMU object (accessible to the main program)
extern SdCard tf;                 // SD card object
extern Pixel rgb;                 // RGB LED object
extern Network g_network;         // Network connection object
extern FlashFS g_flashCfg;        // Flash file system object (replaces Preferences)
extern Display screen;            // Display object
extern Ambient ambLight;          // Ambient light sensor object

// Function to delay for a specified number of milliseconds
boolean doDelayMillisTime(unsigned long interval,
                          unsigned long *previousMillis,
                          boolean state);

// Define pin numbers for ambient light sensor (same as MPU6050)
#define AMB_I2C_SDA 32
#define AMB_I2C_SCL 33

// Define screen resolution
#define SCREEN_HOR_RES 240 // Horizontal resolution
#define SCREEN_VER_RES 240 // Vertical resolution

// Define TFT screen interface pins
// #define PEAK
#ifdef PEAK
#define LCD_BL_PIN 12
/* Battery */
#define CONFIG_BAT_DET_PIN 37
#define CONFIG_BAT_CHG_DET_PIN 38
/* Power */
#define CONFIG_POWER_EN_PIN 21
#define CONFIG_ENCODER_PUSH_PIN 27
#else
#define LCD_BL_PIN 5
#endif

#define LCD_BL_PWM_CHANNEL 0

// Define task priorities (lower value means higher priority)
// The highest priority is configMAX_PRIORITIES-1
#define TASK_RGB_PRIORITY 0  // Priority of the RGB task
#define TASK_LVGL_PRIORITY 2 // Priority of the LVGL page

// Mutex for LVGL operations
extern SemaphoreHandle_t lvgl_mutex;
// Macro for safe LVGL operations (avoiding dirty data)
#define AIO_LVGL_OPERATE_LOCK(CODE)                          \
    if (pdTRUE == xSemaphoreTake(lvgl_mutex, portMAX_DELAY)) \
    {                                                        \
        CODE;                                                \
        xSemaphoreGive(lvgl_mutex);                          \
    }

// Structure for system utility configuration
struct SysUtilConfig
{
    String ssid_0;
    String password_0;
    String ssid_1;
    String password_1;
    String ssid_2;
    String password_2;
    String auto_start_app;        // Name of the app to start on boot
    uint8_t power_mode;           // Power mode (0 for power saving mode, 1 for performance mode)
    uint8_t backLight;            // Screen brightness (1-100)
    uint8_t rotation;             // Screen rotation direction
    uint8_t auto_calibration_mpu; // Whether to auto calibrate the gyroscope (0 to disable, 1 to enable)
    uint8_t mpu_order;            // Operation direction of the MPU
};

#define GFX 0

#if GFX
#define TFT_MISO 19
#define TFT_MOSI 23
#define TFT_SCLK 18
#define TFT_CS -1 // Not connected
#define TFT_DC 2
#define TFT_RST 4 // Connect reset to ensure display initializes
#include <Arduino_GFX_Library.h>
extern Arduino_HWSPI *bus;
extern Arduino_ST7789 *tft;

#else
#include <TFT_eSPI.h>
/*
TFT pins should be set in path/to/Arduino/libraries/TFT_eSPI/User_Setups/Setup24_ST7789.h
*/
extern TFT_eSPI *tft;
#endif

#endif