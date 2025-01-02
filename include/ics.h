// Copyright 2025 Oliver Heinsohn

#ifndef ICS_H
#define ICS_H

#include <stdio.h>

typedef struct {
  char dtstart[32];
  char dtend[32];
  char summary[100];
  char description[200];
} Event;

Event createEvent(const char *dtstart, const char *dtend, const char *summary,
                  const char *description);

int createICSFile(Event event);

int writeICSFile();

#endif
