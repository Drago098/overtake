
float value=0;
float rev=0;
int rpm;
int oldtime=0;
int time;

void isr() //interrupt service routine
{
rev++;
}

void setup()
{
  Serial.begin(9600);
attachInterrupt(0,isr,RISING);  //attaching the interrupt

}

void loop()
{
delay(1000);
detachInterrupt(0);           //detaches the interrupt
time=millis()-oldtime;        //finds the time 
rpm=(rev/time)*60000;//calculates rpm
//int rpm1 = (time*12)/3;
oldtime=millis();             //saves the current time
rev=0;
attachInterrupt(0,isr,RISING);
Serial.println("rpm");
Serial.println(rpm);
//Serial.print(rpm1);

}
