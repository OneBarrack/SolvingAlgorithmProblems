//#include <iostream>
//// 프로그래머스 코딩테스트 연습 
//// Lv2. 연속된 부분 수열의 합
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
//vector<int> solution(vector<int> sequence, int k) {
//    vector<int> answer;
//    
//    int sum = 0;
//
//    int front;
//    int back = sequence.size() - 1;
//
//    for (int i = sequence.size() - 1; i >= 0; i--)
//    {
//        front = i;
//
//        sum += sequence[front];
//
//        if (sum > k || (i > 0 && sum + sequence[front - 1] - sequence[back] == k))
//        {
//            sum -= sequence[back];
//            --back;
//        }
//        else if (sum == k)
//        {
//            answer.push_back(front);
//            answer.push_back(back);
//
//            break;
//        }
//    }
//
//    return answer;
//}
//
//int main()
//{
//    //vector<int> sequence = { 1, 1, 1, 2, 3, 4, 5 };
//    //int k = 5;
//
//    vector<int> sequence = { 2, 2, 2, 2, 2 };
//    int k = 6;
//
//    vector<int> result = solution(sequence, k);
//    
//    cout << result[0] << " " << result[1] << endl;
//
//    return 0;
//}
