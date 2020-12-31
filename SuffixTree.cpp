#include<iostream>
#include<vector>
#include"Node.cpp"
using namespace std;
class SuffixTree {
	int Size;	//Size of string + sentinal
	char* char_arr;	//Save character array
	char** Suffixes;//2D Array to store suffixes
	Node* root;
public:
	SuffixTree(int s ,string a) {
		Size = s;
		char_arr =new char[Size];
		for (int i = 0; i <Size; i++) {	//populate character array from string
			char_arr[i] = a[i];
		}
		Suffixes=new char*[Size];		//build matrix of suffixes
		for(int i=0;i<Size;i++)
			Suffixes[i]=new char[Size];
	}
	void build_Suffix() {
		string suffix;
		int row_suffix=0;
		for(int j=0;j<Size;j++ ,row_suffix++ ){
			suffix = "";
			for (int i = Size-j-1; i <Size; i++) {
				suffix += char_arr[i];
			}
			for(int k=0, column_suffix=0;k<suffix.size();k++, column_suffix++){
				Suffixes[row_suffix][column_suffix]=suffix[k];
			}
		}
		
	}
	void printSuffixes() {
		for (int i = 0; i <Size; i++) {	//for rows
			int j = 0;
			for(;j<Size;j++){	//for columns
				if (Suffixes[i][j] != '$')
					cout << Suffixes[i][j];
				else break;
			}
			cout<<Suffixes[i][j]<<endl; //print sentinal
		}	
	}
};