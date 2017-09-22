/** PixelArray.cpp
 *
 * @author Rafa Couto <caligari@treboada.net>
 * @license GNU General Public License v3.0
 * @see https://github.com/rafacouto/esp-AFOB
 */

#include "PixelArray.h"

#define colorSaturation 64

RgbColor red(colorSaturation, 0, 0);
RgbColor green(0, colorSaturation, 0);
RgbColor blue(0, 0, colorSaturation);
RgbColor white(colorSaturation);


PixelArray::PixelArray(uint8_t pin)
    : _strip(PIXEL_COUNT, pin)
{
    _strip.Begin();
}


void PixelArray::show()
{
    for (int p = 0; p < PIXEL_COUNT; p++)
    {
        RgbColor color(_pixels[p].r, _pixels[p].g, _pixels[p].b);
        _strip.SetPixelColor(p, color);
    }

    _strip.Show();
}


void PixelArray::clear()
{
    static CRGB black = { 0, 0, 0 };
    setAll(black);
    show();
}


void PixelArray::setAll(CRGB color)
{
    for (int p = 0; p < PIXEL_COUNT; p++)
        _pixels[p] = color;
}


