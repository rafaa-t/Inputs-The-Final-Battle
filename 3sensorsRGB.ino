#define trigPin 5
#define echoPin 6

int potenPin = A0;
int ldrPin = A1;

int red_light_pin= 11;
int green_light_pin = 10;
int blue_light_pin = 9;


void setup() {
  Serial.begin(9600);

  pinMode(potenPin, INPUT);
  pinMode(ldrPin, INPUT);
  
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);

  pinMode(red_light_pin, OUTPUT);
  pinMode(green_light_pin, OUTPUT);
  pinMode(blue_light_pin, OUTPUT);
}

void loop() {

  // create the distance in cm ----------------
  int duration, distance;
  digitalWrite(trigPin, LOW); 
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distance = (duration / 2) * 0.0344;
  //-----------------------------------------
 
  int potenValue = analogRead(potenPin);
  int ldrValue = analogRead(ldrPin);
  int distanValue = distance;

  int poten = map(potenValue,0,1023,255,0);
  int ldr = map(ldrValue,0,900,255,0);
  int distan = map(distanValue,0,150,255,0);

  RGB_color(poten,ldr,distan);

  Serial.println(poten);
  Serial.println(ldr);
  Serial.println(distan);
  Serial.println("--------------------");

  delay(1000);

}

void RGB_color(int red_light_value, int green_light_value, int blue_light_value)
 {
  analogWrite(red_light_pin, red_light_value);
  analogWrite(green_light_pin, green_light_value);
  analogWrite(blue_light_pin, blue_light_value);
}
