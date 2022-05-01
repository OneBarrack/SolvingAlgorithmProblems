#include <iostream>
// 프로그래머스 코딩테스트 연습 
// Lv2. [3차] 파일명 정렬

#include <string>
#include <list>
#include <vector>
#include <queue>
#include <algorithm>
#include <stack>
#include <set>
#include <map>
#include <unordered_set>
#include <sstream>
#include <numeric>

using namespace std;

void SplitFileName(string& s, string& head, int& number)
{
    string strHead = "";
    string strNum = "";

    bool isHead = true;
    for ( int i = 0; i < s.size(); ++i )
    {
        char c = s[i];
        if ( isdigit(c) ) // number
        {
            strNum += c;
            isHead = false;
        }
        else if ( isHead ) // head
        {
            strHead += tolower(c);
        }
        else // tail
        {
            break;
        }
    }

    head = strHead;
    number = stoi(strNum);
}

bool compare(string s1, string s2)
{
    string head1, head2;
    int num1, num2;

    SplitFileName(s1, head1, num1);
    SplitFileName(s2, head2, num2);

    if ( head1 < head2 || (head1 == head2 && num1 < num2) )
        return true;

    return false;
}

vector<string> solution(vector<string> files)
{
    stable_sort(files.begin(), files.end(), compare);
    return files;
}

int main()
{
    vector<string> files = { "img12.png", "img10.png", "img02.png", "img1.png", "IMG01.GIF", "img2.JPG" };

    vector<string> result = solution(files);

    for ( string res : result )
        cout << res << endl;

    return 0;
}