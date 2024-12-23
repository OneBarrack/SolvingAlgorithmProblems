#include <iostream>
// 프로그래머스 코딩테스트 연습 
// n개 간격의 원소들

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

vector<int> solution(vector<int> num_list, int n) {
    vector<int> answer;

    for (int i = 0; i < num_list.size(); i += n)
    {
        answer.push_back(num_list[i]);
    }

    return answer;
}

int main()
{
    vector<int> num_list = {4, 2, 6, 1, 7, 6};
    int n = 2;

    vector<int> result = solution(num_list, n);

    for ( int res : result )
        cout << res << endl;

    return 0;
}