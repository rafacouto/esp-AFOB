/* Clock.h
 *
 * @author Rafa Couto <caligari@treboada.net>
 * @license GNU General Public License v3.0
 * @see https://github.com/rafacouto/esp-AFOB
 */

#ifndef _CLOCK_H
#define _CLOCK_H

#include <stdint.h>

class Clock
{
    public:

        typedef void (*TickCallback)(void* watcher, uint32_t unix_time);

        Clock(void* watcher, TickCallback callback);

        uint32_t getBootSeconds() { return _bootSeconds; }

        void setUnixTime(uint32_t unix_time) { _unixTime = unix_time; }
        uint32_t getUnixTime() { return _unixTime; }

        void tick(uint32_t millis);

    private:

        uint32_t _unixTime;
        uint32_t _bootSeconds;

        void* _watcher;
        TickCallback _callback;
};

#endif // _CLOCK_H

