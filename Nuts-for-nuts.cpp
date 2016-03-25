//无向图的哈密顿路径问题，
/*			松鼠吃果子问题
			问题描述：
			let every nut become a Node ,and use from top to below ,use from left to right 
			give the number of the nuts 1~k,使用k位的二进制数来代表当前果子被摘取的情况。开始的时候
			所有的二进制数为00000，然后结束的时候，k位二进制数为2^k-1 。松鼠L和R此时的位置（x，y）和当前果子
			被摘取的状态构成一个组合（x,y,z)设置队列和hash表q存储当前的状态。
			并设置当前的状态的hash状态标志，避免出现重复的情况。初始化，
			将L，R 的出发位置(lx,ly)和当前果子的状态0，组合成初始状态送入队列q，置hash[初始状态] =1
			然后按照下面的方法进行BFS搜索直到队列为空且成功为止：	
			按照8个方向扩展当前队列所有元素。如果扩展出的新状态未在hash表当中即以前没有生成果，则将新状态入
			队，并新设置新状态hash标志。诺新状态是(lx,ly,2^k-1)则将状态设置成成功标志
*/

#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <string>
#include <map>
#include <utility>
#include <vector>
#include <set>
#include <algorithm>
#define maxn 22
using namespace std;


const int dx[9] = (0,0,-1,-1,-1,0,1,1,1);
const int dy[9]	= (0,1,1,0,-1,-1,-1,0,1);
struct node	{ int x,y,get;	}q[10000000];

bool hash [maxn][maxn][32678];

int land[maxn][maxn];

int n,m,sum,Sx,Sy;

void init()
{
	memset(land, 0, sizeof(land));
	sum = 1;
	for(int i=1;i <=n; i++)
	{
		char ch;
		cin.get(ch);
		for(int j=1; j <= m; j++){
			cin.get(ch);
			switch(ch){
				case'L' : land[i][j] = 0; Sx = i;Sy = j; break;
				case'#' : land[i][j] = sum; sum* =2; break;
				case'.'	: land[i][j] = 0; break;
 			}
		}
	}
	for(int i = 0; i <= n+1; i++)
		land[i][0] = land[i][m+1] = -1;
	for(int i = 1; i <= m+1; i++)
		land[0][i] = land[n+1][i] = -1;
	
}


void solve()
{
	memset(hash, 0, sizeof(hash));
	hash[Sx][Sy][0] = 1;
	int head = 1, tail = 1, move = 0;
	q[1].x = Sx; q[1].y = Sy;
	q[1].get = 0;
	bool flag = 0;
	if(sum == 1) flag = 1;
		while(head <= tail && !flag){
			int t = tail;
			for(int i = head; i <= tail; i++){
				int tx = q[i].x, ty = q[i].y;
				for(int j=1; j <= 8; j++){
					int val = land[tx+dx[j]][ty+dy[j]];
					if(val >= 0 && !hash [tx+dx[j]][ty+dy[j]][q[i].get(val))
					{
						t++;
						q[t].x = tx + dx[j]; q[t].y = ty + dy[j];
						q[t].get = q[i].get(val);
						hash[tx+dx[j]][ty+dy[j]][q[i].get(val) = 1;
						if(q[t].x == Sx && q[t].y == Sy && q[t].get == sum-1)
							flag = 1;
					}
				}
			}
			head = tail +1; tail = t;
			move++;
		}
	cout<<move<<endl;
}

int main()
{
	ios::sync_with_stdio(false);
	while(cin>>n>>m){
		intit();
		solve();
	}
	return 0;32678

}
























