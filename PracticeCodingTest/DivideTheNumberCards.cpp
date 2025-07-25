#include <iostream>
// 프로그래머스 연습문제 : 숫자 카드 나누기
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

set<int, greater<int>> GetFactors(int num)
{
    set<int, greater<int>> factors;
    if (num < 1) return factors;

    for (int i = 1; i * i <= num; i++)
        if (num % i == 0) 
            factors.insert({i, num / i});

    return factors;
}

int FindMatchedNumber(vector<int> cards1, vector<int> cards2)
{
    set<int, greater<int>> factors = GetFactors(cards1[0]);
    for (const int& factor : factors)
    {
        bool bFound = true;
        for (int i = 0; i < cards1.size(); i++)
        {
            if (cards1[i] % factor != 0 || cards2[i] % factor == 0)
            {
                bFound = false;
                break;
            }
        }

        if (bFound) return factor;
    }

    return 0;
}

int solution(vector<int> arrayA, vector<int> arrayB) {
    return max(FindMatchedNumber(arrayA, arrayB), FindMatchedNumber(arrayB, arrayA));
}

int main(void) {
    //vector<int> arrayA = {10, 17};
    //vector<int> arrayB = {5, 20};

    //vector<int> arrayA = {10, 20};
    //vector<int> arrayB = {5, 17};

    vector<int> arrayA = {14, 35, 119};
    vector<int> arrayB = {18, 30, 102};

    cout << solution(arrayA, arrayB) << endl;

    return 0;
}
