#include<vector>
using namespace std;
class Node{
char value;
int row_Suffix;
public:
vector<Node*> Children;
Node(char v , int row){
value=v;
row_Suffix = row;		//its number in matrix

}
Node(){}
void addchild(Node* c){
    Children.push_back(c);
}
Node* FindChild(char start){    //find child with start char of prefix
    for(int i=0;i<Children.size();i++){
        if(Children.at(i)->value==start)
            return Children.at(i);
    }
    return NULL;
}
int getRow() {
	return row_Suffix;
}
char getValue() {
	return value;
}
};