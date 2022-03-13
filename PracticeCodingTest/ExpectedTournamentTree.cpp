#include <iostream>
// 프로그래머스 코딩테스트 연습 
// Lv2 예상 대진표

#include <string>
#include <list>
#include <vector>
#include <queue>
#include <algorithm>
#include <stack>
#include <set>
#include <map>
#include <unordered_map>

using namespace std;

bool IsEven(int n)
{
    return (n % 2 == 0) ? true : false;
}

int solution(int n, int a, int b)
{
    int answer = 1;

    while ( true )
    {
        if ( !IsEven(a) ) ++a;
        if ( !IsEven(b) ) ++b;

        if ( a == b )
            break;

        a /= 2;
        b /= 2;
        ++answer;
    }

    return answer;
}

int main()
{
    int n= 8;
    int a = 4;
    int b = 7;
    cout << solution(n, a, b) << endl;

    return 0;
}