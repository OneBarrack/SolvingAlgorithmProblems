#include <iostream>
// 해커랭크 코딩테스트 연습 
// Lv.Medium - Attribute Parser

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

class Tag
{
public:
    Tag* prevTag;
    unordered_map<string, Tag*> nextTags;
    unordered_map<string, string> values;

    Tag() { prevTag = nullptr; }
    ~Tag()
    {
        for ( auto iter = nextTags.begin(); iter != nextTags.end(); ++iter )
        {
            delete iter->second;
        }
    }
};

int main()
{
    int N, Q;
    cin >> N >> Q;
    string line;
    getline(cin, line);

    Tag tagHeader;

    Tag* curTag = &tagHeader;
    for ( int i = 0; i < N; ++i )
    {
        string HRML;
        string tagName, attributeName, attributeValue;

        getline(cin, HRML);
        HRML = HRML.substr(1, HRML.size() - 2); // remove '<' '>'

        stringstream ss(HRML);
        string s;
        getline(ss, s, ' ');
        if ( s[0] != '/' ) // Open
        {
            tagName = s;

            Tag* tempTag = new Tag;
            tempTag->prevTag = curTag;

            while ( getline(ss, s, ' ') )
            {
                attributeName = s;
                getline(ss, s, ' ');
                getline(ss, s, '"');
                getline(ss, s, '"');
                attributeValue = s;
                getline(ss, s, ' ');

                tempTag->values[attributeName] = attributeValue;
            }

            curTag->nextTags[tagName] = tempTag;
            curTag = tempTag;
        }
        else // Close
        {
            curTag = curTag->prevTag;
        }
    }

    for ( int i = 0; i < Q; ++i )
    {
        curTag = &tagHeader;

        string tagName, attributeName, attributeValue;

        string query;
        getline(cin, query);

        stringstream ss1(query);
        string s1;

        getline(ss1, s1, '~');

        stringstream ss2(s1);
        string s2;
        bool bFindTag = true;
        while ( getline(ss2, s2, '.') )
        {
            tagName = s2;

            if ( curTag->nextTags.find(tagName) == curTag->nextTags.end() )
            {
                cout << "Not Found!" << endl;
                bFindTag = false;
                break;
            }

            curTag = curTag->nextTags[tagName];
        }

        if ( bFindTag )
        {
            getline(ss1, s1, ' ');
            attributeName = s1;

            if ( curTag->values.find(attributeName) != curTag->values.end() )
            {
                attributeValue = curTag->values[attributeName];
            }
            else
            {
                attributeValue = "Not Found!";
            }

            cout << attributeValue << endl;
        }
    }

    return 0;
}