print 'install the package python-serial via apt-get before!'

import serial
import sys
ser = serial.Serial()
ser.port = sys.argv[1]
ser.baudrate = 1200
ser.open()
ser.setDTR(0)
ser.close()
