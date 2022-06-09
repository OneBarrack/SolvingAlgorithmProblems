//#include <iostream>
//// 백준 코딩테스트 연습 
//// Lv.Gold5 - Fly Me To The Alpha Centauri
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
//int main()
//{
//    int T;
//    cin >> T;
//    while ( T > 0 )
//    {
//        int x, y;
//        cin >> x >> y;
//        int k = y - x;
//        int n = 0;
//
//        while ( true )
//        {
//            long long bothDirSigma = ((long long)n * (n + 1) / 2) * 2;
//            if ( bothDirSigma == k )
//            {
//                cout << n * 2 << "\n";
//                break;
//            }
//            if ( bothDirSigma > k )
//            {
//                --n;
//                int remainNum = k - ((n * (n + 1) / 2) * 2);
//                cout << (n * 2) + ceil(remainNum / (double)(n + 1)) << "\n";
//                break;
//            }
//
//            ++n;
//        }
//
//        --T;
//    }
//
//    return 0;
//}