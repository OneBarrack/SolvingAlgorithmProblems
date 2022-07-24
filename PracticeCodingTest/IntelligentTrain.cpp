#include <iostream>
// 프로그래머스 코딩테스트 연습 
// Lv.Bronze3 - 2455. Intelligent Train

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

/*
예제 입력 1
0 32
3 13
28 25
39 0
예제 출력 1
42
*/

int main()
{
    int maxPeopleCountInTrain = 0;
    int curPeopleCountInTrain = 0;

    for ( int i = 0; i < 4; ++i )
    {
        int outCount, inCount;
        cin >> outCount >> inCount;

        curPeopleCountInTrain -= outCount;
        curPeopleCountInTrain += inCount;

        maxPeopleCountInTrain = max(maxPeopleCountInTrain, curPeopleCountInTrain);
    }

    cout << maxPeopleCountInTrain;

    return 0;
}