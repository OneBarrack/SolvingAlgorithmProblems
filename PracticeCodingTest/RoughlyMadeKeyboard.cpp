#include <iostream>
// 프로그래머스 코딩테스트 연습 
// 연습문제. 대충 만든 자판

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

vector<int> solution(vector<string> keymap, vector<string> targets) {
    vector<int> keyCounts(26, INT_MAX);
    for (string& key : keymap)
    {
        for (int i = 0; i < key.length(); i++)
        {
            int keyIndex = key[i] - 'A';
            keyCounts[keyIndex] = min(keyCounts[keyIndex], i + 1);
        }
    }

    vector<int> answer;
    for (string& target : targets)
    {
        int clickCount = 0;
        for (int i = 0; i < target.length(); i++)
        {
            int keyIndex = target[i] - 'A';
            if (keyCounts[keyIndex] == INT_MAX)
            {
                clickCount = -1;
                break;
            }

            clickCount += keyCounts[keyIndex];
        }

        answer.push_back(clickCount);
    }

    return answer;
}

int main()
{
    vector<string> keymap = {"ABACD", "BCEFD"};
    vector<string> targets = {"ABCD", "AABB"};

    vector<int> result = solution(keymap, targets);

    for (int res : result)
        cout << res << endl;

    return 0;
}
