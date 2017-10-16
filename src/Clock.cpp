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
    _bootSeconds = 0;
    _unixTime = 0;
    _watcher = watcher;
    _callback = callback;
}


void Clock::tick(uint32_t millis)
{
    uint32_t seconds = millis / 1000;
    if (seconds != _bootSeconds)
    {
        if (_unixTime > 0) _unixTime++;
        _bootSeconds = seconds;
        _callback(_watcher, _unixTime);
    }
}


