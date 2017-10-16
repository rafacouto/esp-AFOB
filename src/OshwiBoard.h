/** OshwiBoard.h
 *
 * @author Rafa Couto <caligari@treboada.net>
 * @license GNU General Public License v3.0
 * @see https://github.com/rafacouto/esp-AFOB
 */

#ifndef _OSHWI_H
#define _OSHWI_H

#define PIN_LED 2
#define PIN_PIXELS 4

#include "Clock.h"
#include "Wifi.h"
#include "PixelClock.h"

class OshwiBoard
{
    public:

        OshwiBoard();

        void init();

        void tick();

    private:

        Clock _clock;
        static void _clockTick(void* watcher, uint32_t unix_time);

        Wifi _wifi;

        PixelClock _pixels;
};

#endif // _OSHWI_H

