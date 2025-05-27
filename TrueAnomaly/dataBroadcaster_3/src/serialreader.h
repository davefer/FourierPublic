/**
 * @file serialreader.h
 * @brief This is the main header file for the SerialReader class.
 * 
 * @author David Ferreira
 * @date 2025-05-27
 */

#pragma once

class SerialReader
{
public:
    static int ReadUart(const char* serialDev, DataPacket& data);
    static void _cfgSerial(char* serialDev);
};