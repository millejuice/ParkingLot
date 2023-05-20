CC : gcc
	
start : main.c menu.o parking.o
	$(CC) -o $@ $^
clear : 
	rm *o start
