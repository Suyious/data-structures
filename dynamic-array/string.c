#include <stdio.h>
#include <stdlib.h>

typedef struct {
	int size;
	int capacity;
	char* contents;
} string;

void string_initialize(string* v){
	v -> size = 0;
	v -> capacity = 0;
	v -> contents = NULL;
}

void string_reallocate(string* v){
	if(v -> capacity == 0){
		v -> contents = malloc(sizeof(char));
		v -> capacity = 1;
	} else {
		v -> contents = realloc(v -> contents, sizeof(char) * ( v -> capacity * 2 ));
		v -> capacity *= 2;
	}
}

void string_push_back(string* v, char data){
	if(++(v -> size) > v -> capacity){
		string_reallocate(v);
	}
	v -> contents[v -> size - 1] = data;
}

void string_pop_back(string* v){
	if(v -> size > 0){
		(v -> size)--;
	}
}

char string_at(string* v, int index){
	return v -> contents[index];
}

void string_set(string* s, char* data, int size){
	string_initialize(s);
	for(int i = 0; i < size; i++){
		string_push_back(s, data[i]);
	}
}

void string_concatenate(string* s, char* data, int size){
	for(int i = 0; i < size; i++){
		string_push_back(s, data[i]);
	}
}

void string_destroy(string* v){
	free(v -> contents);
}

int main(){
	string _s;
	string* s = &_s;

	string_initialize(s);
	string_push_back(s, 's');
	string_push_back(s, 'u');
	string_push_back(s, 'y');
	string_push_back(s, 'a');
	string_push_back(s, 's');
	printf("%s\n", s -> contents);
	printf("size: %d\n", s -> size);

	string_set(s, "nomore", 6);
	printf("%s\n", s -> contents);
	printf("size: %d\n", s -> size);

	string_concatenate(s, " is more", 8);
	printf("%s\n", s -> contents);
	printf("size: %d\n", s -> size);

	string_destroy(s);

	return 0;
}
