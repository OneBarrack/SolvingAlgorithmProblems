#include <iostream>
// 프로그래머스 코드챌린지 1차 예선 : 비밀 코드 해독
// 2

#include <string>
#include <list>
#include <vector>
#include <queue>
#include <algorithm>
#include <stack>
#include <set>
#include <map>
#include <unordered_map>
#include <sstream>

using namespace std;

int solution(int n, vector<vector<int>> q, vector<int> ans) {
    constexpr int maxSecretCodeSize = 5;
    int answer = 0;

    vector<int> numList;
    for (int i = 0; i < n; i++)
    {
        numList.push_back(i + 1);
    }

    vector<bool> checkArr(n, true);
    fill(checkArr.begin(), checkArr.begin() + maxSecretCodeSize, false);

    do {
        vector<int> extractedNums;
        for (int i = 0; i < n; i++)
        {
            if (!checkArr[i])
            {
                extractedNums.push_back(numList[i]);
            }
        }

        bool bFoundSecretCode = true;
        for (int i = 0; i < q.size(); i++)
        {
            int matchedNumCount = 0;
            for (int& extractedNum : extractedNums)
            {
                if (find(q[i].begin(), q[i].end(), extractedNum) != q[i].end())
                {
                    matchedNumCount++;
                }
            }

            if (matchedNumCount != ans[i])
            {
                bFoundSecretCode = false;
                break;
            }
        }

        if (bFoundSecretCode)
        {
            answer++;
        }

    } while (next_permutation(checkArr.begin(), checkArr.end()));

    return answer;
}

int main(void) {
    int n = 15;
    vector<vector<int>> q = {{2, 3, 9, 12, 13} ,{1, 4, 6, 7, 9}, {1, 2, 8, 10, 12}, {6, 7, 11, 13, 15}, {1, 4, 10, 11, 14}};
    vector<int> ans = {2, 1, 3, 0, 1};

    cout << solution(n, q, ans) << endl;

    return 0;
}
