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
}


void OshwiBoard::tick()
{
    uint32_t ms = millis();
    _clock.tick(ms);
}


void OshwiBoard::_clockTick(void* watcher, uint32_t unix_time)
{
    OshwiBoard* self = (OshwiBoard*) watcher;
    self->_pixels.update(self->_clock.getBootSeconds());
}


