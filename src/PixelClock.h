/** PixelClock.h
 *
 * @author Rafa Couto <caligari@treboada.net>
 * @license GNU General Public License v3.0
 * @see https://github.com/rafacouto/esp-AFOB
 */

#ifndef _PIXEL_CLOCK_H
#define _PIXEL_CLOCK_H

#include "PixelArray.h"
#include <stdint.h>

class PixelClock : PixelArray
{
    public:

        PixelClock(int pin) : PixelArray(pin)
        {
            setBrightness(1);
        }

        void update(uint32_t seconds);
};

#endif // _PIXEL_CLOCK_H

