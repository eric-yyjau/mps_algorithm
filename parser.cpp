#include <iostream>
#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <stdlib.h>
#include <algorithm>
#include <fstream>
#include <math.h>

#include "parser.h"

#include "myString.h"



//===============================
//    Member Function for class CmdExec
//----------------------------------------------------------------------
// Return false if error options found
// "optional" = true if the option is optional XD
// "optional": default = true
//
bool lexSingleOption
(const string& option, string& token, bool optional) 
{
   size_t n = myStrGetTok(option, token);
   if (!optional) {
      if (token.size() == 0) {
         //errorOption(CMD_OPT_MISSING, "");
         return false;
      }
   }
   if (n != string::npos) {
      //errorOption(CMD_OPT_EXTRA, option.substr(n));
      return false;
   }
   return true;
}

// if nOpts is specified (!= 0), the number of tokens must be exactly = nOpts
// Otherwise, return false.
//
bool lexOptions
(const string& option, vector<string>& tokens, size_t nOpts) 
{
   string token;
   size_t n = myStrGetTok(option, token);
   while (token.size()) {
      tokens.push_back(token);
      n = myStrGetTok(option, token, n);
   }
   if (nOpts != 0) {
      if (tokens.size() < nOpts) {
         //errorOption(CMD_OPT_MISSING, "");
         return false;
      }
      if (tokens.size() > nOpts) {
         //errorOption(CMD_OPT_EXTRA, tokens[nOpts]);
         return false;
      }
   }
   return true;
}



//================================

void AlgParser::Parse(const string& input_file_name){
  ifstream ifs;
  //char next_line = 13;
  ifs.open(input_file_name.c_str(),ios::in);  //open the file
  string get;
  string a;
  string b;
  std::pair<int,int> _chord;
  ifs >> a;
  //cout<< a <<endl;

  /*for(int i=0; i<20 ; i++){
    ifs >> a;
  cout<< a <<endl;
  }
  */


  //cout<< a_row <<endl;
  myStr2Int(a,_numOfVertex);
  while(true){
    //a_row.erase();
    ifs >> get;
    myStrGetTok(get,a);
    ifs >> get;
    myStrGetTok(get,b);
    //cout<< a<<endl;
    //cout<< b<<endl;
    
    if(a=="0"&& b=="0")
      break;
    myStr2Int(a,_chord.first);
    myStr2Int(b,_chord.second);
    _chords.push_back(_chord);
    swap(_chord.first,_chord.second);
      _chords.push_back(_chord);
  }
  ifs.close();


}


void AlgParser::print(){
  int s = _chords.size();
  cout<< _numOfVertex << endl;
  for(int i=0 ;i<s ;i++ ){
    cout<< _chords[i].first << " " << _chords[i].second << endl;
  }
  cout<< int(0) <<endl;
}



//================================

AlgTimer::AlgTimer(void)
{

};

void AlgTimer::Begin(void)
{
begin_clock = clock();
}

double AlgTimer::End(void)
{
return ( (double)( clock() - begin_clock ) / (double)CLOCKS_PER_SEC );
}


//==================================



