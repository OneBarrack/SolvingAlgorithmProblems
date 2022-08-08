#include <iostream>
// 프로그래머스 코딩테스트 연습 
// Lv.Bronze4 - 2480. Three Dice

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
3 3 6
예제 출력 1
1300
예제 입력 2
2 2 2
예제 출력 2
12000
예제 입력 3
6 2 5
예제 출력 3
600
*/

int main()
{
    int price = 0;

    vector<int> dices(3);
    cin >> dices[0] >> dices[1] >> dices[2];

    if ( dices[0] == dices[1] && dices[0] == dices[2] )
    {
        price = 10000 + (dices[0] * 1000);
    }
    else if ( dices[0] == dices[1] || dices[0] == dices[2] )
    {
        price = 1000 + (dices[0] * 100);
    }
    else if ( dices[1] == dices[2] )
    {
        price = 1000 + (dices[1] * 100);
    }
    else
    {
        price = *max_element(dices.begin(), dices.end()) * 100;
    }

    cout << price;

    return 0;
}