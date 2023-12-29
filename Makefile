INCLUDE_DIRS = -Iinclude/clog/

.PHONY: all

all:
	gcc $(INCLUDE_DIRS) main.c $(LINKS) -o ./main
