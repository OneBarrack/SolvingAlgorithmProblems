#include <iostream>
// 코딜리티 코딩테스트 연습 
// 연습문제. 숫자 짝궁

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

string solution(string X, string Y) {
    unordered_map<int, int> xMap;
    unordered_map<int, int> yMap;

    for (char& x : X)
    {
        xMap[x]++;
    }

    for (char& y : Y)
    {
        yMap[y]++;
    }

    string answer = "";
    for (int i = 9; i >= 0; i--)
    {
        int c = i + '0';
        int count = min(xMap[c], yMap[c]);

        answer.append(count, c);
    }

    if (answer.empty())
    {
        answer = "-1";
    }
    else if (answer[0] == '0')
    {
        answer = "0";
    }

    return answer;
}

int main()
{
    string X = "100";
    //string Y = "2345";
    string Y = "203045";

    cout << solution(X, Y) << endl;

    return 0;
}
