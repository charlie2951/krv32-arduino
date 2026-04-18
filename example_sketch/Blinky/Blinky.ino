void setup() {
  // Initialize GPIO 15 as Outputs
 
    pinMode(15, OUTPUT);
  
}

void loop() {
  // LEDs ON
     digitalWrite(15, HIGH);
  // Uses your timer_delay_ms(TIMER0, 500) via wiring.c
  delay(500); 
  // All LEDs OFF
   digitalWrite(15, LOW);
   delay(500);
}