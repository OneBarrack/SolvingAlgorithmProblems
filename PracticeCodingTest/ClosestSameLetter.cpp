#include <iostream>
// 프로그래머스 코딩테스트 연습 
// 연습문제. 가장 가까운 같은 글자

#include <string>
#include <vector>
#include <queue>
#include <set>
#include <algorithm>
#include <unordered_map>
#include <numeric>
#include <stack>
#include <map>

using namespace std;

vector<int> solution(string s) {
    vector<int> answer;

    unordered_map<char, int> charMap;

    for (int i = 0; i < s.length(); i++)
    {
        char& c = s[i];

        if (charMap.find(c) == charMap.end())
        {
            answer.push_back(-1);
            charMap.insert(make_pair(c, i));
        }
        else
        {
            answer.push_back(i - charMap[c]);
            charMap[c] = i;
        }
    }

    return answer;
}

int main()
{
    string s = "banana";
    //string s = "foobar";

    vector<int> res = solution(s);

    for (int r : res)
        cout << r << " ";

    return 0;
}
