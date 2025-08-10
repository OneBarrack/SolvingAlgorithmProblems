//#include <iostream>
//// 프로그래머스 2024 KAKAO WINTER INTERNSHIP : 가장 많이 받은 선물
//// 1
//
//#include <string>
//#include <list>
//#include <vector>
//#include <queue>
//#include <algorithm>
//#include <stack>
//#include <set>
//#include <map>
//#include <unordered_set>
//#include <unordered_map>
//#include <sstream>
//#include <numeric>
//
//using namespace std;
//
//unordered_map<string, int> GetIndexByNameMap(const vector<string>& friends)
//{
//    unordered_map<string, int> indexByNameMap;
//
//    for (int i = 0; i < friends.size(); i++)
//    {
//        indexByNameMap[friends[i]] = i;
//    }
//
//    return indexByNameMap;
//}
//
//vector<vector<int>> GetNumOfGiftGive(const vector<string>& gifts, const unordered_map<string, int>& indexByNameMap)
//{
//    const int n = (int)indexByNameMap.size();
//    vector<vector<int>> numOfGiftGive(n, vector<int>(n));
//
//    for (const string& gift : gifts)
//    {
//        stringstream ss(gift);
//        string name1; ss >> name1;
//        string name2; ss >> name2;
//
//        auto it1 = indexByNameMap.find(name1);
//        auto it2 = indexByNameMap.find(name2);
//        if (it1 != indexByNameMap.end() && it2 != indexByNameMap.end()) 
//        {
//            numOfGiftGive[it1->second][it2->second]++;
//        }
//    }
//
//    return numOfGiftGive;
//}
//
//vector<int> GetGiftIndices(const vector<vector<int>>& numOfGiftGive)
//{
//    const int n = (int)numOfGiftGive.size();
//    vector<int> giftIndices(n);
//
//    for (int i = 0; i < n; i++)
//    {
//        for (int j = 0; j < n; j++)
//        {
//            giftIndices[i] += numOfGiftGive[i][j] - numOfGiftGive[j][i];
//        }
//    }
//
//    return giftIndices;
//}
//
//vector<int> GetNumOfGiftsToReceiveNextMonth(const vector<vector<int>>& numOfGiftGive, const vector<int>& giftIndices)
//{
//    const int n = (int)numOfGiftGive.size();
//    vector<int> numOfGiftsToReceiveNextMonth(n);
//
//    for (int i = 0; i < n - 1; i++)
//    {
//        for (int j = i + 1; j < n; j++)
//        {
//            int giveCountA = numOfGiftGive[i][j];
//            int giveCountB = numOfGiftGive[j][i];
//
//            if (giveCountA == giveCountB)
//            {
//                if (giftIndices[i] != giftIndices[j])
//                {
//                    if (giftIndices[i] > giftIndices[j])
//                    {
//                        numOfGiftsToReceiveNextMonth[i]++;
//                    }
//                    else
//                    {
//                        numOfGiftsToReceiveNextMonth[j]++;
//                    }
//                }
//                continue;
//            }
//
//            if (giveCountA > giveCountB)
//            {
//                numOfGiftsToReceiveNextMonth[i]++;
//            }
//            else
//            {
//                numOfGiftsToReceiveNextMonth[j]++;
//            }
//        }
//    }
//
//    return numOfGiftsToReceiveNextMonth;
//}
//
//int solution(vector<string> friends, vector<string> gifts) {
//    unordered_map<string, int> indexByNameMap = GetIndexByNameMap(friends);
//    vector<vector<int>> numOfGiftGive = GetNumOfGiftGive(gifts, indexByNameMap);
//    vector<int> giftIndices = GetGiftIndices(numOfGiftGive);
//    vector<int> numOfGiftsToReceiveNextMonth = GetNumOfGiftsToReceiveNextMonth(numOfGiftGive, giftIndices);
//
//    return *max_element(numOfGiftsToReceiveNextMonth.begin(), numOfGiftsToReceiveNextMonth.end());
//}
//
//int main(void)
//{
//    vector<string> friends = {"muzi", "ryan", "frodo", "neo"};
//    vector<string> gifts = {"muzi frodo", "muzi frodo", "ryan muzi", "ryan muzi", "ryan muzi", "frodo muzi", "frodo ryan", "neo muzi"};
//
//    //vector<string> friends = {"joy", "brad", "alessandro", "conan", "david"};
//    //vector<string> gifts = {"alessandro brad", "alessandro joy", "alessandro conan", "david alessandro", "alessandro david"};
//
//    //vector<string> friends = {"a", "b", "c"};
//    //vector<string> gifts = {"a b", "b a", "c a", "a c", "a c", "c a"};
//
//    cout << solution(friends, gifts) << endl;
//
//    return 0;
//}
