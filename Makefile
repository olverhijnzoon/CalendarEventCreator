# compiler flags
CC = gcc
CFLAGS = -Wall -g -Iinclude

# linker flags
LDFLAGS =

SOURCES = $(wildcard src/*.c)
OBJECTS = $(SOURCES:.c=.o)
EXECUTABLE = calendar_event_creator

all: $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@

# create .o from corresponding .c
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

run: $(EXECUTABLE)
	@ mkdir -p tmp/ics_files && \
	ICS_OUTPUT_DIR="tmp/ics_files" \
	./$(EXECUTABLE)

clean:
	rm -f $(OBJECTS) $(EXECUTABLE)

format:
	clang-format -i $(SOURCES)
