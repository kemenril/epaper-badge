#ifndef EPDIF_H
#define EPDIF_H

#include <Arduino.h>

// Pin definition
#define DC_PIN          D4
#define CS_PIN          SS

class EpdIf {
public:
    EpdIf(void);
    ~EpdIf(void);

    static int  IfInit(void);
    static void DigitalWrite(int pin, int value); 
    static int  DigitalRead(int pin);
    static void DelayMs(unsigned int delaytime);
    static void SpiTransfer(unsigned char data);
};

#endif
