#pragma once


class SerialReader
{
public:
    static int ReadUart(const char* serialDev);
    static void _cfgSerial(char* serialDev);
};