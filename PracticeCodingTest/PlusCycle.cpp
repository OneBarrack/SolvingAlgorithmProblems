#include <iostream>
// 프로그래머스 코딩테스트 연습 
// Lv.Bronze1 - 1110. Plus Cycle

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
26
예제 출력 1
4
예제 입력 2
55
예제 출력 2
3
예제 입력 3
1
예제 출력 3
60
예제 입력 4
0
예제 출력 4
1
예제 입력 5
71
예제 출력 5
12
*/

int main()
{
    int inputNum;
    cin >> inputNum;

    int cycleLength = 0;
    int oldNum = inputNum;
    int newNum = -1;
    
    while ( inputNum != newNum )
    {
        int leftOldNum = oldNum / 10;
        int rightOldNum = oldNum % 10;
        newNum = (rightOldNum * 10) + ((leftOldNum + rightOldNum) % 10);
        oldNum = newNum;
        ++cycleLength;
    }

    cout << cycleLength;

    return 0;
}