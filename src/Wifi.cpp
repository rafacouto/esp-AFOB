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

    WiFi.setAutoConnect(false);
    WiFi.setAutoReconnect(true);
    WiFi.mode(WIFI_OFF);
    WiFi.disconnect(true);
}


bool Wifi::isConnected()
{
    return WiFi.isConnected();
}


void Wifi::connect()
{
    WiFi.mode(WIFI_STA);
    WiFi.begin(_ssid, _password);
}


void Wifi::disconnect()
{
    WiFi.disconnect(true);
}


