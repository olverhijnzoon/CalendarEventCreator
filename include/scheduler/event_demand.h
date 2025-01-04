// Copyright 2025 Oliver Heinsohn

#ifndef INCLUDE_SCHEDULER_EVENT_DEMAND_H_
#define INCLUDE_SCHEDULER_EVENT_DEMAND_H_

typedef struct {
  char start[16];
  char end[16];
} TimeSlot;

typedef struct {
  char summary[256];
  char description[1024];
  int durationMinutes;
  TimeSlot timeSlot;
} EventDemand;

#endif // INCLUDE_SCHEDULER_EVENT_DEMAND_H_
