CC=g++
SRC=src/*.cpp
LIBS=-L/usr/lib -L/lib/ikpMP3.dll -lGL -lGLEW -lglfw -lassimp -lLinearMath -lBulletDynamics -lBulletCollision  bin/linux-gcc-64/libIrrKlang.so -pthread
INCLUDE=-I/usr/include/bullet -Iinclude -Ibin
EXEC=bin/prog

all: 
	${CC} ${SRC} -o ${EXEC} ${INCLUDE} ${LIBS}


clear:
	rm bin/prog
