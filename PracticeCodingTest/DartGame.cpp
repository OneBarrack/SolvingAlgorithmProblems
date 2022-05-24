//#include <iostream>
//// 프로그래머스 코딩테스트 연습 
//// Lv 1. 다트 게임
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
//int solution(string dartResult)
//{
//    vector<int> points(3);
//    int order = -1;
//
//    for ( int i = 0; i < dartResult.size(); ++i )
//    {
//        switch ( dartResult[i] )
//        {
//            case 'S':
//                //points[order] = pow(points[order], 1); 
//                break;
//            case 'D':
//                points[order] = pow(points[order], 2);
//                break;
//            case 'T':
//                points[order] = pow(points[order], 3);
//                break;
//            case '*':
//                points[order] *= 2;
//                if ( order > 0 )
//                    points[order - 1] *= 2;
//                break;
//            case '#':
//                points[order] *= -1;
//                break;
//            default:
//                ++order;
//                if ( dartResult[i + 1] == '0' )
//                {
//                    points[order] = 10;
//                    ++i;
//                }
//                else
//                {
//                    points[order] = dartResult[i] - '0';
//                }
//                break;
//        }
//    }
//
//    return accumulate(points.begin(), points.end(), 0);
//}
//
//int main()
//{
//    string dartResult = "1S2D*3T";
//    cout << solution(dartResult) << endl;
//
//    return 0;
//}