#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "esp_system.h"
#include "driver/spi_master.h"
#include "driver/gpio.h"
#include <stdint.h>
#include <math.h>
#include "sdkconfig.h"
#include "esp_log.h"
#include <string.h>

class Epd
{
    public:
    Epd();
    void lcd_cmd(spi_device_handle_t spi, const uint8_t cmd);

    void lcd_data(spi_device_handle_t spi, const uint8_t *data, int len);

    void lcd_init(spi_device_handle_t spi);

 void send_lines(spi_device_handle_t spi, int ypos, uint16_t *linedata);

 void send_line_finish(spi_device_handle_t spi);

 void display_pretty_colors(spi_device_handle_t spi);

void init();
};