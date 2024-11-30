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
    set<int> SetA;

    for (int& a : A)
    {
        SetA.insert(abs(a));
    }

    return SetA.size();
}

int main()
{
    vector<int> A = {-5, -3, -1, 0, 3, 6};

    cout << solution(A) << endl;

    return 0;
}
