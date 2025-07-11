#include <iostream>
// 프로그래머스 코드챌린지 2차 예선 : 지게차와 크레인
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

void CleanUp(vector<string>& storage, vector<vector<bool>>& openedStorage, int row, int col)
{
    if (openedStorage[row][col] && storage[row][col] == '-')
    {
        // 상
        if (row > 0 && !openedStorage[row - 1][col])
        {
            openedStorage[row - 1][col] = true;
            CleanUp(storage, openedStorage, row - 1, col);
        }

        // 하
        if (row < storage.size() - 1 && !openedStorage[row + 1][col])
        {
            openedStorage[row + 1][col] = true;
            CleanUp(storage, openedStorage, row + 1, col);
        }

        // 좌
        if (col > 0 && !openedStorage[row][col - 1])
        {
            openedStorage[row][col - 1] = true;
            CleanUp(storage, openedStorage, row, col - 1);
        }

        // 우
        if (col < storage[row].size() - 1 && !openedStorage[row][col + 1])
        {
            openedStorage[row][col + 1] = true;
            CleanUp(storage, openedStorage, row, col + 1);
        }
    }
}

void CleanUpAll(vector<string>& storage, vector<vector<bool>>& openedStorage)
{
    for (int row = 0; row < storage.size(); row++)
    {
        for (int col = 0; col < storage[0].size(); col++)
        {
            CleanUp(storage, openedStorage, row, col);
        }
    }
}

int solution(vector<string> storage, vector<string> requests) {
    int answer = 0;

    vector<vector<bool>> openedStorage(storage.size(), vector<bool>(storage[0].size(), false));

    for (int i = 0; i < openedStorage.size(); i++)
    {
        if (i == 0 || i == openedStorage.size() - 1)
        {
            fill(openedStorage[i].begin(), openedStorage[i].end(), true);
        }
        else
        {
            openedStorage[i][0] = true;
            openedStorage[i][openedStorage[i].size() - 1] = true;
        }
    }

    for (string& req : requests)
    {
        for (int i = 0; i < storage.size(); i++)
        {
            for (int j = 0; j < storage[0].size(); j++)
            {
                if (req[0] == storage[i][j])
                {
                    if (req.length() == 1 && !openedStorage[i][j])
                        continue;

                    storage[i][j] = '-';
                }
            }
        }

        CleanUpAll(storage, openedStorage);
    }

    for (string& str : storage)
    {
        answer += str.size() - count(str.begin(), str.end(), '-');
    }

    return answer;
}

int main(void) {
    vector<string> storage = {"AZWQY", "CAABX", "BBDDA", "ACACA"};
    vector<string> requests = {"A", "BB", "A"};

    cout << solution(storage, requests) << endl;

    return 0;
}
