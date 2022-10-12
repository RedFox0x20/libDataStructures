.PHONY: all

# CC FLAGS
CC:=gcc
CC_FLAGS:=-c -std=c99 -Wall -Wextra -Wpedantic -D_DEFAULT_SOURCE
CC_LIBS:=-lm

SOURCE_FILES:=$(wildcard src/*.c)
HEADER_FILES:=$(wildcard src/*.h)
OBJ_FILES:=$(addsuffix .o, $(patsubst src/%,build/%,$(SOURCE_FILES)))

# App data
APP_NAME:=libDataStructures
IDIR:=~/lib

# Make commands
all: dirs includes app

run: all
	@[[ -f "lib/$(APP_NAME)" ]] && lib/$(APP_NAME)

dirs:
	@mkdir -p bin lib include build $(IDIR) $(IDIR)/include/$(APP_NAME)

clean:
	@echo "Deleting directories: ./lib ./bin ./build"
	@rm -rf lib bin include build 2>/dev/null

install: all
	@echo "Installing to $(IDIR)"
	@echo "Installing headers to $(IDIR)/$(APP_NAME)"
	@cp lib/$(APP_NAME).a $(IDIR)/$(APP_NAME).a
	@cp src/*.h $(IDIR)/include/$(APP_NAME)/

uninstall:
	@echo "Deleting installation: $(IDIR)/$(APP_NAME).a"
	@echo "Deleting headers: $(IDIR)/$(APP_NAME)/*.h"
	@rm $(IDIR)/$(APP_NAME).a
	@rm -rf $(IDIR)/$(APP_NAME)

# Builders
#
includes: $(HEADER_FILES)
	@echo "Copying header files to ./include"
	@cp src/*.h include/

app: $(OBJ_FILES)
	@echo "Building bin/$(APP_NAME).a"
	@ar rcs lib/$(APP_NAME).a $(OBJ_FILES) 

build/%.c.o: src/%.c
	@echo "Building $@"
	@$(CC) $(CC_FLAGS) $< -o $@ $(CC_LIBS)
	
build/%.c.o: src/%.c src/%.h
	@echo "Building $@"
	@$(CC) $(CC_FLAGS) $< -o $@ $(CC_LIBS)

