#include <iostream>
#include <cstdlib>
#include <Magick++.h>
#include <memory>

const size_t width = 100;
const size_t height = 100;
const size_t pixelDepth = 3;

void setPixel(size_t _x, size_t _y,
              unsigned char _r, unsigned char _g, unsigned char _b,
              std::unique_ptr<unsigned char []> &_image)
{
    auto offset = (_y * width) * 3 + (_x * 3);
    _image[offset] = _r;
    _image[offset + 1] = _g;
    _image[offset + 2] = _b;
}

void clearScreen (unsigned char _r, unsigned char _g, unsigned char _b,
                  std::unique_ptr<unsigned char []> &_image)
{

    for (size_t i = 0; i < width*height*pixelDepth; i=i+3)
    {
        _image[i] = _r;
        _image[i+1] = _g;
        _image[i+2] = _b;
    }
}

int main() 
{
    std::unique_ptr<unsigned char []> image = std::make_unique<unsigned char []>(width * height * pixelDepth);

    clearScreen(0,0,255,image);

    for (size_t x = 0; x < width; ++x)
    {
        setPixel(x,x,255,0,0,image);
        setPixel(width-x,x,255,0,0,image);
    }

    Magick::Image output(width, height, "RGB", Magick::CharPixel,image.get());

    output.write("test.bmp");
    
    return EXIT_SUCCESS;
}
