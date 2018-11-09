TARGET=ParticleTests
SOURCES += main.cpp \
           ../Particle/src/Particle.cpp \
           ../Particle/src/Emitter.cpp
CONFIG+=c++11

INCLUDEPATH += /usr/local/include/

LIBS += -L/usr/local/lib -lgtest

INCLUDEPATH += ../Particle/include
cache()
CONFIG-=app_bundle
