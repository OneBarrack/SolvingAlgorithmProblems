#include <iostream>
// Codility 
// Lesson 5 Medium. GenomicRangeQuery

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

int GetImpactFactor(char nucleotides)
{
    int impactFactor = 0;

    switch (nucleotides)
    {
    case 'A': impactFactor = 1; break;
    case 'C': impactFactor = 2; break;
    case 'G': impactFactor = 3; break;
    case 'T': impactFactor = 4; break;
    default:
        impactFactor = 0;
        break;
    }

    return impactFactor;
}

vector<int> solution(string& S, vector<int>& P, vector<int>& Q) {
    vector<vector<int>> dp;
    dp.reserve(S.length());

    for (size_t i = 0; i < S.length(); i++)
    {
        char& s = S[i];
        vector<int> implactFactorCounts;

        if (i == 0)
        {
            implactFactorCounts.resize(4);
        }
        else
        {
            implactFactorCounts = dp[i - 1];
        }

        int impactFactor = GetImpactFactor(s);
        if (impactFactor > 0)
        {
            ++implactFactorCounts[impactFactor - 1];
        }

        dp.push_back(implactFactorCounts);
    }

    vector<int> answer;

    for (size_t i = 0; i < P.size(); i++)
    {
        vector<int> implactFactorCounts = dp[Q[i]];

        for (int impactFactor = 0; impactFactor < 4; impactFactor++)
        {
            if (P[i] > 0)
            {
                implactFactorCounts[impactFactor] -= dp[P[i] - 1][impactFactor];
            }

            if (implactFactorCounts[impactFactor] > 0)
            {
                answer.push_back(impactFactor + 1);
                break;
            }
        }
    }

    return answer;
}

int main()
{
    string S = "CAGCCTA";
    vector<int> P = {2, 5, 0};
    vector<int> Q = {4, 5, 6};

    vector<int> result = solution(S, P, Q);
    for (int res : result)
        cout << res << endl;

    return 0;
}
