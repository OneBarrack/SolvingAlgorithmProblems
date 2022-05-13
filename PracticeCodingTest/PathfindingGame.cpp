#include <iostream>
// 프로그래머스 코딩테스트 연습 
// lv.3 - 길 찾기 게임

#include <string>
#include <list>
#include <vector>
#include <queue>
#include <algorithm>
#include <stack>
#include <set>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <sstream>
#include <numeric>

using namespace std;

struct Node
{
    Node(int _x, int _num) :
        x(_x),
        num(_num),
        pLeft(nullptr),
        pRight(nullptr)
    {
    }

    ~Node()
    {
        delete pLeft;
        delete pRight;
    }

    int x;
    int num;

    Node* pLeft;
    Node* pRight;
};

class NodeGraph
{
public:
    Node* topNode;

    void Insert(Node* pInputNode)
    {
        Node* pNode = topNode;
        Node* pNextNode;

        while ( true )
        {
            if ( pNode->x < pInputNode->x )
            {
                pNextNode = pNode->pRight;
                if ( !pNextNode )
                {
                    pNode->pRight = pInputNode;
                    break;
                }
            }
            else
            {
                pNextNode = pNode->pLeft;
                if ( !pNextNode )
                {
                    pNode->pLeft = pInputNode;
                    break;
                }
            }

            pNode = pNextNode;
        }
    }

    NodeGraph() : topNode(nullptr) {}
    ~NodeGraph() { delete topNode; }
};

bool compare(vector<int> a, vector<int> b)
{
    return (a[1] > b[1] || (a[1] == b[1] && a[0] < b[0]));
}

void GetPreorder(vector<int>& result, Node* pNode)
{
    if ( !pNode )
        return;

    result.push_back(pNode->num);
    GetPreorder(result, pNode->pLeft);
    GetPreorder(result, pNode->pRight);
}

void GetPostorder(vector<int>& result, Node* pNode)
{
    if ( !pNode )
        return;

    GetPostorder(result, pNode->pLeft);
    GetPostorder(result, pNode->pRight);
    result.push_back(pNode->num);
}

vector<vector<int>> solution(vector<vector<int>> nodeinfo)
{
    vector<vector<int>> answer(2);

    for ( int i = 0; i < nodeinfo.size(); ++i )
        nodeinfo[i].push_back(i + 1);

    sort(nodeinfo.begin(), nodeinfo.end(), compare);
    NodeGraph header;
    header.topNode = new Node(nodeinfo.front()[0], nodeinfo.front()[2]);

    for ( int i = 1; i < nodeinfo.size(); ++i )
    {
        Node* pNode = new Node(nodeinfo[i][0], nodeinfo[i][2]);
        header.Insert(pNode);
    }

    GetPreorder(answer[0], header.topNode);
    GetPostorder(answer[1], header.topNode);
    return answer;
}

int main()
{
    vector<vector<int>> nodeinfo = { {5,3},{11,5},{13,3},{3,5},{6,1},{1,3},{8,6},{7,2},{2,2} };
    
    vector<vector<int>> result = solution(nodeinfo);
    for ( vector<int> res : result )
        for ( int r : res )
            cout << r << endl;

    return 0;
}