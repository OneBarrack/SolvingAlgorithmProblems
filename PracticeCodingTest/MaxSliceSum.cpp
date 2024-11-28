#include <iostream>
// Codility 코딩테스트 연습 
// Exercise 9 easy. MaxSliceSum

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

int solution(vector<int>& A) {
    int maxSum = 0;

    int sum = 0;
    for (size_t i = 0; i < A.size(); i++)
    {
        sum += A[i];

        if (sum < 0)
        {
            sum = 0;
        }

        maxSum = max(sum, maxSum);
    }

    return (maxSum > 0) ? maxSum : *max_element(A.begin(), A.end());
}

int main()
{
    vector<int> A = {3, 2, -6, 4, 0};

    cout << solution(A) << endl;

    return 0;
}
