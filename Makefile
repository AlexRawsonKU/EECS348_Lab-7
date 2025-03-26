# This Makefile makes heavy use of implicit rules

CC := gcc
CFLAGS ?= -Wall -Wextra

# Phony bonus rule
.PHONY: all
all: football.exe temperature.exe

# Define Football rules

football.exe: football.o football_main.o
	$(CC) -o $@ $^ $(CFLAGS)

football.o: football.c

football_main.o: football_main.c

# Define Temperature rules

temperature.exe: temperature.o temperature_main.o
	$(CC) -o $@ $^ $(CFLAGS)

temperature.o: temperature.c

temperature_main.o: temperature_main.c
