#include <iostream>
// 프로그래머스 코딩테스트 연습 
// Lv.3 - 가장 긴 펠린드롬

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

int solution(string s)
{
    int answer = 1;

    for ( int curIndex = 1; curIndex < s.size(); ++curIndex )
    {
        int prevIndex = curIndex - 1;
        int nextIndex = curIndex + 1;

        // even        
        if ( s[prevIndex] == s[curIndex] )
        {
            int matchedCount = 2;
            int tempPrevIndex = prevIndex;
            int tempCurIndex = curIndex;

            while ( -1 < --tempPrevIndex && ++tempCurIndex < s.size() )
            {
                if ( s[tempPrevIndex] != s[tempCurIndex] )
                    break;

                matchedCount += 2;
            }

            answer = max(answer, matchedCount);
        }

        if ( curIndex == s.size() - 1 )
            break;

        // odd
        if ( s[prevIndex] == s[nextIndex] )
        {
            int matchedCount = 3;
            int tempPrevIndex = prevIndex;
            int tempNextIndex = nextIndex;

            while ( -1 < --tempPrevIndex && ++tempNextIndex < s.size() )
            {
                if ( s[tempPrevIndex] != s[tempNextIndex] )
                    break;

                matchedCount += 2;
            }

            answer = max(answer, matchedCount);
        }
    }

    return answer;
}

int main()
{
    //string s = "abcdcba";
    string s = "abbb";
    cout << solution(s) << endl;

    return 0;
}