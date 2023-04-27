SRCDIR = .
SRCS = $(wildcard $(SRCDIR)/*.c) $(wildcard $(SRCDIR)/commands/*.c)
OBJDIR = obj
BINDIR = bin
OBJS = $(patsubst $(SRCDIR)/%.c,$(OBJDIR)/%.o,$(SRCS))
CC = gcc
CFLAGS = -Wall -Wextra -Werror -g
LDFLAGS =

.PHONY: clean

$(BINDIR)/my_program: $(OBJS)
	$(CC) $(LDFLAGS) $^ -o $@

$(OBJDIR)/%.o: $(SRCDIR)/%.c
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJDIR)/%.o: $(SRCDIR)/commands/%.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJDIR)/*.o $(BINDIR)/my_program
