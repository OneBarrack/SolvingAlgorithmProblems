#include <iostream>
//// 해커랭크 코딩테스트 연습
//// Easy. Find Digits

#include <string>
#include <vector>
#include <queue>
#include <set>
#include <algorithm>
#include <unordered_map>
#include <numeric>
#include <stack>
#include <map>

using namespace std;

int FindDigits(int n) {
    int result = 0;

    int digits = n;
    while (digits > 0)
    {
        int digit = digits % 10;

        if (digit > 0 && n % digit == 0)
        {
            ++result;
        }

        digits /= 10;
    }

    return result;
}

int main()
{
    cout << FindDigits(1012) << endl;

    return 0;
}
