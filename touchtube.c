
#include <mega328p.h>

#include <delay.h>

#define TUBE  PIND.4
#define START PIND.3
#define END   PIND.2

#define GLED PORTB.4
#define RLED PORTC.0
#define LEDS PORTB.4=PORTC.0

void main(void){ 

unsigned char play;

DDRD.4 = DDRD.3 = DDRD.2 = 0;    //входы
PORTD.4 = PORTD.3 = PORTD.2 = 1; //подт€жка

DDRB.4 = DDRC.0 = 1;  //¬ыходы на светодиоды

  GLED=1;
  RLED=0;
  delay_ms(100);
  GLED=0;
  RLED=1;
  delay_ms(100);
  RLED=0;
  
  
  play=1;
  
  while (1){
  
  if( !START ) {
  BEGIN:
  play=1;
  GLED=1;       
  RLED=0;
  }
  
  if ( !END ) {

    while(1) {
    if (!START) goto BEGIN;
    LEDS=1;
    delay_ms(150);
    LEDS=0;
    if (!START) goto BEGIN;
    delay_ms(50);
    LEDS=1;
    if (!START) goto BEGIN;
    delay_ms(150);
    LEDS=0;
    if (!START) goto BEGIN;
    delay_ms(50);
    LEDS=1;
    if (!START) goto BEGIN;
    delay_ms(150);
    LEDS=0;
    if (!START) goto BEGIN;
    delay_ms(200); 
    
    if (!START) goto BEGIN;
    
    GLED=1;
    delay_ms(100);
    GLED=0;
    if (!START) goto BEGIN;
    delay_ms(100);
    GLED=1;
    if (!START) goto BEGIN;
    delay_ms(100);
    GLED=0;
    if (!START) goto BEGIN;
    delay_ms(200);
    
    RLED=1;
    if (!START) goto BEGIN;
    delay_ms(100);
    RLED=0;
    if (!START) goto BEGIN;
    delay_ms(100);
    RLED=1;
    if (!START) goto BEGIN;
    delay_ms(100);
    RLED=0;
    if (!START) goto BEGIN;
    delay_ms(200);
    }
  }
  
  if ( !TUBE ){      //если коснулись трубы, то
    GLED=0;          //гасим зеленый и
    RLED=1;          //светитс€ красный
    while ( START ); //пока не коснулись старта  
    goto BEGIN;
  }
 } 
}