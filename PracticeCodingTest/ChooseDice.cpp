#include <iostream>
// 프로그래머스 2024 KAKAO WINTER INTERNSHIP : 주사위 고르기
// 3

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

void SumDice(map<int, int>& sumDiceMap, vector<vector<int>>& diceList, int& resultSum, int currentDiceIndex)
{
    if (currentDiceIndex == diceList.size())
    {
        sumDiceMap[resultSum]++;
        return;
    }

    for (int dice : diceList[currentDiceIndex])
    {
        int sum = resultSum + dice;
        SumDice(sumDiceMap, diceList, sum, currentDiceIndex + 1);
    }
}

map<int, int> GetSumResults(vector<vector<int>>& diceList)
{
    map<int, int> sumDiceMap;

    if (!diceList.empty())
    {
        int resultSum = 0;
        SumDice(sumDiceMap, diceList, resultSum, 0);
    }

    return sumDiceMap;
}

vector<int> solution(vector<vector<int>> dice) {
    vector<int> answer;
    map<int, vector<int>, greater<int>> DiceCombinationByWinCount;

    vector<bool> checkArr(dice.size(), true);
    fill(checkArr.begin(), checkArr.begin() + (dice.size() / 2), false);

    do {
        vector<vector<int>> diceListA;
        vector<vector<int>> diceListB;

        vector<int> diceIndexListA;
        for (int i = 0; i < checkArr.size(); i++)
        {
            if (!checkArr[i])
            {
                // A
                diceListA.push_back(dice[i]);
                diceIndexListA.push_back(i + 1);
            }
            else
            {
                // B
                diceListB.push_back(dice[i]);
            }
        }

        map<int, int> sumDiceMapA = GetSumResults(diceListA);
        map<int, int> sumDiceMapB = GetSumResults(diceListB);

        int totalWinCount = 0;
        for (auto resultSumA : sumDiceMapA)
        {
            int sumA = resultSumA.first;
            int countA = resultSumA.second;

            int winCount = 0;
            for (auto resultSumB : sumDiceMapB)
            {
                int sumB = resultSumB.first;
                int countB = resultSumB.second;

                if (sumA > sumB)
                {
                    winCount += countB;
                }
            }

            totalWinCount += winCount * countA;
        }

        DiceCombinationByWinCount[totalWinCount] = diceIndexListA;

    } while (next_permutation(checkArr.begin(), checkArr.end()));

    if (!DiceCombinationByWinCount.empty())
    {
        answer = DiceCombinationByWinCount.begin()->second;
    }

    return answer;
}

int main(void) {
    //vector<vector<int>> dice = {{1, 2, 3, 4, 5, 6} ,{3, 3, 3, 3, 4, 4}, {1, 3, 3, 4, 4, 4}, {1, 1, 4, 4, 5, 5}};
    vector<vector<int>> dice = {{1, 2, 3, 4, 5, 6} ,{2, 2, 4, 4, 6, 6}};

    solution(dice);
    //cout << solution(dice) << endl;

    return 0;
}
