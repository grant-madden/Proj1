// The implementation file for the RunJournal class
#include "RunJournal.h"
#include "MyTime.h"
#include "runtime.h"
#include <cstdlib>
#include <iostream>
#include <iomanip>
using namespace std;

void RunJournal::record(Runtime tmp){
    if (recordedRuns < CAPACITY){
        journal[recordedRuns] = tmp;
        recordedRuns++;
    }
    else {
        cout << "RunJournal is at max capacity \n";
    }
}
void RunJournal::display(){
    for (int i = 0; i < recordedRuns; i++){
        cout << "| Run "<< i + 1 << " | Time: " << journal[i].get_time() << " | Distance: " << journal[i].get_distance() << " | \n";
        // Runtime tmp;
        // if (journal[i] != tmp){
        //     cout << "| Run "<< i + 1 << " | Time: " << journal[i].get_time() << " | Distance: " << journal[i].get_distance() << " | \n";
        // }
    }
}
void RunJournal::find_remove(Runtime tmp){
    Runtime copy;
    double totalMin = 0;
    bool exit = false;

    for (int i = 0; i < recordedRuns; i++){
        char userInput;
        bool validChar = false;
        if (tmp == journal[i]  && !exit){

            totalMin += (journal[i].get_time().get_hours() * 60);
            totalMin += journal[i].get_time().get_minutes();
            totalMin += (journal[i].get_time().get_seconds() / 60);

            cout << fixed << setprecision(2);
            cout << "Would you like to remove this run?\n";
            cout << "| Time: " << journal[i].get_time() << " | Distance: " << journal[i].get_distance() 
                << " | Pace: " <<  totalMin / journal[i].get_distance() << " |\n";
            cout << "(y/n): ";

            cin >> userInput;
                while (!validChar){
                    if (tolower(userInput) == 'y' || tolower(userInput) == 'n'){
                        validChar = true;
                    }
                    else {
                        cout << "Invalid input, Would you like to remove this run? (y/n): ";
                        cin >> userInput;
                    }
                }
            
            if (tolower(userInput) == 'y'){
                MyTime remove;
                journal[i].set_time(remove);
                journal[i].set_distance(0);
                // cout << "X: " << i << " RecordedRuns: " << recordedRuns << endl;
                // for (int x = i; x < recordedRuns; x++){
                //     journal[x] = journal[x+i];
                // }
                recordedRuns--;
            }

            exit = true;
        }
    }
}
void RunJournal::distance_view(double dist){
    for (int i = 0; i < recordedRuns; i++){
        if (journal[i].get_distance() == dist){
            cout << "| Run "<< i + 1 << " | Time: " << journal[i].get_time() << " | Distance: " << 
            journal[i].get_distance() << " | \n";
        }
    }
}

void RunJournal::time_sort(){
    int minIndex;
    for (int i = 0; i< recordedRuns - 1; i++){
        minIndex = indexOfSmallestTime(i, recordedRuns);
        swap(journal[i], journal[minIndex]);
    }
}
int RunJournal::indexOfSmallestTime( int startIndex, int endIndex){
    double min = journal[startIndex].get_time().get_total();
    int minIndex = startIndex;
    for (int i = startIndex; i < endIndex; i++){
        if (journal[i].get_time().get_total() < min){
            min = journal[i].get_time().get_total();
            minIndex = i + 0;
        }
    }
    return minIndex;
}

void RunJournal::distance_sort(){
    int minIndex;
    for (int i = 0; i< recordedRuns - 1; i++){
        minIndex = indexOfSmallestDistance(i, recordedRuns);
        swap(journal[i], journal[minIndex]);
    }
}
int RunJournal::indexOfSmallestDistance( int startIndex, int endIndex){
    double min = journal[startIndex].get_distance();
    int minIndex = startIndex;
    for (int i = startIndex; i < endIndex; i++){
        if (journal[i].get_distance() < min){
            min = journal[i].get_distance();
            minIndex = i + 0;
        }
    }
    return minIndex;
}
MyTime RunJournal::total_time(){
    int totalSeconds = 0;
    int totalMinutes = 0;
    int totalHours = 0;

    for (int i = 0; i < recordedRuns; i++){
        totalSeconds += (journal[i].get_time()).get_seconds();
        totalMinutes += (journal[i].get_time()).get_minutes();
        totalHours += (journal[i].get_time()).get_hours();
    }

    totalMinutes += totalSeconds/60;
	totalSeconds = totalSeconds%60;
    totalHours += totalMinutes/60;
	totalMinutes = totalMinutes%60;

    MyTime tmp(totalHours, totalMinutes, totalSeconds);
    
    return tmp;
}
double RunJournal::total_distance(){
    int totalDistance = 0;

    for (int i = 0; i < recordedRuns; i++){
        totalDistance += journal[i].get_distance();
    }
    return totalDistance;
}
double RunJournal::average_pace(){
    double totalMin = 0;
    totalMin += (total_time().get_hours() * 60);
    totalMin += total_time().get_minutes();
    totalMin += (total_time().get_seconds() / 60);

    return totalMin / total_distance();
}
void RunJournal::save(std::ostream& outs){
    for (int i = 0; i < recordedRuns; i++){
        outs << journal[i].get_time() << " " << journal[i].get_distance() << endl;
    }
}
