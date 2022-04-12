#include <iostream>
// 프로그래머스 코딩테스트 연습 
// Lv.3 - 110 옮기기

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

vector<string> solution(vector<string> s)
{
    vector<string> answer;

    for ( string str : s )
    {
        if ( str.size() < 4 )
        {
            answer.push_back(str);
        }
        else
        {
            int countOf110 = 0;
            vector<char> charList;

            for ( int i = 0; i < str.size(); ++i )
            {
                char c = str[i];
                size_t charListSize = charList.size();

                if ( charListSize > 1 &&
                    charList[charListSize - 2] == '1' && charList[charListSize - 1] == '1' && c == '0' )
                {
                    ++countOf110;
                    charList.pop_back();
                    charList.pop_back();
                }
                else
                {
                    charList.push_back(c);
                }
            }

            string strOf110 = "";
            for ( int i = 0; i < countOf110; ++i )
            {
                strOf110 += "110";
            }

            vector<char>::reverse_iterator rIter = find(charList.rbegin(), charList.rend(), '0');
            if ( rIter == charList.rend() )
            {
                string backStr(charList.begin(), charList.end());
                answer.push_back(strOf110 + backStr);
            }
            else
            {
                vector<char>::iterator iter(rIter.base());
                string prevStr(charList.begin(), iter);
                string backStr(iter, charList.end());

                answer.push_back(prevStr + strOf110 + backStr);
            }
        }
    }

    return answer;
}

int main()
{
    vector<string> s = { "1110","100111100","0111111010" };
    vector<string> result = solution(s);
    for ( string res : result )
        cout << res << endl;

    return 0;
}