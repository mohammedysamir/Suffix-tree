#include<vector>
using namespace std;
class Node{
char value;
vector<Node*> Children;
public:
Node(char v){
value=v;
}
Node(){
    value=' ';
}
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

};