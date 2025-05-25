#pragma once 

#include <array>
#include <cstddef>
#include <stdint.h>

using namespace std;

class DataPacket
{
public:
    byte frameByte1;
    byte frameByte2;
    byte frameByte3;
    byte frameByte4;

    uint32_t packetCount;
    float x_GyroRate;
    float y_GyroRate;
    float z_GyroRate;

    uint8_t toByteArray(array<byte, 20>& byte_array);
    uint8_t fromByteArray(array<byte, 20>& byte_array);
};