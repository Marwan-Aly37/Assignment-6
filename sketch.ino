const int PIN_ENCODER_A=2;
const int PIN_ENCODER_B=3;
long long counter = 0;

void setup()
{
  pinMode(PIN_ENCODER_A, INPUT_PULLUP);
  pinMode(PIN_ENCODER_B, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(PIN_ENCODER_A), ISR_encoderPinA, CHANGE);
  attachInterrupt(digitalPinToInterrupt(PIN_ENCODER_B), ISR_encoderPinB, CHANGE);
  Serial.begin(9600);
}

void ISR_encoderPinA()
{
  if (digitalRead(PIN_ENCODER_A) != digitalRead(PIN_ENCODER_B))
    counter++;
  else
    counter--;
}

void ISR_encoderPinB()
{
  if (digitalRead(PIN_ENCODER_A) == digitalRead(PIN_ENCODER_B))
    counter++;
  else
    counter--;
}

void loop()
{
 Serial.println((long)counter);
}
