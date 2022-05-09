//-------------------------------------------
// Showing Characters on Multiple Displays
// using Reg74595Disp Library
// by: Anas Kuzechie (May 09, 2022)
//-------------------------------------------
#include <Reg74595Disp.h>
//------------------------------------------
Reg74595Disp disp1(2, 3, 4), disp2(5, 6, 7);
//------------------------------------------
void setup()
{
  disp1.Clear(); disp2.Clear();
  delay(1000);
}
//----------------------------------------------------
void loop()
{
  for(byte MSD=0; MSD<=9; MSD++)
  {
    for(byte LSD=0; LSD<=9; LSD++)
    {
      for(int i=1; i<=100; i++)
      {
        disp1.Text("PLAY");
        disp2.Char(1, 'C');
        disp2.Char(2, '=');
        disp2.Num (3, MSD);
        disp2.Num (4, LSD);
      }
    }
  }
  disp1.Clear(); disp2.Clear();
  delay(1000);
}