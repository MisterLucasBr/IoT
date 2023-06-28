// C++ code
//
int setPoint1 = 30; // Acionar ventilador
int setPoint2 = 50; // LED Vermelho + Buzina
int celsius = 0;
int temp = 0;

int relayPin = 2; // (Representado por led verde)
int redLedPin = 3;
int buzzerPin = 4;

void setup()
{
  pinMode(A0, INPUT);
  Serial.begin(9600);

  pinMode(relayPin, OUTPUT); // Rele Ventilador (Representado por led verde)
  pinMode(redLedPin, OUTPUT); // LED Vermelho Alarme
  pinMode(buzzerPin, OUTPUT); // Buzzer Alarme
}

void loop()
{
  
  celsius = map(((analogRead(A0) - 20) * 3.04), 0, 1023, -40, 125);

  Serial.print(celsius);
  Serial.println(" C");  

  temp = celsius;
  if(temp >= setPoint1)
  {
  digitalWrite(relayPin, HIGH);
  }
  
  if(temp >= setPoint2)
  {
  digitalWrite(redLedPin, HIGH);
  digitalWrite(buzzerPin, HIGH);
  }
  
}