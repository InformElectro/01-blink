#include <Arduino.h>

static const int long_delay = 500;
static const int short_delay = 50;

void
setup(void) 
{
    pinMode(LED, OUTPUT);
    pinMode(PUSH, INPUT_PULLUP);
    digitalWrite(LED,LOW);
    Serial.begin(BAUD);
}

void
loop(void) 
{
    static int last_delay;
    int delay_now;

    digitalWrite(LED,!digitalRead(LED));
    if( ( delay_now = digitalRead(PUSH) ? long_delay : short_delay ) != last_delay )
        Serial.printf( "%s: delay = %4d mseg.\n", __FUNCTION__, last_delay = delay_now );
    delay( delay_now );
}
