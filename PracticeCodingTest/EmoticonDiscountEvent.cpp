#include <iostream>
// 프로그래머스 2023 KAKAO BLIND RECRUITMENT : 이모티콘 할인행사
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

void SumEmoticonPrices(const vector<vector<int>>& users, const vector<int>& emoticons, const int emoticonIndex, vector<int>& answer, map<int, int> discountedPricesSum = map<int, int>())
{
    static const vector<int> discountRates = {10, 20, 30, 40};

    if (emoticonIndex == emoticons.size())
    {
        int signupCount = 0;
        int totalSales = 0;

        for (vector<int> user : users)
        {
            int goalDiscountPrice = ceil(user[0] / 10.0f) * 10;
            int totalPurchaseCost = 0;

            while (goalDiscountPrice <= discountRates.back())
            {
                totalPurchaseCost += discountedPricesSum[goalDiscountPrice];
                goalDiscountPrice += 10;
            }

            if (totalPurchaseCost < user[1])
            {
                totalSales += totalPurchaseCost;
            }
            else
            {
                signupCount++;
            }
        }

        if (answer[0] <= signupCount)
        {
            answer[1] = (answer[0] == signupCount) ? max(answer[1], totalSales) : totalSales;
            answer[0] = signupCount;
        }

        return;
    }

    for (int discountRate : discountRates)
    {
        int discountedPrice = emoticons[emoticonIndex] * ((100 - discountRate) / 100.0f);

        map<int, int> nextDiscountedPricesSum = discountedPricesSum;
        nextDiscountedPricesSum[discountRate] += discountedPrice;

        SumEmoticonPrices(users, emoticons, emoticonIndex + 1, answer, nextDiscountedPricesSum);
    }
}

vector<int> solution(vector<vector<int>> users, vector<int> emoticons) {
    vector<int> answer(2);
    SumEmoticonPrices(users, emoticons, 0, answer);
    return answer;
}

int main(void) {
    //vector<vector<int>> users = {{40, 10000}, {25, 10000}};
    //vector<int> emoticons = {7000, 9000};
    
    vector<vector<int>> users = {{40, 2900} ,{23, 10000}, {11, 5200}, {5, 5900}, {40, 3100}, {27, 9200}, {32, 6900}};
    vector<int> emoticons = {1300, 1500, 1600, 4900};

    vector<int> result = solution(users, emoticons);
    for (int res : result)
        cout << res << endl;
    
    //cout << solution(order) << endl;

    return 0;
}
