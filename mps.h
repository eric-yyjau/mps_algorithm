#include <iostream>
#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <stdlib.h>
#include <algorithm>
#include <fstream>
#include <math.h>
#include <vector>

//std::pair<int,int> chord;




template <class T>
class maxPlanarSubset{
public:
	maxPlanarSubset(){}
	maxPlanarSubset(int n , vector<T> ch){
		_numOfVertex=n;
		origin_chord=ch;
	}
	int Mis(int _start, int _end){
		initialize_matrix();
		T chord(0,0);
		for(int i=0; i<_numOfVertex; i++){
			m[i][i]=0;
		}
		int j;
		for(int l=1; l<_numOfVertex; l++){
			for(int i=0; i<(_numOfVertex-l); i++){
				j=i+l;
				m[i][j]=m[i][j-1];
				s[i][j]=1;
				//cout<<"m["<<i<<"]["<<j<<"]= " << m[i][j]<<endl;
				

				//chord = search_chd(j,0,origin_chord.size());
				chord = search_chd(j);	

				//assert(!(chord.first==0 && chord.second==0));
				if(!(chord.first==0 && chord.second==0)){
					if(chord.second>j||chord.second<i)
						s[i][j]=1;
					else if((chord.second<j) && (chord.second>i)){
						int temp;
						temp=m[i][chord.second-1]+1+m[chord.second+1][j-1];
						if(temp>m[i][j]){
							m[i][j]=temp;
							s[i][j]=2;
							//cout<<"**m["<<i<<"]["<<j<<"]= " << m[i][j]<<endl;
						}
					}
					else if(chord.second==i){
						++m[i][j];
						s[i][j]=3;
					}
				}
			}
		}
		_numOfPlanar=m[_numOfVertex-1][_numOfVertex-1];
		return _numOfPlanar;
	/*	int _num=0;
		if(_start>=_end)
			return _num;
		T chord(0,0);
		chord = search_chd(_end,0,origin_chord.size());
		//cout<<chord.first <<" "<<chord.second<<endl;
		//cout<<"s=" <<_start <<" "<< "e= "<<_end<<endl;

		if(!(chord.first==0 && chord.second==0)){
			if(chord.second>_end)
				return Mis(_start,_end-1);
			else if(chord.second==_start){
				push_back(chord);
				return (1+Mis(_start+1,_end-1));
			}
			else if(chord.second<_end && chord.second>_start){
				push_back(chord);
				return (Mis(_start,chord.second-1)+1+Mis(chord.second+1,_end));
			}
			else return 0;
		}
		else{
			return Mis(_start,_end-1);
		}
	*/
	}
	void push_back(T& t){
		planar_subset.push_back(t);
	}
	void getPlanarSubset(int i,int j){
		T chord(0,0);
		if(i<j){
			//cout<<"s["<<i<<"]["<<j<<"]= " << s[i][j]<<endl;
			if(s[i][j]==1){
				getPlanarSubset(i,j-1);
			}
			else if(s[i][j]==2){
				//chord=search_chd(j,0,origin_chord.size()-1);
				chord=search_chd(j);
				//cout<<"chord= "<<chord.first <<" , " << chord.second<<endl;
				push_back(chord);
				getPlanarSubset(i,chord.second-1);
				getPlanarSubset(chord.second+1,j);
			}
			else if(s[i][j]==3){
				//chord=search_chd(j,0,origin_chord.size()-1);
				chord=search_chd(j);
				push_back(chord);
				getPlanarSubset(i+1,j-1);
			}
			else if(s[i][j]==4){
				getPlanarSubset(i-1,j);
			}
		}

	}

	void print(int i=0){
		if(i==0){
			int s=origin_chord.size();
			cout<< _numOfVertex << endl;
  			for(int i=0 ;i<s ;i++ ){
    			cout<< origin_chord[i].first << " " << origin_chord[i].second << endl;
  			}	
  			cout<< int(0) <<endl;
		}
		else if(i==1){
			int s=planar_subset.size();
			cout<< s << endl;
  			for(int i=0 ;i<s ;i++ ){
    			cout<< planar_subset[i].first << " " << planar_subset[i].second << endl;
  			}	
  			//cout<< int(0);
		}
	}
	void output_orig(const char* output_file){
		ofstream outputFile;
		//cout<<"yo~"<<endl;
		outputFile.open(output_file);
		//int s=planar_subset.size();
		outputFile<< _numOfVertex << endl;
		for(int i=0 ;i<_numOfVertex ;i++ ){
    		outputFile<< origin_chord[i].first << " " << origin_chord[i].second << endl;
  		}	
  		outputFile<< int(0) <<endl;

	}

	void output_chord(const char* output_file){
		ofstream outputFile;
		//cout<<"yo~"<<endl;
		outputFile.open(output_file);
		int s=planar_subset.size();
		outputFile<< s << endl;
  	for(int i=0 ;i<s ;i++ ){
    	outputFile<< planar_subset[i].first << " " << planar_subset[i].second << endl;
  	}
  	outputFile.close();
	}

	void reset(){}
	void initialize_matrix(){
		m=new int*[_numOfVertex];
		for(int i=0;i<_numOfVertex;i++){
			m[i]=new int[_numOfVertex];
		}
		s=new int*[_numOfVertex];
		for(int i=0;i<_numOfVertex;i++){
			s[i]=new int[_numOfVertex];
		}
	}
	void get_chord( vector<T> c ){
		origin_chord = c;
	}
	void sort_chord(int i){
		chdSort s;
		if(i==0){
			std::sort(origin_chord.begin(),origin_chord.end(),s);
		}
		else if(i==1){
			std::sort(planar_subset.begin(),planar_subset.end(),s);
		}
	}
	T search_chd(int chordV){
		T ret(0,0);
		//cout<<origin_chord.size()
		assert(chordV<_numOfVertex);
		if(origin_chord.size()==_numOfVertex){
			if(origin_chord[chordV].first==chordV){
				//cout<<"get"<<endl;
				return origin_chord[chordV];
			}
		}
		else return(search_chd(chordV,0,origin_chord.size()));

		return ret;
	}

	//bug!!!
	T search_chd(int chordV , int p ,int r){
		int q=floor((p+r)/2.0);
		//cout<<"p= " <<p  <<" q= "<<q <<" r= "<<r <<endl;
		T ret(0,0);
		if(p>r){
			//cout<<"here"<<endl;
			return ret;
		}
		
		//cout<<chordV<<endl;

		ret = origin_chord[q];
		//cout<<ret.first<<endl;
		if(chordV==ret.first)
			return ret;
		else if(chordV>ret.first)
			return search_chd(chordV,q+1,r);
		else if(chordV<ret.first)
			return search_chd(chordV,p,q-1);
	}


	void org_planar_subset(){
		getPlanarSubset(0,_numOfVertex-1);
		int s =planar_subset.size();
		for(int i=0; i<s ; i++){
			if(planar_subset[i].first>planar_subset[i].second)
				swap(planar_subset[i].first,planar_subset[i].second);
		}
	}

	int get_numOfV(){ return _numOfVertex; }

private:
	int _numOfVertex;
	int _numOfPlanar;
	vector<T> origin_chord;
	vector<T> planar_subset;
	int** m;
	int** s;
	struct chdSort
	{
   	bool operator() (const pair<int,int>& r1, const pair<int,int>& r2) const{
   	  if(r1.first<r2.first)
   	  	return true;
   	  else 
   	  	return false;
   	}
   
	};
};