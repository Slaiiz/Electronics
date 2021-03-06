# Rainbow Clock Project Pinout

      ______________________________________________________________________________________
     |      Module      |   Pins    |        Pin designator(s)       |        Notes         |
     |__________________|___________|________________________________|______________________|
     | 1x Temperature   |         2 | SCL1, SDA1                     | Uses I2C.            |
     |__________________|___________|________________________________|______________________|
     | 1x Bluetooth     |         2 | RPB6*, RPA0*                   | Uses UART.           |
     |__________________|___________|________________________________|______________________|
     | 1x Led strip     |         1 | RC4                            | Single pin, 60 leds. |
     |__________________|___________|________________________________|______________________|
     | 1x LCD Screen    |        10 | RB10..RB15, RC0, RC1, RB2, RB3 | xxxxxxxxxxxxxxxxxxxx |
     |__________________|___________|________________________________| xxxxxxxxxxxxxxxxxxxx |
     | 1x Light sensor  |         1 | AN1                            | xxxxxxxxxxxxxxxxxxxx |
     |__________________|___________|________________________________| xxxxxxxxxxxxxxxxxxxx |
     | 1x ICD           |         3 | PGEC1, PGED1, MCLR             | xxxxxxxxxxxxxxxxxxxx |
     |__________________|___________|________________________________|______________________|
     | 1x LCD Backlight |         1 | RPC7*                          | Uses Output compare. |
     |__________________|___________|________________________________|______________________|
     | 3x Button        |     3 + 1 | INT0, RPC2*, RPC3*, RPC8*      | Uses NMI.            |
     |__________________|___________|________________________________|______________________|
     | 1x 8MHz Osc.     |         2 | OSC1, OSC2                     | xxxxxxxxxxxxxxxxxxxx |
     |__________________|___________|________________________________|______________________|
     | 1x 32kHz Osc.    |         2 | SOSCI, SOSCO                   | For the RTC.         |
     |__________________|___________|________________________________|______________________|
     | xxxxxxxxxxxxxxxx |         1 | RPC5*                          | Neopixel debug pin.  |
     |__________________|___________|________________________________|______________________|
     |        Total: 12 | Total: 29 |
     |__________________|___________|

     * pin is remappable for a function (Output compare, UART, SPI, NMI, etc...)
