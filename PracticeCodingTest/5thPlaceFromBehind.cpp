#include <iostream>
// 프로그래머스 코딩테스트 연습 
// 뒤에서 5등 위로

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

using namespace std;

vector<int> solution(vector<int> num_list) {
    sort(num_list.begin(), num_list.end());

    vector<int> answer;
    answer.assign(num_list.begin() + 5, num_list.end());
    return answer;
}

int main(void) {
    vector<int> num_list = {12, 4, 15, 46, 38, 1, 14, 56, 32, 10};

    vector<int> result = solution(num_list);

    for (int& res : result)
        cout << res << endl;

    return 0;
}