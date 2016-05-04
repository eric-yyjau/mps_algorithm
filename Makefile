#
# This is for your executable
#
CFLAGS = -O3 -DNDEBUG
#CFLAGS = -Wall
#
# This is the setting for TA
#
# CFLAGS = -g -Wall -DTA_KB_SETTING
# CFLAGS = -O3 -DTA_KB_SETTING
# CFLAGS = -O3 -m32 -DTA_KB_SETTING

###############
# PHONY rules #
###############
.PHONY : mps


mps : MAKEFLAGS =  $(CFLAGS)


mps :  clean my_mps


##############
# Executable #
##############
my_mps: 	main.o myString.o parser.o 
	g++ -o $@ $(MAKEFLAGS)  main.o myString.o parser.o 
	




################
# Object files #
################
main.o: main.cpp parser.h mps.h
	g++ -c $(MAKEFLAGS) main.cpp

myString.o: myString.cpp myString.h
	g++ -c $(MAKEFLAGS) myString.cpp

parser.o: parser.cpp parser.h
	g++ -c $(MAKEFLAGS) parser.cpp

#mps.o: mps.h
#	g++ -c $(MAKEFLAGS) mps.cpp



#######################
# No dependency rules #
#######################
clean:
	rm -f *.o main parser

#mergesort:
	
	
