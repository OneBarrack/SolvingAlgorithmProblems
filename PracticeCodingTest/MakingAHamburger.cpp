//#include <iostream>
//// 코딜리티 코딩테스트 연습 
//// 연습문제. 햄버거 만들기
//
//#include <string>
//#include <vector>
//#include <queue>
//#include <set>
//#include <algorithm>
//#include <unordered_map>
//#include <numeric>
//#include <stack>
//#include <map>
//
//using namespace std;
//
//int solution(vector<int> ingredient) {
//    int answer = 0;
//
//    vector<int> ingredientStack;
//    for (int i = 0; i < ingredient.size(); i++)
//    {
//        ingredientStack.push_back(ingredient[i]);
//        if (ingredientStack.size() < 4)
//            continue;
//
//        if (ingredientStack[ingredientStack.size() - 4] == 1 &&
//            ingredientStack[ingredientStack.size() - 3] == 2 &&
//            ingredientStack[ingredientStack.size() - 2] == 3 &&
//            ingredientStack[ingredientStack.size() - 1] == 1)
//        {
//            ingredientStack.resize(ingredientStack.size() - 4);
//
//            ++answer;
//        }
//    }
//
//    return answer;
//}
//
//int main()
//{
//    vector<int> ingredient = {2, 1, 1, 2, 3, 1, 2, 3, 1};
//
//    cout << solution(ingredient) << endl;
//
//    return 0;
//}
