#include<iostream>
#include<vector>
using namespace std;
class SuffixTree {
	int Size;	//Size of string + sentinal
	char* char_arr;	//Save character array
	vector<string> Suffixes;
public:
	SuffixTree(int s ,string a) {
		Size = s;
		char_arr =new char[Size+1];
		for (int i = 0; i < Size; i++) {	//populate character array from string
			char_arr[i] = a[i];
		}
	}
	void build_Suffix() {
		string suffix;
		for(int j=0;j<Size;j++){
			suffix = "";
			for (int i = Size-j-1; i <Size; i++) {
				suffix += char_arr[i];
			}
			Suffixes.push_back(suffix);		//pushes suffixes
		}
		
	}
	void printSuffixes() {
		for (int i = 0; i < Suffixes.size(); i++) {
			cout << Suffixes.at(i) << endl;
		}
	}
};