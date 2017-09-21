/* Clock.h
 *
 * @author Rafa Couto <caligari@treboada.net>
 * @license GNU General Public License v3.0
 * @see https://github.com/rafacouto/esp-AFOB
 */

#ifndef _CLOCK_H
#define _CLOCK_H

#include <Ticker.h>

class Clock : Ticker
{
    public:

        typedef void (*TickCallback)(void* watcher, uint32_t unix_time);

        Clock(void* watcher, TickCallback callback);

        void setUnixTime(uint32_t unix_time) { _unixTime = unix_time; }
        uint32_t getUnixTime() { return _unixTime; }

    private:

        void* _watcher;
        TickCallback _callback;

        uint32_t _unixTime;

        static void _clock_second_tick(Clock* c) { c->_second_tick(); }
        void _second_tick();
};

#endif // _CLOCK_H

