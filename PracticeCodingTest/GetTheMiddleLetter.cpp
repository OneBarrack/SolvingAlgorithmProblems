#include <iostream>
// 프로그래머스 코딩테스트 연습 
// Lv1. 가운데 글자 가져오기

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

using namespace std;

string solution(string s)
{
    return (s.size() % 2 == 1) ? s.substr(s.size() / 2, 1) : s.substr(s.size() / 2 - 1, 2);
}

int main()
{
    string s = "abcde";
    cout << solution(s) << endl;

    return 0;
}