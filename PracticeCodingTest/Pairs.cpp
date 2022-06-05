#include <iostream>
// 해커랭크 코딩테스트 연습 
// Lv.Medium - Pairs

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

int pairs(int k, vector<int> arr)
{
    int answer = 0;
    sort(arr.begin(), arr.end());

    int left = 0;
    int right = lower_bound(arr.begin(), arr.end(), arr[left] + k) - arr.begin();
    while ( right < arr.size() )
    {
        if ( arr[right] - arr[left] > k )
        {
            ++left;
        }
        else if ( arr[right] - arr[left] < k )
        {
            ++right;
        }
        else // if ( arr[right] - arr[left] == k )
        {
            ++left;
            ++right;
            ++answer;
        }
    }

    return answer;
}

int main()
{
    int k = 2;
    vector<int> arr = { 1, 5, 3, 4, 2 };

    cout << pairs(k, arr) << endl;

    return 0;
}