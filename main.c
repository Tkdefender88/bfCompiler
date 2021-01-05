#include <stdio.h>
#include <stdlib.h>

char* readFile(char *fileName);

int main() {

	char* buff = readFile("./src_code/hello_world.bf");

	printf("%s", buff);

}

// readFile will read all the contents of a file into a buffer and return it.
// takes one parameter being the file name. If an error occurs readFile will return NULL
char* readFile(char *fileName) {
	FILE *fp = fopen(fileName, "r");
	char *code;
	size_t n = 0;
	int c;

	if (fp == NULL) {
		return NULL; // cannot open file
	}

	// find the size of the file
	fseek(fp, 0, SEEK_END);
	long f_size = ftell(fp);
	fseek(fp, 0, SEEK_SET);
	// create a buffer to hold all the code
	code = malloc(f_size);

	// read each character into the buffer
	while (( c = fgetc(fp)) != EOF ) {
		code[n++] = (char) c;
	}

	// null terminate that boi
	code[n] = '\0';
	
	return code;
}
