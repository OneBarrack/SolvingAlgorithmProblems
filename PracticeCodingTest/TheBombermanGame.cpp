//#include <iostream>
//// 해커랭크 코딩테스트 연습 
//// Lv.Medium - The Bomberman Game
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
//vector<string> bomberMan(int n, vector<string> grid)
//{
//    int row = grid.size();
//    int col = grid[0].size();
//    vector<string> bombAllGrid(row, string(col, 'O'));
//    vector<string> grid1 = bombAllGrid;
//    vector<string> grid2 = bombAllGrid;
//
//    for ( int i = 0; i < row; ++i )
//    {
//        for ( int j = 0; j < col; ++j )
//        {
//            if ( grid[i][j] == 'O' )
//            {
//                grid1[i][j] = '.';
//                if ( i > 0 )       grid1[i - 1][j] = '.';
//                if ( i < row - 1 ) grid1[i + 1][j] = '.';
//                if ( j > 0 )       grid1[i][j - 1] = '.';
//                if ( j < col - 1 ) grid1[i][j + 1] = '.';
//            }
//        }
//    }
//
//    for ( int i = 0; i < row; ++i )
//    {
//        for ( int j = 0; j < col; ++j )
//        {
//            if ( grid1[i][j] == 'O' )
//            {
//                grid2[i][j] = '.';
//                if ( i > 0 )       grid2[i - 1][j] = '.';
//                if ( i < row - 1 ) grid2[i + 1][j] = '.';
//                if ( j > 0 )       grid2[i][j - 1] = '.';
//                if ( j < col - 1 ) grid2[i][j + 1] = '.';
//            }
//        }
//    }
//
//    vector<vector<string>> gridSequence = { grid2, bombAllGrid, grid1, bombAllGrid };
//    return (n == 1) ? grid : gridSequence[(n - 1) % 4];
//}
//
//int main()
//{
//    int n = 3;
//    vector<string> grid = {
//        ".......",
//        "...O...",
//        "....O..",
//        ".......",
//        "OO.....",
//        "OO....."
//    };
//
//    vector<string> result = bomberMan(n, grid);
//    for ( string s : result )
//        cout << s << endl;
//
//    return 0;
//}