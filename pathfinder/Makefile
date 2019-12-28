AP_NAME = pathfinder

SRCF = \
src/main.c \

OBJ = \
main.o \

LIBMXF = ../libmx/inc

LIB_NAME = libmx.a

INCF =  inc/

CFLAGS = -std=c11 -Wall -Wextra -Werror -Wpedantic

all: install clean

install:
	@make -C $(LIBMXF)
	@clang $(CFLAGS) $(SRCF) -I $(INCF) -I $(LIBMXF)
	# @clang $(CFLAGS) $(OBJ) $(LIBMXF)/$(LIB_NAME) -o $(APP_NAME)
	# @mkdir ./obj
	# @mv $(OBJ) ./obj

uninstall:
	@make uninstall -C $(LIBMXF)
	@rm -rf $(APP_NAME)

clean:
	@make clean -C $(LIBMXF)
	@rm -rf ./obj
	@rm -rf pathfinder.h.gch

reinstall: uninstall all
