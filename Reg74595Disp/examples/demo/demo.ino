//---------------------------------
// Count from 00 99
// using Reg74595Disp Library
// by: Anas Kuzechie (May 09, 2022)
//---------------------------------
#include <Reg74595Disp.h>
//---------------------------------------
#define DIO     2
#define RCLK    3
#define SCLK    4
//---------------------------------------
Reg74595Disp disp(DIO, RCLK, SCLK);
//----------------------------------------------------
void setup()
{
  disp.Clear(); delay(1000);
}
//----------------------------------------------------
void loop()
{
  for(int i=1; i<2000; i++) disp.Text("PLAY");
  disp.Clear(); delay(1000);
  //---------------------------------------------
  for(int i=1; i<2000; i++)
  {
    disp.Char (1, 'd');
    disp.Char (2, '=');
    disp.Numdp(3, 3);
    disp.Num  (4, 9);
  }    
  disp.Clear(); delay(1000);
  //------------------------------
  for(byte MSD=0; MSD<=9; MSD++)
  {
    for(byte LSD=0; LSD<=9; LSD++)
    {
      for(int i=1; i<=250; i++)
      {
        disp.Char(1, 'C');
        disp.Char(2, '=');
        disp.Num (3, MSD);
        disp.Num (4, LSD);
      }
    }
  }
  disp.Clear(); delay(1000);
}