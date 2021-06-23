#include <vector>
#include <iostream>
#include <string>
#include <set>
#include <algorithm>
#define endl "\n"
#define MAX 16

using namespace std;

typedef struct {
	int p;
	int f;
	int c;
	int v;
	int price;
}GRADIENT;

GRADIENT gradient[MAX];
int N;
int mp, mf, mc, mv;
int max_money = 1e9;
int max_cnt;
vector<int> index_vector, answer;

void init()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
}

void dfs(int idx, int sp, int sf, int sc, int sv, int sum_price)
{
	if (sp >= mp && sf >= mf && sc >= mc && sv >= mv && sum_price < max_money)
	{
		max_money = sum_price;
		answer = index_vector;
		return;
	}

	if (idx > N) return;

	index_vector.push_back(idx);
	dfs(idx+1 , sp + gradient[idx].p, sf + gradient[idx].f, sc + gradient[idx].c, sv + gradient[idx].v, sum_price + gradient[idx].price);
	index_vector.pop_back();

	dfs(idx + 1, sp, sf , sc , sv , sum_price);
}

int main(void)
{
	init();
	cin >> N;

	cin >> mp >> mf >> mc >> mv;

	for (int i = 1; i <= N; i++)
	{
		cin >> gradient[i].p >> gradient[i].f >> gradient[i].c >> gradient[i].v >> gradient[i].price;
	}
	
	dfs(1, 0, 0, 0, 0, 0);

	if (max_money == 1e9) 
	{
		cout << "-1";
	}
	else 
	{
		cout << max_money << endl;

		sort(answer.begin(), answer.end());

		for (auto r : answer) 
		{
			cout << r << " ";
		}
	}

	return 0;
}
