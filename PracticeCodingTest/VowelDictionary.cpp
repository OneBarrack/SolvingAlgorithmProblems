//#include <iostream>
//// 프로그래머스 코딩테스트 연습 
//// Lv.2 - 모음 사전
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
//#include <numeric>
//
//using namespace std;
//
//void FindWord(vector<char> v, int index, string currentWord, string targetWord, int& searchCount, bool& bFind)
//{    
//    if ( bFind )
//        return;
//
//    currentWord += v[index];
//    ++searchCount;
//    
//    if ( currentWord == targetWord )
//    {
//        bFind = true;
//    }
//    else if ( currentWord.size() < 5 )
//    {
//        for ( int i = 0; i < v.size(); ++i )
//        {
//            FindWord(v, i, currentWord, targetWord, searchCount, bFind);
//        }
//    }
//}
//
//int solution(string word)
//{
//    vector<char> v = { 'A', 'E', 'I', 'O', 'U' };
//    bool bFind = false;
//    int searchCount = 0;
//
//    for ( int i = 0; i < v.size(); ++i )
//    {
//        if ( bFind )
//            break;
//
//        FindWord(v, i, "", word, searchCount, bFind);
//    }
//
//    return searchCount;
//}
//
//int main()
//{
//    string word = "I";
//    cout << solution(word) << endl;
//
//    return 0;
//}