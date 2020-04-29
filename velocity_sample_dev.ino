#include<Wire.h>
const int MPU_addr=0x68;  
int16_t AcX,AcY,AcZ,Tmp,GyX,GyY,GyZ;
int velocity(int m , int n , int o);
void setup(){
  Wire.begin();
  Wire.beginTransmission(MPU_addr);
  Wire.write(0x6B);  
  Wire.write(0);    
  Wire.endTransmission(true);
  Serial.begin(9600);
}
void loop(){
  Wire.beginTransmission(MPU_addr);
  Wire.write(0x3B);  
  Wire.endTransmission(false);
  Wire.requestFrom(MPU_addr,14,true); 
  AcX=Wire.read()<<8|Wire.read(); 
  int a = AcX/16852;    
  AcY=Wire.read()<<8|Wire.read();
  int b = AcY/16852; 
  AcZ=Wire.read()<<8|Wire.read();
  int c = AcZ/16852;  
  Tmp=Wire.read()<<8|Wire.read();  
  GyX=Wire.read()<<8|Wire.read(); 
  GyY=Wire.read()<<8|Wire.read();  
  GyZ=Wire.read()<<8|Wire.read(); 
  Serial.print("AcX = "); Serial.print(AcX);
  Serial.print(" | AcY = "); Serial.print(AcY);
  Serial.print(" | AcZ = "); Serial.print(AcZ);
  Serial.print(" | Tmp = "); Serial.print(Tmp/340.00+36.53); 
  Serial.print(" | GyX = "); Serial.print(GyX);
  Serial.print(" | GyY = "); Serial.print(GyY);
  Serial.print(" | GyZ = "); Serial.println(GyZ);
  delay(333);
  int x = velocity(a,b,c);
}
int velocity(int m, int n, int o)
{
  int t = 0.001;
  int u = 0; 
  int vx = u + m*t;
  int vy = u + n*t;
  int vz = u + o*t;
  int v = sqrt((vx*vx)+(vy*vy)+(vz*vz));
  return v ; 
}
