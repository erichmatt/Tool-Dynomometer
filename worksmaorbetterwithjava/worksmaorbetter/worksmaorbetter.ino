void setup()
{
  // put your setup code here, to run once:
  pinMode(2, INPUT);
  pinMode(LED_BUILTIN, OUTPUT);
  Serial.begin(9600);

}

void loop()
{
  digitalWrite(LED_BUILTIN, HIGH);
  // put your main code here, to run repeatedly:
  char encoderstate, laststate;
  unsigned int list[3800];
  unsigned int interval[2];
  unsigned long t1, t2;
  int i = 0;
  t1 = micros();
  laststate = digitalRead(2);
  while (i <= 7600)
  {
    encoderstate = digitalRead(2);
    if (encoderstate != laststate)
    {
      if (encoderstate == HIGH)
      {
        t2 = micros();
        interval[i % 2] = t2 - t1;
        t1 = t2;
        if (i % 2 == 0)
        {
          list[i / 2] = interval[0] + interval[1];
        }
        ++i;
      }
    }
    laststate = encoderstate;
  }
  for (int i = 0; i <= 3800; ++i)
  {
    Serial.print(list[i], DEC);
      Serial.print("\n");

  }
  while (1)
  {
    digitalWrite(LED_BUILTIN, HIGH);
    delay(500);
    digitalWrite(LED_BUILTIN, LOW);
    delay(500);


  }
}
