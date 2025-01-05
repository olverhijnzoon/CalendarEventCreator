#ifndef EVENT_DEMAND_BRIDGE_H
#define EVENT_DEMAND_BRIDGE_H

#include "event_demand.h"

extern EventDemand createEventDemand(const char *summary,
                                     const char *description,
                                     int durationMinutes, const char *start,
                                     const char *end);

#endif
