#include <iostream>
// 프로그래머스 코딩테스트 연습 
// 연습문제. 덧칠하기

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

int solution(int n, int m, vector<int> section) {
    int answer = 0;

    int curPos = 0;
    for (int& sec : section)
    {
        if (curPos < sec)
        {
            ++answer;
            curPos = sec + m - 1;
        }
    }

    return answer;
}

int main()
{
    int n = 8;
    int m = 4;
    vector<int> section = {2, 3, 6};

    cout << solution(n, m, section) << endl;

    return 0;
}
