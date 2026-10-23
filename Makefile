CC = gcc
EXEC = a.out
BACKEND_SRC = fob/backends/fob_linux_x86_64.c
SRCS = test.c $(wildcard fob/*.c) $(BACKEND_SRC) -Ifob
CFLAGS = -Wall -Wextra -Wpedantic -std=c99 -march=native
DEBUG ?= 0

ifeq ($(DEBUG),0)
CFLAGS += -s -O3 -DNDEBUG
else
CFLAGS += -g -Wl,-z,now -Wl,-z,relro \
	  -fsanitize=undefined,address \
	  -fstack-protector-strong \
	  -ftrampolines \
	  -ftrivial-auto-var-init=pattern
endif

.PHONY: all

all:
	$(CC) $(CFLAGS) -o $(EXEC) $(SRCS)
