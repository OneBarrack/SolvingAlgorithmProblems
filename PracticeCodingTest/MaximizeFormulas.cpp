//#include <iostream>
//// 프로그래머스 코딩테스트 연습 
//// Lv2 수식 최대화
//
//#include <string>
//#include <list>
//#include <vector>
//#include <queue>
//#include <algorithm>
//#include <stack>
//#include <set>
//#include <map>
//
//using namespace std;
//
//long long Calculation(long long a, long long b, char operation)
//{
//    long long result = 0;
//
//    switch ( operation )
//    {
//        case '*': result = a * b; break;
//        case '+': result = a + b; break;
//        case '-': result = a - b; break;
//    }
//
//    return result;
//}
//
//long long solution(string expression)
//{
//    long long answer = 0;
//
//    vector<char> operationOrder = { '+', '-', '*' };
//    sort(operationOrder.begin(), operationOrder.end());
//
//    vector<long long> nums;
//    vector<char> operations;
//
//    string delimeter = "+-*";
//    size_t prevPos = 0;
//    while ( true )
//    {
//        size_t curPos = expression.find_first_of(delimeter, prevPos);
//        nums.push_back(stoi(expression.substr(prevPos, curPos - prevPos)));
//
//        if ( curPos == string::npos )
//            break;
//
//        operations.push_back(expression[curPos]);
//        prevPos = curPos + 1;
//    }
//
//    do
//    {
//        vector<long long> tempNums = nums;
//        vector<char> tempOperations = operations;
//        for ( char oper : operationOrder )
//        {            
//            while ( true )
//            {
//                auto iter = find(tempOperations.begin(), tempOperations.end(), oper);
//                if ( iter == tempOperations.end() )
//                    break;
//
//                int index = distance(tempOperations.begin(), iter);
//                tempNums[index] = Calculation(tempNums[index], tempNums[index + 1], tempOperations[index]);
//                
//                tempNums.erase(tempNums.begin() + index + 1);
//                tempOperations.erase(tempOperations.begin() + index);
//            }            
//        }
//        if ( answer < abs(tempNums[0]) )
//        {
//            answer = abs(tempNums[0]);
//        }
//    } while ( next_permutation(operationOrder.begin(), operationOrder.end()) );
//
//    return answer;
//}
//
//int main()
//{
//    //string expression = "100-200*300-500+20";
//    string expression = "50*6-3*2";
//
//    cout << solution(expression) << endl;
//
//    return 0;
//}