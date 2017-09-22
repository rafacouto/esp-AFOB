/** OshwiBoard.h
 *
 * @author Rafa Couto <caligari@treboada.net>
 * @license GNU General Public License v3.0
 * @see https://github.com/rafacouto/esp-AFOB
 */

#ifndef _OSHWI_H
#define _OSHWI_H

#define PIN_LED 2

#include "Clock.h"
#include "Wifi.h"

class OshwiBoard
{
    public:

        OshwiBoard();

        void init();

    private:

        Clock _clock;
        static void _clockTick(void* watcher, uint32_t unix_time);

        Wifi _wifi;
};

#endif // _OSHWI_H

