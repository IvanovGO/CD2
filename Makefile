all:
	gcc main.c dlist.c save.c pair.c prepare.c conv.c   -o cd2 -Wall -Wpedantic 

win:
	winegcc main.c prepare.c conv.c dlist.c pair.c -o cd2 -Wall -Wpedantic 

clean:
	rm cd2 cd2.*

