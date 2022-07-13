#include <iostream>
// 프로그래머스 코딩테스트 연습 
// Lv.Bronze4 - Test Score

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
* 예제 입력 1 
100 80 70 60
80 70 80 90
예제 출력 1 
320
예제 입력 2 
100 80 70 60
80 70 60 100
예제 출력 2 
310
*/

int main()
{
    int minkookScore = 0;
    int mansaeScore = 0;

    for ( int i = 0; i < 4; ++i )
    {
        int score;
        cin >> score;
        minkookScore += score;
    }
    for ( int i = 0; i < 4; ++i )
    {
        int score;
        cin >> score;
        mansaeScore += score;
    }

    if ( minkookScore >= mansaeScore )
        cout << minkookScore;
    else
        cout << mansaeScore;

    return 0;
}