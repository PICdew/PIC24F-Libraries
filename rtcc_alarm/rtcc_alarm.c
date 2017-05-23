#include "xc.h"
#include "rtcc_alarm.h"

void alarmInit()
{
    ALCFGRPTbits.AMASK = 1;     //alarm every second
                                // 1 - second
                                // 2 - 30 seconds
                                // 3 - minute
    
    //two lines below allow for indefinite alarm
    ALCFGRPTbits.CHIME = 1;
    ALCFGRPTbits.ARPT = 0xFF; 
    
    ALCFGRPTbits.ALRMPTR = 2; //set pointer
    
    IEC3bits.RTCIE = 1; //enable rtcc interrupt
    IFS3bits.RTCIF = 0; //clear rtcc interrupt flag
    
    RCFGCALbits.RTCEN = 1; //enable rtcc
    ALCFGRPTbits.ALRMEN = 1; //enable alrm
    
}

#if 0
void __attribute__((interrupt,auto_psv)) _RTCCInterrupt(void)
{
    rtcc_flag=1; //set flag
    IFS3bits.RTCIF = 0; //clear flag
    
}
#endif

void disableAlarm(){
    ALCFGRPTbits.ALRMEN = 0; //disable alarm
}

void enableAlarm(){
    ALCFGRPTbits.ALRMEN = 1; //enable alarm
}
