//#include <iostream>
//// 프로그래머스 연습문제 : 혼자 놀기의 달인
//// 2
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
//int solution(vector<int> cards) {
//    int answer = 0;
//    priority_queue<int> pq;
//
//    int boxGroupNum = -1;
//    for (int& card : cards)
//    {        
//        if (card < 0) continue;
//        
//        int nextCardIndex = card - 1;
//        card = boxGroupNum;
//        
//        int boxCount = 1;
//        while (cards[nextCardIndex] != boxGroupNum)
//        {
//            int nextCard = cards[nextCardIndex];
//            cards[nextCardIndex] = boxGroupNum;
//            nextCardIndex = nextCard - 1;
//
//            boxCount++;
//        }
//
//        pq.push(boxCount);
//        boxGroupNum--;
//    }
//
//    if (pq.size() > 1)
//    {
//        answer = pq.top();
//        pq.pop();
//        
//        answer *= pq.top();
//    }
//
//    return answer;
//}
//
//int main(void) {
//    vector<int> cards = {8,6,3,7,2,5,1,4};
//
//    cout << solution(cards) << endl;
//
//    return 0;
//}
