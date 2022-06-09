#include <iostream>
// 백준 코딩테스트 연습 
// Lv.Gold5 - Make Password

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

/*
4 6
a t c i s w
*/

void DFS(int L, vector<char>& vowels, vector<char> chars, int index, int vowelsCount, string result)
{
    if ( L == result.size() )
    {
        if ( vowelsCount > 0 && result.size() - vowelsCount > 1 )
            cout << result << "\n";

        return;
    }

    for ( int i = index + 1; i < chars.size(); ++i )
    {
        if ( chars.size() - i < L - result.size() )
            break;

        int nextVowelsCount = (find(vowels.begin(), vowels.end(), chars[i]) == vowels.end()) ? vowelsCount : vowelsCount + 1;
        DFS(L, vowels, chars, i, nextVowelsCount, result + chars[i]);
    }
}

int main()
{
    int L, C;    
    cin >> L >> C;
    vector<char> chars(C);
    for ( int i = 0; i < C; ++i )
        cin >> chars[i];
    
    sort(chars.begin(), chars.end());
    vector<char> vowels = { 'a', 'e', 'i', 'o', 'u' };

    DFS(L, vowels, chars, -1, 0, "");

    return 0;
}