#include <iostream>
// 해커랭크 코딩테스트 연습 
// Lv.Medium - The Full Counting Sort

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

int birthdayCakeCandles(vector<int> candles)
{
    return count(candles.begin(), candles.end(), *max_element(candles.begin(), candles.end()));
}

int main()
{
    vector<int> candles = { 3, 2, 1, 3 };
    cout << birthdayCakeCandles(candles) << endl;

    return 0;
}