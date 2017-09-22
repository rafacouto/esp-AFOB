/* Wifi.h
 *
 * @author Rafa Couto <caligari@treboada.net>
 * @license GNU General Public License v3.0
 * @see https://github.com/rafacouto/esp-AFOB
 */

#include "Wifi.h"

#include <ESP8266WiFi.h>


Wifi::Wifi(const char* ssid, const char* password)
{
    _ssid = ssid;
    _password = password;

    WiFi.mode(WIFI_STA);
    WiFi.setAutoConnect(false);
    WiFi.setAutoReconnect(true);
}


bool Wifi::isConnected()
{
    return WiFi.isConnected();
}


void Wifi::connect()
{
    WiFi.begin(_ssid, _password);
}


void Wifi::disconnect()
{
    WiFi.disconnect(true);
}


