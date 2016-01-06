#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define BUFFER_SIZE 200

char* loadFile(char* fileName);

int main(int argc, char* argv[]) {
	
	if(argc < 2 || argc > 2) {
		printf("Usage: ./brainfkinterp [file]\n");
		return -1;
	}

	char* source = loadFile(argv[1]);
	if(source == NULL) return -1;
	int srcp = 0;

	int* buffer = (int*) calloc(BUFFER_SIZE, sizeof(int));
	int pointer = 0;

	int loop;

	while(srcp < strlen(source)) {
		
		switch(source[srcp]) {
		case '+':
			++(buffer[pointer]);
			break;
		case '-':
			--(buffer[pointer]);
			break;
		case '>':
			++pointer;
			if(pointer > BUFFER_SIZE - 1)
				pointer = 0;
			break;
		case '<':
			--pointer;
			if(pointer < 0)
				pointer = BUFFER_SIZE - 1;
			break;
		case '.':
			printf("%c", (char) buffer[pointer]);
			break;
		case ',':
			scanf("%c", (char*) (buffer + pointer));
			break;
		case '[':
			if(buffer[pointer] == 0) {
				loop = 1;
				while(loop > 0) {
					++srcp;
					char c = source[srcp];
					if(c == '[')
						++loop;
					if(c == ']')
						--loop;
				}
			}
			break;
		case ']':
			loop = 1;
			while(loop > 0) {
				--srcp;
				char c = source[srcp];
				if(c == '[')
					--loop;
				if(c == ']')
					++loop;
			}
			--srcp;
			break;
		}

		++srcp;

	}

	return 0;

}

char* loadFile(char* fileName) {

	FILE* fd = fopen(fileName, "r");
	if(fd == NULL) {
		printf("Could not open file.");
		return NULL;
	}
	fseek(fd, 0, SEEK_END);
	long size = ftell(fd);
	rewind(fd);
	char* buffer = malloc(size);
	if(buffer == NULL) {
		printf("Could not allocate buffer to read file.");
		fclose(fd);
		return NULL;
	}
	fread(buffer, size, 1, fd);
	fclose(fd);
	return buffer;

}
