#include <iostream>
// 프로그래머스 코딩테스트 연습 
// Lv2 단체사진 찍기

#include <string>
#include <list>
#include <vector>
#include <queue>
#include <algorithm>
#include <stack>
#include <set>

using namespace std;

void MakeNames(vector<string>& resultNames, int n, vector<string> nameList, string nameOrderStr)
{
    nameOrderStr += nameList[n];
    nameList.erase(nameList.begin() + n);

    if ( nameList.empty() )
    {
        resultNames.push_back(nameOrderStr);
        return;
    }

    for ( int i = 0; i < nameList.size(); ++i )
    {
        MakeNames(resultNames, i, nameList, nameOrderStr);
    }
}

int solution(int n, vector<string> data)
{
    int answer = 0;
    vector<string> resultNames;

    vector<string> nameList = { "A", "C", "F", "J", "M", "N", "R", "T" };
    for ( int i = 0; i < nameList.size(); ++i )
    {
        MakeNames(resultNames, i, nameList, "");
    }

    for ( string name : resultNames )
    {
        bool bCorrect = true;
        for ( string dataCondition : data )
        {
            int pos1 = name.find(dataCondition[0]);
            int pos2 = name.find(dataCondition[2]);
            char oper = dataCondition[3];
            int conditionDist = dataCondition[4] - '0';
            int dist = abs(pos2 - pos1) - 1;

            if ( (oper == '=' && dist == conditionDist) ||
                (oper == '>' && dist > conditionDist) ||
                (oper == '<' && dist < conditionDist) )
            {
                continue;
            }

            bCorrect = false;
            break;
        }

        if ( bCorrect )
        {
            ++answer;
        }
    }

    return answer;
}

int main()
{
    int n = 2;
    vector<string> data = { "N~F=0", "R~T>2" };
    cout << solution(n, data) << endl;

    return 0;
}