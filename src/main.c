// Copyright 2025 Oliver Heinsohn

#include "ics/ics.h"

int main() {
  Event dummyEvent = createEvent("20250103T090000Z", "20250103T093000Z",
                                 "Breakfast", "Let's have breakfast.");
  if (createICSFile(dummyEvent) != 0) {
    return 1;
  }
  writeICSFile();
  return 0;
}
