//#include <iostream>
//// 해커랭크 코딩테스트 연습 
//// Lv Medium. The Grid Search
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
//#include <numeric>
//
//using namespace std;
//
//string gridSearch(vector<string> G, vector<string> P)
//{
//    for ( int gRow = 0; gRow < G.size() - (P.size() - 1); ++gRow )
//    {
//        for ( int gCol = 0; gCol < G[0].size() - (P[0].size() - 1); ++gCol )
//        {
//            if ( G[gRow][gCol] == P[0][0] )
//            {
//                bool isEqual = true;
//                for ( int pRow = 0; pRow < P.size(); ++pRow )
//                {
//                    for ( int pCol = 0; pCol < P[0].size(); ++pCol )
//                    {
//                        if ( G[gRow + pRow][gCol + pCol] != P[pRow][pCol] )
//                        {
//                            isEqual = false;
//                            break;
//                        }
//                    }
//
//                    if ( !isEqual )
//                        break;
//                }
//
//                if ( isEqual )
//                    return "YES";
//            }
//        }
//    }
//
//    return "NO";
//}
//
//int main()
//{
//    vector<string> G = {
//        "7283455864",
//        "6731158619",
//        "8988242643",
//        "3830589324",
//        "2229505813",
//        "5633845374",
//        "6473530293",
//        "7053106601",
//        "0834282956",
//        "4607924137"
//    };
//    vector<string> P = {
//        "9505",
//        "3845",
//        "3530"
//    };
//    cout << gridSearch(G, P) << endl;
//
//    return 0;
//}