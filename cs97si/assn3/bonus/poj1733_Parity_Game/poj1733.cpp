#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
#include<cassert>
using namespace std;



const int MAXN = 32 * 1024;

struct Item{
	int from, to; //(from, to]
  string cmd;
  Item():from(), to(), cmd(){}; 
};
Item items[5000];
int n;
int M = 0;
void compress(){
	vector<int> xs;
	for (int i = 0; i < n; i++) xs.push_back(items[i].from), xs.push_back(items[i].to);
	sort(xs.begin(), xs.end());
	xs.erase(unique(xs.begin(), xs.end()), xs.end());
	for (int i = 0; i < n; i++){
		items[i].from = lower_bound(xs.begin(), xs.end(), items[i].from) - xs.begin();
		items[i].to   = lower_bound(xs.begin(), xs.end(), items[i].to) - xs.begin();
	}
	M = xs.size();
}

int p[MAXN];
void p_init(){
	for (int i = 0; i < 2 * M; i++){
		p[i] = i;
	}
}
int find(int u){
  assert(u < 2 * M);
	int root = u;
	while (root != p[root]) root = p[root];
	while (u != root) {int next_u = p[u]; p[u] = root; u = next_u;}
	return root;
}
void join(int u, int v){
	int pu = find(u);
	int pv = find(v);
	if (pu != pv) p[pu] = pv;
}
int main(){
	int m; cin >> m;
	cin >> n;
	for (int i = 0; i < n; i++)	{
		cin >> items[i].from >> items[i].to >> items[i].cmd;
		items[i].from--;
	}
	compress();
	p_init();
  assert(2 * M < MAXN);
	for (int i = 0; i < n; i++){
		Item &it = items[i];
		int u = it.from;
		int v = it.to;
		if (it.cmd == "even"){
			if (find(v + M) == find(u)){
				cout << i << endl;
				exit(0);
			}
			join(u, v);
			join(u + M, v + M);
		}else{
			if (find(u) == find(v)){
				cout << i << endl;
				exit(0);
			}
			join(u, v + M);
			join(v, u + M);
		}
	}
	cout << n << endl;
}
