#include <iostream>
// 해커랭크 코딩테스트 연습 
// Lv Medium. Larry's Array

#include <string>
#include <list>
#include <vector>
#include <queue>
#include <algorithm>
#include <stack>
#include <set>
#include <map>
#include <unordered_map>
#include <numeric>

using namespace std;

string larrysArray(vector<int> A)
{
    for ( int i = 0; i < A.size() - 2; ++i )
    {
        if ( A.back() == i + 1 )
        {
            int temp = A[A.size() - 3];
            A[A.size() - 3] = A[A.size() - 2];
            A[A.size() - 2] = A[A.size() - 1];
            A[A.size() - 1] = temp;
        }

        auto iter = find(A.begin(), A.end(), i + 1);
        while ( A[i] > i + 1 )
        {
            int temp = *prev(iter);
            *prev(iter) = *iter;
            *iter = *next(iter);
            *next(iter) = temp;
            --iter;
        }
    }

    for ( int i = 0; i < A.size(); ++i )
        if ( A[i] > i + 1 )
            return "NO";

    return "YES";
}

int main()
{
    vector<int> A = { 1, 3, 4, 2 };
    cout << larrysArray(A) << endl;

    return 0;
}