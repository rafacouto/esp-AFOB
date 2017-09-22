/* Wifi.h
 *
 * @author Rafa Couto <caligari@treboada.net>
 * @license GNU General Public License v3.0
 * @see https://github.com/rafacouto/esp-AFOB
 */

#ifndef _WIFI_H
#define _WIFI_H

class Wifi {

    public:

        Wifi(const char* ssid, const char* password);

        void connect();
        void disconnect();
        bool isConnected();

    private:

        const char* _ssid;
        const char* _password;
};

#endif // _WIFI_H
