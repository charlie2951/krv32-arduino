#include "printf.h"
#include "spi.h"
#include "adxl345.h"

#define SPI_CLOCK_DIVIDER 50
adxl345_data_t accel;
void setup() {
  // put your setup code here, to run once:
  

      my_printf("--- SPI Universal Master Test ---\r\n");

   if (adxl345_spi_init(SPI_CLOCK_DIVIDER)) {
      my_printf("ADXL345 Initialized Successfully!\r\n");
   } else {
       my_printf("ADXL345 Error: ID Mismatch or Hardware Timeout\r\n");
       // Loop here on error
       while(1);
   }
}

void loop() {
  // put your main code here, to run repeatedly:
  // Read X, Y, Z data in one multi-byte SPI burst
       adxl345_read_accel(&accel);
       my_printf("%d,%d,%d\r\n",(int32_t)accel.x, (int32_t)accel.y, (int32_t)accel.z); 
              
       // Wait approx 1sec between samples
       delay(1000); 

}
