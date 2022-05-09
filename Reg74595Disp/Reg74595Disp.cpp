//---------------------------------
// Reg74595Disp.cpp - Source File
// by: Anas Kuzechie (May 09, 2022)
//---------------------------------
#include <Arduino.h>
#include <Reg74595Disp.h>
//------------------------------------------------------------
// Constructor
//------------------------------------------------------------
Reg74595Disp::Reg74595Disp(int DIO, int RCLK, int SCLK)
{
    pinMode(DIO, OUTPUT); _DIO = DIO;
    pinMode(RCLK, OUTPUT); _RCLK = RCLK;
    pinMode(SCLK, OUTPUT); _SCLK = SCLK;
}
//------------------------------------------------------------
// Function Prototypes
//------------------------------------------------------------
void send_byte(byte);
byte convertNum(byte);
byte convertNumdp(byte);
byte convertChar(char);
//------------------------------------------------------------
// Methods
//------------------------------------------------------------
void Reg74595Disp::Clear()
{
    for(byte i=0; i<=3; i++)
    {
        send_byte(0xFF);
        send_byte(0x01 << i);
        digitalWrite(_RCLK, LOW); digitalWrite(_RCLK, HIGH);
    }
}
//------------------------------------------------------------
void Reg74595Disp::Num(byte digit, byte n)
{
    byte digit1;
    switch(digit)
    {
        case 1: digit1 = 8; break;
        case 2: digit1 = 4; break;
        case 3: digit1 = 2; break;
        case 4: digit1 = 1;
    }
    //------------------------------------------
    byte m = convertNum(n);
    send_byte(m);
    send_byte(digit1);
    digitalWrite(_RCLK, LOW); digitalWrite(_RCLK, HIGH);
}
//------------------------------------------------------------
void Reg74595Disp::Numdp(byte digit, byte n)
{
    byte digit1;
    switch(digit)
    {
        case 1: digit1 = 8; break;
        case 2: digit1 = 4; break;
        case 3: digit1 = 2; break;
        case 4: digit1 = 1;
    }
    //------------------------------------------
    byte m = convertNumdp(n);
    send_byte(m);
    send_byte(digit1);
    digitalWrite(_RCLK, LOW); digitalWrite(_RCLK, HIGH);
}
//------------------------------------------------------------
void Reg74595Disp::Char(byte digit, char c)
{
    byte digit1;
    switch(digit)
    {
        case 1: digit1 = 8; break;
        case 2: digit1 = 4; break;
        case 3: digit1 = 2; break;
        case 4: digit1 = 1;
    }
    //------------------------------------------
    byte m = convertChar(c);
    send_byte(m);
    send_byte(digit1);
    digitalWrite(_RCLK, LOW); digitalWrite(_RCLK, HIGH);
}
//------------------------------------------------------------
void Reg74595Disp::Text(String s)
{
    char c[5]; byte d = 8;
    s.toCharArray(c, 5);
    //------------------------------------------
    for(byte i=0; i<s.length(); i++)
    {
        byte m = convertChar(c[i]);
        send_byte(m);
        send_byte(d >> i);
        digitalWrite(_RCLK, LOW); digitalWrite(_RCLK, HIGH);
    }   
}
//------------------------------------------------------------
void Reg74595Disp::send_byte(byte dataByte)
{
    for(int i=1; i<=8; i++)
    {
        if(dataByte & 0x80) digitalWrite(_DIO, HIGH);
        else digitalWrite(_DIO, LOW);
        dataByte = dataByte << 1;
        digitalWrite(_SCLK, LOW); digitalWrite(_SCLK, HIGH);
    }
}
//------------------------------------------------------------
// Functions
//------------------------------------------------------------
byte convertNum(byte n)
{
    byte m;
    switch(n)
    {
        case 0: m = 0xC0; break;
        case 1: m = 0xF9; break;
        case 2: m = 0xA4; break;
        case 3: m = 0xB0; break;
        case 4: m = 0x99; break;
        case 5: m = 0x92; break;
        case 6: m = 0x82; break;
        case 7: m = 0xF8; break;
        case 8: m = 0x80; break;
        case 9: m = 0x90;
    }
    return m;
}
//------------------------------------------------------------
byte convertNumdp(byte n)
{
    byte m;
    switch(n)
    {
        case 0: m = 0x40; break;
        case 1: m = 0x79; break;
        case 2: m = 0x24; break;
        case 3: m = 0x30; break;
        case 4: m = 0x19; break;
        case 5: m = 0x12; break;
        case 6: m = 0x02; break;
        case 7: m = 0x78; break;
        case 8: m = 0x00; break;
        case 9: m = 0x10;
    }
    return m;
}
//------------------------------------------------------------
byte convertChar(char c)
{
    byte m;
    switch(c)
    {
        case 'A': m = 0x88; break;
        case 'B': m = 0x83; break;
        case 'C': m = 0xC6; break;
        case 'c': m = 0xA7; break;
        case 'd': m = 0xA1; break;
        case 'E': m = 0x86; break;
        case 'F': m = 0x8E; break;
        case 'g': m = 0x90; break;
        case 'H': m = 0x89; break;
        case 'h': m = 0x8B; break;
        case 'I': m = 0xCF; break;
        case 'i': m = 0xEF; break;
        case 'J': m = 0xE1; break;
        case 'L': m = 0xC7; break;
        case 'n': m = 0xAB; break;
        case 'O': m = 0xC0; break;
        case 'o': m = 0xA3; break;
        case 'P': m = 0x8C; break;
        case 'r': m = 0xAF; break;
        case 'S': m = 0x92; break;
        case 't': m = 0x87; break;
        case 'U': m = 0xC1; break;
        case 'u': m = 0xE3; break;
        case 'Y': m = 0x91; break;
        //------------------------
        case '=': m = 0xB7;
    }
    return m;
}