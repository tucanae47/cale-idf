// Epaper: 5.65inch ACeP 7-Color  https://www.waveshare.com/product/displays/e-paper/5.65inch-e-paper-module-f.htm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "freertos/FreeRTOS.h"
#include "esp_system.h"
#include <stdint.h>
#include <math.h>
#include "sdkconfig.h"
#include "esp_log.h"
#include <string>
#include <epd.h>
#include <Adafruit_GFX.h>
#include <epdspi.h>
// Todo replace by acep_7_colors or declare here
#include <wave7colors.h>

// Controller: Unknown
#define WAVE5I7COLOR_WIDTH 600
#define WAVE5I7COLOR_HEIGHT 448
#define WAVE5I7COLOR_BUFFER_SIZE (uint32_t(WAVE5I7COLOR_WIDTH) * uint32_t(WAVE5I7COLOR_HEIGHT) / 2)

class Wave5i7Color : public Epd
{
  public:
   
    Wave5i7Color(EpdSpi& IO);
    // Public properties for this display
    const uint8_t colors_supported = 7;
    const bool has_partial_update = false;
    
    void init(bool debug = false);
    void drawPixel(int16_t x, int16_t y, uint16_t color);
    void fillScreen(uint16_t color);
    void update();

  private:
    EpdSpi& IO;

    uint8_t _buffer[WAVE5I7COLOR_BUFFER_SIZE];
    // TODO: Not sure if I need this properties here since we do not use Partial windows
    uint16_t _pw_x = 0;
    uint16_t _pw_y = 0;
    uint16_t _pw_w = WAVE5I7COLOR_WIDTH;
    uint16_t _pw_h = WAVE5I7COLOR_HEIGHT;

    bool _initial = true;
    void _wakeUp();
    void _sleep();
    void _waitBusy(const char* message);
    void _rotate(uint16_t& x, uint16_t& y, uint16_t& w, uint16_t& h);
    uint8_t _color7(uint16_t color);
};