//Push_Led.ino

//
// If the button is pushed  -  keep LED off,
// if button is unpressed - turn the LED on.
//


int PinLed = 2;
int PinBtn = 10;
int ON = 1 ;
int OFF = 0;
int def_state, state = 0 ;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(PinLed, OUTPUT);
  pinMode(PinBtn, INPUT_PULLUP);
  def_state = digitalRead(PinBtn);
}

void TurnLed( int flag){
	if(flag){
		digitalWrite(PinLed, HIGH);
		} else {
			digitalWrite(PinLed, LOW);
		}
	}

  void loop() {
if (state == digitalRead(PinBtn)) {
    digitalWrite(PinLed, !digitalRead(PinLed));
}
  Serial.println(digitalRead(PinBtn));
  // Serial.println( !digitalRead(PinLed));
  // (state == digitalRead(PinBtn)) ? : (void)(state=digitalRead(PinBtn) , (void)TurnLed(state) ) ;
  delay(300);               // wait for a second
 }
