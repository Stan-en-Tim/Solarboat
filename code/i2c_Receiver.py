import smbus, time

bus = smbus.SMBus(1)

while True:
    data = bus.read_i2c_block_data(0x08, 0x00, 16)
    output = ""
    for byte in data:
        if not byte == 255:
            output += chr(byte)
    print(output)
    time.sleep(1)
