#include <iostream>
// 프로그래머스 코딩테스트 연습 
// Lv.2 - 방금 그 곡

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

void ParseMusicInfo(string musicInfo, int& playTime, string& musicName, string& musicCodes)
{
    int startTime = 0;
    int endTime = 0;

    stringstream ss(musicInfo);
    string token;

    if ( getline(ss, token, ',') ) startTime = stoi(token.substr(0, 2)) * 60 + stoi(token.substr(3, 2));
    if ( getline(ss, token, ',') ) endTime = stoi(token.substr(0, 2)) * 60 + stoi(token.substr(3, 2));
    if ( getline(ss, token, ',') ) musicName = token;
    if ( getline(ss, token, ',') ) musicCodes = token;

    playTime = endTime - startTime;
}

void ConvertMusicCodes(string& musicCodes)
{
    string convertMusicCodes = "";
    for ( char c : musicCodes )
    {
        if ( c == '#' )
        {
            char& lastMusicCode = convertMusicCodes.back();
            lastMusicCode = tolower(lastMusicCode);
            continue;
        }

        convertMusicCodes += c;
    }
    musicCodes = convertMusicCodes;
}

string solution(string m, vector<string> musicinfos)
{
    multimap<int, string, greater<int>> musicPlayTimeInfos;

    ConvertMusicCodes(m);
    for ( string musicInfo : musicinfos )
    {
        int playTime;
        string musicName, musicCodes;

        ParseMusicInfo(musicInfo, playTime, musicName, musicCodes);
        ConvertMusicCodes(musicCodes);

        string resultMusicCodes = "";
        for ( int i = 0; i < playTime / musicCodes.size(); ++i )
            resultMusicCodes += musicCodes;
        resultMusicCodes += musicCodes.substr(0, playTime % musicCodes.size());

        if ( resultMusicCodes.find(m, 0) != string::npos )
            musicPlayTimeInfos.insert(make_pair(playTime, musicName));
    }

    return musicPlayTimeInfos.empty() ? "(None)" : musicPlayTimeInfos.begin()->second;
}


int main()
{
    string m = "ABC";
    vector<string> musicInfos = { "12:00,12:14,HELLO,C#DEFGAB", "13:00,13:05,WORLD,ABCDEF" };
    cout << solution(m, musicInfos) << endl;

    return 0;
}