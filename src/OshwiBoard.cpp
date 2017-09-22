/** OshwiBoard.cpp
 *
 * @author Rafa Couto <caligari@treboada.net>
 * @license GNU General Public License v3.0
 * @see https://github.com/rafacouto/esp-AFOB
 */

#include "OshwiBoard.h"
#include <Arduino.h>

OshwiBoard::OshwiBoard()
    : _clock(this, _clockTick)
    , _wifi(WIFI_SSID, WIFI_PASS)
    , _pixels(PIN_PIXELS)
{
}


void OshwiBoard::init()
{
    _pixels.setBrightness(1);
}

        static PixelArray::CRGB red = { 255, 0, 0 };
        static PixelArray::CRGB green = { 0, 255, 0 };
        static PixelArray::CRGB blue = { 0, 0, 255 };
        static PixelArray::CRGB white = { 255, 255, 255 };
        static PixelArray::CRGB black = { 0, 0, 0 };

void OshwiBoard::_clockTick(void* watcher, uint32_t unix_time)
{
    OshwiBoard* self = (OshwiBoard*) watcher;

    bool even = (unix_time % 2 == 0);

    if (even)
    {
        self->_pixels.setPixel(0, red);
        self->_pixels.setPixel(1, green);
        self->_pixels.setPixel(2, blue);
        self->_pixels.setPixel(3, white);
        self->_pixels.setPixel(4, black);
    }
    else
    {
        self->_pixels.setAll(black);
        self->_pixels.setPixel(4, white);
    }
    self->_pixels.show();
}
