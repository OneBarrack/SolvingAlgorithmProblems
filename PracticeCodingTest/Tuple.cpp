#include <iostream>
// 프로그래머스 코딩테스트 연습 
// Lv2 튜플

#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <sstream>
#include <set>

using namespace std;

bool compareTuple(vector<int>& a, vector<int>& b)
{
    return a.size() < b.size();
}

vector<int> solution(string s)
{    
    vector<int> answer;
    vector<vector<int>> tuple;

    s.erase(s.begin());
    s.erase(s.end() - 1);
    stringstream ss(s);
    string tupleElem;
    while ( getline(ss, tupleElem, '{') && getline(ss, tupleElem, '}') )
    {
        vector<int> subTuple;
        stringstream sss(tupleElem);
        string subTupleElem;

        while ( getline(sss, subTupleElem, ',') )
        {
            subTuple.emplace_back(stoi(subTupleElem));
        }
        if ( !subTuple.empty() )
        {
            tuple.emplace_back(subTuple);
        }
    }

    sort(tuple.begin(), tuple.end(), compareTuple);

    for ( auto subTuple : tuple )
    {
        for ( int elem : subTuple )
        {
            if ( find(answer.begin(), answer.end(), elem) == answer.end() )
            {
                answer.emplace_back(elem);
            }
        }
    }

    return answer;
}

int main()
{
    string s = "{{2},{2,1,3},{2,1},{2,1,3,4}}";

    vector<int> result = solution(s);

    for ( int res : result )
        cout << res << endl;

    return 0;
}