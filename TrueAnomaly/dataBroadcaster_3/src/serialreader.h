#pragma once


class SerialReader
{
public:
    static int ReadUart(const char* serialDev, DataPacket& data);
    static void _cfgSerial(char* serialDev);
};