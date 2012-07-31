CC=g++
CFLAGS=-Wall
SRCDIR=src/
LDFLAGS=
INCLUDES=include/
OBJDIR=src/
TESTDIR=tests/
OUTPUT=regexvm
TESTBIN=regexvmtest
SOURCES=\
   backtrackingvm.cpp

TEST_SRC=\
   backtrackingvmtest.cpp

OBJECTS=$(SOURCES:.cpp=.o)

COMPILE_SOURCES=$(addprefix $(SRCDIR), $(SOURCES))
COMPILE_OBJECTS=$(addprefix $(OBJDIR), $(OBJECTS))
COMPILE_TESTSRC=$(addprefix $(TESTDIR), $(TEST_SRC))
LIBOUT=$(addsuffix $(OUTPUT), lib)
OUTPUT_FILE=$(addprefix $(LIBOUT), .a)

vpath %.cpp src
vpath %.hpp include

default: $(COMPILE_OBJECTS) lib

lib:
	ar rcs $(OUTPUT_FILE) $(COMPILE_OBJECTS)

tests: lib exe

exe:
	$(CC) -I$(INCLUDES) -L./ $(CFLAGS)  $(COMPILE_TESTSRC) -o $(TESTBIN) -l$(OUTPUT)

%.o: %.cpp
	$(CC) -c -I$(INCLUDES) $(CFLAGS) $< -o $@

clean:
	rm -f $(SRCDIR)*.o $(OBJDIR)*.o $(TESTDIR)*.o	
