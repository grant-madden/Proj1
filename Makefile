
#Variables
CC = g++
CFLAGS = -g -Wall -std=c++11

# Linking all the files

## Intro 
a.exe: MyTime.o MyTime.h runtime.o runtime.h RunJournal.o RunJournal.h main.o
	$(CC) $(CFLAGS) MyTime.o runtime.o RunJournal.o main.o -o a.exe


## Body
MyTime.o: MyTime.cc MyTime.h
	$(CC) -c $(CFLAGS) MyTime.cc -o MyTime.o

RunJournal.o: RunJournal.cc RunJournal.h
	$(CC) -c $(CFLAGS) RunJournal.cc -o RunJournal.o

runtime.o: runtime.cc runtime.h
	$(CC) -c $(CFLAGS) runtime.cc -o runtime.o


## Conclusion
main.o: main.cc MyTime.h 
	$(CC) -c $(CFLAGS) main.cc -o main.o
