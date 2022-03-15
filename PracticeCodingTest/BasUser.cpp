//#include <iostream>
//// 프로그래머스 코딩테스트 연습 
//// Lv3 불량 사용자
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
//int solution(vector<string> user_id, vector<string> banned_id)
//{
//    set<set<string>> totalBanLists;
//
//    for ( int banIndex = 0; banIndex < banned_id.size(); ++banIndex )
//    {
//        string bannedId = banned_id[banIndex];
//        set<set<string>> curBanLists;
//
//        for ( int userIndex = 0; userIndex < user_id.size(); ++userIndex )
//        {
//            string userId = user_id[userIndex];
//            if ( userId.size() != bannedId.size() )
//                continue;
//
//            bool bFindMatched = true;
//            for ( int i = 0; i < userId.size(); ++i )
//            {
//                if ( bannedId[i] != userId[i] && bannedId[i] != '*' )
//                {
//                    bFindMatched = false;
//                    break;
//                }
//            }
//
//            if ( bFindMatched )
//            {                
//                if ( totalBanLists.empty() )
//                {
//                    set<string> banList;
//                    banList.insert(userId);
//                    curBanLists.insert(banList);
//                }
//                else
//                {
//                    for ( set<string> banList : totalBanLists )
//                    {
//                        banList.insert(userId);
//                        if ( banList.size() > banIndex )
//                        {
//                            curBanLists.insert(banList);
//                        }
//                    }
//                }
//            }
//        }
//
//        totalBanLists = curBanLists;
//    }
//
//    return totalBanLists.size();
//}
//
//int main()
//{
//    vector<string> user_id = { "frodo", "fradi", "crodo", "abc123", "frodoc" };
//    //vector<string> banned_id = { "fr*d*", "abc1**" };
//    //vector<string> banned_id = { "*rodo", "*rodo", "******" };
//    vector<string> banned_id = { "fr*d*", "*rodo", "******", "******" };
//    cout << solution(user_id, banned_id) << endl;
//
//    return 0;
//}