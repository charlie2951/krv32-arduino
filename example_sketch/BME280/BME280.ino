#include "i2c.h"
#include "bme280.h"
#include "printf.h"
#include "spi.h"//use it if using spi interface

#define I2C_PORT I2C1 //using I2C1 

int32_t  temperature;
uint32_t pressure;
uint32_t humidity;

void setup() {
  // Initialize I2C (adjust divider for your clock frequency)
    i2c_init(&I2C_PORT, 499); 
    uint8_t resp = bme280_init_i2c(&I2C_PORT);
    // For SPI use following
   // uint8_t resp = bme280_init_spi(10);
    // Initialize BME280
    if ( resp == 0) 
       my_printf("BME280 Initialized Successfully!\r\n");
       else 
        my_printf("Error: BME280 not found!\r\n");
    
}

void loop() {
  //note:BME280 cant measure humidity
  bme280_i2c_get_temperature(&I2C_PORT, &temperature);
  bme280_i2c_get_pressure(&I2C_PORT, &pressure);
  // For SPI, use the following
  // bme280_get_temperature_spi(&temperature);
  // bme280_get_pressure_spi(&pressure);
  my_printf(" BME280 -> Temp: %d.%d C | Press: %d.%d hPa \r\n", 
                    temperature / 100,  temperature % 100, 
                    pressure/100, pressure%100);
  
  delay(1000);
}
