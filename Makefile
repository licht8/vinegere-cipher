TARGET = Vigenere_Ciph
SRCS = main.c vigenere.c
OBJDIR = obj
OBJS = $(SRCS:%.c=$(OBJDIR)/%.o)
CC = gcc
CFLAGS = -Wall -Wextra -I.

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $(OBJS)

$(OBJDIR):
	mkdir -p $(OBJDIR)

$(OBJDIR)/%.o: %.c | $(OBJDIR)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(TARGET)
	rm -f $(OBJDIR)/*.o

verbose: CFLAGS += -v
verbose: $(TARGET)

debug: CFLAGS += -g
debug: $(TARGET)

.PHONY: all clean verbose debug