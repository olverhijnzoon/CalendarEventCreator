// Copyright 2025 Oliver Heinsohn

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
	char dtstart[32];
	char dtend[32];
  char summary[100];
  char description[200];
} Event;

Event createEvent(const char *dtstart, const char *dtend, const char *summary, const char *description) {
  Event newEvent;
  strncpy(newEvent.dtstart, dtstart, sizeof(newEvent.dtstart));
  strncpy(newEvent.dtend, dtend, sizeof(newEvent.dtend));
  strncpy(newEvent.summary, summary, sizeof(newEvent.summary));
  strncpy(newEvent.description, description, sizeof(newEvent.description));
	return newEvent;
}

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
  fprintf(file, "VERSION:2.0\n");
  fprintf(file, "BEGIN:VEVENT\n");
  fprintf(file, "DTSTART:%s\n", event.dtstart);
  fprintf(file, "DTEND:%s\n", event.dtend);
  fprintf(file, "SUMMARY:%s\n", event.summary);
  fprintf(file, "DESCRIPTION:%s\n", event.description);
  fprintf(file, "END:VEVENT\n");
	fprintf(file, "END:VCALENDAR\n");

  fclose(file);
  printf("[INFO] ICS file created successfully at '%s'.\n", filepath);
  return 0;
}

int writeICSFile() { return 0; }

int main() {
  Event dummyEvent = createEvent("20250103T090000Z", "20250103T093000Z", "Breakfast", "Let's have breakfast.");
  if (createICSFile(dummyEvent) != 0) {
    return 1;
  }
  writeICSFile();
  return 0;
}
