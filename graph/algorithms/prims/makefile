CC = gcc
NAME = prims
FILES = prims.c ../../graph.c

compile:
	$(CC) -o $(NAME) $(FILES)

run: compile
	./$(NAME)

debug:
	$(CC) -o $(NAME) -g $(FILES)

clean:
	rm ${NAME}

