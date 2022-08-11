#include <iostream>
// 프로그래머스 코딩테스트 연습 
// Lv.Bronze4 - 10039. Avarage Score

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
10
65
100
30
95
예제 출력 1
68
*/

int main()
{
    vector<int> score(5);
    for ( int i = 0; i < 5; ++i )
    {
        cin >> score[i];
        if ( score[i] < 40 )
            score[i] = 40;
    }

    cout << accumulate(score.begin(), score.end(), 0) / 5;

    return 0;
}