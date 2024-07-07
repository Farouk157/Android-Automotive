# compiler 
CC = gcc

# Directoris 
INCDIR = include
SRCDIR = src
BINDIR = bin
BUILDIR= build

# Source, object, and executable files
SRC = $(wildcard $(SRCDIR)/*.c)
OBJ = $(patsubst $(SRCDIR)/%.c,$(BINDIR)/%.o, $(SRC))
EXEC = $(BUILDIR)/app

CFLAG = -I$(INCDIR)

all: $(EXEC)


$(BINDIR)/%.o: $(SRCDIR)/%.c
	$(CC) -c $< -o $@ $(CFLAG)

$(EXEC): $(OBJ)
	$(CC) $^ -o $@

.PHONY: all clean
clean:
	rm -rf $(BINDIR)/*.o $(BUILDDIR)/app


