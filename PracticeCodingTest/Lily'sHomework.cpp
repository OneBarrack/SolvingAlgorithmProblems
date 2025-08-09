//#include <iostream>
//// HackerRank Prepare algorithms : Lily's Homework
//// Medium
//
//#include <string>
//#include <list>
//#include <vector>
//#include <queue>
//#include <algorithm>
//#include <stack>
//#include <set>
//#include <map>
//#include <unordered_map>
//#include <sstream>
//#include <numeric>
//
//using namespace std;
//
///*
// * Complete the 'lilysHomework' function below.
// *
// * The function is expected to return an INTEGER.
// * The function accepts INTEGER_ARRAY arr as parameter.
// */
//
//int GetSwapCount(vector<int> arr, map<int, int> numMap, bool bReverse)
//{
//    int swapCount = 0;
//
//    int index = bReverse ? arr.size() - 1 : 0;
//    auto iter = numMap.begin();
//    while (iter != numMap.end())
//    {
//        bool bMisMatched = bReverse ? iter->second < index : iter->second > index;
//        if (bMisMatched)
//        {
//            numMap[arr[index]] = iter->second;
//            arr[iter->second] = arr[index];
//            swapCount++;
//        }
//
//        bReverse ? index-- : index++;
//        iter++;
//    }
//
//    return swapCount;
//}
//
//int lilysHomework(vector<int> arr) {
//    map<int, int> numMap;
//    for (int i = 0; i < arr.size(); i++)
//    {
//        numMap[arr[i]] = i;
//    }
//
//    return min(GetSwapCount(arr, numMap, true), GetSwapCount(arr, numMap, false));
//}
//
//int main(void)
//{
//    vector<int> arr = {2, 5, 3, 1};
//
//    cout << lilysHomework(arr) << endl;
//
//    return 0;
//}
