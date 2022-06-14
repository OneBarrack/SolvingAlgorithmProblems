//#include <iostream>
//// 해커랭크 코딩테스트 연습 
//// Lv.Easy - Grading Students
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
//vector<int> gradingStudents(vector<int> grades)
//{
//    for ( int& grade : grades )
//    {
//        if ( grade < 38 )
//            continue;
//
//        int remainder = grade % 5;
//        if ( remainder > 2 )
//            grade = grade + 5 - remainder;
//    }
//
//    return grades;
//}
//
//int main()
//{
//    vector<int> grades = { 73, 67, 38, 33 };
//    vector<int> result = gradingStudents(grades);
//    for ( int res : result )
//        cout << res << endl;
//
//    return 0;
//}