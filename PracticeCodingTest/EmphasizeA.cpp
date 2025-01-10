#include <iostream>
// 프로그래머스 코딩테스트 연습 
// A 강조하기

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

string solution(string myString) {
    for (char& c : myString)
    {
        if (isalpha(c))
        {
            if (c == 'A')
                continue;
            else if (c == 'a')
                c = toupper(c);
            else
                c = tolower(c);
        }
    }

    return myString;
}

int main(void) {
    string myString = "PrOgRaMmErS";

    string result = solution(myString);
    cout << result << endl;

    return 0;
}