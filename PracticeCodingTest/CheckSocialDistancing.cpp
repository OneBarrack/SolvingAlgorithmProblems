//#include <iostream>
//// 프로그래머스 코딩테스트 연습 
//// Lv2 거리두기 확인하기
//
//#include <string>
//#include <list>
//#include <vector>
//#include <queue>
//#include <algorithm>
//#include <stack>
//#include <set>
//#include <map>
//
//using namespace std;
//
//bool CheckSocialDist(vector<vector<bool>> visit, vector<string> place, int x, int y, int depth)
//{   
//    if ( visit[x][y] )
//        return true;
//
//    visit[x][y] = true;
//
//    bool bResult = true;
//    char placeType = place[x][y];
//
//    if ( placeType == 'X' || depth > 2 )
//        return true;
//
//    if ( depth > 0 && placeType == 'P' )
//        return false;
//
//    // Left
//    if ( bResult && y > 0 )
//    {
//        bResult = CheckSocialDist(visit, place, x, y - 1, depth + 1);
//    }
//
//    // Top
//    if ( bResult && x > 0 )
//    {
//        bResult = CheckSocialDist(visit, place, x - 1, y, depth + 1);
//    }
//
//    // Right
//    if ( bResult && y < place[0].size() - 1 )
//    {
//        bResult = CheckSocialDist(visit, place, x, y + 1, depth + 1);
//    }
//
//    // Bottom
//    if ( bResult && x < place.size() - 1 )
//    {
//        bResult = CheckSocialDist(visit, place, x + 1, y, depth + 1);
//    }
//
//    return bResult;
//}
//
//vector<int> solution(vector<vector<string>> places)
//{
//    vector<int> answer;   
//
//    for ( vector<string> place : places )
//    {
//        vector<vector<bool>> visit(5, vector<bool>(5, false));
//        bool bResult = true;
//
//        for ( int i = 0; i < 25; ++i )
//        {
//            int row = i / 5;
//            int col = i % 5;
//
//            char placeType = place[row][col];
//            if ( placeType == 'P' )
//                bResult = CheckSocialDist(visit, place, row, col, 0);
//                
//            if ( !bResult )
//                break;
//        }        
//
//        answer.push_back(bResult);
//    }
//
//    return answer;
//}
//
//int main()
//{
//    vector<vector<string>> places = { {"POOOP", "OXXOX", "OPXPX", "OOXOX", "POXXP"},
//        {"POOPX", "OXPXP", "PXXXO", "OXXXO", "OOOPP"},
//        {"PXOPX", "OXOXP", "OXPOX", "OXXOP", "PXPOX"},
//        {"OOOXX", "XOOOX", "OOOXX", "OXOOX", "OOOOO"},
//        {"PXPXP", "XPXPX", "PXPXP", "XPXPX", "PXPXP"} };
//
//    vector<int> result = solution(places);
//    for ( int res : result )
//        cout << res << endl;
//
//    return 0;
//}