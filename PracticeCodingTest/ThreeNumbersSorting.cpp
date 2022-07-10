#include <iostream>
// 프로그래머스 코딩테스트 연습 
// Lv.Bronze4 - Three Numbers Sorting

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

/*
예제 입력 1
3 1 2
예제 출력 1
1 2 3
*/

int main()
{
    vector<int> nums(3);
    cin >> nums[0] >> nums[1] >> nums[2];
    
    sort(nums.begin(), nums.end());
    cout << nums[0] << " " << nums[1] << " " << nums[2];

    return 0;
}