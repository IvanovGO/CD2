all:
	gcc main.c prepare.c conv.c dlist.c -o cd2 -Wall -Wpedantic 

clean:
	rm cd2

