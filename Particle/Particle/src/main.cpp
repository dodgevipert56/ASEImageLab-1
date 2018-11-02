#include <iostream>
#include "Particle.h"

int main()
{
    std::cout << "Particle Main\n";
    Particle p;

    p.setDirection({0.0f, 1.0f, 0.0f});

    p.setMaxLife(10);
    p.setLife(0);

    // If age >= maxLife ( ==10 for default ) -> move it back to (0,0,0)
    // If age < maxLife                    -> move it up according to direction
    while(true)
    {
        p.render();

        if (p.getLife() < p.getMaxLife())
        {
            p.update();
            int lifeUpdate = p.getLife() + 1;
            p.setLife(lifeUpdate);
        } else
        {
            p.setPosition({0.0f, 0.0f, 0.0f});
            p.setLife(0);
        }

    }
}
