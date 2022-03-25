#include <iostream>
// Codility 코딩테스트 연습 
// Easy level - Passing Cars

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

int solution(vector<int>& A)
{
    if ( A.size() < 2 )
        return 0;

    int answer = 0;
    int eastDirCount = 0;

    for ( int& carDir : A )
    {
        if ( carDir == 0 )
        {
            ++eastDirCount;
        }
        else if ( answer + eastDirCount <= 1000000000 )
        {
            answer += eastDirCount;
        }
        else
        {
            answer = -1;
            break;
        }
    }

    return answer;
}

int main()
{
    vector<int> A = { 0, 1, 0, 1, 1 };
    //vector<int> A = { 1, 2, 3 };
    //vector<int> A = { -1, -3 };

    //vector<int> result = solution(N, A);
    //for ( int res : result )
    //    cout << res << endl;

    cout << solution(A) << endl;

    return 0;
}