/*****************************************************************
	This is a class that stores time. It stores the time in 
	hours, minutes and seconds, which makes it a little more
	extensive than the one you have used in lab.

	Note: That since all the operators are overloaded, including
	input and output there is NO need to for the application 
	programmer to get directly to the individual components of
	the Time. USE THE OPERATORS!!!
		John Dolan, Associate Professor of Instruction
		Ohio University, Athens, Ohio
		Spring Semester 2020
*************************************************************************/
/*
	Grant Madden
	CS 2401
	2/2/2020
	
*/
#include <iostream>
#ifndef RUNJOURNAL_H
#define RUNJOURNAL_H

#include "runtime.h"
#include "MyTime.h"

class RunJournal
{   
  public:
    static const int CAPACITY =  200; 

    RunJournal(){
        recordedRuns = 0;
    } 

    void record(const Runtime tmp);
    void display();
    void find_remove(Runtime tmp);
    void distance_view(double dist);
    void time_sort();
    void distance_sort();
    MyTime total_time();
    double total_distance();
    double average_pace();
    void save(std::ostream& outs);
   
   int getRecordedRuns(){return recordedRuns;}

   int indexOfSmallestTime(int startIndex, int endIndex);
   int indexOfSmallestDistance(int startIndex, int endIndex);

  private:
      Runtime journal [CAPACITY];
      int recordedRuns;
 };
 
#endif