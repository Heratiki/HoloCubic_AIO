#ifndef NETWORK_H
#define NETWORK_H

// Timezone offset (in hours) 8*60*60
#define TIMEZERO_OFFSIZE (28800000)

#define CONN_SUCC 0
#define CONN_ERROR 1
#define CONN_ERR_TIMEOUT 15 // Timeout for WiFi connection (in seconds)

// WiFi connection flag
#define AP_DISABLE 0
#define AP_ENABLE 1

// Set your server's logical name here e.g. if 'myserver' then address is http://myserver.local/
#define SERVER_NAME "fileserver"

#ifdef ESP8266
#include <ESP8266WiFi.h>      // Built-in library for ESP8266
#include <ESP8266WiFiMulti.h> // Built-in library for ESP8266
#include <ESP8266WebServer.h> // Built-in library for ESP8266
#include <ESP8266mDNS.h>
#else
#include <WiFi.h>      // Built-in library for ESP32
#include <WiFiMulti.h> // Library for managing multiple WiFi network connections on ESP8266
#include <WebServer.h> // Library for ESP32 Web Server
#include <ESPmDNS.h>
#include <HTTPClient.h>
#endif

extern IPAddress local_ip; // Set your server's fixed IP address here
extern IPAddress gateway;  // Set your network Gateway usually your Router base address
extern IPAddress subnet;   // Set your network sub-network mask here
extern IPAddress dns;      // Set your network DNS usually your Router base address

extern const char *AP_SSID; // Hotspot name

void restCallback(TimerHandle_t xTimer);

class Network
{
private:
    unsigned long m_preDisWifiConnInfoMillis; // Stores the timestamp of the last displayed connection status

public:
    Network();
    void search_wifi(void);
    boolean start_conn_wifi(const char *ssid, const char *password);
    boolean end_conn_wifi(void);
    boolean close_wifi(void);
    boolean open_ap(const char *ap_ssid = AP_SSID, const char *ap_password = NULL);
};

#endif
