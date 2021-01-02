#include<cstring>
#include <iostream>
#include"SuffixTrie.cpp"
using namespace std;
int main()
{
    // Construct a suffix trie containing all suffixes of "bananabanaba$"

    //            0123456789012
    SuffixTrie t("bananabanaba$");
    t.Search("ana"); // Prints: 1 3 7
	t.Search("naba"); // Prints: 4 8

    return 0;
}
