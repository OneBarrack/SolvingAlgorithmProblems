#include <iostream>
// 프로그래머스 연습문제 : 택배상자
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

int solution(vector<int> order) {
    int answer = 0;
    stack<int> subBelt;

    int mainBeltBox = 1;
    for (int& target : order)
    {
        while (mainBeltBox < target)
        {
            subBelt.push(mainBeltBox);
            mainBeltBox++;
        }

        if (mainBeltBox == target)
        {
            mainBeltBox++;
        }
        else if (!subBelt.empty() && subBelt.top() == target)
        {
            subBelt.pop();
        }
        else
        {
            break;
        }

        answer++;
    }

    return answer;
}

int main(void) {
    //vector<int> order = {4, 3, 1, 2, 5};
    vector<int> order = {5, 4, 3, 2, 1};

    cout << solution(order) << endl;

    return 0;
}
