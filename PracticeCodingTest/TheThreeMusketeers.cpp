//#include <iostream>
//// Codility 코딩테스트 연습 
//// Exercise 9 easy. MaxSliceSum
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
//int solution(vector<int> number) {
//    int answer = 0;
//
//    for (int i = 0; i < number.size() - 2; i++)
//    {
//        for (int j = i + 1; j < number.size() - 1; j++)
//        {
//            for (int k = j + 1; k < number.size(); k++)
//            {
//                if (number[i] + number[j] + number[k] == 0)
//                    ++answer;
//            }
//        }
//    }
//
//    return answer;
//}
//
//int main()
//{
//    vector<int> number = {-2, 3, 0, 2, -5};
//
//    cout << solution(number) << endl;
//
//    return 0;
//}
