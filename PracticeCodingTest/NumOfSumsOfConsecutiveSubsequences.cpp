#include <iostream>
// ���α׷��ӽ� �������� : ���� �κ� ���� ���� ����
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

int solution(vector<int> elements) {
    set<int> results;

    for (int pivot = 0; pivot < elements.size(); pivot++)
    {
        int sum = elements[pivot];
        results.insert(sum);
        
        // right
        for (int r = pivot + 1; r < elements.size(); r++)
        {
            sum += elements[r];
            results.insert(sum);
        }

        // left
        for (int l = 0; l < pivot - 1; l++)
        {
            sum += elements[l];
            results.insert(sum);
        }
    }

    return results.size();
}

int main(void) {
    vector<int> elements = {7, 9, 1, 1, 4};

    cout << solution(elements) << endl;

    return 0;
}
