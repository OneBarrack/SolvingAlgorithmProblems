//#include <iostream>
//// 프로그래머스 코딩테스트 연습 
//// Lv.Silver5 - 1427. Sort Inside
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
//시간 제한	메모리 제한	제출	정답	맞힌 사람	정답 비율
//2 초	128 MB	60108	38414	32262	64.280%
//문제
//배열을 정렬하는 것은 쉽다. 수가 주어지면, 그 수의 각 자리수를 내림차순으로 정렬해보자.
//
//입력
//첫째 줄에 정렬하려고 하는 수 N이 주어진다. N은 1,000,000,000보다 작거나 같은 자연수이다.
//
//출력
//첫째 줄에 자리수를 내림차순으로 정렬한 수를 출력한다.
//
//예제 입력 1
//2143
//예제 출력 1
//4321
//예제 입력 2
//999998999
//예제 출력 2
//999999998
//예제 입력 3
//61423
//예제 출력 3
//64321
//예제 입력 4
//500613009
//예제 출력 4
//965310000
//*/
//int main()
//{
//    int N;
//    cin >> N;
//
//    priority_queue<int> arr;
//    while ( N > 0 )
//    {
//        arr.push(N % 10);
//        N /= 10;
//    }
//
//    while ( !arr.empty() )
//    {
//        cout << arr.top();
//        arr.pop();
//    }
//
//    return 0;
//}