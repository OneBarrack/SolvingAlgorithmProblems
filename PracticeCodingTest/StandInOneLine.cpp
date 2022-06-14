#include <iostream>
// 백준 코딩테스트 연습 
// Lv.Silver4 - Stand In One Line

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
4
2 1 1 0
*/
int main()
{
    int N;
    cin >> N;

    vector<int> line(N);
    for ( int i = 0; i < N; ++i )
    {
        int tallManCount;
        cin >> tallManCount;

        int zeroCount = 0;
        for ( int j = 0; j < N; ++j )
        {
            if ( line[j] > 0 )
                continue;

            if ( zeroCount == tallManCount )
            {
                line[j] = i + 1;
                break;
            }

            ++zeroCount;
        }
    }

    for ( int& people : line )
        cout << people << " ";

    return 0;
}