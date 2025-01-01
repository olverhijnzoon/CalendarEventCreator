#include <stdio.h>
#include <stdlib.h>

// function to create an ICS calendar file
int createICSFile() {
	
	// get ICS file output directory from environment variable
	char *outputDir = getenv("ICS_OUTPUT_DIR");
	if (outputDir == NULL) {
		fprintf(stderr, "[ERROR] ICS_OUTPUT_DIR environment variable not set.\n");
		return 1;
	}
	printf("[INFO] Environment variable ICS_OUTPUT_DIR is set to '%s'.\n", outputDir);
	return 0;
}
	
// function to write to an ICS calendar file
int writeICSFile() {
	printf("[INFO] Writing ICS file\n");
	return 0;	
}

int main() {
	printf("$$$$$$$$$$$$$$\n");
	printf("[INFO] Calendar Event Creator routine is started.\n");
	
	if (createICSFile() != 0){
					return 1;
	}

	writeICSFile();
	return 0;
}
