
OUTFILE=cubes
CFLAGS=-Wall
LIBS=-lglfw -lGL -lGLU

OBJECTS= \
	main.o \
	camera.o \
	scene.o \
	quaternion.o \
	vector3.o \
	axis-animator.o \
	cube-grid.o \
	position-animator.o


all: $(OBJECTS)
	g++ -g $(OBJECTS) -o $(OUTFILE) $(LIBS)

.c.o:
	g++ $< -c $(CFLAGS)

tags:
	ctags *.cc *.hh

clean:
	rm $(OBJECTS) $(OUTFILE)

