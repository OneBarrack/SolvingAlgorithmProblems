#include <iostream>
//// 프로그래머스 코딩테스트 연습 
//// Lv.Gold3 - ACM Craft

#include <string>
#include <vector>
#include <queue>
#include <set>
#include <algorithm>
#include <unordered_map>
#include <numeric>
#include <stack>
#include <map>

#define _CRTDBG_MAP_ALLOC

using namespace std;

string solution(vector<int> food) {
    string answer = "";

    string Player1 = "";
    string Player2 = "";

    for (int i = 1; i < food.size(); i++)
    {
        if (food[i] < 2)
            continue;

        for (int j = 0; j < food[i] / 2; j++)
        {
            Player1 += to_string(i);
            Player2 += to_string(i);
        }
    }

    reverse(Player2.begin(), Player2.end());

    answer += Player1;
    answer += "0";
    answer += Player2;

    return answer;
}

int main() {
    vector<int> food = {1, 3, 4, 6};
    cout << solution(food) << endl;

    return 0;
}