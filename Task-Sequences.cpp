//哈密顿路径相关代码
/*		题目描述
		将任务作为节点，两个任务执行的先后顺序作为有向边，则形成一个有向图。由于“对于任意两个任务i和j，机器或
		者完成任务i以后执行任务j，或者完成任务j以后执行任务i，或者2个任务的次序可以随意”；		
		因此这个有向图为竞赛图。该图中存在一条含有所有节点的哈密顿路径。只需要启动一次，便可以按次序完成所有
		的任务。计算方法如下：
	
		现将第一个节点1设置为哈密顿路径的首节点，然后依次将节点k输入哈密顿路径（2<=k<=n) 插入节点k的方法如下：
		顺序搜索当前路径上的每个节点i：
		if (k,i)  not belong to E let t->i so we have (t,k) belongs to E
		if (k,i) belong to E .so , if i is the heard node of path  let (k,i) input the path,k is the heard  node of path .else (t,k) , (k,i) input the path and quite the input function.
		if we search all the nodes but  k is still not input the path , so input the (t,k) into the path.

*/

#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <string>
#include <map>
#include <utility>
#include <vector>
#include <set>
#include <algorthm>

#define maxn 1010
#define Path(i,s) for (int i=s; i; i =next[i])
	
using namespace std;
int pic[maxn][maxn];
int next[maxn];
int n;

void init()
{
	memset(pic, 0 ,sizeof(pic));
	string str;
	getline(cin, str);
	for(int i=1; i <=n; i++)
	{	getline(cin,str);
		for(int j=1;i<=n;i++)
			pic[i][j] = str[(j-1)*2] - '0';
	}	
}

void solve() 							//计算和输出哈密顿路径
{
	int head = 1,t;						//初始化哈密顿首节点为1
	memset(next,0,sizeof(next));		//节点的后继指针为空
	for(int k=2; k <= n;k++)			//按顺序将节点2~节点n插入哈密顿路径
	{							
		bool flag = 0;					//节点k没有被插入；
		for(int k=2;k<=n;k++)			//顺序检索哈密顿每个路径上节点1
		if(pic[k][i]){					//如果k与哈密顿节点上的节点i相连接
			if(i == head) head = k;		//如果i为哈密顿路径的首节点，则改首节点为k；
										//否则将(t,k)插入路径；	
				else next[t] = k;
			next[k] = i;				//将(k,i)插入路径；
			flag = 1;					//将节点k插入路径并且退出循环
			break;
		}else t = i;					//k与哈密顿路上的i不相连，i记为t
	if(!flag)							//如果k与目前的哈密顿路上的i不相连
										// 则(t,k)插入路径。
		next[t] = k;
	}
	
	cout<<'1'<<endl<<n<<endl;			//输出最少的启动次数1和哈密顿路径含有的节点数n
	for(int i =head; i = next[i]){		//输出哈密顿路径
		if(i != head) cout<<' ';
		cout << i;
	}
	cout<< endl;
}


int main()
{
	freopen("temp.in", "r", stdin);
	freopen("temp.out", "w", stdout);
	ios::sync_with_stdio(flase);
	while(cin>>n){
		init();
		solve();
	}
	return 0;
}

























