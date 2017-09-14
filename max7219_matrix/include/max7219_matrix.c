/*
 * File:   max7219_matrix.c
 * Author: Rusty
 *
 * Created on September 14, 2017, 9:37 PM
 */
#include "xc.h"
#include "max7219_matrix.h"

#define HIGH    1
#define LOW     0

#define CLK     LATBbits.LATB7  // CLK
#define DATA    LATBbits.LATB8  // DATA   
#define CS      LATBbits.LATB9  // CS

void initMAX7219( void )
{
    CS = LOW;
    
    writeMAX7219_byte( 0x09 );
    writeMAX7219_byte( 0x00 );
    pulseCS();
    
    writeMAX7219_byte( 0x0A );
    writeMAX7219_byte( 0x03 );
    pulseCS();

    writeMAX7219_byte( 0x0B );
    writeMAX7219_byte( 0x07 );
    pulseCS();

    writeMAX7219_byte( 0x0C );
    writeMAX7219_byte( 0x01 );
    pulseCS();

    writeMAX7219_byte( 0x0F );
    writeMAX7219_byte( 0x00 );
    pulseCS();
}

void writeMAX7219( char address, char data )
{
    writeMAX7219_byte( address );
    writeMAX7219_byte( data );
    pulseCS();
}

void writeMAX7219_byte( unsigned char val )
{
    int j;
    unsigned char temp;
    for ( j = 0; j < 8;  j++ )  // Shift out MSB first
    {
        temp = val & 0x80;      // MSB out first
        if ( temp == 0x80 )
            DATA = HIGH;
        else
            DATA = LOW;
        
        CLK = HIGH;
        delay_us(20);
        CLK = LOW;
        
        val = val << 1;
    }
}

void pulseCS( void )
{
    CS = HIGH;
    delay_ms( 1 );
    CS = LOW;
}
