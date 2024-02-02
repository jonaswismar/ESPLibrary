#include <Arduino.h>

void setup()
{
  // Common
  // ESP.deepSleep();
  // ESP.flashEraseSector();
  // ESP.flashRead();
  // ESP.flashWrite();
  ESP.getCpuFreqMHz();
  ESP.getCycleCount();
  ESP.getFlashChipMode();
  ESP.getFlashChipSize();
  ESP.getFlashChipSpeed();
  ESP.getFreeHeap();
  ESP.getFreeSketchSpace();
  ESP.getSdkVersion();
  ESP.getSketchMD5();
  ESP.getSketchSize();
  // ESP.magicFlashChipMode();
  // ESP.magicFlashChipSize();
  // ESP.magicFlashChipSpeed();
  ESP.restart();

  // uint8_t newMACAddress[] = {0x32, 0xAE, 0xA4, 0x07, 0x0D, 0x66};
  /*
  //ESP32
  ESP.getChipModel();
  ESP.getChipRevision();
  ESP.getEfuseMac();
  ESP.getFreePsram();
  ESP.getHeapSize();
  ESP.getMaxAllocHeap();
  ESP.getMaxAllocPsram();
  ESP.getMinFreeHeap();
  ESP.getMinFreePsram();
  ESP.getPsramSize();
  ESP.partitionEraseRange();
  ESP.partitionRead();
  ESP.partitionWrite();

  //ESP8266
  ESP.checkFlashConfig();
  ESP.checkFlashCRC();
  ESP.deepSleepInstant();
  ESP.deepSleepMax();
  ESP.eraseConfig();
  ESP.getBootMode();
  ESP.getBootVersion();
  ESP.getCoreVersion();
  ESP.getFlashChipId();
  ESP.getFreeContStack();
  ESP.getHeapFragmentation();
  ESP.getHeapStats();
  ESP.getMaxFreeBlockSize();
  ESP.getResetInfoPtr();
  ESP.getVcc();
  ESP.rebootIntoUartDownloadMode();
  ESP.resetFreeContStack();
  ESP.resetHeap();
  ESP.rtcUserMemoryRead();
  ESP.rtcUserMemoryWrite();
  ESP.setDramHeap();
  ESP.setExternalHeap();
  ESP.setIramHeap();
  ESP.updateSketch();
  ESP.wdtDisable();
  ESP.wdtEnable();
  ESP.wdtFeed();*/

}

void loop()
{
  
}