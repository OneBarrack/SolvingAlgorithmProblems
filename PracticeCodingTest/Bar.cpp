#include <iostream>
// 프로그래머스 코딩테스트 연습 
// Lv.Silver5 - Bar

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
23
예제 출력 1
4
예제 입력 2
32
예제 출력 2
1
예제 입력 3
64
예제 출력 3
1
예제 입력 4
48
예제 출력 4
2
*/

int main()
{   
    int X;
    cin >> X;
    
    priority_queue<int, vector<int>, greater<int>> bars;
    int totalLength = 64;
    bars.push(totalLength);

    while ( totalLength != X )
    {
        int minLength = bars.top() / 2;
        bars.pop();

        bars.push(minLength);
        if ( totalLength - minLength < X )
            bars.push(minLength);
        else
            totalLength -= minLength;
    }

    cout << bars.size();

    return 0;
}