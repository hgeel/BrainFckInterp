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

	char* buffer = (char*) malloc(BUFFER_SIZE);
	memset(buffer, 0, BUFFER_SIZE);
	int pointer = 0;

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
			if(pointer + 1 >= BUFFER_SIZE) {
				printf("Out of buffer bounds (>).\n");
				return -1;
			}
			++pointer;
			//printf("Increase pointer.\n");	//Debug
			break;
		case '<':
			if(pointer - 1 < 0) {
				printf("Out of buffer bounds (<).\n");
				return -1;
			}
			--pointer;
			//printf("Decrease pointer.\n");	//Debug
			break;
		case '.':
			printf("%c", buffer[pointer]);	//Not working when debug lines are commented.
			break;
		case ',':
			scanf("%c", buffer + pointer);
			break;
		}

		++srcp;

	}
	
	printf("\n");
	return 0;

}
