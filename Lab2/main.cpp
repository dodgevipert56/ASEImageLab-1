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
*/

int main() 
{
    /*
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> colour(0,255);
    */

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

    // Total Number of Frames
    const int framesNumber = 100;

    // WARINING: this works just with square picture (height == width)
    if (height != width)
        return EXIT_FAILURE;

    // Dividing frames for Animate left-to-right line and right-to-left line
    const int framesNumberForAnimateWidth = framesNumber / 2;
    const int framesNumberForAnimateHight = framesNumber - framesNumberForAnimateWidth;

    // Parameters for left-to-right-line
    const int widthPercentagePerFrameLeft = round(width/framesNumberForAnimateWidth);
    int startWidthLeft = 0;
    int incrementWidthLeft = widthPercentagePerFrameLeft;

    // Parameters for right-to-left-line
    const int heightPercentagePerFrameRight = round(width/framesNumberForAnimateHight);
    int startHeightRight = 0;
    int incrementHeightRight = heightPercentagePerFrameRight;

    for (size_t frame=0; frame < framesNumber; frame++)
    {
        // Block for animating left-to-right line
        if (frame < framesNumberForAnimateWidth)
        {
            for (size_t x=startWidthLeft; x<incrementWidthLeft; x++)
            {
                //setPixel(x,y,rand()%255, rand()%255, rand()%255);
                //setPixel(x,y, colour(gen), colour(gen), colour(gen));
                setPixel(x,x,255,0,0);
            }

            startWidthLeft += widthPercentagePerFrameLeft;

            if (frame != framesNumberForAnimateWidth - 1)
            {
                incrementWidthLeft += widthPercentagePerFrameLeft;
            } else
            {
                incrementWidthLeft = width;
            }
        } else {

            // Block for animating right-to-left line
            for (size_t x=startHeightRight; x<incrementHeightRight; x++)
            {
                setPixel(width-x,x,255,0,0);
            }

            startHeightRight += heightPercentagePerFrameRight;
            if (frame != framesNumber - 2)
            {
                incrementHeightRight += heightPercentagePerFrameRight;
            } else
            {
                incrementHeightRight = height;
            }
        }



        sprintf(fileName, "image.%03d.bmp", frame);
        Magick::Image output(width, height, "RGB", Magick::CharPixel,image.get());
        output.depth(10);
        std::cout<<"Writing file "<<fileName<<"\n";
        output.write(fileName);

    }

    return EXIT_SUCCESS;
}
