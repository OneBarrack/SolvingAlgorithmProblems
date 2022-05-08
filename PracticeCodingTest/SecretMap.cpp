#include <iostream>
// 프로그래머스 코딩테스트 연습 
// lv.1 - [1차] 비밀 지도

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

vector<string> solution(int n, vector<int> arr1, vector<int> arr2)
{
    vector<string> secretMap(n, string(n, ' '));
    for ( int i = 0; i < n; ++i )
    {
        string& strLine = secretMap[i];
        int num1 = arr1[i];
        int num2 = arr2[i];

        int charIndex = n - 1;
        while ( 0 < num1 || 0 < num2 )
        {
            if ( num1 % 2 == 1 || num2 % 2 == 1 )
                strLine[charIndex] = '#';

            num1 /= 2;
            num2 /= 2;
            --charIndex;
        }
    }
    return secretMap;
}

int main()
{
    int n = 5;
    vector<int> arr1 = { 9, 20, 28, 18, 11 };
    vector<int> arr2 = { 30, 1, 21, 17, 28 };

    vector<string> result = solution(n, arr1, arr2);
    for ( string res : result )
        cout << res << endl;

    return 0;
}