CC=g++
CFLAGS=-Wall
SRCDIR=src/
LDFLAGS=
INCLUDES=include/
OBJDIR=src/
SOURCES=\
   backtrackingvm.cpp

OBJECTS=$(SOURCES:.cpp=.o)

COMPILE_SOURCES=$(addprefix $(SRCDIR), $(SOURCES))
COMPILE_OBJECTS=$(addprefix $(OBJDIR), $(OBJECTS))

vpath %.cpp src
vpath %.hpp include

default: $(COMPILE_OBJECTS) lib

lib:
	ar rcs libregexvm.a $(COMPILE_OBJECTS)

%.o: %.cpp
	$(CC) -c -I$(INCLUDES) $(CFLAGS) $< -o $@

clean:
	rm $(COMPILE_OBJECTS)	
