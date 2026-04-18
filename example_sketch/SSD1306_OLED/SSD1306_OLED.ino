#include "ssd1306.h"
#define I2C I2C0 //using I2C-0

void setup() {
  // put your setup code here, to run once:
    ssd1306_init(&I2C);
    ssd1306_set_cursor(0, 0);
    ssd1306_write_string("Hello KRV32!");
}

void loop() {
  // put your main code here, to run repeatedly:

}
