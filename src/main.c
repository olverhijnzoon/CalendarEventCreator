// Copyright 2025 Oliver Heinsohn

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
  char summary[100];
  char description[200];
} Event;

int createICSFile(Event event) {
  char *outputDir = getenv("ICS_OUTPUT_DIR");
  if (outputDir == NULL) {
    fprintf(stderr, "[ERROR] ICS_OUTPUT_DIR environment variable not set.\n");
    return 1;
  }
  printf("[INFO] Environment variable ICS_OUTPUT_DIR is set to '%s'.\n",
         outputDir);

  char filepath[256];
  snprintf(filepath, sizeof(filepath), "%s/event.ics", outputDir);
  FILE *file = fopen(filepath, "w");
  if (file == NULL) {
    fprintf(stderr, "[ERROR] Could not open file '%s' for writing.\n",
            filepath);
    return 1;
  }

  fprintf(file, "BEGIN:VCALENDAR\n");
  fprintf(file, "SUMMARY:%s\n", event.summary);
	fprintf(file, "DESCRIPTION:%s\n", event.description);
	fprintf(file, "END:VCALENDAR\n");

  fclose(file);
  printf("[INFO] ICS file created successfully at '%s'.\n", filepath);
  return 0;
}

int writeICSFile() { return 0; }

int main() {
  Event dummyEvent;
	strcpy(dummyEvent.summary, "dummyEvent summary");
	strcpy(dummyEvent.description, "dummyEvent Description");
  if (createICSFile(dummyEvent) != 0) {
    return 1;
  }
  writeICSFile();
  return 0;
}
