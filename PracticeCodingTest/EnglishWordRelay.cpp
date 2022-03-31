//#include <iostream>
//// 프로그래머스 코딩테스트 연습 
//// Lv2 영어 끝말잇기
//
//#include <string>
//#include <list>
//#include <vector>
//#include <queue>
//#include <algorithm>
//#include <stack>
//#include <set>
//#include <map>
//#include <unordered_map>
//#include <sstream>
//
//using namespace std;
//
//vector<int> solution(int n, vector<string> words)
//{
//    vector<int> answer = { 0, 0 };
//
//    string prevWord = words[0];
//    set<string> usedWord;
//    usedWord.insert(prevWord);
//    for ( int i = 1; i < words.size(); ++i )
//    {
//        string word = words[i];
//        int order = (i / n) + 1;
//        int user = (i % n) + 1;
//
//        if ( usedWord.find(word) != usedWord.end() ||
//            prevWord[prevWord.length() - 1] != word[0] )
//        {
//            answer[0] = user;
//            answer[1] = order;
//            break;
//        }
//
//        usedWord.insert(word);
//        prevWord = word;
//    }
//
//    return answer;
//}
//
//int main()
//{
//    int n = 3;
//    vector<string> words = { "tank", "kick", "know", "wheel", "land", "dream", "mother", "robot", "tank" };
//
//    vector<int> result = solution(n, words);
//    for ( int res : result )
//        cout << res << endl;
//
//    return 0;
//}