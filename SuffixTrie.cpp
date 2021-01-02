#include<iostream>
#include<vector>
#include"Node.cpp"
using namespace std;
class SuffixTrie {
	int Size;	//Size of string + sentinal
	char* char_arr;	//Save character array
	char** Suffixes;//2D Array to store suffixes
	Node* root;

	void Insert(){
		for (int i = 0 ; i < Size; i++) {
			Node* temp = root;
			for (int j = 0; j < Size; j++) {
				if (Suffixes[i][j - 1] == '$')break; //prevent reading from empty indexes
				//search if the suffix[i][j] inserted before in the tree
				//if true , continue from this node
				if (temp->FindChild(Suffixes[i][j]) != NULL) {
					temp = temp->FindChild(Suffixes[i][j]);
					continue;
				}
				//else create new node to insert suffix[i][j] and continue from it
				else {
					//create new node contains begining of new suffix
					Node* newnode=new Node(Suffixes[i][j],i);
					temp->addchild(newnode);//add it to parent node
					temp = newnode;	//move pointer to it 
				}
			}
		}
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
	/*void printSuffixes() {
		for (int i = 0; i <Size; i++) {	//for rows
			int j = 0;
			for(;j<Size;j++){	//for columns
				if (Suffixes[i][j] != '$')
					cout << Suffixes[i][j];
				else break;
			}
			cout<<Suffixes[i][j]<<endl; //print sentinal
		}	
	}*/

	void Traverse(Node* temp, int length,int StringSize) {
		if (temp->Children.size()==0) { //leaf sentinal
			cout << StringSize-length <<" ";
			return;
		}
		for (int i = 0; i < temp->Children.size(); i++) {
			//cout << "value: " << temp->Children.at(i)->getValue() << endl;
			Traverse(temp->Children.at(i), length + 1, StringSize);
		}
	}
public:
	SuffixTrie(string a) {
		Size = a.size();
		char_arr =new char[Size];
		for (int i = 0; i <Size; i++) {	//populate character array from string
			char_arr[i] = a[i];
		}
		Suffixes=new char*[Size];		//build matrix of suffixes
		for(int i=0;i<Size;i++)
			Suffixes[i]=new char[Size];
			root = new Node();
			build_Suffix();	//prepare matrix of suffixes
			//printSuffixes();
			Insert();	//insert suffixes into tree
	}
	
	void Search(string s){
		Node* temp = root;
		for (int i = 0; i < s.size(); i++) {
			temp = temp->FindChild(s[i]); //Find node of suffix[i]
			if(temp== NULL)//suffix not found
			{
				cout << "This suffix isn't in the tree" << endl;
				return;
			}
		}
		//now temp at last index of suffix
		Node* traverse = temp;
		Traverse(traverse, s.size(), Size);//traverse each path to sentinal and print Size-PathLength
		cout << endl;
	}
};