CC=g++
# compiler options
CFLAGS=-c -Wall -Wextra -g

# linker options
LDFLAGS=

# list of source files
SOURCES=hello.cc
# name of executable
EXECUTABLE=hello_make

OBJECTS=$(SOURCES:.cc=.o)

all: $(SOURCES) $(EXECUTABLE)

# link target (link all object files)
$(EXECUTABLE): $(OBJECTS)
				$(CC) $(LDFLAGS) $(OBJECTS) -o $@


# compile target (compile *.cc files to *.o object files)
.cc.o:
				$(CC) $(CFLAGS) $< -o $@
clean:
				$(RM) hello{.o,_make}
