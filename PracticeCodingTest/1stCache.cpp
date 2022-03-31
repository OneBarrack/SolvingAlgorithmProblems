#include <iostream>
// 프로그래머스 코딩테스트 연습 
// Lv2 [1차] 캐시

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

int solution(int cacheSize, vector<string> cities)
{
    int answer = 0;

    unordered_map<string, bool> isCached;
    list<string> cache;

    for ( string city : cities )
    {
        transform(city.begin(), city.end(), city.begin(), ::tolower);
        if ( isCached[city] )
        {
            ++answer;
            if ( *cache.rbegin() != city )
            {
                cache.erase(find(cache.begin(), cache.end(), city));
                cache.push_back(city);
            }
        }
        else
        {
            if ( cacheSize > 0 )
            {
                if ( cache.size() == cacheSize )
                {
                    auto cachedCityIter = find(cache.begin(), cache.end(), city);
                    if ( cachedCityIter != cache.end() )
                    {
                        cache.erase(cachedCityIter);
                    }
                    isCached[cache.front()] = false;
                    cache.pop_front();
                }

                cache.push_back(city);
                isCached[city] = true;
            }

            answer += 5;
        }
    }

    return answer;
}

int main()
{	
    int cacheSize = 2;
    vector<string> cities = { "Jeju", "Pangyo", "Seoul", "NewYork", "LA", "SanFrancisco", "Seoul", "Rome", "Paris", "Jeju", "NewYork", "Rome" };

	cout << solution(cacheSize, cities) << endl;

	return 0;
}