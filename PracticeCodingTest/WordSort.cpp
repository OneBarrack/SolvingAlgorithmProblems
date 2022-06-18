#include <iostream>
// 백준 코딩테스트 연습 
// Lv.Silver5 - Word Sort

#include <string>
#include <list>
#include <vector>
#include <queue>
#include <algorithm>
#include <stack>
#include <set>
#include <map>
#include <unordered_map>
#include <sstream>
#include <numeric>

using namespace std;

/*
13
but
i
wont
hesitate
no
more
no
more
it
cannot
wait
im
yours
*/
int main()
{
    int N;
    cin >> N;

    map<int, set<string>> wordsForSize;
    for ( int i = 0; i < N; ++i )
    {
        string word;
        cin >> word;
        wordsForSize[word.size()].insert(word);
    }

    for ( auto words : wordsForSize )
        for ( string word : words.second )
            cout << word << "\n";

    return 0;
}