#include <iostream>
// 해커랭크 코딩테스트 연습 
// Lv Easy. Staircase

#include <string>
#include <list>
#include <vector>
#include <queue>
#include <algorithm>
#include <stack>
#include <set>
#include <map>
#include <unordered_map>
#include <numeric>

using namespace std;

void staircase(int n)
{
    for ( int i = 1; i <= n; ++i )
    {
        string s = "";
        s.append(n - i, ' ');
        s.append(i, '#');
        cout << s << endl;
    }
}

int main()
{
    int n = 6;
    staircase(n);

    return 0;
}