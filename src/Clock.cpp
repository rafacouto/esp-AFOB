/** Clock.cpp
 *
 * @author Rafa Couto <caligari@treboada.net>
 * @license GNU General Public License v3.0
 * @see https://github.com/rafacouto/esp-AFOB
 */

#include "Clock.h"

#include <Arduino.h>


Clock::Clock(void* watcher, TickCallback callback)
{
    _watcher = watcher;
    _callback = callback;
    _unixTime = 0;

    attach_ms(1000, _clock_second_tick, this);
}


void Clock::_second_tick()
{
    _unixTime++;

    _callback(_watcher, _unixTime);
}


