#include <iostream>
#include "Emitter.h"

int main()
{
    std::cout << "Particle Main\n";
    Emitter e(Vec3(0,0,0), 100);

    for (size_t i = 0; i < 10; i++)
    {
        e.render();
        e.update();
    }
}
