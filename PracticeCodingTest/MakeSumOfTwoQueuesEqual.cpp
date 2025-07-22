#include <iostream>
// 프로그래머스 2022 KAKAO TECH INTERNSHIP : 두 큐 합 같게 만들기
// 2

#include <string>
#include <list>
#include <vector>
#include <queue>
#include <algorithm>
#include <stack>
#include <set>
#include <map>
#include <unordered_map>
#include <sstream>
#include <numeric>

using namespace std;

int solution(vector<int> queue1, vector<int> queue2) {
    long long sumA = accumulate(queue1.begin(), queue1.end(), 0LL);
    long long sumB = accumulate(queue2.begin(), queue2.end(), 0LL);
    long long goal = (sumA + sumB) / 2;

    int pivotA = 0;
    int pivotB = 0;
    int count = 0;
    while (true)
    {
        if (sumA == goal) return count;

        if (pivotA == queue1.size() || pivotB == queue2.size())
            break;

        if (sumA > goal)
        {
            sumA -= queue1[pivotA];
            pivotA++;
        }
        else
        {
            sumA += queue2[pivotB];
            queue1.push_back(queue2[pivotB]);
            pivotB++;
        }

        count++;
    }

    return -1;
}

int main(void) {
    vector<int> queue1 = {3, 2, 7, 2};
    vector<int> queue2 = {4, 6, 5, 1};
    //vector<int> queue1 = {1, 2, 1, 2};
    //vector<int> queue2 = {1, 10, 1, 2};
    //vector<int> queue1 = {1, 1};
    //vector<int> queue2 = {1, 5};

    cout << solution(queue1, queue2) << endl;

    return 0;
}
