//#include <iostream>
//// 프로그래머스 코딩테스트 연습 
//// Lv1 신고 결과 받기
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
//
//using namespace std;
//
//vector<int> solution(vector<string> id_list, vector<string> report, int k)
//{
//    vector<int> receiveMailCounts(id_list.size());
//    unordered_map<string, int> userListIndex;
//    unordered_map<string, set<string>> reportedUserInfos;
//   
//    for ( int listIndex = 0; listIndex < id_list.size(); ++listIndex )
//    {
//        string userId = id_list[listIndex];
//        userListIndex[userId] = listIndex;
//    }
//
//    for ( string reportStr : report )
//    {
//        size_t splitPos = reportStr.find(" ");
//        string userId = reportStr.substr(0, splitPos);
//        string reportedUserId = reportStr.substr(splitPos + 1);
//
//        reportedUserInfos[reportedUserId].insert(userId);
//    }
//
//    for ( auto reportedUserInfo : reportedUserInfos )
//    {
//        string reportedUserId = reportedUserInfo.first;
//        set<string> reportUserIdList = reportedUserInfo.second;
//
//        if ( reportUserIdList.size() >= k )
//        {
//            for ( string reportUserId : reportUserIdList )
//            {
//                ++receiveMailCounts[userListIndex[reportUserId]];
//            }
//        }
//    }
//
//    return receiveMailCounts;
//}
//
//int main()
//{
//    vector<string> id_list = { "muzi", "frodo", "apeach", "neo" };
//    vector<string> report = { "muzi frodo","apeach frodo","frodo neo","muzi neo","apeach muzi" };
//    int k = 2;
//
//    vector<int> result = solution(id_list, report, k);
//
//    for ( int res : result )
//        cout << res << endl;
//
//    return 0;
//}