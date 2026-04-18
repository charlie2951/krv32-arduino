#include "bmp180.h"
#include "printf.h"
/*
SDA -> JA3
SCL -> JA4
VCC -> JA6
GND -> JA5
*/

void setup() {
    i2c_init(&I2C0, 249); //initialize i2c0 50Khz speed. Set it to499 for 100Khz
    if (bmp180_init(&I2C0) != 0){
       my_printf("Unable to detect BMP180 sensor! \r\n ");
         while(1); // Error
    }
    my_printf("BMP180 found in I2C bus! \r\n ");//this is a custom function works efficiently compared to Serial.println()
}
       
    void loop() {
        
        int32_t raw_t = bmp180_get_raw_temp(&I2C0);
        int32_t temp = bmp180_calculate_temp(raw_t); // e.g., 255 = 25.5C

        int32_t raw_p = bmp180_get_raw_pressure(&I2C0, BMP180_STANDARD);
        int32_t pressure = bmp180_calculate_pressure(raw_p, BMP180_STANDARD);
       // 3. Calculate Altitude (Relative to Sea Level)
        int32_t altitude = bmp180_get_altitude(pressure, SEA_LEVEL_PRESSURE);
        // Use temp and pressure...
        my_printf("\r\nTemp is %d.%d:", temp/10, temp%10);
        my_printf("\r\n Atmospheric pressure is %d.%d: ", pressure/100,pressure%100);
        my_printf("\r\n Altitude is: %d", altitude);
        delay(2000);//2sec delay
    } 
    