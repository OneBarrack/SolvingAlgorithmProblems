#include <iostream>
// 프로그래머스 코딩테스트 연습 
// Lv.2 - 숫자의 표현

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

int solution(int n)
{
    int answer = 0;
    for ( int baseNum = 1, varCount = 1; baseNum <= n; baseNum += ++varCount )
        if ( (n - baseNum) % varCount == 0 )
            ++answer;
    return answer;
}

int main()
{
    int n = 15;
    cout << solution(n) << endl;

    return 0;
}