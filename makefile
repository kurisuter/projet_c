CC=gcc
EXEC=main
SRCS=source/main.c source/arbre.c
OBJS=$(SRCS:.c=.o) 
CFLAGS= -g -Wall -Iinclude 


$(EXEC): $(OBJS)
	$(CC) $(OBJS) -o $(EXEC)
%: %.o
	$(CC) %.o -o %

clean: 
	rm -rf $(OBJS)

mrproper: clean
	rm -vf $(EXEC)

