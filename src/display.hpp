#ifndef DISPLAY_HPP
#define DISPLAY_HPP

#include <LiquidCrystal_I2C.h>

class Display {
public:
    Display(uint8_t lcd_addr, uint8_t lcd_cols, uint8_t lcd_rows);
    void init();
    void showShockAlert(float temperature);
    void showNoAlert(float temperature);

private:
    LiquidCrystal_I2C lcd;
};

#endif
