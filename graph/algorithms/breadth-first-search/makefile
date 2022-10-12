CC = gcc
NAME = bfs
FILES = bfs.c ../../graph.c ../../../queue/queue.c

compile:
	$(CC) -o $(NAME) $(FILES)

run: compile
	./$(NAME)

debug:
	$(CC) -o $(NAME) -g $(FILES)

clean:
	rm ${NAME}

