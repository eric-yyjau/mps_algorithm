#include <cstdio>
#include <iostream>
#include <fstream>

#include "parser.h"
#include "mps.h"
#include "myString.h"

//#define mergesort
//#define insertionsort
//#define selectionsort

#ifndef NDEBUG

#endif // NDEBUG

void print_string( AlgParser& p );
void do_insertionsort( AlgParser& p);
void print_insertionsort( AlgParser& p);
void print_sort_string( AlgParser& p);
void print_sort_appearance_vector (AlgParser& p);

int main( int argc, char** argv )
{
    AlgParser p;
    AlgTimer t;
  if( argc == 3){
        // Declare the functional objects

    //maxPlanarSubset mps;
        // Pass the arguement 1 as the input file name
    p.Parse( argv[1] );
        // Start timer
    t.Begin();
    maxPlanarSubset< pair<int,int> > mps(p.get_numOfVer(), p.get_data() );
    mps.sort_chord(0);
    //mps.print(0);
    
    mps.Mis(0,mps.get_numOfV()-1);
    mps.org_planar_subset();
    mps.sort_chord(1);
    //mps.print(1);
    
    //output all chords
    //mps.output_orig(argv[2]);
    
    //output mps
    mps.output_chord(argv[2]);
    //mps.print(1);
    
    //Display the accumulated time
    cout << "The execution spends " << t.End() << " seconds" << endl;
    return 1;
}
else 
{
    cout << "Usage Mis <input_file_name> <output_file_name>"<<endl;
    string _file;
    cin>>_file;
    t.Begin();
    p.Parse(_file);
    //p.print();
    maxPlanarSubset< pair<int,int> > mps(p.get_numOfVer(), p.get_data() );
    mps.sort_chord(0);
    //mps.print(0);
    
    mps.Mis(0,mps.get_numOfV()-1);
    mps.org_planar_subset();
    mps.sort_chord(1);
    mps.print(1);
    cout << "The execution spends " << t.End() << " seconds" << endl;
    



    return 1;
}

}

/*

void print_sort_appearance_vector (AlgParser& p){
    for( int i=0 ; i<p.sort_word_appearance.size() ; i++){
        cout<<i<<"= "<<p.sort_word_appearance[i]<<endl;
    }
}


void print_string( AlgParser& p ){
   // Display all strings and line numbers

    for( int i = 0 ; i < p.QueryTotalStringCount() ; i++ )
    {
        cout << p.QueryString(i) << " " << p.QueryLineNumber(i) << " " << p.QueryWordOrder(i)<< endl;
    }

}

void do_insertionsort( AlgParser& p){
    p.initialize_str_sortorder();
    p.my_insertionsort();
}

void print_insertionsort( AlgParser& p){
    for( int i = 0 ; i < p.QueryTotalStringCount() ; i++ )
    {
        // cout<<"get"<<endl;
        int temp = p.str_sortorder[i];
        if( p.repeat( temp ) == false)
        {
            cout << p.QueryString(temp)  << " ";
            p.print_repeat_word_order( temp );
            cout << endl;
        }

    }
}

void print_sort_string( AlgParser& p){
    for( int i = 0 ; i < p.QueryTotalStringCount() ; i++ )
    {
            // cout<<"get"<<endl;
        int temp = p.str_sortorder[i];
        cout << p.QueryString(temp)  << " " << p.QueryLineNumber(temp)
        <<  " " << p.QueryWordOrder(temp) << endl;
    }
}

*/