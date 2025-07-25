#include <iostream>
// 프로그래머스 연습문제 : 테이블 해시 함수
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

int solution(vector<vector<int>> data, int col, int row_begin, int row_end) {
    int answer = 0;

    sort(data.begin(), data.end(), [col](const vector<int>& dataA, const vector<int>& dataB) {
        return (dataA[col - 1] == dataB[col - 1]) ? dataA[0] > dataB[0] : dataA[col - 1] < dataB[col - 1];
        });

    for (int i = row_begin; i <= row_end; i++)
    {
        int valueS = 0;
        for (int& d : data[i - 1])
        {
            valueS += d % i;
        }
        answer ^= valueS;
    }

    return answer;
}

int main(void) {
    vector<vector<int>> data = {{2,2,6}, {1,5,10}, {4,2,9}, {3,8,3}};
    int col = 2;
    int row_begin = 2;
    int row_end = 3;

    cout << solution(data, col, row_begin, row_end) << endl;

    return 0;
}
