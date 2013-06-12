// Toy Car Race controlling by leapmotion
// Maxwell Dayvson da Silva, Felipe Silva, Patrik Matos, Bernardo Schorr


const int front = 6;
const int back = 7;
const int right = 9;
const int left = 11;

const char goFrontValue = 'F';
const char goBackValue = 'B';
const char goLeftValue = 'L';
const char goRightValue = 'R';
const char stopCarValue = 'S';

void stopCar()
{
  digitalWrite(left, LOW);
  digitalWrite(front, LOW);  
  digitalWrite(right, LOW);
  digitalWrite(back, LOW);
}

void goBack()
{
  stopCar();
  digitalWrite(back, HIGH);
}

void goFront()
{
  stopCar();
  digitalWrite(front, HIGH);
}

void goLeftFront()
{
  stopCar();
  digitalWrite(left, HIGH);
  digitalWrite(front, HIGH);
}

void goRightFront()
{
  stopCar();
  digitalWrite(right, HIGH);
  digitalWrite(front, HIGH);
}



void setup() {
  Serial.begin(9600);
  pinMode(front,OUTPUT);
  pinMode(back,OUTPUT);
  pinMode(right,OUTPUT);
  pinMode(left,OUTPUT);
  stopCar();
}

void loop() {
  // send data only when you receive data
  if (Serial.available() > 0) {
      char _direction = Serial.read();
      if(_direction == goFrontValue){
        goFront();
        Serial.println("GO FRONT");
      }else if(_direction == goBackValue){
        goBack();
        Serial.println("GO BACK");
      }else if(_direction == goLeftValue){
        goLeftFront();
        Serial.println("GO LEFT");
      }else if(_direction == goRightValue){
        goRightFront();
        Serial.println("GO RIGHT");
      }else if(_direction == stopCarValue){
        stopCar();
      }
  }
}
