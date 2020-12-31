#include<cstring>
#include <iostream>
#include"SuffixTree.cpp"
using namespace std;
int main()
{
	string original;
	cout << "enter String to build Suffix Tree" << endl;
	cin >> original;
	original += '$';	//add sentinal
	int Size = original.size();
	SuffixTree st(Size,original); //initialize character array
	st.build_Suffix();
	st.printSuffixes();
}
