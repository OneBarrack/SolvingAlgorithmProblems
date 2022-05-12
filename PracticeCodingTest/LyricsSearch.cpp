//#include <iostream>
//// 프로그래머스 코딩테스트 연습 
//// lv.4 - 가사 검색
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
//#include <unordered_set>
//#include <sstream>
//#include <numeric>
//
//using namespace std;
//
//class Node
//{
//public:
//    unordered_map<int, int> LinkedNodeCountForSize;
//    unordered_map<char, Node*> nextNodes;
//
//    ~Node()
//    {
//        for ( auto nextNodeInfo : nextNodes )
//            delete nextNodeInfo.second;
//    }
//};
//
//class Trie
//{
//public:
//    Node headerNode;
//
//    void InsertWord(string word)
//    {
//        Node* node = &headerNode;
//        for ( char c : word )
//        {
//            node->LinkedNodeCountForSize[word.size()]++;
//            if ( !node->nextNodes[c] )
//                node->nextNodes[c] = new Node;
//            node = node->nextNodes[c];
//        }
//        node->LinkedNodeCountForSize[word.size()]++;
//    }
//
//    int GetMatchWord(string word)
//    {
//        int count = 0;
//
//        vector<Node*> nodeList;
//        nodeList.push_back(&headerNode);
//
//        for ( char c : word )
//        {
//            if ( c == '?' )
//                break;
//
//            vector<Node*> nextNodeList;
//
//            for ( Node* node : nodeList )
//            {
//                if ( node->nextNodes.find(c) != node->nextNodes.end() )
//                {
//                    nextNodeList.push_back(node->nextNodes[c]);
//                }
//            }
//
//            nodeList = nextNodeList;
//        }
//
//        for ( Node* node : nodeList )
//        {
//            count += node->LinkedNodeCountForSize[word.size()];
//        }
//
//        return count;
//    }
//};
//
//vector<int> solution(vector<string> words, vector<string> queries)
//{
//    vector<int> answer;
//    Trie header;
//    Trie reverseHeader;
//
//    for ( string word : words )
//    {
//        header.InsertWord(word);
//        reverse(word.begin(), word.end());
//        reverseHeader.InsertWord(word);
//    }
//
//    for ( string query : queries )
//    {
//        if ( query[0] == '?' )
//        {
//            reverse(query.begin(), query.end());
//            answer.push_back(reverseHeader.GetMatchWord(query));
//        }
//        else
//        {
//            answer.push_back(header.GetMatchWord(query));
//        }
//    }
//
//    return answer;
//}
//
//int main()
//{
//    vector<string> words = { "frodo", "front", "frost", "frozen", "frame", "kakao" }; 
//    vector<string> queries = { "fro??", "????o", "fr???", "fro???", "pro?" };
//    //[3, 2, 4, 1, 0]
//
//    vector<int> result = solution(words, queries);
//    for ( int res : result )
//        cout << res << endl;
//
//    return 0;
//}