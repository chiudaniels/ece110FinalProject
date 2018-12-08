#define trigPin1 3
#define echoPin1 2
#define trigPin2 4
#define echoPin2 5
#define trigPin3 7
#define echoPin3 8
#define trigPin4 9
#define echoPin4 10
#define reedPin 12
#define ledPin 13
#define buttonPin 6
#define speakerPin 11


long duration, distance, sensor1,sensor2,sensor3,sensor4;
int alarmStatus, starter;
unsigned long previousTime = 0; 
int previousUltra[4]; 
int currentUltra[4];
int ledState = LOW;
int buttonState = 0;

void setup()
{
Serial.begin (9600);
pinMode(trigPin1, OUTPUT);
pinMode(echoPin1, INPUT);
pinMode(trigPin2, OUTPUT);
pinMode(echoPin2, INPUT);
pinMode(trigPin3, OUTPUT);
pinMode(echoPin3, INPUT);
pinMode(trigPin4, OUTPUT);
pinMode(echoPin4, INPUT);
pinMode(ledPin, OUTPUT);
pinMode(reedPin, INPUT_PULLUP);
pinMode(buttonPin, INPUT);
alarmStatus = 1;
starter = 0;

}
 
void loop() {
  
buttonState = digitalRead(buttonPin);

if (buttonState == HIGH) {
  Serial.println("button pressed");
  Serial.println("current status");
  Serial.print(alarmStatus);
  if(alarmStatus == 4){
    alarmStatus=0;    
  }
  else{
    alarmStatus++;
  }
  Serial.println("new current status");
  Serial.print(alarmStatus);
  delay(1000);
}

unsigned long currentTime = millis();
if (alarmStatus == 0){
  noTone(speakerPin);
  int proximity = digitalRead(reedPin); // Read the state of the switch
  if (proximity == HIGH) // If the pin reads low, the switch is closed.
  {
    alarmStatus = 3;
  }
  
  if (currentTime - previousTime >= 1000){
    previousTime = currentTime;
    if (starter == 0){
      SonarSensor(trigPin1, echoPin1);
      sensor1 = distance;
      SonarSensor(trigPin2, echoPin2);
      sensor2 = distance;
      SonarSensor(trigPin3, echoPin3);
      sensor3 = distance;
      SonarSensor(trigPin4, echoPin4);
      sensor4 = distance;
      previousUltra[0]=sensor1;
      previousUltra[1]=sensor2;
      previousUltra[2]=sensor3;
      previousUltra[3]=sensor4;
      currentUltra[0]=sensor1;
      currentUltra[1]=sensor2;
      currentUltra[2]=sensor3;
      currentUltra[3]=sensor4;
      Serial.println("starter = 0");
       Serial.println("current");
      Serial.print(currentUltra[0]);
      Serial.print(" - ");
      Serial.print(currentUltra[1]);
      Serial.print(" - ");
      Serial.print(currentUltra[2]);
      Serial.print(" - ");
      Serial.println(currentUltra[3]);
      Serial.println("previous");
      Serial.print(previousUltra[0]);
      Serial.print(" - ");
      Serial.print(previousUltra[1]);
      Serial.print(" - ");
      Serial.print(previousUltra[2]);
      Serial.print(" - ");
      Serial.println(previousUltra[3]);
      starter = 1;
    }
    if (starter == 1){
      Serial.println("starter = 1");
      SonarSensor(trigPin1, echoPin1);
      sensor1 = distance;
      SonarSensor(trigPin2, echoPin2);
      sensor2 = distance;
      SonarSensor(trigPin3, echoPin3);
      sensor3 = distance;
      SonarSensor(trigPin4, echoPin4);
      sensor4 = distance;
      currentUltra[0]=sensor1;
      currentUltra[1]=sensor2;
      currentUltra[2]=sensor3;
      currentUltra[3]=sensor4;
      if(checkPrev(0)|| checkPrev(1) || checkPrev(2)|| checkPrev(3)){ 
        alarmStatus = 3;
      }
      previousUltra[0]=sensor1;
      previousUltra[1]=sensor2;
      previousUltra[2]=sensor3;
      previousUltra[3]=sensor4;
      Serial.println("current");
      Serial.print(currentUltra[0]);
      Serial.print(" - ");
      Serial.print(currentUltra[1]);
      Serial.print(" - ");
      Serial.print(currentUltra[2]);
      Serial.print(" - ");
      Serial.println(currentUltra[3]);
      Serial.println("previous");
      Serial.print(previousUltra[0]);
      Serial.print(" - ");
      Serial.print(previousUltra[1]);
      Serial.print(" - ");
      Serial.print(previousUltra[2]);
      Serial.print(" - ");
      Serial.println(previousUltra[3]);
    }
  }
}

if (alarmStatus == 1){
  noTone(speakerPin);
  if (currentTime - previousTime >= 1000){
    previousTime = currentTime;
    if (starter == 0){
      SonarSensor(trigPin1, echoPin1);
      sensor1 = distance;
      SonarSensor(trigPin2, echoPin2);
      sensor2 = distance;
      SonarSensor(trigPin3, echoPin3);
      sensor3 = distance;
      SonarSensor(trigPin4, echoPin4);
      sensor4 = distance;
      previousUltra[0]=sensor1;
      previousUltra[1]=sensor2;
      previousUltra[2]=sensor3;
      previousUltra[3]=sensor4;
      currentUltra[0]=sensor1;
      currentUltra[1]=sensor2;
      currentUltra[2]=sensor3;
      currentUltra[3]=sensor4;
      Serial.println("starter = 0");
       Serial.println("current");
      Serial.print(currentUltra[0]);
      Serial.print(" - ");
      Serial.print(currentUltra[1]);
      Serial.print(" - ");
      Serial.print(currentUltra[2]);
      Serial.print(" - ");
      Serial.println(currentUltra[3]);
      Serial.println("previous");
      Serial.print(previousUltra[0]);
      Serial.print(" - ");
      Serial.print(previousUltra[1]);
      Serial.print(" - ");
      Serial.print(previousUltra[2]);
      Serial.print(" - ");
      Serial.println(previousUltra[3]);
      starter = 1;
    }
    if (starter == 1){
      Serial.println("starter = 1");
      SonarSensor(trigPin1, echoPin1);
      sensor1 = distance;
      SonarSensor(trigPin2, echoPin2);
      sensor2 = distance;
      SonarSensor(trigPin3, echoPin3);
      sensor3 = distance;
      SonarSensor(trigPin4, echoPin4);
      sensor4 = distance;
      currentUltra[0]=sensor1;
      currentUltra[1]=sensor2;
      currentUltra[2]=sensor3;
      currentUltra[3]=sensor4;
      if(checkPrev(0)|| checkPrev(1) || checkPrev(2)|| checkPrev(3)){ 
        alarmStatus = 3;
      }
      previousUltra[0]=sensor1;
      previousUltra[1]=sensor2;
      previousUltra[2]=sensor3;
      previousUltra[3]=sensor4;
      Serial.println("current");
      Serial.print(currentUltra[0]);
      Serial.print(" - ");
      Serial.print(currentUltra[1]);
      Serial.print(" - ");
      Serial.print(currentUltra[2]);
      Serial.print(" - ");
      Serial.println(currentUltra[3]);
      Serial.println("previous");
      Serial.print(previousUltra[0]);
      Serial.print(" - ");
      Serial.print(previousUltra[1]);
      Serial.print(" - ");
      Serial.print(previousUltra[2]);
      Serial.print(" - ");
      Serial.println(previousUltra[3]);
    }
  }
}

if (alarmStatus==2){
  noTone(speakerPin);
  int proximity = digitalRead(reedPin); // Read the state of the switch
  if (proximity == HIGH) // If the pin reads low, the switch is closed.
  {
    alarmStatus = 3;
  }
}

if (alarmStatus == 3){
  if (currentTime - previousTime >= 1000){
    Serial.println("OwO");
    previousTime = currentTime;
     if (ledState == LOW)
      ledState = HIGH;
    else
      ledState = LOW;
    digitalWrite(ledPin, ledState);
    tone(speakerPin,1000);
  }
}

if (alarmStatus == 4){
  noTone(speakerPin);
}

}

bool checkPrev(int ind){
  return abs(currentUltra[ind] - previousUltra[ind]) > 10;
}
 
void SonarSensor(int trigPin,int echoPin)
{
digitalWrite(trigPin, LOW);
delayMicroseconds(2);
digitalWrite(trigPin, HIGH);
delayMicroseconds(10);
digitalWrite(trigPin, LOW);
duration = pulseIn(echoPin, HIGH);
distance = (duration/2) / 29.1;
 
}
