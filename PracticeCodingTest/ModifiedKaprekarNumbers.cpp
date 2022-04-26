#include <iostream>
// 해커랭크 코딩테스트 연습 
// Lv.Medium - Modified Kaprekar Numbers

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

int GetDigit(int n)
{
    int digit = 0;

    while ( n > 0 )
    {
        n /= 10;
        ++digit;
    }

    return digit;
}

bool IsKaprekarNumber(int n)
{
    int digit = pow(10, GetDigit(n));
    long long squareNum = n * (long long)n;
    long long leftNum = squareNum / digit;
    long long rightNum = squareNum % digit;

    return (leftNum + rightNum == n);
}

void kaprekarNumbers(int p, int q)
{
    bool IsValidRange = false;
    for ( int i = p; i <= q; ++i )
    {
        if ( IsKaprekarNumber(i) )
        {
            IsValidRange = true;
            cout << i << " ";
        }
    }

    if ( !IsValidRange )
        cout << "INVALID RANGE" << endl;
}

int main()
{
    int p = 1;
    int q = 100;
    kaprekarNumbers(p, q);

    return 0;
}