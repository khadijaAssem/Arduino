#define LDR A0 // pin where we connected the LDR and the resistor
#define LASER 3
#define GREENLED 4
#define REDLED 5


void setup() {
  pinMode(LASER,OUTPUT);
  pinMode(GREENLED,OUTPUT);
  pinMode(REDLED,OUTPUT);
  pinMode(LDR,INPUT);
  digitalWrite(LASER,LOW);
  digitalWrite(GREENLED,LOW);
  digitalWrite(REDLED,LOW);
  Serial.begin(9600); // sets serial port for communication
}

void loop() {
//  if (Serial.available() > 0) {
//      output(Serial.readString());  
//  } 
//  di gitalWrite(3,LOW);
//  //Serial.println("LED IS LOW");
//  delay(100);                    // wait a little
    digitalWrite(4,HIGH);
    Serial.println(analogRead(LDR));
    delay(5000);
    digitalWrite(4,LOW);
    Serial.println(analogRead(LDR));
    delay(1000);
}

void output(String str){
  for(int i=0;i< str.length();i++){
    Serial.println(str[i]);
    if(str[i] == '1'){
      digitalWrite(LASER,HIGH);
      delay(1000);
      Serial.println("LASER IS ON");
      if (SSMachine(1)==readSensor(1)){
        digitalWrite(GREENLED,HIGH);
      }
      else {
        digitalWrite(GREENLED,LOW);
        digitalWrite(REDLED,HIGH);
        return;
      }
    }
    else if(str[i] == '0') {
      digitalWrite(LASER,LOW);
      delay(1000);
      Serial.println("LASER IS OFF");
       if (SSMachine(0)==readSensor(0)){
        digitalWrite(GREENLED,HIGH);
      }
      else {
        digitalWrite(GREENLED,LOW);
        digitalWrite(REDLED,HIGH);
        return;
      }
    }
  }
}
int SSMachine(int s){
  return 0;
}
int readSensor(int s){
  int LDRValue = 0;     // result of reading the analog pin
  LDRValue = analogRead(LDR); // read the value from the LDR
  Serial.println(LDRValue);  // print the value to the serial port
  if(LDRValue<=900&&LDRValue>=800)
    return 1;
  else 
    return 0;
}
