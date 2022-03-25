#include <iostream>
// Codility 코딩테스트 연습 
// Medium level - MaxCounters

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

using namespace std;

vector<int> solution(int N, vector<int>& A)
{
    vector<int> res(N);

    int maxNum = 0;
    int curMaxNum = 0;
    for ( int& num : A )
    {
        if ( num > N )
        {
            maxNum = curMaxNum;
        }
        else
        {
            if ( res[num - 1] < maxNum )
            {
                res[num - 1] = maxNum + 1;
            }
            else
            {
                res[num - 1]++;
            }

            if ( curMaxNum < res[num - 1] )
            {
                curMaxNum = res[num - 1];
            }
        }
    }

    for ( int& resNum : res )
    {
        if ( resNum < maxNum )
        {
            resNum = maxNum;
        }
    }

    return res;
}

int main()
{
    int N = 5;
    vector<int> A = { 3, 4, 4, 6, 1, 4, 4 };

    vector<int> result = solution(N, A);
    for ( int res : result )
        cout << res << endl;

    return 0;
}