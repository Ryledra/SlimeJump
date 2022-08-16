#
# Structure from: https://hiltmon.com/blog/2013/07/03/a-simple-c-plus-plus-project-structure/
#
# TODO: Create window with OpenGL
#
 
CC := g++ -std=c++17 # This is the main compiler (g++ using c++17 standard)
# CC := clang --analyze # and comment out the linker last line for sanity
SRCDIR := src
BUILDDIR := build
TARGETDIR := bin
TARGET := ${TARGETDIR}/SlimeJump
SHADERSDIR := ${TARGETDIR}/shaders/
 
SRCEXT := cpp
SOURCES := $(shell find $(SRCDIR) -type f -name *.$(SRCEXT))
OBJECTS := $(patsubst $(SRCDIR)/%,$(BUILDDIR)/%,$(SOURCES:.$(SRCEXT)=.o)) $(BUILDDIR)/glad/glad.o
CFLAGS := -g # -Wall
LIB := -lglfw -framework OpenGL # -pthread -lmongoclient -L lib -lboost_thread-mt -lboost_filesystem-mt -lboost_system-mt
INC := -I include -I src

$(TARGET): $(OBJECTS)
	@echo " Moving shaders..."
	@mkdir -p ${SHADERSDIR}
	@cp shaders/* ${SHADERSDIR} 
	@echo " Linking..."
	@echo " $(CC) $^ -o $(TARGET) $(LIB)"; $(CC) $^ -o $(TARGET) $(LIB)

$(BUILDDIR)/%.o: $(SRCDIR)/%.c
	@mkdir -p ${BUILDDIR}
	@mkdir -p ${BUILDDIR}/glad
	@echo " gcc $(CFLAGS) $(INC) -c -o $@ $<"; gcc $(CFLAGS) $(INC) -c -o $@ $<

$(BUILDDIR)/%.o: $(SRCDIR)/%.$(SRCEXT)
	@mkdir -p ${BUILDDIR} 
	@mkdir -p ${BUILDDIR}/common ${BUILDDIR}/engine ${BUILDDIR}/entities
	@echo " $(CC) $(CFLAGS) $(INC) -c -o $@ $<"; $(CC) $(CFLAGS) $(INC) -c -o $@ $<

clean:
	@echo " Cleaning..."; 
	@echo " $(RM) -r $(BUILDDIR) $(TARGETDIR)"; $(RM) -r $(BUILDDIR) $(TARGETDIR)

# Tests
tester:
	$(CC) $(CFLAGS) test/tester.cpp $(INC) $(LIB) -o bin/tester

# Spikes
ticket:
	$(CC) $(CFLAGS) spikes/ticket.cpp $(INC) $(LIB) -o bin/ticket

.PHONY: clean
