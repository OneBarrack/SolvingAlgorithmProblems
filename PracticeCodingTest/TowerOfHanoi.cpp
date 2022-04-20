#include <iostream>
// 프로그래머스 코딩테스트 연습 
// Lv.3 - 하노이의 탑

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

void Hanoi(vector<vector<int>>& answer, int n, int from, int to, int via)
{
    if ( n == 1 )
    {
        answer.push_back({ from, to });
        return;
    }

    Hanoi(answer, n - 1, from, via, to);
    answer.push_back({ from, to });
    Hanoi(answer, n - 1, via, to, from);
}

vector<vector<int>> solution(int n)
{
    vector<vector<int>> answer;
    Hanoi(answer, n, 1, 3, 2);
    return answer;
}

int main()
{
    int n = 5;

    vector<vector<int>> result = solution(n);
    for ( vector<int> res : result )
        cout << res[0] << " > " << res[1] << endl;

    return 0;
}