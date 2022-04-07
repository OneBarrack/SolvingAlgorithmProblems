#include <iostream>
// 프로그래머스 코딩테스트 연습 
// Lv.3 - 베스트 앨범

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

bool compareMusicsForPlayCount(pair<int, int> musicInfo1, pair<int, int> musicInfo2)
{
    if ( (musicInfo1.second > musicInfo2.second) ||
        (musicInfo1.second == musicInfo2.second && musicInfo1.first < musicInfo2.first) )
        return true;

    return false;
}

vector<int> solution(vector<string> genres, vector<int> plays)
{
    vector<int> answer;

    unordered_map<string, int> playCountForGenre;
    map<int, string, greater<int>> orderedGenreForPlays;
    unordered_map<string, vector<pair<int, int>>> musicsForGenre;

    for ( int music = 0; music < genres.size(); ++music )
    {
        string genre = genres[music];
        int playCount = plays[music];

        playCountForGenre[genre] += playCount;

        pair<int, int> musicInfo = make_pair(music, playCount);
        musicsForGenre[genre].push_back(musicInfo);
    }

    for ( auto iter = playCountForGenre.begin(); iter != playCountForGenre.end(); ++iter )
    {
        orderedGenreForPlays.insert(make_pair(iter->second, iter->first));
    }

    for ( auto iter = musicsForGenre.begin(); iter != musicsForGenre.end(); ++iter )
    {
        vector<pair<int, int>>& musicInfo = iter->second;
        sort(musicInfo.begin(), musicInfo.end(), compareMusicsForPlayCount);
    }

    for ( auto iter = orderedGenreForPlays.begin(); iter != orderedGenreForPlays.end(); ++iter )
    {
        string genre = iter->second;

        int recordCount = 2;
        for ( auto musicInfo : musicsForGenre[genre] )
        {
            int music = musicInfo.first;
            if ( recordCount == 0 )
                break;

            answer.emplace_back(music);
            --recordCount;
        }
    }

    return answer;
}

int main()
{
    vector<string> genres = { "classic", "pop", "classic", "classic", "pop" };
    vector<int> plays = { 500, 600, 150, 800, 2500 };

    vector<int> result = solution(genres, plays);
    for ( int res : result )
        cout << res << endl;

    return 0;
}