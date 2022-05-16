#include <iostream>
// 프로그래머스 코딩테스트 연습 
// Lv.3 - 숫자 게임

#include <string>
#include <list>
#include <vector>
#include <queue>
#include <algorithm>
#include <stack>
#include <set>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <sstream>
#include <numeric>

using namespace std;

int solution(vector<int> A, vector<int> B)
{
    int answer = 0;

    sort(A.begin(), A.end());
    sort(B.begin(), B.end());

    for ( int posA = 0, posB = 0; posB < B.size(); ++posB )
    {
        if ( A[posA] < B[posB] )
        {
            ++answer;
            ++posA;
        }
    }

    return answer;
}

int main()
{
    vector<int> A = { 5, 1, 3, 7 }; 
    vector<int> B = { 2, 2, 6, 8 };    

    cout << solution(A, B) << endl;

    return 0;
}