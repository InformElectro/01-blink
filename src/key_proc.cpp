/*
 * 	key_proc.cpp
 * 		key process
 */

#include <Arduino.h>

#include "key_proc.h"

static const int long_delay = 500;
static const int short_delay = 50;
static int key;

void
init_key( int push_key )
{
    pinMode(key = push_key, INPUT_PULLUP);
}

void
test_key(void)
{
    static int last_delay;
    int delay_now;

    if( ( delay_now = digitalRead(key) ? long_delay : short_delay ) != last_delay )
        Serial.printf( "%s: delay = %4d\n", __FUNCTION__, last_delay = delay_now );
    delay( delay_now );
}
