#include <iostream>
// 프로그래머스 코딩테스트 연습 
// Lv2. 최댓값과 최솟값

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

using namespace std;

string solution(string s)
{
    int minNum = INT_MAX;
    int maxNum = INT_MIN;
    stringstream ss(s);
    while ( getline(ss, s, ' ') )
    {
        minNum = min(minNum, stoi(s));
        maxNum = max(maxNum, stoi(s));
    }
    return to_string(minNum) + " " + to_string(maxNum);
}

int main()
{
    string s = "-1 -2 -3 -4";
    cout << solution(s) << endl;

    return 0;
}