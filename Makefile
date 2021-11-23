all:
	gcc main.c prepare.c conv.c -o cd2 -Wall -Wpedantic 

clean:
	rm cd2

