#include <iostream>
// 코딜리티 코딩테스트 연습 
// Excercise 4 easy. FirstUnique

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
    unordered_map<int, int> numCountInfos;

    for (int& num : A)
    {
        ++numCountInfos[num];
    }

    for (int& num : A)
    {
        if (numCountInfos[num] == 1)
        {
            return num;
        }
    }

    return -1;
}

int main()
{
    vector<int> A = {4, 10, 5, 4, 2, 10};

    cout << solution(A) << endl;

    return 0;
}
