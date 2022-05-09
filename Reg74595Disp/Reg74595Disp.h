//--------------------------------------------------------
// Reg74595Disp.h - Header File
// Library for Displaying Numbers on 74595 4-digit Display 
// by: Anas Kuzechie (May 09, 2022)
//--------------------------------------------------------
//header guards
#ifndef Reg74595Disp_h
#define Reg74595Disp_h
//--------------------------------------------------------
//class definition
class Reg74595Disp
{
    public:
        //constructor
        Reg74595Disp(int DIO, int RCLK, int SCLK);
        //methods
        void Clear();
        void Num(byte digit, byte n);
        void Numdp(byte digit, byte n);
        void Char(byte digit, char c);
        void Text(String s);
        void send_byte(byte dataByte);
    private:
        int _DIO;
        int _RCLK;
        int _SCLK;
};
//--------------------------------------------------------
#endif