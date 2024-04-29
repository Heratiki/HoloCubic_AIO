#include "network.h"
#include "common.h"
#include <esp_wifi.h>
#include "HardwareSerial.h"

// Set your server's fixed IP address here
IPAddress local_ip(192, 168, 4, 2);
// Set your network Gateway usually your Router base address
IPAddress gateway(192, 168, 4, 2);
// Set your network sub-network mask here
IPAddress subnet(255, 255, 255, 0);
// Set your network DNS usually your Router base address
IPAddress dns(192, 168, 4, 1);

// Hotspot name
const char *AP_SSID = "HoloCubic_AIO";
// Host name
const char *HOST_NAME = "HoloCubic";

uint16_t ap_timeout = 0; // Timeout for no connection to the hotspot

TimerHandle_t xTimer_ap;

Network::Network()
{
    m_preDisWifiConnInfoMillis = 0;
    WiFi.enableSTA(false);
    WiFi.enableAP(false);
}

void Network::search_wifi(void)
{
    Serial.println("scan start");
    int wifi_num = WiFi.scanNetworks();
    Serial.println("scan done");
    if (0 == wifi_num)
    {
        Serial.println("no networks found");
    }
    else
    {
        Serial.print(wifi_num);
        Serial.println(" networks found");
        for (int cnt = 0; cnt < wifi_num; ++cnt)
        {
            Serial.print(cnt + 1);
            Serial.print(": ");
            Serial.print(WiFi.SSID(cnt));
            Serial.print(" (");
            Serial.print(WiFi.RSSI(cnt));
            Serial.print(")");
            Serial.println((WiFi.encryptionType(cnt) == WIFI_AUTH_OPEN) ? " " : "*");
        }
    }
}

boolean Network::start_conn_wifi(const char *ssid, const char *password)
{
    if (WiFi.status() == WL_CONNECTED)
    {
        Serial.println(F("\nWiFi is OK.\n"));
        return false;
    }
    Serial.println("");
    Serial.print(F("Connecting: "));
    Serial.print(ssid);
    Serial.print(F(" @ "));
    Serial.println(password);

    // Set to STA mode and connect to WiFi
    WiFi.enableSTA(true);
    // Change the host name
    WiFi.setHostname(HOST_NAME);
    WiFi.begin(ssid, password);
    m_preDisWifiConnInfoMillis = GET_SYS_MILLIS();

    return true;
}

boolean Network::end_conn_wifi(void)
{
    if (WL_CONNECTED != WiFi.status())
    {
        if (doDelayMillisTime(10000, &m_preDisWifiConnInfoMillis, false))
        {
            // This if statement is to reduce frequent printing
            Serial.println(F("\nWiFi connect error.\n"));
        }
        return CONN_ERROR;
    }

    if (doDelayMillisTime(10000, &m_preDisWifiConnInfoMillis, false))
    {
        // This if statement is to reduce frequent printing
        Serial.println(F("\nWiFi connected"));
        Serial.print(F("IP address: "));
        Serial.println(WiFi.localIP());
    }
    return CONN_SUCC;
}

boolean Network::close_wifi(void)
{
    if(WiFi.getMode() & WIFI_MODE_AP)
    {
        WiFi.enableAP(false);
        Serial.println(F("AP shutdown"));
    }

    if (!WiFi.disconnect())
    {
        return false;
    }
    WiFi.enableSTA(false);
    WiFi.mode(WIFI_MODE_NULL);
    Serial.println(F("WiFi disconnect"));
    return true;
}

boolean Network::open_ap(const char *ap_ssid, const char *ap_password)
{
    WiFi.enableAP(true); // Configure as AP mode
    // Change the host name
    WiFi.setHostname(HOST_NAME);
    boolean result = WiFi.softAP(ap_ssid, ap_password); // Start WiFi hotspot
    if (result)
    {
        WiFi.softAPConfig(local_ip, gateway, subnet);
        IPAddress myIP = WiFi.softAPIP();

        // Print relevant information
        Serial.print(F("\nSoft-AP IP address = "));
        Serial.println(myIP);
        Serial.println(String("MAC address = ") + WiFi.softAPmacAddress().c_str());
        Serial.println(F("waiting ..."));
        ap_timeout = 300; // Start the timer
    }
    else
    {
        // Failed to start hotspot
        Serial.println(F("WiFiAP Failed"));
        return false;
        delay(1000);
        ESP.restart(); // Reset ESP32
    }
    // Set the domain name
    if (MDNS.begin(HOST_NAME))
    {
        Serial.println(F("MDNS responder started"));
    }
    return true;
}

void restCallback(TimerHandle_t xTimer)
{
    // Reset the device if there is no access to WiFi Config for a long time
    --ap_timeout;
    Serial.print(F("AP timeout: "));
    Serial.println(ap_timeout);
    if (ap_timeout < 1)
    {
        WiFi.softAPdisconnect(true);
    }
}
