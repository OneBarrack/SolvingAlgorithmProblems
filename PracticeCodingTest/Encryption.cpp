#include <iostream>
// 해커랭크 코딩테스트 연습 
// Lv Medium. Encryption

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

string encryption(string s)
{
    string str = "";
    for ( char& c : s )
        if ( c != ' ' )
            str += c;

    int row = static_cast<int>(sqrt(s.length()));
    int col = static_cast<int>(ceil(sqrt(s.length())));

    if ( row * col < str.length() )
        row = col;

    string answer = "";
    for ( int j = 0; j < col; ++j )
    {
        for ( int i = 0; i < row; ++i )
        {
            int index = col * i + j;
            if ( index < str.size() )
                answer += str[index];
        }

        answer += " ";
    }

    return answer;
}


int main()
{
    string s = "if man was meant to stay on the ground god would have given us roots";
    cout << encryption(s) << endl;

    return 0;
}