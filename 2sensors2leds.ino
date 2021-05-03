// value output to the PWM (analog out)

void setup() {
  Serial.begin(9600);
}

void loop() {
  int potenPin = A0;
  int ldrPin = A1;
  
  int potenValue = analogRead(potenPin);
  int ldrValue = analogRead(ldrPin);

  int poten = map(potenValue,0,1023,255,0);
  int ldr = map(ldrValue,0,950,255,0);

  if(poten > 10){
    analogWrite(5, poten);
  }else{
    digitalWrite(5,LOW);
  }
  analogWrite(6, ldr);  

  Serial.println(ldrValue);
  Serial.println(potenValue);

  delay(2);
}
