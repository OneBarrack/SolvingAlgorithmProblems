//#include <iostream>
//// 프로그래머스 코딩테스트 연습 
//// lv.2 - 후보 키
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
//#include <unordered_set>
//#include <sstream>
//#include <numeric>
//
//using namespace std;
//
//bool IsCandidateKey(vector<vector<string>>& relation, vector<int> keyColumns, vector<string>& candidateKeys)
//{
//    bool isCandidateKey = true;
//
//    unordered_set<string> keyList;
//    for ( vector<string>& relationRow : relation )
//    {
//        string key = "";
//
//        for ( int keyColumn : keyColumns )
//            key += relationRow[keyColumn];
//
//        if ( keyList.find(key) != keyList.end() )
//        {
//            isCandidateKey = false;
//            break;
//        }
//
//        keyList.insert(key);
//    }
//
//    if ( isCandidateKey )
//    {
//        string key = "";
//        for ( int keyColumn : keyColumns )
//            key += to_string(keyColumn);
//
//        candidateKeys.push_back(key);
//    }
//
//    return isCandidateKey;
//}
//
//void SearchCandidateKey(vector<vector<string>>& relation, vector<bool> usedColumns, vector<int> keyColumns, int curColumn, vector<string>& candidateKeys)
//{
//    vector<vector<int>> notFoundColumnsList;
//    for ( int nextColumn = curColumn + 1; nextColumn < relation[0].size(); ++nextColumn )
//    {
//        if ( usedColumns[nextColumn] )
//            continue;
//
//        vector<int> nextColumns = keyColumns;
//        nextColumns.push_back(nextColumn);
//        if ( IsCandidateKey(relation, nextColumns, candidateKeys) )
//        {
//            usedColumns[nextColumn] = true;
//        }
//        else
//        {
//            notFoundColumnsList.push_back(nextColumns);
//        }
//    }
//
//    for ( vector<int> notFoundColumns : notFoundColumnsList )
//    {
//        SearchCandidateKey(relation, usedColumns, notFoundColumns, notFoundColumns.back(), candidateKeys);
//    }
//}
//
//bool compare(string s1, string s2)
//{
//    if ( s1.size() < s2.size() ) return true;
//    if ( s1.size() == s2.size() && s1 < s2 ) return true;
//    return false;
//}
//
//int solution(vector<vector<string>> relation)
//{
//    vector<string> candidateKeys;
//    vector<bool> usedColumns(relation[0].size(), false);
//    SearchCandidateKey(relation, usedColumns, vector<int>(), -1, candidateKeys);
//    sort(candidateKeys.begin(), candidateKeys.end(), compare);
//
//    for ( auto iter1 = candidateKeys.begin(); iter1 != candidateKeys.end(); ++iter1 )
//    {
//        for ( auto iter2 = next(iter1); iter2 != candidateKeys.end(); )
//        {
//            if ( (*iter2).find(*iter1) != string::npos )
//                iter2 = candidateKeys.erase(iter2);
//            else
//                ++iter2;
//        }
//    }
//
//    return candidateKeys.size();
//}
//
//int main()
//{
//    //vector<vector<string>> relation = {
//    //    {"100","ryan","music","2"},
//    //    {"200","apeach","math","2"},
//    //    {"300","tube","computer","3"},
//    //    {"400","con","computer","4"},
//    //    {"500","muzi","music","3"},
//    //    {"600","apeach","music","2" } 
//    //};
//
//    vector<vector<string>> relation = {
//        {"a", "1", "aaa", "c", "ng"},
//        {"b", "1", "bbb", "c", "g"},
//        {"c", "1", "aaa", "d", "ng"},
//        {"d", "2", "bbb", "d", "ng"}
//    };
//
//    cout << solution(relation) << endl;
//
//    return 0;
//}