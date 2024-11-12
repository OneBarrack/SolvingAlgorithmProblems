#include <iostream>
// 프로그래머스 코딩테스트 연습 
// Lv1. 카드 뭉치

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

string solution(vector<string> cards1, vector<string> cards2, vector<string> goal) {
    vector<string>::iterator card1 = cards1.begin();
    vector<string>::iterator card2 = cards2.begin();
    
    for (string& s : goal)
    {
        if (card1 != cards1.end() && *card1 == s)
            card1++;
        else if (card2 != cards2.end() && *card2 == s)
            card2++;
        else
            return "No";
    }

    return "Yes";
}

int main()
{
    vector<string> cards1 = {"i", "drink", "water"};
    vector<string> cards2 = {"want", "to"};
    vector<string> goal = {"i", "want", "to", "drink", "water"};

    cout << solution(cards1, cards2, goal) << endl;

    return 0;
}
