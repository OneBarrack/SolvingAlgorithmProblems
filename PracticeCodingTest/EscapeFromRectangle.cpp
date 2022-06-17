#include <iostream>
// 백준 코딩테스트 연습 
// Lv.Bronze3 - Escape From Rectangle

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
* 6 2 10 3
*/
int main()
{	
    int x, y, w, h;
    cin >> x >> y >> w >> h;
    cout << min({ x, y, w - x, h - y });
	return 0;
}