#include <iostream>
// 프로그래머스 코딩테스트 연습 
// lv.1 - 시저 암호

#include <string>
#include <list>
#include <vector>
#include <queue>
#include <algorithm>
#include <stack>
#include <set>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <sstream>
#include <numeric>

using namespace std;

string solution(string s, int n)
{
    for ( char& c : s ) if ( isalpha(c) ) c = isupper(c) ? 'A' + (((c - 'A') + n) % 26) : 'a' + (((c - 'a') + n) % 26);
    return s;
}

int main()
{
    string s = "a B z";
    int n = 4;

    cout << solution(s, n) << endl;

    return 0;
}