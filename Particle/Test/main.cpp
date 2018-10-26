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

TEST(Vec3, defaultCtor)
{
    Vec3 a;
    EXPECT_FLOAT_EQ(a.x, 0.0f);
    EXPECT_FLOAT_EQ(a.y, 0.0f);
    EXPECT_FLOAT_EQ(a.z, 0.0f);
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
