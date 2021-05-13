byte seven_seg_digits[10][7] = {    { 0,0,0,0,0,0,1 },  // = 0
                                 { 1,0,0,1,1,1,1 },  // = 1
                                 { 0,0,1,0,0,1,0 },  // = 2
                                 { 0,0,0,0,1,1,0 },  // = 3
                                 { 1,0,0,1,1,0,0},  // = 4
                                 { 0,1,0,0,1,0,0 },  // = 5
                                 { 0,1,0,0,0,0,0 },  // = 6
                                 { 0,0,0,1,1,1,1 },  // = 7
                                 { 0,0,0,0,0,0,0 },  // = 8
                                 { 0,0,0,1,1,0,0 }   // = 9
                             };

const int buttonPin = 9;
int num=0;
int oldbtn= 0;

void sevenSegWrite(byte digit) {
  byte pin = 2;
  for (byte seg = 0; seg < 7; ++seg) {
    digitalWrite(pin, seven_seg_digits[digit][seg]);
    pin++;
  }
}


void setup() {
  Serial.begin(9600);

  for(int thisLed=2;thisLed<9;thisLed++){
    pinMode(thisLed,OUTPUT);
  }
  pinMode(buttonPin,INPUT);

  sevenSegWrite(num);
}


void loop() {
  int buttonState = digitalRead(buttonPin);
  
  if(buttonState == HIGH && oldbtn ==0){
    Serial.println(num);
     num ++;
    if(num > 9){ num = 0;}
   sevenSegWrite(num);
}
 oldbtn=buttonState;  
 delay(20);

}

