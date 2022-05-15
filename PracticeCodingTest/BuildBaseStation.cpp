#include <iostream>
// 프로그래머스 코딩테스트 연습 
// Lv.3 - 기지국 설치

#include <string>
#include <list>
#include <vector>
#include <queue>
#include <algorithm>
#include <stack>
#include <set>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <sstream>
#include <numeric>

using namespace std;

int solution(int n, vector<int> stations, int w)
{
    int answer = 0;
    int wavesRange = w * 2 + 1;

    int prevWavesEndPos = 0;
    for ( int station : stations )
    {
        int wavesStartPos = station - w;
        int noWavesRange = wavesStartPos - (prevWavesEndPos + 1);

        answer += static_cast<int>(ceil(noWavesRange / static_cast<double>(wavesRange)));
        prevWavesEndPos = station + w;
    }

    answer += static_cast<int>(ceil((n - prevWavesEndPos) / static_cast<double>(wavesRange)));
    return answer;
}

int main()
{
    int n = 11;
    vector<int> stations = { 4, 11 };
    int w = 1;

    cout << solution(n, stations, w) << endl;

    return 0;
}