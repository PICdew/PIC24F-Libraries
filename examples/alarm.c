/*
 * File:   alarm.c
 * Author: John
 *
 * Created on May 14, 2017, 12:08 PM
 */

#pragma config FWDTEN=OFF, JTAGEN=OFF
#pragma config POSCMOD=NONE, OSCIOFNC=ON, FCKSM=CSDCMD, FNOSC=FRCPLL 
#pragma config PLL96MHZ=OFF, PLLDIV=NODIV
#pragma config SOSCSEL=IO
#pragma config I2C1SEL=PRI 
#pragma config RTCOSC = LPRC //trial

#include "xc.h"
#include "../lcd/lcd_4bit.h"
#include "../local_rtcc/local_rtcc.h"
#include "../rtcc_alarm/rtcc_alarm.h"

int rtcc_flag=0;

void __attribute__((interrupt,auto_psv)) _RTCCInterrupt(void) {
    lcdPrint("Interrupt!");
    rtcc_flag=1; //set flag
    IFS3bits.RTCIF = 0; //clear flag
    
}

int main(void) {
    int time = 0;
    
    TRISB = 0;
    AD1PCFG=0xFDFF;
    lcdInit();
    rtccInit();
    
    
    alrm_rtcc_t test, test2;
    
    test.alrm_rtcc_mon = 1;
    test.alrm_rtcc_mday = 18;
    test.alrm_rtcc_wday = 13;
    test.alrm_rtcc_hour = 2;
    test.alrm_rtcc_min = 35;
    test.alrm_rtcc_min = 6;
    test.alrm_rtcc_sec = 17;
    
    alarmInit();
    
    while(1) {
        if(rtcc_flag) {
            time = time+1;
            
            setCursor(0xC0);
            lcdIntPrint(time);
            setCursor(0xA0);
            rtcc_flag=0;
        }   
    }  
}
