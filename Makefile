.ONESHELL:
.RECIPEPREFIX = >

SOURCEPATH=src
LIBPATH=lib
SOURCES=$(wildcard $(SOURCEPATH)/*.cpp)
OBJECTS=$(SOURCES:.cpp=.o)
TARGET=ioaware

CXXFLAGS=-std=c++17
CXXFLAGS+=-g0
CXXFLAGS+=-m64
CXXFLAGS+=-march=native
CXXFLAGS+=-mtune=native
CXXFLAGS+=-O2
CXXFLAGS+=-pedantic
CXXFLAGS+=-pedantic-errors
CXXFLAGS+=-pipe
CXXFLAGS+=-s
CXXFLAGS+=-Wall
CXXFLAGS+=-Werror
CXXFLAGS+=-Wextra
CXXFLAGS+=-Wpedantic

LDFLAGS=-L$(LIBPATH)
LDLIBS=-lraylib

all: clean $(TARGET) run

$(TARGET): $(OBJECTS)
> $(LINK.cpp) $^ -o $@ $(LDLIBS)

run:
> ./$(TARGET)

clean:
> rm -f $(TARGET) $(OBJECTS)
