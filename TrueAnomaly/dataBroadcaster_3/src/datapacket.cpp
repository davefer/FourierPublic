#include "datapacket.h"
#include <string.h>

uint8_t DataPacket::toByteArray(array<byte, 20>& byte_array)
{
    uint8_t count = 0;

    memcpy(byte_array.data(), &this->frameByte1, 1);
    memcpy((byte_array.data() + 1), &this->frameByte2, 1);
    memcpy((byte_array.data() + 2), &this->frameByte3, 1);
    memcpy((byte_array.data() + 3), &this->frameByte4, 1);
    memcpy((byte_array.data() + 4), &this->packetCount, 4);
    memcpy((byte_array.data() + 8), &this->x_GyroRate, 4);
    memcpy((byte_array.data() + 12), &this->y_GyroRate, 4);
    memcpy((byte_array.data() + 16), &this->z_GyroRate, 4);

    return 20;
}

uint8_t DataPacket::fromByteArray(array<byte, 20>& byte_array)
{
    uint8_t count = 0;

    memcpy(&this->frameByte1, byte_array.data(), 1);
    memcpy(&this->frameByte2, (byte_array.data() + 1), 1);
    memcpy(&this->frameByte3, (byte_array.data() + 2), 1);
    memcpy(&this->frameByte4, (byte_array.data() + 3), 1);
    memcpy(&this->packetCount, (byte_array.data() + 4), 4);
    memcpy(&this->x_GyroRate, (byte_array.data() + 8), 4);
    memcpy(&this->y_GyroRate, (byte_array.data() + 12), 4);
    memcpy(&this->z_GyroRate, (byte_array.data() + 16), 4);

    return 20;
}

