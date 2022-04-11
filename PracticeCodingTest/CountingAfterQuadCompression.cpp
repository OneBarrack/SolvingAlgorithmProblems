#include <iostream>
// 프로그래머스 코딩테스트 연습 
// Lv.2 - 쿼드압축 후 개수 세기

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

vector<int> CompressQuad(vector<vector<int>> arr)
{
    vector<int> result(2);

    if ( arr.size() == 1 )
    {
        ++result[arr[0][0]];
    }
    else
    {
        int arrSize = arr.size();
        int halfArrSize = arr.size() / 2;
        vector<vector<int>> subArr(halfArrSize, vector<int>(halfArrSize));
        vector<vector<int>> subCompressResult;

        // 1사분면
        for ( int row = 0, subRow = 0; row < halfArrSize; ++row, ++subRow )
        {
            for ( int col = halfArrSize, subCol = 0; col < arrSize; ++col, ++subCol )
            {
                subArr[subRow][subCol] = arr[row][col];
            }
        }
        subCompressResult.push_back(CompressQuad(subArr));

        // 2사분면
        for ( int row = 0, subRow = 0; row < halfArrSize; ++row, ++subRow )
        {
            for ( int col = 0, subCol = 0; col < halfArrSize; ++col, ++subCol )
            {
                subArr[subRow][subCol] = arr[row][col];
            }
        }
        subCompressResult.push_back(CompressQuad(subArr));

        // 3사분면
        for ( int row = halfArrSize, subRow = 0; row < arrSize; ++row, ++subRow )
        {
            for ( int col = 0, subCol = 0; col < halfArrSize; ++col, ++subCol )
            {
                subArr[subRow][subCol] = arr[row][col];
            }
        }
        subCompressResult.push_back(CompressQuad(subArr));

        // 4사분면
        for ( int row = halfArrSize, subRow = 0; row < arrSize; ++row, ++subRow )
        {
            for ( int col = halfArrSize, subCol = 0; col < arrSize; ++col, ++subCol )
            {
                subArr[subRow][subCol] = arr[row][col];
            }
        }
        subCompressResult.push_back(CompressQuad(subArr));

        for ( vector<int> subRes : subCompressResult )
        {
            result[0] += subRes[0];
            result[1] += subRes[1];
        }
    }

    if ( result[0] == 4 && result[1] == 0 )      result[0] = 1;
    else if ( result[0] == 0 && result[1] == 4 ) result[1] = 1;

    return result;
}

vector<int> solution(vector<vector<int>> arr)
{
    return CompressQuad(arr);
}

int main()
{
    //vector<vector<int>> arr = { {1,1,0,0} ,{1,0,0,0}, {1,0,0,1}, {1,1,1,1} };
    vector<vector<int>> arr = { 
        {1, 1, 1, 1, 1, 1, 1, 1},
        {0, 1, 1, 1, 1, 1, 1, 1},
        {0, 0, 0, 0, 1, 1, 1, 1},
        {0, 1, 0, 0, 1, 1, 1, 1},
        {0, 0, 0, 0, 0, 0, 1, 1},
        {0, 0, 0, 0, 0, 0, 0, 1},
        {0, 0, 0, 0, 1, 0, 0, 1},
        {0, 0, 0, 0, 1, 1, 1, 1} };
    vector<int> result = solution(arr);

    for ( int res : result )
        cout << res << endl;

    return 0;
}