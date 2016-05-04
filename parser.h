#ifndef _DEFINE_PARSER_
#define _DEFINE_PARSER_

#include <fstream>
#include <string>
#include <vector>
#include <cstdio>
#include <iostream>
#include <assert.h>

#define output_1
//#define mergesort
//#define selectionsort

using namespace std;
//std::pair<int,int>::pair;

struct sortint
{
    bool operator() (const int & i1 , const int& i2)
    {
        return i1 < i2 ;
    }
};




class AlgParser
{
public:
    AlgParser(){}
    // Specify the parsing file name and then parse the file
    void Parse(const string& input_file_name);
    void print();
    int get_numOfVer(){
        return _numOfVertex;
    }
    vector< pair<int,int> > get_data(){
        return _chords;
    }

//TODO::
private:
    vector< pair<int,int> > _chords;
    int _numOfVertex;

};

class AlgTimer
{
public:
    long begin_clock;
    AlgTimer(void);
    // Strat the timer
    void Begin(void);
    // Return the accumulated time in seconds
    double End(void);

};

#endif
