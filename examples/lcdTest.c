/*
 * File:   lcdTest.c
 * Author: Rusty
 *
 * Created on May 5, 2017, 11:13 PM
 */


#include "xc.h"
#include "../lcd/lcd_4bit.h"

#pragma config FWDTEN=OFF, JTAGEN=OFF
#pragma config POSCMOD=NONE, OSCIOFNC=ON, FCKSM=CSDCMD, FNOSC=FRCPLL 
#pragma config PLL96MHZ=OFF, PLLDIV=NODIV
#pragma config SOSCSEL=IO
#pragma config I2C1SEL=PRI 

int main(void) {
    TRISB = 0;
    TRISA = 0;
    AD1PCFG = 0xFDFF;
    LATB = 0xffff;
    
    noBlink();
    noCursor();
    lcdPrint("LCD Test");
    setCursor(0xC0);
    lcdPrint("Number Test: ");
    delay(5000);
    lcdIntPrint(115);
    delay(2000);
    clearDisplay();
    lcdPrint("Loading");
    setCursor(0xC0);

    int count;
    count = 0;
    while (count < 16){
        lcdWrite(0xFFFF);
        delay(1000);
        count++;
    }
    
    clearDisplay();
    lcdPrint("Loading Complete");
    delay(2500);
    clearDisplay();
    
    lcdPrint("  Hello World");
    setCursor(0xC0);
    lcdPrint("  I <3 CoE115");
    while(1){
    }
    
    return 0;
}
