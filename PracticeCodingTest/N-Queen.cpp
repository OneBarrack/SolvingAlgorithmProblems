#include <iostream>
// 프로그래머스 코딩테스트 연습 
// Lv.3 - N-Queen

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

void DFS(int n, int depth, int& answer, int prevQueen, vector<tuple<int, int, int>> queensList = vector<tuple<int, int, int>>())
{
    if ( n == depth )
    {
        ++answer;
        return;
    }

    vector<int> rowBoard(n);
    tuple<int, int, int> queens = make_tuple(prevQueen, prevQueen, prevQueen);
    queensList.push_back(queens);

    for ( auto& queens : queensList )
    {
        int& left = get<0>(queens);
        int& mid = get<1>(queens);
        int& right = get<2>(queens);

        if ( left > 0 ) rowBoard[--left] = 1;
        rowBoard[mid] = 1;
        if ( right < n - 1 ) rowBoard[++right] = 1;
    }

    for ( int i = 0; i < n; ++i )
    {
        if ( rowBoard[i] == 1 )
            continue;

        DFS(n, depth + 1, answer, i, queensList);
    }
}

int solution(int n)
{
    int answer = 0;

    for ( int i = 0; i < n; ++i )
        DFS(n, 1, answer, i);

    return answer;
}

int main()
{
    int n = 4;
    cout << solution(n) << endl;

    return 0;
}