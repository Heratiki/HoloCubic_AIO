// Define the macro NEW_FLASH_FS
#define NEW_FLASH_FS

// Check if NEW_FLASH_FS is not defined
#ifndef NEW_FLASH_FS

/***************************************************
  Due to the use of a new file system, the functionality implemented in config.cpp/config.h
  has been deprecated. The code is kept for reference purposes.

  Github repositories: https://github.com/ClimbSnail/HoloCubic_AIO

  Last review/edit by ClimbSnail: 2023/03/14
 ****************************************************/

// Check if CONFIG_H is not defined
#ifndef CONFIG_H
#define CONFIG_H

// Include necessary libraries
#include <WString.h>
#include <Preferences.h>

// Declare Preferences object
extern Preferences prefs;

// Define the structure for MPU configuration
struct MPU_Config
{
    int16_t x_gyro_offset;
    int16_t y_gyro_offset;
    int16_t z_gyro_offset;

    int16_t x_accel_offset;
    int16_t y_accel_offset;
    int16_t z_accel_offset;
};

// Define the structure for configuration settings
struct Config
{
    String ssid;
    String password;
    String cityname;              // City to be displayed
    String language;              // Address code for weather query
    String weather_key;           // API key for ZhiXin weather
    String tianqi_appid;          // App ID for TianQi API
    String tianqi_appsecret;      // App secret for TianQi API
    String tianqi_addr;           // Address for TianQi API (in Chinese)
    String bili_uid;              // UID for Bilibili
    uint8_t backLight;            // Screen brightness (1-100)
    uint8_t rotation;             // Screen rotation direction
    uint8_t auto_calibration_mpu; // Whether to enable auto calibration for gyroscope (0: disabled, 1: enabled)
    uint8_t mpu_order;
    MPU_Config mpu_config;        // Save MPU calibration data
};

// Function to read configuration from file
void config_read(const char *file_path, Config *cfg);

// Function to save configuration to file
void config_save(const char *file_path, Config *cfg);

// Function to read MPU configuration from file
void mpu_config_read(const char *file_path, Config *cfg);

// Function to save MPU configuration to file
void mpu_config_save(const char *file_path, Config *cfg);

#endif

#endif