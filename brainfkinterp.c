#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define BUFFER_SIZE 200

int main(int argc, char* argv[]) {
	
	if(argc < 2) {
		printf("No input.\n");
		return -1;
	}

	char* source = argv[1];
	int srcp = 0;

	int* buffer = (int*) malloc(BUFFER_SIZE);
	memset(buffer, 0, BUFFER_SIZE);
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
	
	printf("\n");
	return 0;

}
