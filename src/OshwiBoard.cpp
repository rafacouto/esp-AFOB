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
{
}


void OshwiBoard::init()
{
    // ESP-12E built-in LED is low-activated
    pinMode(PIN_LED, OUTPUT_OPEN_DRAIN);
}


void OshwiBoard::_clockTick(void* watcher, uint32_t unix_time)
{
    OshwiBoard* self = (OshwiBoard*) watcher;

    if (self->_wifi.isConnected())
        digitalWrite(PIN_LED, unix_time % 2 == 0? LOW : HIGH);
}
