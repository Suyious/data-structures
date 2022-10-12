CC = gcc
NAME = heap
FILES = main.c heap.c

compile:
	$(CC) -o $(NAME) $(FILES)

run: compile
	./$(NAME)

debug:
	$(CC) -o $(NAME) -g $(FILES)

clean:
	rm ${NAME}
