void setup() 
{
  // put your setup code here, to run once:
  pinMode(2, INPUT);
  Serial.begin(9600);
}

void loop() 
{
  // put your main code here, to run repeatedly:
  unsigned int list[800];
  for (int i =0; i <= 800; i++)
  {
    list[i] = i;
  }
  for (int i =0; i <= 800; i++)
  {
    Serial.print(list[i],DEC);
    Serial.print("\n");
  }
  while (1)
  {
    
  }
}
