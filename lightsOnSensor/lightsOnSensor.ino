int ledPins[] = {2,3,4};
int pingPin = 7;
int echoPin = 6;

void setup() {
  int index;
  Serial.begin(9600);
  //Initialise LED pins
  for(index = 0; index <= 2; index++) {
    pinMode(ledPins[index], OUTPUT);
  }   
}

void loop() {
  long duration, inches, cm;
  //Initialise sensor pins
  pinMode(pingPin, OUTPUT);
  digitalWrite(pingPin, LOW);
  delayMicroseconds(2);
  digitalWrite(pingPin, HIGH);  
  delayMicroseconds(10);
  digitalWrite(pingPin, LOW);
  pinMode(echoPin, INPUT);
  
  duration = pulseIn(echoPin, HIGH);
  inches = microsecondsToInches(duration);
  cm = microsecondsToCentimeters(duration);
  //Print object distance from sensor
  Serial.print(inches);
  Serial.print("in, ");
  Serial.print(cm);
  Serial.print("cm");
  Serial.println();

  //When object is < 5 cm away from sensor
  if(cm < 5) { 
    //Turn on pin 2 and turn off rest
    digitalWrite(ledPins[0], HIGH);
    digitalWrite(ledPins[1], LOW);
    digitalWrite(ledPins[2], LOW);
  } else if(cm > 5 && cm < 10) {
    //Turn on pin 3 and turn off rest
    digitalWrite(ledPins[0], LOW);
    digitalWrite(ledPins[1], HIGH);
    digitalWrite(ledPins[2], LOW);
  } else if(cm > 10 && cm < 15) {
    //Turn on pin 4 and turn off rest
    digitalWrite(ledPins[0], LOW);
    digitalWrite(ledPins[1], LOW);
    digitalWrite(ledPins[2], HIGH);
  } else {
    //Turn off all
    digitalWrite(ledPins[0], LOW);
    digitalWrite(ledPins[1], LOW);
    digitalWrite(ledPins[2], LOW);
  }
  
  delay(100);
}

long microsecondsToInches(long microseconds) {
   return microseconds / 74 / 2;
}

long microsecondsToCentimeters(long microseconds) {
   return microseconds / 29 / 2;
}

  
  
