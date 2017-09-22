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
    // ESP-12E built-in LED is low-activated
    pinMode(PIN_LED, OUTPUT_OPEN_DRAIN);
    digitalWrite(PIN_LED, HIGH);

    _pixels.setBrightness(1);
}


void OshwiBoard::_clockTick(void* watcher, uint32_t unix_time)
{
    OshwiBoard* self = (OshwiBoard*) watcher;

    bool even = (unix_time % 2 == 0);

    if (self->_wifi.isConnected())
        digitalWrite(PIN_LED, even ? LOW : HIGH);

    if (even)
    {
        static PixelArray::CRGB red = { 200, 0, 0 };
        static PixelArray::CRGB green = { 0, 200, 0 };
        static PixelArray::CRGB blue = { 0, 0, 200 };
        self->_pixels.setPixel(0, red);
        self->_pixels.setPixel(1, green);
        self->_pixels.setPixel(2, blue);
        self->_pixels.show();
    }
    else
    {
        self->_pixels.clear();
    }
}
