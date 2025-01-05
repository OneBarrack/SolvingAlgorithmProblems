#include <iostream>
// 프로그래머스 코딩테스트 연습 
// 문자열 뒤의 n 글자.

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

string solution(string my_string, int n) {
    return my_string.substr(my_string.length() - n);
}

int main(void) {
    string my_string = "ProgrammerS123";
    int n = 11;

    cout << solution(my_string, 11) << endl;

    return 0;
}