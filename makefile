# Authored by Noah Klein (based on provided makefile from CSE 2421)

COMP=g++
CPPFLAGS=-std=c++17 -pedantic -Wformat -Wreturn-type 

all: main

main: main.o cards.o
	$(COMP) $(COMP_FLAGS) $^ -o $@



# This is our master compiler rule to generate .o files.
# It needs all 4 warnings
%.o:%.cpp *.hpp
	$(COMP) $(CPPFLAGS) -g -c $< -o $@
