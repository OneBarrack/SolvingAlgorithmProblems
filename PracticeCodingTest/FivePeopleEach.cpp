#include <iostream>
// 프로그래머스 코딩테스트 연습 
// 5명씩

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

vector<string> solution(vector<string> names) {
    vector<string> answer;

    for (int i = 0; i < names.size(); i += 5)
    {
        answer.push_back(names[i]);
    }

    return answer;
}

int main(void) {
    vector<string> names = {"nami", "ahri", "jayce", "garen", "ivern", "vex", "jinx"};

    vector<string> result = solution(names);

    for (string& res : result)
        cout << res << endl;

    return 0;
}