import smbus, time

bus = smbus.SMBus(1)

while True:
    #read the data from address 8
    data = bus.read_i2c_block_data(0x08, 0x00, 16)
    output = ""
    #convert every byte to a char and add it to the string
    for byte in data:
        #if the byte is empty (has a value of 255), do not add it to the string
        if not byte == 255:
            output += chr(byte)
    #print the data
    print(output)
    #wait a second before sending the next request
    time.sleep(1)
