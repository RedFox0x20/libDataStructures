.PHONY: all

# CC FLAGS
CC:=gcc
CC_FLAGS:=-std=c99 -Wall -Wextra -Wpedantic -D_DEFAULT_SOURCE
CC_LIBS:=-lm

SOURCE_FILES:=$(wildcard src/*.c)
HEADER_FILES:=$(wildcard src/*.h)
INTERNAL_HEADER_FILES:=$(wildcard src/*.internal.h) 
PUBLIC_HEADER_FILES:=$(filter-out $(INTERNAL_HEADER_FILES), $(HEADER_FILES))
OBJ_FILES:=$(addsuffix .o, $(patsubst src/%,build/%,$(SOURCE_FILES)))

# App data
APP_NAME:=libDataStructures
IDIR:=~/lib

# Make commands
all: dirs includes app

test: all tests/tests.c
	$(CC) $(CC_FLAGS) -Iinclude -Lbin tests/tests.c -o \
	tests/tests -lDataStructures
	exec tests/tests

run: all
	@[[ -f "lib/$(APP_NAME)" ]] && bin/$(APP_NAME)

dirs:
	@mkdir -p bin lib include build $(IDIR) $(IDIR)/include/$(APP_NAME)

clean:
	@echo "Deleting directories: ./lib ./bin ./build"
	@rm -rf lib bin include build 2>/dev/null

install: all
	@echo $(PUBLIC_HEADER_FILES)
	@echo "Installing to $(IDIR)"
	@echo "Installing headers to $(IDIR)/$(APP_NAME)"
	@cp bin/$(APP_NAME).a $(IDIR)/$(APP_NAME).a
	@cp $(PUBLIC_HEADER_FILES) $(IDIR)/include/$(APP_NAME)/

uninstall:
	@echo "Deleting installation: $(IDIR)/$(APP_NAME).a"
	@echo "Deleting headers: $(IDIR)/$(APP_NAME)/*.h"
	@rm $(IDIR)/$(APP_NAME).a
	@rm -rf $(IDIR)/$(APP_NAME)

# Builders
#
includes: $(HEADER_FILES)
	@echo "Copying header files to ./include"
	@cp $(PUBLIC_HEADER_FILES) include/

app: $(OBJ_FILES)
	@echo "Building bin/$(APP_NAME).a"
	@ar rcs bin/$(APP_NAME).a $(OBJ_FILES) 

build/%.c.o: src/%.c
	@echo "Building $@"
	@$(CC) -c $(CC_FLAGS) $< -o $@ $(CC_LIBS)
	
build/%.c.o: src/%.c src/%.h
	@echo "Building $@"
	@$(CC) -c $(CC_FLAGS) $< -o $@ $(CC_LIBS)

