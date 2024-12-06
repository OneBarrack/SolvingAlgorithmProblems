#include <iostream>
// 프로그래머스 코딩테스트 연습 
// 연습문제. 숫자 변환하기

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

int solution(int x, int y, int n) {
    if (x == y)
        return 0;

    int answer = 0;

    set<int> xSet;
    xSet.insert(x);

    while (!xSet.empty())
    {
        set<int> tempSet;

        for (int tempX : xSet)
        {
            if (tempX >= y)
            {
                if (tempX == y)
                {
                    return answer;
                }

                continue;
            }

            tempSet.insert(tempX + n);
            tempSet.insert(tempX * 2);
            tempSet.insert(tempX * 3);
        }

        xSet = tempSet;
        ++answer;
    }

    return -1;
}

int main()
{
    int x = 10;
    int y = 40;
    int n = 5;

    cout << solution(10, 40, 5) << endl;

    return 0;
}
