#include <iostream>
// 코딜리티 코딩테스트 연습 
// 연습문제. 할 일 목록

#include <string>
#include <vector>
#include <queue>
#include <set>
#include <algorithm>
#include <unordered_map>
#include <numeric>
#include <stack>
#include <map>

using namespace std;

vector<string> solution(vector<string> todo_list, vector<bool> finished) {
    vector<string> answer;

    for (int i = 0; i < todo_list.size(); i++)
    {
        if (!finished[i])
        {
            answer.push_back(todo_list[i]);
        }
    }

    return answer;
}

int main()
{
    vector<string> todo_list = {"problemsolving", "practiceguitar", "swim", "studygraph"};
    vector<bool> finished = {true, false, true, false};

    vector<string> result = solution(todo_list, finished);

    for (string res : result)
        cout << res << endl;

    return 0;
}
