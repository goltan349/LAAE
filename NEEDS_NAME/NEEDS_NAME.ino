/*
 * 
 * 
 */

/* CONSTANTS */
int BAUD = 9600;      //The rate at which the Arduino will communicate with the host computer
int analogInput = A1;

/* INITALIZATIONS */
float vout = 0.0;
float vin = 0.0;
float R1 = 30000.0;
float R2 = 7500.0;
int value = 0;
int pwmOut = 3;


void setup() {
  //Set up the inputs and outputs for the system
  pinMode(analogInput, INPUT);
  pinMode(pwmOut, OUTPUT);

  //Start the serial terminal
  Serial.begin(BAUD);

  Serial.print("DC VOLTMETER");  
}

void loop() {
  value = analogRead(analogInput);
  vout = (value * 5.0) / 1024.0; // see text
  vin = vout / (R2 / (R1 + R2));

  do {

    if (analogInput == 0) {
      analogWrite(pwmOut, 0); // about zero volts
    } else if (analogInput == 1) {
      analogWrite(pwmOut, 51); // about 1 volt
    } else if (analogInput == 2) {
      analogWrite(pwmOut, 102); // about 2 volts
    } else if (analogInput == 2.5) {
      analogWrite(pwmOut, 128); // about 2.5 volts
    } else if (analogInput == 3) {
      analogWrite(pwmOut, 153); // about 3.0 volts
    } else if (analogInput == 4) {
      analogWrite(pwmOut, 204); // about 4.0 volts
    } else if (analogInput == 5) {
      analogWrite(pwmOut, 255); // about 5.0 volts
    }

  } while (analogInput >= 0 && analogInput <= 5);

  Serial.print("INPUT V= ");
  Serial.println(vin, 2);
  delay(500);
}
