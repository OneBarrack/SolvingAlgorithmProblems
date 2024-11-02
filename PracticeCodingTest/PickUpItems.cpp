#include <iostream>
//// 프로그래머스 코딩테스트 연습 
//// Lv3. 아이템 줍기

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

void DFS(vector<vector<vector<int>>> rectPosList, int characterX, int characterY, int itemX, int itemY, vector<vector<bool>> movePath, int moveCount, int& answer)
{
    if (movePath[characterX][characterY] == true)
        return;

    movePath[characterX][characterY] = true;
    ++moveCount;

    if (characterX == itemX && characterY == itemY)
    {
        answer = min(answer, moveCount);
        return;
    }

    for (vector<vector<int>> rectPos : rectPosList)
    {
        vector<int> p1 = rectPos[0];
        vector<int> p2 = rectPos[1];
        vector<int> p3 = rectPos[2];
        vector<int> p4 = rectPos[3];

        if ((p1[0] == characterX && (p1[1] <= characterY && characterY < p2[1])) ||
            (p2[1] == characterY && (p2[0] <= characterX && characterX < p3[0])) ||
            (p3[0] == characterX && (p3[1] >= characterY && characterY > p4[1])) ||
            (p4[1] == characterY && (p4[0] >= characterX && characterX > p1[0])))
        {
            for (vector<vector<int>> rectPos : rectPosList)
            {
                vector<int> p1 = rectPos[0];
                vector<int> p3 = rectPos[2];

                if ((p1[0] < characterX && characterX < p3[0]) && (p1[1] < characterY && characterY < p3[1]))
                {
                    return;
                }
            }
            
            DFS(rectPosList, characterX - 1, characterY, itemX, itemY, movePath, moveCount, answer);
            DFS(rectPosList, characterX + 1, characterY, itemX, itemY, movePath, moveCount, answer);
            DFS(rectPosList, characterX, characterY - 1, itemX, itemY, movePath, moveCount, answer);
            DFS(rectPosList, characterX, characterY + 1, itemX, itemY, movePath, moveCount, answer);

            break;
        }
    }
}

int solution(vector<vector<int>> rectangle, int characterX, int characterY, int itemX, int itemY) {
    int answer = INT_MAX;
    vector<vector<vector<int>>> rectPosList;

    for (vector<int> r : rectangle)
    {
        vector<vector<int>> rectPos;
        rectPos.push_back({r[0] * 2, r[1] * 2});
        rectPos.push_back({r[0] * 2, r[3] * 2});
        rectPos.push_back({r[2] * 2, r[3] * 2});
        rectPos.push_back({r[2] * 2, r[1] * 2});

        rectPosList.push_back(rectPos);
    }

    vector<vector<bool>> movePath(100, vector<bool>(100));
    DFS(rectPosList, characterX * 2, characterY * 2, itemX * 2, itemY * 2, movePath, -1, answer);

    return answer / 2;
}

int main()
{
    vector<vector<int>> rectangle = { {1,1,7,4}, {3,2,5,5}, {4,3,6,9}, {2,6,8,8} };
    int characterX = 1;
    int characterY = 3;
    int itemX = 7;
    int itemY = 8;

    //vector<vector<int>> rectangle = {{1,1,8,4} ,{2,2,4,9}, {3,6,9,8}, {6,3,7,7}};
    //int characterX = 9;
    //int characterY = 7;
    //int itemX = 6;
    //int itemY = 1;

    //vector<vector<int>> rectangle = {{1,1,5,7}};
    //int characterX = 1;
    //int characterY = 1;
    //int itemX = 4;
    //int itemY = 7;

    //vector<vector<int>> rectangle = {{2,1,7,5} ,{6,4,10,10}};
    //int characterX = 3;
    //int characterY = 1;
    //int itemX = 7;
    //int itemY = 10;

    //vector<vector<int>> rectangle = {{2,2,5,5} ,{1,3,6,4}, {3,1,4,6}};
    //int characterX = 1;
    //int characterY = 4;
    //int itemX = 6;
    //int itemY = 3;

    cout << solution(rectangle, characterX, characterY, itemX, itemY) << endl;

    return 0;
}
