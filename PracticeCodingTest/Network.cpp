#include <iostream>
// 프로그래머스 코딩테스트 연습 
// Lv3 네트워크

#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

void CheckConnect(int id, vector<vector<int>> computers, vector<bool>& visit)
{
    visit[id] = true;

    vector<int> comNetwork = computers[id];
    for ( int i = 0; i < comNetwork.size(); ++i )
    {
        if ( visit[i] || comNetwork[i] == 0 )
            continue;

        CheckConnect(i, computers, visit);
    }
}

int solution(int n, vector<vector<int>> computers)
{
    int answer = 0;
    vector<bool> visit(n, false);

    for ( int i = 0; i < n; ++i )
    {
        if ( visit[i] )
            continue;

        CheckConnect(i, computers, visit);
        ++answer;
    }

    return answer;
}

int main()
{
    int n = 3;
    vector<vector<int>> computers = { {1, 1, 0} ,{1, 1, 0},{0, 0, 1} };
    //vector<vector<int>> computers = { {1, 1, 0} ,{1, 1, 1},{0, 1, 1} };

    cout << solution(3, computers) << endl;

    return 0;
}