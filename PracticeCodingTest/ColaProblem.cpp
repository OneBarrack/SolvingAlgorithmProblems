#include <iostream>
// 프로그래머스 코딩테스트 연습 
// 연습문제. 콜라 문제

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

int solution(int a, int b, int n) {
    int answer = 0;

    while (n >= a)
    {
        int reward = n / a * b;
        answer += reward;

        n = reward + (n % a);
    }

    return answer;
}

int main()
{
    int a = 2;
    int b = 1;
    int n = 20;

    cout << solution(a, b, n) << endl;

    return 0;
}
