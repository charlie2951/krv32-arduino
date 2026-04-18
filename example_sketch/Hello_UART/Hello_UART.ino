void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
Serial.print("KRV32");
Serial.print("\r\n");
}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.println("Hello world!");
  delay(5000);

}
