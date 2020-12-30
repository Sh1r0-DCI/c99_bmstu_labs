CC = gcc
CF = -std=c99 -Wall -Wextra -pedantic -I ./inc

OBJDIR = ./out
SRCDIR = ./src
DEPSDIR = ./inc

DEPS = $(wildcard $(DEPSDIR)/*.h)
SRC = $(wildcard $(SRCDIR)/*.c)
TEMPSRC = $(patsubst %.c, %.o, $(SRC))
SRCOBJECTS = $(patsubst $(SRCDIR)%, $(OBJDIR)%, $(TEMPSRC))

ALL_OBJECTS = $(SRCOBJECTS) $(UNITOBJECTS)

OBJECTS = $(filter-out $(OBJDIR)/main.o, $(ALL_OBJECTS))

MAINNAME = app.exe

compile: objdir $(MAINNAME)


$(MAINNAME): $(SRCOBJECTS)
	$(CC) $(CF) $^ -o $@

objdir:
	@mkdir -p $(OBJDIR)

clean:
	rm -rf $(MAINNAME) $(OBJDIR)
	rm -rf ./out.txt

$(UNITNAME): $(OBJECTS)
	@mkdir -p $(OBJDIR)
	$(CC) $(UNITF) $^ -o $@

$(OBJDIR)/%.o: $(SRCDIR)/%.c $(DEPS)
	@mkdir -p $(OBJDIR)
	$(CC) $(CF) $< -c -o $@

$(OBJDIR)/%.o: $(UNITDIR)/%.c $(DEPS)
	@mkdir -p $(OBJDIR)
	$(CC) $(CF) $< -c -o $@