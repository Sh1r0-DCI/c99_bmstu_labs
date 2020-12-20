CC = gcc
CF = -Wall -Wextra -pedantic

OBJDIR = ./out
SRCDIR = ./src
DEPSDIR = ./inc

DEPS = $(wildcard $(DEPSDIR)/*.h)
SRC = $(wildcard $(SRCDIR)/*.c)
TEMPSRC = $(patsubst %.c, %.o, $(SRC))
SRCOBJECTS = $(patsubst $(SRCDIR)%, $(OBJDIR)%, $(TEMPSRC))

OBJECTS = $(filter-out $(OBJDIR)/main.o, $(ALL_OBJECTS))

MAINNAME = app.exe

compile: objdir $(MAINNAME)


$(MAINNAME): $(SRCOBJECTS)
	$(CC) $(CF) $^ -o $@
	@echo "Build done."

objdir:
	@mkdir -p $(OBJDIR)

clean:
	rm -rf *.dSYM
	rm -rf $(MAINNAME) $(OBJDIR)
	rm -rf ./tests_res
	rm -rf ./test_build
	rm -rf ./out.txt


$(OBJDIR)/%.o: $(SRCDIR)/%.c $(DEPS)
	@mkdir -p $(OBJDIR)
	$(CC) $(CF) $< -c -o $@

