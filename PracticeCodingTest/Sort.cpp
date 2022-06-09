#include <iostream>
// 백준 코딩테스트 연습 
// Lv.Gold5 - Sort

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

/*
10
19 20 17 18 15 16 13 14 11 12
5
*/
int main()
{
    int N, S;
    vector<int> arr;

    cin >> N;
    for ( int i = 0; i < N; ++i )
    {
        int num;
        cin >> num;
        arr.push_back(num);
    }
    cin >> S;

    while ( S > 0 && !arr.empty() )
    {
        auto iter = (S < arr.size()) ? max_element(arr.begin(), arr.begin() + S + 1) : max_element(arr.begin(), arr.end());
        cout << *iter << " ";
        S -= distance(arr.begin(), iter);
        arr.erase(iter);
    }

    for ( int& num : arr )
        cout << num << " ";

    return 0;
}