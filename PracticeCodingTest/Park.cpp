#include <iostream>
// 프로그래머스 코딩테스트 연습 
// [PCCP 기출문제] 10번 / 공원

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

void Search(vector<vector<string>>& park, int x, int y, const int maxMatLen, int depth, int& answer)
{
    if (maxMatLen < depth + 1 || !(x + depth < park.size() && y + depth < park[0].size()))
        return;

    for (int i = 0; i < depth; i++)
    {
        if (park[x + i][y + depth] != "-1")
            return;
    }

    for (int i = 0; i <= depth; i++)
    {
        if (park[x + depth][y + i] != "-1")
            return;
    }

    answer = max(answer, depth + 1);

    Search(park, x, y, maxMatLen, depth + 1, answer);
}

int solution(vector<int> mats, vector<vector<string>> park) {
    int answer = 0;
    sort(mats.begin(), mats.end());

    const int maxMatLen = mats.back();
    for (int i = 0; i < park.size(); i++)
    {
        for (int j = 0; j < park[0].size(); j++)
        {
            if (park[i][j] != "-1")
                continue;

            Search(park, i, j, maxMatLen, 0, answer);
        }
    }
    
    auto upperIter = upper_bound(mats.begin(), mats.end(), answer);
    answer = (upperIter == mats.begin()) ? -1 : *(--upperIter);

    return answer;
}

int main()
{
    vector<int> mats = {5, 3, 2};
    vector<vector<string>> park = {{"A", "A", "-1", "B", "B", "B", "B", "-1"},
        {"A", "A", "-1", "B", "B", "B", "B", "-1"},
        {"-1", "-1", "-1", "-1", "-1", "-1", "-1", "-1"},
        {"D", "D", "-1", "-1", "-1", "-1", "E", "-1"},
        {"D", "D", "-1", "-1", "-1", "-1", "-1", "F"},
        {"D", "D", "-1", "-1", "-1", "-1", "E", "-1"}};

    cout << solution(mats, park) << endl;

    return 0;
}
