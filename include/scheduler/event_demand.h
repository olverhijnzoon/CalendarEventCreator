#ifndef EVENT_DEMAND_H
#define EVENT_DEMAND_H

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

#endif // EVENT_DEMAND_H
