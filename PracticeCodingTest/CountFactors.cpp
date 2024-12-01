#include <iostream>
// Codility 코딩테스트 연습 
// Lesson 10 easy. CountFactors

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

int solution(int N) {
    if (N == 1)
        return 1;

    int answer = 0;
    for (long long i = 1; i * i <= N; i++)
    {
        if (i * i == N)
        {
            ++answer;
        }
        else if (N % i == 0)
        {
            answer += 2;
        }
    }

    return answer;
}

int main()
{
    int N = 15;

    cout << solution(15) << endl;

    return 0;
}
