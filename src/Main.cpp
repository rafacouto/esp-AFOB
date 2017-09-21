/** Main.cpp
 *
 * @author Rafa Couto <caligari@treboada.net>
 * @license GNU General Public License v3.0
 * @see https://github.com/rafacouto/esp-AFOB
 */

#include <Arduino.h>
#include "OshwiBoard.h"

OshwiBoard oshwi_2017;

void setup() {
    oshwi_2017.init();
}

void loop() {
    delay(50);
}

