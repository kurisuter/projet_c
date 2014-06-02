CC=gcc
EXEC=main
SRCS=source/main.c source/mtf.c source/rle.c  source/arbre.c  source/huffman.c source/package-merge.c  source/list_int.c  source/gestion_fichier.c  source/tab_longueur.c
OBJS=$(SRCS:.c=.o) 
CFLAGS= -g -Wall -Iinclude 


$(EXEC): $(OBJS)
	$(CC) $(OBJS) -o $(EXEC) -lm
%: %.o
	$(CC) %.o -o %

clean: 
	rm -rf $(OBJS)

mrproper: clean
	rm -vf $(EXEC)

