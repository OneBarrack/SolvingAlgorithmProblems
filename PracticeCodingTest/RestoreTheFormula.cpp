#include <iostream>
// 프로그래머스 [PCCP 기출문제] 4번 : 수식 복원하기
// 3

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

enum class EExpressionElement : uint8_t
{
    ValueA = 0,
    PlusOrMinusSign,
    ValueB,
    ValueC
};

string ConvertDecimalNumberSystem(int n, int numberSystem)
{
    if (n == 0) return "0";

    string result = "";
    while (n > 0)
    {
        result += to_string(n % numberSystem);
        n /= numberSystem;
    }

    reverse(result.begin(), result.end());
    return result;
}

bool ConvertToDecimal(string numStr, int numberSystem, int& outDecimal)
{
    int result = 0;
    for (int i = numStr.size() - 1, power = 0; i >= 0; i--, power++)
    {
        char c = numStr[i];
        if (!isdigit(c))
        {
            return false;
        }

        result += (c - '0') * pow(numberSystem, power);
    }

    outDecimal = result;
    return true;
}

bool IsValidNumberSystem(vector<string> expression, int numberSystem)
{
    if (expression.size() < 3)
        return false;

    int decimalValue1, decimalValue2, decimalValue3;
    if (ConvertToDecimal(expression[static_cast<int>(EExpressionElement::ValueA)], numberSystem, decimalValue1) &&
        ConvertToDecimal(expression[static_cast<int>(EExpressionElement::ValueB)], numberSystem, decimalValue2) &&
        ConvertToDecimal(expression[static_cast<int>(EExpressionElement::ValueC)], numberSystem, decimalValue3))
    {
        int sign = (expression[static_cast<int>(EExpressionElement::PlusOrMinusSign)] == "-") ? -1 : 1;
        return decimalValue1 + (decimalValue2 * sign) == decimalValue3;
    }

    return false;
}

vector<int> GetValidNumberSystems(vector<string> expression, vector<int> numberSystems)
{
    vector<int> validNumberSystems;

    for (int& numberSystem : numberSystems)
    {
        if (IsValidNumberSystem(expression, numberSystem))
        {
            validNumberSystems.push_back(numberSystem);
        }
    }

    return validNumberSystems;
}

void GroupByVeryfiedExpressions(vector<string> expressions, vector<vector<string>>& verifiedExpressions, vector<vector<string>>& unverifiedExpressions, int& minNumberSystem)
{
    for (string& expression : expressions)
    {
        bool bIsVeryfied = (expression.back() != 'X') ? true : false;
        vector<string> elements;

        stringstream ssExpression(expression);
        string element;
        while (ssExpression >> element)
        {
            if (element == "=" || element == "X")
            {
                continue;
            }

            elements.push_back(element);
            minNumberSystem = max(minNumberSystem, *max_element(element.begin(), element.end()) - '0' + 1);
        }

        if (bIsVeryfied)
        {
            verifiedExpressions.push_back(elements);
        }
        else
        {
            unverifiedExpressions.push_back(elements);
        }
    }
}

vector<string> solution(vector<string> expressions) {
    vector<string> answer;    
    
    vector<vector<string>> verifiedExpressions;
    vector<vector<string>> unverifiedExpressions;
    int minNumberSystem = 0;
    GroupByVeryfiedExpressions(expressions, verifiedExpressions, unverifiedExpressions, minNumberSystem);
    
    vector<int> numberSystems;
    for (int i = minNumberSystem; i <= 9; i++)
    {
        numberSystems.push_back(i);
    }
    
    // Extract valid number systems
    for (vector<string>& verifiedExpression : verifiedExpressions)
    {
        numberSystems = GetValidNumberSystems(verifiedExpression, numberSystems);
    }

    // Derive C
    for (vector<string>& unverifiedExpression : unverifiedExpressions)
    {
        string valueA = unverifiedExpression[static_cast<int>(EExpressionElement::ValueA)];
        string plusOrMinusSign = unverifiedExpression[static_cast<int>(EExpressionElement::PlusOrMinusSign)];
        string valueB = unverifiedExpression[static_cast<int>(EExpressionElement::ValueB)];
        string valueC = "?";
                
        set<string> calcResults;
        for (int numberSystem : numberSystems)
        {
            int decimalValue1, decimalValue2;
            if (ConvertToDecimal(valueA, numberSystem, decimalValue1) &&
                ConvertToDecimal(valueB, numberSystem, decimalValue2))
            {
                int sign = (plusOrMinusSign == "-") ? -1 : 1;
                calcResults.insert(ConvertDecimalNumberSystem(decimalValue1 + (decimalValue2 * sign), numberSystem));
            }
        }

        if (calcResults.size() == 1)
        {
            valueC = *calcResults.begin();
        }

        // result
        string result = valueA + " " + plusOrMinusSign + " " + valueB + " = " + valueC;
        answer.push_back(result);
    }

    return answer;
}

int main(void) {
    vector<string> expressions = {"14 + 3 = 17", "13 - 6 = X", "51 - 5 = 44"};
    //vector<string> expressions = {"1 + 1 = 2", "1 + 3 = 4", "1 + 5 = X", "1 + 2 = X"};
    //vector<string> expressions = {"10 - 2 = X", "30 + 31 = 101", "3 + 3 = X", "33 + 33 = X"};
    //vector<string> expressions = {"2 - 1 = 1", "2 + 2 = X", "7 + 4 = X", "5 - 5 = X"};
    //vector<string> expressions = {"2 - 1 = 1", "2 + 2 = X", "7 + 4 = X", "8 + 4 = X"};
    
    vector<string> result = solution(expressions);
    for (string& res : result)
        cout << res << endl;

    //cout << solution(nodes, edges) << endl;

    return 0;
}
