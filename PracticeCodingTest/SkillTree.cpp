#include <iostream>
// 프로그래머스 코딩테스트 연습 
// Lv.2 - 스킬트리

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

int solution(string skill, vector<string> skill_trees)
{
    int answer = 0;

    unordered_map<char, int> isLinearSkill;
    queue<char> linearSkills;

    for ( char c : skill )
    {
        isLinearSkill[c] = 1;
        linearSkills.push(c);
    }

    for ( string skillTree : skill_trees )
    {
        queue<char> curLinearSkills = linearSkills;
        bool isCorrectSkillTree = true;

        for ( char c : skillTree )
        {
            if ( curLinearSkills.empty() )
                break;

            if ( isLinearSkill.find(c) != isLinearSkill.end() )
            {
                if ( c == curLinearSkills.front() )
                {
                    curLinearSkills.pop();
                    continue;
                }

                isCorrectSkillTree = false;
                break;
            }
        }

        if ( isCorrectSkillTree )
        {
            ++answer;
        }
    }

    return answer;
}

int main()
{
    string skill = "CBD";
    vector<string> skill_trees = { "BACDE", "CBADF", "AECB", "BDA" };

    cout << solution(skill, skill_trees) << endl;

    return 0;
}