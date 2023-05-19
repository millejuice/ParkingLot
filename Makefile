CC : gcc
	
start : main.c menu.o
	$(CC) -o $@ $^
clear : 
	rm *o start
