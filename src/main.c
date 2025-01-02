#include <stdio.h>
#include <stdlib.h>

int createICSFile() {
	char *outputDir = getenv("ICS_OUTPUT_DIR");
	if (outputDir == NULL) {
		fprintf(stderr, "[ERROR] ICS_OUTPUT_DIR environment variable not set.\n");
		return 1;
	}
	printf("[INFO] Environment variable ICS_OUTPUT_DIR is set to '%s'.\n", outputDir);
	return 0;
}
	
int writeICSFile() {
	return 0;	
}

int main() {
	if (createICSFile() != 0){
		return 1;
	}
	writeICSFile();
	return 0;
}
