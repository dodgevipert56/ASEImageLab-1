#include <iostream>
#include <cstdlib>
#include <Magick++.h>
#include <memory>
#include<random>

const size_t width = 100;
const size_t height = 100;
const size_t pixelDepth = 3;

/*
void setPixel(size_t _x, size_t _y,
              unsigned char _r, unsigned char _g, unsigned char _b,
              std::unique_ptr<unsigned char []> &_image)
{
    auto offset = (_y * width) * 3 + (_x * 3);
    _image[offset] = _r;
    _image[offset + 1] = _g;
    _image[offset + 2] = _b;
}
*/

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
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> colour(0,255);

    std::unique_ptr<unsigned char []> image = std::make_unique<unsigned char []>(width * height * pixelDepth);

    // Same as function setPixel, but in lambda realisation
    auto setPixel=[&image](size_t _x, size_t _y,
            unsigned char _r, unsigned char _g, unsigned char _b)
    {
        auto offset = (_y * width) * 3 + (_x * 3);
        image[offset] = _r;
        image[offset + 1] = _g;
        image[offset + 2] = _b;
    };

    /*
    clearScreen(0,0,255,image);

    for (size_t x = 0; x < width; ++x)
    {
        setPixel(x,x,255,0,0);
        setPixel(width-x,x,255,0,0);
    }
    */

    //srand(time(nullptr));

    char fileName[20];

    for (size_t frame=0; frame<100; frame++){

        for (size_t y=0; y<height; y++)
            for (size_t x=0; x<width; x++) {
                //setPixel(x,y,rand()%255, rand()%255, rand()%255);
                setPixel(x,y, colour(gen), colour(gen), colour(gen));
            }

        sprintf(fileName, "image.%03d.bmp", frame);
        Magick::Image output(width, height, "RGB", Magick::CharPixel,image.get());
        output.depth(10);
        std::cout<<"Writing file "<<fileName<<"\n";
        output.write(fileName);
    }

    return EXIT_SUCCESS;
}
