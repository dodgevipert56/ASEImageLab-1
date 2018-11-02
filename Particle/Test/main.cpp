#include <iostream>
#include <gtest/gtest.h>
#include "Particle.h"
#include "Vec3.h"

int main(int argc, char **argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

TEST(Particle, defaultCtor)
{
    Particle p;
    auto pos = p.getPosition();
    EXPECT_FLOAT_EQ(pos.x, 0.0f);
    EXPECT_FLOAT_EQ(pos.y, 0.0f);
    EXPECT_FLOAT_EQ(pos.z, 0.0f);
}

TEST(Vec3, userCtor)
{
    Vec3 a={0.2f, -0.2f, 0.2f};
    EXPECT_FLOAT_EQ(a.x, 0.2f);
    EXPECT_FLOAT_EQ(a.y, -0.2f);
    EXPECT_FLOAT_EQ(a.z, 0.2f);
}

TEST(Vec3, copyCtor)
{
    Vec3 a={0.2f, -0.2f, 0.2f};
    auto b = a;
    EXPECT_FLOAT_EQ(b.x, 0.2f);
    EXPECT_FLOAT_EQ(b.y, -0.2f);
    EXPECT_FLOAT_EQ(b.z, 0.2f);
}

TEST(Particle, update)
{
    Particle p;
    p.setDirection(Vec3(0,1,0));
    for(int i = 0; i<10; i++)
    {
        p.update();
        p.render();
    }
    EXPECT_FLOAT_EQ(p.getPosition().y, 10.0f);
}

TEST(Particle,setLife)
{
    Particle p;
    p.setLife(10);
    auto life=p.getLife();
    EXPECT_EQ(life, 10);

}

TEST(Particle, setPosition)
{
    Particle p;
    p.setPosition({0.5f, -0.2f, 12.303f});
    auto pos = p.getPosition();
    EXPECT_FLOAT_EQ(pos.x, 0.5f);
    EXPECT_FLOAT_EQ(pos.y, -0.2f);
    EXPECT_FLOAT_EQ(pos.z, 12.303f);
}

TEST(Particle, setColor)
{
    Particle p;
    p.setColor({0.2f, 0.2f, 0.2f});
    auto color = p.getColor();
    EXPECT_FLOAT_EQ(color.x, 0.2f);
    EXPECT_FLOAT_EQ(color.y, 0.2f);
    EXPECT_FLOAT_EQ(color.z, 0.2f);
}

TEST(Particle, setDirection)
{
    Particle p;
    p.setDirection({0.0f, 1.0f, 0.0f});
    auto direction = p.getDirection();
    EXPECT_FLOAT_EQ(direction.x, 0.0f);
    EXPECT_FLOAT_EQ(direction.y, 1.0f);
    EXPECT_FLOAT_EQ(direction.z, 0.0f);
}

TEST(Particle, setMaxLife)
{
    Particle p;
    p.setMaxLife(10);
    auto lifetime = p.getMaxLife();
    EXPECT_EQ(lifetime, 10);
}

TEST(Vec3, plusEquals)
{
    Vec3 a = {1.0f, 2.0f, 3.0f};
    Vec3 b = {1.0f, 1.0f, 1.0f};
    a += b;
    EXPECT_FLOAT_EQ(a.x, 2.0f);
    EXPECT_FLOAT_EQ(a.y, 3.0f);
    EXPECT_FLOAT_EQ(a.z, 4.0f);
}
