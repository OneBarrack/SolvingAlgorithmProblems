#include <iostream>
// 해커랭크 코딩테스트 연습 
// Lv.Easy - Time Conversion

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

string timeConversion(string s)
{
    string result = "";
    int inputHour = stoi(s.substr(0, 2));
    int outputHour = (s.substr(8, 2) == "AM") ? 0 : 12;

    if ( outputHour < 10 )
        result += "0";

    result += to_string(outputHour + (inputHour % 12)) + s.substr(2, 6);
    return result;
}

int main()
{	
    string s = "07:05:45PM";
	cout << timeConversion(s) << endl;

	return 0;
}