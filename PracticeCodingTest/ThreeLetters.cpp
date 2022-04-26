#include <iostream>
// Colidity 코딩테스트 연습 
// Lv.Medium - Three letters

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

string solution(int A, int B)
{
    string answer = "";
    while ( true )
    {
        if ( A == 0 || B == 0 )
        {
            if ( A == 0 ) answer.append(B, 'b');
            if ( B == 0 ) answer.append(A, 'a');
            break;
        }

        if ( A > B )
        {
            answer += "aab";
            A -= 2;
            B -= 1;
        }
        else if ( A < B )
        {
            answer += "bba";
            A -= 1;
            B -= 2;
        }
        else
        {
            answer += "ab";
            --A;
            --B;
        }
    }

    return answer;
}

int main()
{
    int A = 1;
    int B = 4;
    cout << solution(A, B) << endl;

    return 0;
}