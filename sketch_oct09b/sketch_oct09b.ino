
int pin8 = 8 ;
int pin9 = 9 ;

void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
pinMode(pin8,OUTPUT);
//pinMode(pin9,INPUT_PULLUP);
pinMode(pin9,INPUT_PULLUP);
}

void loop() {
  // put your main code here, to run repeatedly:
//digitalWrite(pin8,HIGH);
//delay(1000);
//digitalWrite(pin8,LOW);
//delay(1000);
Serial.println(digitalRead(pin9));
delay(1000);
}
