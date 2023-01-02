CXX = g++
CXXFLAGS = -std=c++17 -Wall -I h -I /usr/local/include/gtest/ -c
LXXFLAGS = -std=c++17 -I h -pthread
_OBJ = main_unittest.o def_unittest.o core.o compiler.o buffer.o parser.o table.o
OBJECTS = $(patsubst %,$(ODIR)/%,$(_OBJ))
GTEST = /usr/local/lib/libgtest.a
TARGET = main

# C lang specific vars
IDIR=.
CC=gcc
CFLAGS=-I$(IDIR)

ODIR=obj
LDIR =.

LIBS=-lm -lpthread

_DEPS = core.h structs.h enums.h
DEPS = $(patsubst %,$(IDIR)/%,$(_DEPS))

#_OBJ = core.o compiler.o buffer.o parser.o table.o
OBJ = $(patsubst %,$(ODIR)/%,$(_OBJ))
# ---

$(TARGET): $(OBJECTS)
	$(CXX) $(LXXFLAGS) -o $(TARGET) $(OBJECTS) $(GTEST) $(LIBS)

$(ODIR)/%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

./obj/def_unittest.o: ./gtest/def_unittest.cpp
	$(CXX) $(CXXFLAGS) ./gtest/def_unittest.cpp -o ./obj/def_unittest.o

./obj/main_unittest.o: ./gtest/main_unittest.cpp
	$(CXX) $(CXXFLAGS) ./gtest/main_unittest.cpp -o ./obj/main_unittest.o

clean:
	rm -fv $(TARGET) $(OBJECTS)