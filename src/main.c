// Copyright 2025 Oliver Heinsohn

#include "ics/ics.h"
#include "scheduler/event_demand.h"

int main() {
  EventDemand demand0 = {
      .summary = "Way to Work",
      .description = "Plan time to get to workplace.",
      .durationMinutes = 60,
      .timeSlot = {.start = "20250106T070000Z", .end = "20250106T080000Z"}};

  Event dummyEvent = createEvent("20250103T090000Z", "20250103T093000Z",
                                 "Breakfast", "Let's have breakfast.");
  if (createICSFile(dummyEvent) != 0) {
    return 1;
  }
  writeICSFile();
  return 0;
}
