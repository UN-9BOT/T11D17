GC=gcc -g -Wall -Werror -Wextra
BUI=../build

all: clean door_struct list_test

door_struct: clean
	$(GC) dmanager_module.c -o $(BUI)/Quest_1

list_test: clean
	$(GC) list.c list_test.c -o $(BUI)/Quest_2

clean:
	rm -rf compil*
	rm -rf $(BUI)/*
