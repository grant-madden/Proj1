/*
	Grant Madden
	CS 2401
	2/2/2020
	
*/
#include "runtime.h"
#include "MyTime.h"
#include <cstdlib>
#include <iostream>
#include <iomanip>
using namespace std;

Runtime::Runtime(){
    rtime = 0;
    distance = 0;
}

Runtime Runtime::operator +(const Runtime& rhs)const{
    Runtime tmp;
    tmp.rtime = rtime + rhs.rtime;
	tmp.distance = distance + rhs.distance;
	return tmp;
}

Runtime Runtime::operator -(const Runtime& rhs)const{
    Runtime tmp;
    tmp.rtime = rtime - rhs.rtime;
	tmp.distance = distance - rhs.distance;
	return tmp;
}

Runtime Runtime::operator *(const double& rhs) const{
    Runtime tmp;
    tmp.rtime = rtime * rhs;
    tmp.distance = distance * rhs;
	return tmp;
}
Runtime Runtime::operator /(const double& rhs) const{
    Runtime tmp;
    tmp.rtime = rtime / rhs;
    tmp.distance = distance / rhs;
	return tmp;
}

bool Runtime::operator == (const Runtime& rhs)const{
    
    if (rtime == rhs.rtime && distance == rhs.distance){
        return true;
    }
    else {
        return false;
    }
}
bool Runtime::operator != (const Runtime& rhs)const{
    if (rtime == rhs.rtime && distance == rhs.distance){
        return false;
    }
    else {
        return true;
    }
}

bool Runtime::distance_equal(double d) const{
    if (distance == d){
        return true;
    }
    else {
        return false;
    }
}
void Runtime::input(std::istream& ins){

    ins>>rtime;
    ins>>distance;
}
void Runtime::output(std::ostream& outs)const{
    outs<<rtime;
    outs<<distance;
}

ostream& operator <<(ostream& outs, const Runtime& t1){
	t1.output(outs);
	return outs;
}

istream& operator >> (istream& ins, Runtime& t1){
	t1.input(ins);
	return ins;
}
