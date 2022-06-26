#include <iostream>
// 백준 코딩테스트 연습 
// Lv.Silver3 - On off switch

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
#include <deque>

using namespace std;

int main()
{	
	int answer = 0;

	int switchCount;
	cin >> switchCount;

	vector<int> switches(switchCount + 1);
	for ( int i = 1; i <= switchCount; ++i )
		cin >> switches[i];

	int studentCount;
	cin >> studentCount;

	while ( studentCount > 0 )
	{
		int gender, targetSwitch;
		cin >> gender >> targetSwitch;

		if ( gender == 1 )
		{
			for ( int i = targetSwitch; i < switchCount + 1; i += targetSwitch )
				switches[i] ^= 1;
		}
		else
		{
			switches[targetSwitch] ^= 1;
			
			int left = targetSwitch - 1;
			int right = targetSwitch + 1;
			while ( 0 < left && right < switchCount + 1 )
			{
				if ( switches[left] != switches[right] )
					break;

				switches[left] ^= 1;
				switches[right] ^= 1;
				--left;
				++right;
			}
		}

		--studentCount;
	}

	for ( int i = 1; i < switchCount + 1; ++i )
	{		
		cout << switches[i] << " ";
		
		if ( i % 20 == 0 )
			cout << "\n";
	}

	return 0;
}