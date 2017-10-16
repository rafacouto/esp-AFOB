
#include "PixelClock.h"


static PixelArray::CRGB red = { 255, 0, 0 };
static PixelArray::CRGB green = { 0, 255, 0 };
static PixelArray::CRGB blue = { 0, 0, 255 };
static PixelArray::CRGB white = { 255, 255, 255 };
static PixelArray::CRGB black = { 0, 0, 0 };


void PixelClock::update(uint32_t seconds)
{
    bool even = (seconds % 2 == 0);

    uint8_t sec = seconds % 60;
    seconds /= 60;
    uint8_t min = seconds % 60;
    seconds /= 60;
    uint8_t hour = seconds % 24;

    setAll(black);

    if (even)
    {
        // minute sector
        uint8_t index = min / 15;
        setPixel(index++, red);
        setPixel(index, red);
    }
    else
    {
        // hour sector
        uint8_t index = hour / 8;
        setPixel(index++, green);
        setPixel(index++, green);
        setPixel(index, green);
    }

    show();
}


