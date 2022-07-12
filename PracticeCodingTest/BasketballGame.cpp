//#include <iostream>
//// 프로그래머스 코딩테스트 연습 
//// Lv.Bronze4 - Basketball Game
//
//#include <string>
//#include <vector>
//#include <queue>
//#include <set>
//#include <algorithm>
//#include <unordered_map>
//#include <numeric>
//#include <stack>
//#include <map>
//
//using namespace std;
//
///*
//예제 입력 1
//18
//babic
//keksic
//boric
//bukic
//sarmic
//balic
//kruzic
//hrenovkic
//beslic
//boksic
//krafnic
//pecivic
//klavirkovic
//kukumaric
//sunkic
//kolacic
//kovacic
//prijestolonasljednikovi
//예제 출력 1
//bk
//예제 입력 2
//6
//michael
//jordan
//lebron
//james
//kobe
//bryant
//예제 출력 2
//PREDAJA
//*/
//
//int main()
//{
//    int N;
//    cin >> N;
//
//    map<char, int> nameCountInfos;
//
//    while ( N > 0 )
//    {
//        string name;
//        cin >> name;
//        
//        ++nameCountInfos[name[0]];
//
//        --N;
//    }
//
//    string result = "";
//    for ( auto& nameCountInfo : nameCountInfos )
//    {
//        if ( nameCountInfo.second < 5 )
//            continue;
//
//        result += nameCountInfo.first;
//    }
//
//    if ( result.empty() )
//        cout << "PREDAJA";
//    else
//        cout << result;
//
//    return 0;
//}