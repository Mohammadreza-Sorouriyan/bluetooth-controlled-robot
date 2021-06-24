String readString;
int SPEED;
#define E1 11  // Enable Pin for motor 2

#define E2 11  // Enable Pin for motor 2
 
#define I1 2  // Control pin 1 for motor 1
#define I2 3  // Control pin 2 for motor 1
#define I3 4  // Control pin 1 for motor 2
#define I4 5  // Control pin 2 for motor 2
 
void setup() {
  Serial.begin(9600); 
    pinMode(E1, OUTPUT); 
    pinMode(E2, OUTPUT);
 
    pinMode(I1, OUTPUT);
    pinMode(I2, OUTPUT);
    pinMode(I3, OUTPUT);
    pinMode(I4, OUTPUT);
   
  analogWrite(E1, 255); // Run in full speed
  analogWrite(E2, 255); // Run in full speed
  
}
 
void loop() {
  
  while (Serial.available()) {
    delay(50);
    char c = Serial.read();
    readString += c;
  }
  if (readString.length() > 0) {
    Serial.println(readString);
    
 //main code that work repeated   
  
  analogWrite(E1, 255); // Run in full speed
  analogWrite(E2, 255); // Run in full speed
  
  if (readString == "f") { //forward command
 forward();
  }
 
  if (readString == "b") { //backward command
 backward();
  }
 
   if (readString == "r") { //right command
 right();
  }
 
   if (readString == "l") { //laft command
 left();
  }
  
  if(readString == "s") { //stop command
 stoped();
  }
 
      readString="";
}
 
}
void forward(void){
    digitalWrite(I1, HIGH);
    digitalWrite(I2, LOW);
    digitalWrite(I3, HIGH);
    digitalWrite(I4, LOW);
}
 
void backward(void){
    digitalWrite(I1, LOW);
    digitalWrite(I2, HIGH);
    digitalWrite(I3, LOW);
    digitalWrite(I4, HIGH);
}
 
void right(void){
    digitalWrite(I1, LOW);
    digitalWrite(I2, HIGH);
    digitalWrite(I3, HIGH);
    digitalWrite(I4, LOW);
}
 
void left(void){
    digitalWrite(I1, HIGH);
    digitalWrite(I2, LOW);
    digitalWrite(I3, LOW);
    digitalWrite(I4, HIGH);
}
 
void stoped(void){
    digitalWrite(I1, LOW);
    digitalWrite(I2, LOW);
    digitalWrite(I3, LOW);
    digitalWrite(I4, LOW);
}
