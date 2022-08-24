#include <iostream>
// ���α׷��ӽ� �ڵ��׽�Ʈ ���� 
// Lv.Silver5 - 1427. Sort Inside

#include <string>
#include <vector>
#include <queue>
#include <set>
#include <algorithm>
#include <unordered_map>
#include <numeric>
#include <stack>
#include <map>

using namespace std;

/*
�ð� ����	�޸� ����	����	����	���� ���	���� ����
2 ��	128 MB	60108	38414	32262	64.280%
����
�迭�� �����ϴ� ���� ����. ���� �־�����, �� ���� �� �ڸ����� ������������ �����غ���.

�Է�
ù° �ٿ� �����Ϸ��� �ϴ� �� N�� �־�����. N�� 1,000,000,000���� �۰ų� ���� �ڿ����̴�.

���
ù° �ٿ� �ڸ����� ������������ ������ ���� ����Ѵ�.

���� �Է� 1
2143
���� ��� 1
4321
���� �Է� 2
999998999
���� ��� 2
999999998
���� �Է� 3
61423
���� ��� 3
64321
���� �Է� 4
500613009
���� ��� 4
965310000
*/
int main()
{
    int N;
    cin >> N;

    priority_queue<int> arr;
    while ( N > 0 )
    {
        arr.push(N % 10);
        N /= 10;
    }

    while ( !arr.empty() )
    {
        cout << arr.top();
        arr.pop();
    }

    return 0;
}