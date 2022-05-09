//-------------------------------------
// DHT22 Sensor, Temperature & Humidity
// using Reg74595Disp Library
// by: Anas Kuzechie (May 05, 2022)
//-------------------------------------
#include <Reg74595Disp.h>
#include <DHT.h>
//---------------------------------
#define DIO     2
#define RCLK    3
#define SCLK    4
//---------------------------------
Reg74595Disp disp(DIO, RCLK, SCLK);
DHT dht(5, DHT22);
//-------------------------------------------------------
float temp; int humidity;
int temp_LSD, temp_MSD, temp_fraction, hum_LSD, hum_MSD;
unsigned long millisCapture = millis(), myDelay = 15000;
//-------------------------------------------------------
void setup()
{
  dht.begin();
  //-----------------------------------------
  disp.Clear(); delay(1000);
  //-----------------------------------------
  for(int i=1; i<5000; i++) disp.Text("dht");
  //-----------------------------------------
  disp.Clear(); delay(1000);
}
//-------------------------------------------------------
void loop()
{
  disp_temp();
  //------------------------------------
  if(millis() - millisCapture > myDelay)
  {
    disp.Clear(); delay(1000);
    disp_hum();
    disp.Clear(); delay(1000);
  }
}
//-------------------------------------------------------
void disp_temp()
{
  temp = dht.readTemperature();
  temp_MSD = int(temp)/10;
  temp_LSD = int(temp)%10;
  temp_fraction = (temp - int(temp))*10;
  //------------------------------------
  disp.Num  (1, temp_MSD);
  disp.Numdp(2, temp_LSD);
  disp.Num  (3, temp_fraction);
  disp.Char (4, 'C');
}
//-------------------------------------------------------
void disp_hum()
{
  humidity = dht.readHumidity();
  hum_MSD = humidity/10;
  hum_LSD = humidity%10;
  //----------------------------
  for(int i=1; i<5000; i++)
  {
    disp.Char(1, 'H');
    disp.Num(2, hum_MSD);
    disp.Num(3, hum_LSD);
    disp.Char(4, 'P');
  }
  //----------------------------
  millisCapture = millis();
}