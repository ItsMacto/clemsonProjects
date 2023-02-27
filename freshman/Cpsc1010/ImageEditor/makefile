# Mac Howe, Pmhowe
# 12/7/2022
# Section 020
# PA4 "Fun With ppm Images"
# Makes and compiles all files for program


a.out: mainDriver.c getHeader.c initInputImageArray.c manip.c writeHeader.c writePixels.c defs.h
	gcc -Wall mainDriver.c getHeader.c initInputImageArray.c manip.c writeHeader.c writePixels.c defs.h

run: a.out
	./a.out Disney.pnm ClemsonPaw.pnm
clean:
	rm -f *.o
	rm -f a.out
	rm -f out1.pnm
	rm -f out2.pnm
