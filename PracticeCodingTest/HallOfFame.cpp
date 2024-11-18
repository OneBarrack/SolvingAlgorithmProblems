#include <iostream>
// 프로그래머스 코딩테스트 연습 
// 연습문제. 문자열 나누기

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

vector<int> solution(int k, vector<int> score) {
    vector<int> answer;

    multiset<int, greater<int>> highestScores;
    for (int& num : score)
    {
        highestScores.insert(num);
        if (highestScores.size() > k)
        {
            highestScores.erase(--highestScores.end());
        }

        answer.push_back(*highestScores.rbegin());
    }

    return answer;
}

int main()
{
    int k = 3;
    vector<int> score = {10, 100, 20, 150, 1, 100, 200};

    vector<int> result = solution(k, score);
    for (int res : result)
        cout << res << endl;

    return 0;
}
