#include <iostream>
// 프로그래머스 코딩테스트 연습 
// Lv2 멀쩡한 사각형

#include <string>
#include <list>
#include <vector>
#include <queue>
#include <algorithm>
#include <stack>
#include <set>
#include <map>

using namespace std;

long long solution(int w, int h)
{
    int cuttedSquare = 0;
    for ( int i = 0; i < w; ++i )
    {
        cuttedSquare += ceil((double)h * (i + 1) / w) - floor((double)h * i / w);
    }

    return (long long)w * h - cuttedSquare;
}

int main()
{
    int w = 8;
    int h = 12;

    cout << solution(w, h) << endl;

    return 0;
}