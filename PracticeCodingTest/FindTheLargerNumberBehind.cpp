#include <iostream>
// 프로그래머스 연습 문제 : 뒤에 있는 큰 수 찾기
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

vector<int> solution(vector<int> numbers) {
    vector<int> answer(numbers.size(), -1);

    stack<int> bigNumbers;
    for (int i = numbers.size() - 1; i >= 0; i--)
    {
        while (!bigNumbers.empty() && bigNumbers.top() <= numbers[i])
        {
            bigNumbers.pop();
        }

        if (!bigNumbers.empty())
        {
            answer[i] = bigNumbers.top();
        }

        bigNumbers.push(numbers[i]);
    }

    return answer;
}

int main(void) {
    //vector<int> numbers = {2, 3, 3, 5};
    vector<int> numbers = {9, 1, 5, 3, 6, 2};

    vector<int> results = solution(numbers);
    for (int& res : results)
        cout << res << endl;

    //cout << solution(numbers) << endl;

    return 0;
}
