#include <iostream>
// 프로그래머스 코딩테스트 연습 
// Lv.4 - 안티 세포

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
#include <numeric>

using namespace std;

void SearchAntiCellGroups(int n, vector<int> antiCells, vector<int> Y, int X, int i, int& resultCount)
{
    if ( !Y.empty() && Y.back() == X )
    {
        int tempX = Y.back() + X;
        vector<int> tempY = Y;
        tempY.pop_back();
        SearchAntiCellGroups(n, antiCells, tempY, tempX, i, resultCount);
    }

    if ( i == n - 1 )
    {
        ++resultCount;
        return;
    }

    Y.emplace_back(X);
    SearchAntiCellGroups(n, antiCells, Y, antiCells[i + 1], i + 1, resultCount);
}

vector<int> solution(vector<int> a, vector<int> s)
{
    vector<int> answer;

    int startPos = 0;
    for ( int& range : s )
    {
        int endPos = startPos + range;
        vector<int> antiCells(a.begin() + startPos, a.begin() + endPos);
        startPos = endPos;

        int resultCount = 0;
        SearchAntiCellGroups(antiCells.size(), antiCells, vector<int>(), antiCells[0], 0, resultCount);
        answer.emplace_back(resultCount);
    }

    return answer;
}

int main()
{
    vector<int> a = { 1, 1, 1, 1, 1, 1, 2, 5, 8, 2, 1, 1, 4, 8, 8, 8, 12, 6, 6 }; 
    vector<int> s = { 4, 3, 1, 5, 6 };

    vector<int> result = solution(a, s);
    for ( int res : result )
        cout << res << endl;

    return 0;
}