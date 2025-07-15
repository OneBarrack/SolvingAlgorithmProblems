#include <iostream>
// 프로그래머스 [PCCP 기출문제] 2번 / 석유 시추
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

bool CalcOilLumpSize(vector<vector<int>>& land, vector<vector<int>>& oilNumbers, map<int, int>& oilLumpSizes, int row, int col, int oilNumber)
{
    if (land[row][col] == 0 || oilNumbers[row][col] > 0)
        return false;

    oilNumbers[row][col] = oilNumber;
    oilLumpSizes[oilNumber]++;

    // 상
    if (row > 0)
    {
        CalcOilLumpSize(land, oilNumbers, oilLumpSizes, row - 1, col, oilNumber);
    }

    // 하
    if (row < land.size() - 1)
    {
        CalcOilLumpSize(land, oilNumbers, oilLumpSizes, row + 1, col, oilNumber);
    }

    // 좌
    if (col > 0)
    {
        CalcOilLumpSize(land, oilNumbers, oilLumpSizes, row, col - 1, oilNumber);
    }

    // 우
    if (col < land[row].size() - 1)
    {
        CalcOilLumpSize(land, oilNumbers, oilLumpSizes, row, col + 1, oilNumber);
    }

    return true;
}

int GetLargestAmountOfOil(vector<vector<int>>& land, vector<vector<int>>& oilNumbers, map<int, int>& oilLumpSizes)
{
    int largestAmountOfOil = 0;

    for (int col = 0; col < land[0].size(); col++)
    {
        set<int> extractedOilNumbers;
        for (int row = 0; row < land.size(); row++)
        {
            int oilNumber = oilNumbers[row][col];
            if (oilNumber > 0)
            {
                extractedOilNumbers.insert(oilNumber);
            }
        }

        int totalExtractedOilAmount = 0;
        for (int extractedOilNumber : extractedOilNumbers)
        {
            totalExtractedOilAmount += oilLumpSizes[extractedOilNumber];
        }

        largestAmountOfOil = max(largestAmountOfOil, totalExtractedOilAmount);
    }

    return largestAmountOfOil;
}

int solution(vector<vector<int>> land) {
    vector<vector<int>> oilNumbers(land.size(), vector<int>(land[0].size()));
    map<int, int> oilLumpSizes;

    int oilNumber = 1;
    for (int row = 0; row < land.size(); row++)
    {
        for (int col = 0; col < land[0].size(); col++)
        {
            if (CalcOilLumpSize(land, oilNumbers, oilLumpSizes, row, col, oilNumber))
            {
                oilNumber++;
            }
        }
    }

    return GetLargestAmountOfOil(land, oilNumbers, oilLumpSizes);
}

int main(void) {
    //vector<vector<int>> land = {
    //    {0, 0, 0, 1, 1, 1, 0, 0},
    //    {0, 0, 0, 0, 1, 1, 0, 0},
    //    {1, 1, 0, 0, 0, 1, 1, 0},
    //    {1, 1, 1, 0, 0, 0, 0, 0},
    //    {1, 1, 1, 0, 0, 0, 1, 1}
    //};

    vector<vector<int>> land = {
        {1, 0, 1, 0, 1, 1},
        {1, 0, 1, 0, 0, 0},
        {1, 0, 1, 0, 0, 1},
        {1, 0, 0, 1, 0, 0},
        {1, 0, 0, 1, 0, 1},
        {1, 0, 0, 0, 0, 0},
        {1, 1, 1, 1, 1, 1}
    };

    cout << solution(land) << endl;

    return 0;
}
