#include <Arduino.h>

uint8_t getChipCores();
uint32_t getChipId();
String getChipModel();
uint8_t getChipRevision();

uint32_t getCpuFreqMHz();

uint8_t getFlashChipVendorId();
String getFlashChipMode();
uint32_t getFlashChipRealSize();
uint32_t getFlashChipSize();
uint32_t  getFlashChipSpeed();

String getSDKVersion();
String getFullVersion();

uint32_t getHeapSize();
uint32_t getFreeHeap();

uint32_t getPsramSize();
uint32_t getFreePsram();

uint32_t getRandom();

String getResetInfo();
String getResetReason();
void reset();

uint32_t getSketchSize();
uint32_t getFreeSketchSpace();
String getSketchMD5();

boolean setMAC(uint8_t);