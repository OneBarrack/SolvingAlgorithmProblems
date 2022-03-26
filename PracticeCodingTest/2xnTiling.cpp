#include <iostream>
// Codility 코딩테스트 연습 
// Lv3 2 x n 타일링

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

int solution(int n)
{
    int arr[60001];
    arr[1] = 1;
    arr[2] = 1;
    for ( int i = 3; i <= n; ++i )
        arr[i] = (arr[i - 1] + arr[i - 2] + (i % 2)) % 1000000007;
    return arr[n] + ((n % 2) ^ 1);
}

int main()
{
    int n = 4;

    cout << solution(n) << endl;

    return 0;
}