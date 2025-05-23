class ImuPacket:
    Data = 0

    def __init__():
        gr_x = 0
        gr_y = 0
        gr_z = 0
        packetCount = 5

        prelimData = b"\x7F,\xF0,x\1C,\xAF,\x00,\x00,\x00,\x01,\x00,\x00,\x00,\x01,\x00,\x00,\x00,\x01,\x00,\x00,\x00,\x01"
        ImuPacket.Data = bytearray(prelimData)
