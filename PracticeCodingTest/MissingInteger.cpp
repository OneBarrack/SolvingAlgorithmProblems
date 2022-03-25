#include <iostream>
// Codility 코딩테스트 연습 
// Medium level - Missing Integer

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
    int answer = 1;
    set<int> aSet;

    for ( int num : A )
    {
        if ( num > 0 )
            aSet.insert(num);
    }

    for ( int num : aSet )
    {
        if ( answer < num )
            break;

        ++answer;
    }

    return answer;
}

int main()
{
    vector<int> A = { 1, 3, 6, 4, 1, 2 };
    //vector<int> A = { 1, 2, 3 };
    //vector<int> A = { -1, -3 };

    //vector<int> result = solution(N, A);
    //for ( int res : result )
    //    cout << res << endl;

    cout << solution(A) << endl;

    return 0;
}