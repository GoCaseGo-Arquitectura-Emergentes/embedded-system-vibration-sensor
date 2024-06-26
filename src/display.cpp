#include "display.hpp"

Display::Display(uint8_t lcd_addr, uint8_t lcd_cols, uint8_t lcd_rows) 
    : lcd(lcd_addr, lcd_cols, lcd_rows) {}

void Display::init() {
    lcd.init();
    lcd.backlight();
}

void Display::showShockAlert(float temperature) {
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Alerta de choque!");
    lcd.setCursor(0, 1);
    lcd.print("Temp: ");
    lcd.print(temperature);
    lcd.print(" C");
}

void Display::showNoAlert(float temperature) {
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Sin alertas     ");
    lcd.setCursor(0, 1);
    lcd.print("Temp: ");
    lcd.print(temperature);
    lcd.print(" C");
}
