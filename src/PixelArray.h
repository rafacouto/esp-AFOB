/** PixelArray.h
 *
 * @author Rafa Couto <caligari@treboada.net>
 * @license GNU General Public License v3.0
 * @see https://github.com/rafacouto/esp-AFOB
 */

#ifndef _PIXEL_ARRAY
#define _PIXEL_ARRAY

#define PIXEL_COUNT 5

#include <NeoPixelBrightnessBus.h>

class PixelArray
{
    public:

        typedef struct {
            uint8_t r;
            uint8_t g;
            uint8_t b;
        } CRGB;

        PixelArray(uint8_t pin);

        CRGB getPixel(uint8_t pixel) { return _pixels[pixel]; }
        void setPixel(uint8_t pixel, CRGB color) { _pixels[pixel] = color; }
        void setAll(CRGB color);

        void show();
        void clear();

        void setBrightness(uint8_t brightness) { _strip.SetBrightness(brightness); }

    private:

        CRGB _pixels[PIXEL_COUNT];

        NeoPixelBrightnessBus<NeoGrbFeature, NeoEsp8266BitBang800KbpsMethod> _strip;
};

#endif // _PIXEL_ARRAY
