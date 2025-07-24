#include <iostream>
// 프로그래머스 연습문제 : 디펜스 게임
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
#include <numeric>

using namespace std;

int solution(int n, int k, vector<int> enemy) {
    multiset<int, greater<int>> defendedEnemies;
    
    int soldierCount = n;
    int round = 0;
    while (round < enemy.size())
    {
        const int enemyCount = enemy[round];

        if (enemyCount <= soldierCount)
        {
            defendedEnemies.insert(enemyCount);
            soldierCount -= enemyCount;
        }
        else if (k > 0)
        {
            if (!defendedEnemies.empty() && *defendedEnemies.begin() > enemyCount)
            {
                soldierCount += *defendedEnemies.begin() - enemyCount;
                defendedEnemies.erase(defendedEnemies.begin());
                defendedEnemies.insert(enemyCount);
            }

            k--;
        }
        else
        {
            break;
        }

        round++;
    }

    return round;
}

int main(void) {
    //int n = 7;
    //int k = 3;
    //vector<int> enemy = {4, 2, 4, 5, 3, 3, 1};

    //int n = 2;
    //int k = 4;
    //vector<int> enemy = {3, 3, 3, 3};

    int n = 5;
    int k = 1;
    vector<int> enemy = {3, 1, 1, 1, 2, 2, 10};

    //vector<int> result = solution(begin, end);
    //for (int res : result)
    //    cout << res << endl;

    cout << solution(n, k, enemy) << endl;

    return 0;
}
