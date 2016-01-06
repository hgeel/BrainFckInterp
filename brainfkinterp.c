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
			//printf("Increase value.\n");		//Debug
			break;
		case '-':
			--(buffer[pointer]);
			//printf("Decrease value.\n");		//Debug
			break;
		case '>':
			++pointer;
			if(pointer > BUFFER_SIZE)
				pointer = 0;
			//printf("Increase pointer.\n");	//Debug
			break;
		case '<':
			--pointer;
			if(pointer < 0)
				pointer = BUFFER_SIZE - 1;
			//printf("Decrease pointer.\n");	//Debug
			break;
		case '.':
			printf("%c", (char) buffer[pointer]);	//Not working when debug lines are commented.
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
