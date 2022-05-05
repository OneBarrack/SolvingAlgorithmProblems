#include <iostream>
// 프로그래머스 코딩테스트 연습 
// Lv2. 압축

#include <string>
#include <list>
#include <vector>
#include <queue>
#include <algorithm>
#include <stack>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <sstream>
#include <numeric>
#include <cmath>
#include <cfloat>

using namespace std;

vector<int> solution(string msg)
{
    vector<int> answer;

    unordered_map<string, int> dic;
    int dicSize = 0;

    for ( int i = 0; i < 26; ++i )
    {
        string s = "";
        s += 'A' + i;
        dic.insert(make_pair(s, ++dicSize));
    }

    for ( int pos = 0; pos < msg.size(); )
    {
        int order;
        string word = "";
        word += msg[pos];

        while ( dic.find(word) != dic.end() )
        {
            order = dic[word];
            word += msg[++pos];
        }

        dic.insert(make_pair(word, ++dicSize));
        answer.emplace_back(order);
    }

    return answer;
}

int main()
{
    string msg = "TOBEORNOTTOBEORTOBEORNOT";
    vector<int> result = solution(msg);
    
    for ( int res : result )
        cout << res << endl;

    return 0;
}