#include <string>
#include <vector>
#include <algorithm>

using namespace std;

typedef struct node
{
	int num;
	int x, y;
	node *left;
	node *right;
}node;

bool comp(node &a, node &b) 
{
	if (a.y == b.y) 
	{
		return a.x < b.x;
	}
	return a.y > b.y;
}

// 루트 -> 왼쪽 -> 오른쪽
void PreOrder(vector<int> &answer, node *n) 
{
	if (n == NULL) return;
		
	answer.push_back(n->num);
	PreOrder(answer, n->left);
	PreOrder(answer, n->right);
}

// 왼쪽 -> 오른쪽 -> 루트
void PostOrder(vector<int> &answer, node *n) 
{
	if (n == NULL) return;
		
	PostOrder(answer, n->left);
	PostOrder(answer, n->right);
	answer.push_back(n->num);
}

void AddNode(node &parent, node &child) 
{
	if (parent.x > child.x)
	{
		if (parent.left == NULL) 
		{
			parent.left = &child;
		}
		else 
		{
			AddNode(*parent.left, child);
		}
	}
	else 
	{
		if (parent.right == NULL) 
		{
			parent.right = &child;
		}
		else 
		{
			AddNode(*parent.right, child);
		}
	}
}

vector<vector<int>> solution(vector<vector<int>> nodeinfo) 
{
	vector<vector<int>> answer;
	answer.resize(2);

	vector<node> n;

	for (int i = 0; i < nodeinfo.size(); i++)
	{
		int x = nodeinfo[i][0];
		int y = nodeinfo[i][1];
		n.push_back({ i + 1, x, y, NULL, NULL });
	}

	sort(n.begin(), n.end(), comp); // 트리 만들기 전 정렬

	for (int i = 1; i < nodeinfo.size(); i++) // 트리에 노드 추가
	{
		AddNode(n[0], n[i]);
	}

	PreOrder(answer[0], &n[0]); // 전위 탐색
	PostOrder(answer[1], &n[0]); // 후위 탐색

	return answer;
}
