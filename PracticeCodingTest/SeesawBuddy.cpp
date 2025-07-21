#include <iostream>
// 프로그래머스 연습 문제 : 시소 짝꿍
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

long long solution(vector<int> weights) {
    long long answer = 0;

    map<int, int> weightCounts;
    map<int, vector<int>> weightSums;
    map<int, set<int>> balancedWeights;

    for (int& weight : weights)
    {
        if (weightCounts[weight]++ > 0)
            continue;

        for (int& prevWeight : weightSums[weight * 2]) balancedWeights[prevWeight].insert(weight);
        for (int& prevWeight : weightSums[weight * 3]) balancedWeights[prevWeight].insert(weight);
        for (int& prevWeight : weightSums[weight * 4]) balancedWeights[prevWeight].insert(weight);

        weightSums[weight * 2].push_back(weight);
        weightSums[weight * 3].push_back(weight);
        weightSums[weight * 4].push_back(weight);
    }

    for (const pair<int,int>& weightInfo : weightCounts)
    {
        int weight = weightInfo.first;
        int weightCount = weightInfo.second;

        answer += (long long)weightCount * (weightCount - 1) / 2;
        for (int balancedWeight : balancedWeights[weight])
        {
            answer += weightCounts[balancedWeight] * weightCount;
        }
    }

    return answer;
}

int main(void) {
    //vector<int> numbers = {2, 3, 3, 5};
    vector<int> weights = {100, 180, 360, 100, 270};
    //vector<int> weights = {200, 300, 300};

    cout << solution(weights) << endl;

    return 0;
}
