#include <iostream>
// 프로그래머스 코딩테스트 연습 
// Lv3 단어 변환

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

bool IsPossibleConversion(string word1, string word2)
{
    int matchedCount = 0;
    for ( int i = 0; i < word1.size(); ++i )
    {
        if ( word1[i] == word2[i] )
            ++matchedCount;
    }

    return (matchedCount == word1.size() - 1) ? true : false;
}

int solution(string begin, string target, vector<string> words)
{
    int answer = 0;

    unordered_map<string, vector<string>> wordMap;
    unordered_map<string, bool> visit;

    for ( int i = 0; i < words.size(); ++i )
    {
        string word = words[i];
        if ( IsPossibleConversion(begin, word) )
        {
            wordMap[begin].emplace_back(word);
        }        
    }

    for ( int i = 0; i < words.size(); ++i )
    {
        string word1 = words[i];

        for ( int j = 0; j < words.size(); ++j )
        {
            string word2 = words[j];
            if ( word1 == word2 )
                continue;

            if ( IsPossibleConversion(word1, word2) )
            {
                wordMap[word1].emplace_back(word2);
            }
        }
    }
    
    queue<pair<string, int>> wordQueue;
    wordQueue.push(make_pair(begin, 0));

    while ( !wordQueue.empty() )
    {
        string curWord = wordQueue.front().first;
        int convertCount = wordQueue.front().second;
        wordQueue.pop();

        if ( curWord == target )
        {
            answer = convertCount;
            break;
        }            

        visit[curWord] = true;

        for ( string nextWord : wordMap[curWord] )
        {
            if ( !visit[nextWord] )
            {
                wordQueue.push(make_pair(nextWord, convertCount + 1));
            }
        }
    }

    return answer;
}

int main()
{
    string begin = "hit";
    string target = "cog";
    vector<string> words = { "hot", "dot", "dog", "lot", "log" };

    cout << solution(begin, target, words) << endl;

    return 0;
}