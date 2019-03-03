CC      = g++
SRCDIR  = ./src
OBJDIR	= ./obj
CFLAGS  = -Isrc/ -lGL -lGLU -lglut
LDFLAGS = -lGL -lGLU -lglut


all: clean setupdir smtp 

smtp: fog.o Player.o Figures.o FiguresSphere.o FiguresCube.o Wall.o Lights.o LightsSpot.o lib_keys.o lib_mouse.o lib_utility.o lib_texture.o object_pool.o main.o 
	cd $(OBJDIR) ; $(CC) -o ../smtp $^ $(LDFLAGS) 

fog.o: $(SRCDIR)/fog.cpp
	$(CC) -c $(CFLAGS) $< -o $(OBJDIR)/$@

Player.o: $(SRCDIR)/Player.cpp
	$(CC) -c $(CFLAGS) $< -o $(OBJDIR)/$@

Figures.o: $(SRCDIR)/Figures.cpp
	$(CC) -c $(CFLAGS) $< -o $(OBJDIR)/$@

FiguresSphere.o: $(SRCDIR)/FiguresSphere.cpp
	$(CC) -c $(CFLAGS) $< -o $(OBJDIR)/$@

FiguresCube.o: $(SRCDIR)/FiguresCube.cpp
	$(CC) -c $(CFLAGS) $< -o $(OBJDIR)/$@

Wall.o: $(SRCDIR)/Wall.cpp
	$(CC) -c $(CFLAGS) $< -o $(OBJDIR)/$@

Lights.o: $(SRCDIR)/Lights.cpp
	$(CC) -c $(CFLAGS) $< -o $(OBJDIR)/$@

LightsSpot.o: $(SRCDIR)/LightsSpot.cpp
	$(CC) -c $(CFLAGS) $< -o $(OBJDIR)/$@

lib_keys.o: $(SRCDIR)/lib_keys.cpp
	$(CC) -c $(CFLAGS) $< -o $(OBJDIR)/$@

lib_mouse.o: $(SRCDIR)/lib_mouse.cpp
	$(CC) -c $(CFLAGS) $< -o $(OBJDIR)/$@

lib_utility.o: $(SRCDIR)/lib_utility.cpp
	$(CC) -c $(CFLAGS) $< -o $(OBJDIR)/$@

lib_texture.o: $(SRCDIR)/lib_texture.cpp
	$(CC) -c $(CFLAGS) $< -o $(OBJDIR)/$@

object_pool.o: $(SRCDIR)/object_pool.cpp
	$(CC) -c $(CFLAGS) $< -o $(OBJDIR)/$@

main.o: $(SRCDIR)/main.cpp
	$(CC) -c $(CFLAGS) $< -o $(OBJDIR)/$@
	
setupdir: 
	mkdir $(OBJDIR)

clean:
	rm -fR $(OBJDIR) smtp
	