#include <Arduino.h>

#include "ESPLib.h"

#if defined(ESP32)
#include <core_version.h>
#include <esp_random.h>
#include <esp_wifi.h>
#include <rom/rtc.h>
#include <rom/spi_flash.h>
#include <WiFi.h>
#elif defined(ESP8266)
#include <ESP8266WiFi.h>
#endif

uint8_t getChipCores()
{
#if defined(ESP32)
    return ESP.getChipCores();
#elif defined(ESP8266)
    return 1;
#endif
}
uint32_t getChipId()
{
#if defined(ESP32)
    uint32_t chipId = 0;
    for (int i = 0; i < 17; i = i + 8)
    {
        chipId |= ((ESP.getEfuseMac() >> (40 - i)) & 0xff) << i;
    }
    return chipId;
#elif defined(ESP8266)
    return ESP.getChipId();
#endif
}
String getChipModel()
{
#if defined(ESP32)
    return ESP.getChipModel();
#elif defined(ESP8266)
    return ""; // ToDo Implement
#endif
}
uint8_t getChipRevision()
{
#if defined(ESP32)
    return ESP.getChipRevision();
#elif defined(ESP8266)
    return 1; // ToDo Implement
#endif
}

uint32_t getCpuFreqMHz()
{
    return ESP.getCpuFreqMHz();
}

uint8_t getFlashChipVendorId()
{
#if defined(ESP32)
    return g_rom_flashchip.device_id;
#elif defined(ESP8266)
    return ESP.getFlashChipVendorId();
#endif
}
String getFlashChipMode()
{
return String(ESP.getFlashChipMode());
}
uint32_t getFlashChipRealSize()
{
#if defined(ESP32)
    return spi_flash_get_chip_size();
#elif defined(ESP8266)
    return ESP.getFlashChipRealSize();
#endif
}
uint32_t getFlashChipSize()
{
return ESP.getFlashChipSize();
}
uint32_t  getFlashChipSpeed()
{
return ESP.getFlashChipSpeed();
}

String getSDKVersion()
{
    return ESP.getSdkVersion();
}
String getFullVersion()
{
#if defined(ESP32)
    String s(F("SDK:"));
    s.reserve(127);
    s += ESP.getSdkVersion();
    s += FPSTR(ARDUINO_ESP32_GIT_VER);
    s += FPSTR(ARDUINO_ESP32_RELEASE);
    return s;
#elif defined(ESP8266)
    return ESP.getFullVersion();
#endif
}

uint32_t getHeapSize()
{
    #if defined(ESP32)
    return ESP.getHeapSize();
#elif defined(ESP8266)
    static uint32_t myfree;
    static uint16_t mymax;
    static uint8_t myfrag;
    ESP.getHeapStats(&myfree, &mymax, &myfrag);
    return mymax;
#endif
}
uint32_t getFreeHeap()
{
    return ESP.getFreeHeap();
}

uint32_t getPsramSize()
{
    #if defined(ESP32)
    return ESP.getPsramSize();
#elif defined(ESP8266)
    return 0;
#endif
}
uint32_t getFreePsram()
{
    #if defined(ESP32)
    return ESP.getFreePsram();
#elif defined(ESP8266)
    return 0;
#endif
}

uint32_t getRandom()
{
#if defined(ESP32)
    return esp_random();
#elif defined(ESP8266)
    return ESP.random();
#endif
}

String getResetInfo()
{
#if defined(ESP32)
    switch (rtc_get_reset_reason(0))
    {
    case 1:
        return F("POWERON_RESET");
        break; /**<1, Vbat power on reset*/
    case 3:
        return F("SW_RESET");
        break; /**<3, Software reset digital core*/
    case 4:
        return F("OWDT_RESET");
        break; /**<4, Legacy watch dog reset digital core*/
    case 5:
        return F("DEEPSLEEP_RESET");
        break; /**<5, Deep Sleep reset digital core*/
    case 6:
        return F("SDIO_RESET");
        break; /**<6, Reset by SLC module, reset digital core*/
    case 7:
        return F("TG0WDT_SYS_RESET");
        break; /**<7, Timer Group0 Watch dog reset digital core*/
    case 8:
        return F("TG1WDT_SYS_RESET");
        break; /**<8, Timer Group1 Watch dog reset digital core*/
    case 9:
        return F("RTCWDT_SYS_RESET");
        break; /**<9, RTC Watch dog Reset digital core*/
    case 10:
        return F("INTRUSION_RESET");
        break; /**<10, Instrusion tested to reset CPU*/
    case 11:
        return F("TGWDT_CPU_RESET");
        break; /**<11, Time Group reset CPU*/
    case 12:
        return F("SW_CPU_RESET");
        break; /**<12, Software reset CPU*/
    case 13:
        return F("RTCWDT_CPU_RESET");
        break; /**<13, RTC Watch dog Reset CPU*/
    case 14:
        return F("EXT_CPU_RESET");
        break; /**<14, for APP CPU, reseted by PRO CPU*/
    case 15:
        return F("RTCWDT_BROWN_OUT_RESET");
        break; /**<15, Reset when the vdd voltage is not stable*/
    case 16:
        return F("RTCWDT_RTC_RESET");
        break; /**<16, RTC Watch dog reset digital core and rtc module*/
    default:
        return F("NO_MEAN");
    }
#elif defined(ESP8266)
    return ESP.getResetInfo();
#endif
}
String getResetReason()
{
#if defined(ESP32)
    switch (rtc_get_reset_reason(0))
    {
    case 1:
        return F("Vbat power on reset");
        break;
    case 3:
        return F("Software reset digital core");
        break;
    case 4:
        return F("Legacy watch dog reset digital core");
        break;
    case 5:
        return F("Deep Sleep reset digital core");
        break;
    case 6:
        return F("Reset by SLC module, reset digital core");
        break;
    case 7:
        return F("Timer Group0 Watch dog reset digital core");
        break;
    case 8:
        return F("Timer Group1 Watch dog reset digital core");
        break;
    case 9:
        return F("RTC Watch dog Reset digital core");
        break;
    case 10:
        return F("Instrusion tested to reset CPU");
        break;
    case 11:
        return F("Time Group reset CPU");
        break;
    case 12:
        return F("Software reset CPU");
        break;
    case 13:
        return F("RTC Watch dog Reset CPU");
        break;
    case 14:
        return F("for APP CPU, reseted by PRO CPU");
        break;
    case 15:
        return F("Reset when the vdd voltage is not stable");
        break;
    case 16:
        return F("RTC Watch dog reset digital core and rtc module");
        break;
    default:
        return F("NO_MEAN");
    }
#elif defined(ESP8266)
    return ESP.getResetReason();
#endif
}
void reset()
{
#if defined(ESP32)
    ESP.restart();
#elif defined(ESP8266)
    ESP.reset();
#endif
}

uint32_t getSketchSize()
{
    return ESP.getSketchSize();
}
uint32_t getFreeSketchSpace()
{
    return ESP.getFreeSketchSpace();
}
String getSketchMD5()
{
    return ESP.getSketchMD5();
}

boolean setMAC(uint8_t newMACAddress[])
{
#if defined(ESP32)
    return esp_wifi_set_mac(WIFI_IF_STA, &newMACAddress[0]);
#elif defined(ESP8266)
    if (WiFi.getMode() == WIFI_AP)
    {
        return wifi_set_macaddr(SOFTAP_IF, &newMACAddress[0]);
    }
    else if (WiFi.getMode() == WIFI_STA)
    {
        return wifi_set_macaddr(STATION_IF, &newMACAddress[0]);
    }
    else
    {
        return false;
    }
#endif
}