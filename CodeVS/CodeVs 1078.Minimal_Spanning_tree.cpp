//最小生成树prim算法 

#include<bits/stdc++.h>
using namespace std;

#define MAX_DIS 100010
int prim(int **map,int N)
{
	int dis=0;
	int *visited=new int[N];
	int *low=new int[N];
	int pos,min;
	for(int i=0;i<N;i++)
	{
		visited[i]=0;
	}
	visited[0]=1;
	pos=0;
	for(int i=0;i<N;i++)
	{
		if(map[pos][i]==0)
		low[i]=MAX_DIS;
		else
		low[i]=map[pos][i];
	}
	
	for(int i=0;i<N-1;i++)
	{
		min=MAX_DIS;
		for(int j=0;j<N;j++)
		{
			if(visited[j]==0 && min>low[j])
			{
				min=low[j];
				pos=j;
			}
		}
		visited[pos]=1;
		dis+=min;
		for(int j=0;j<N;j++)
		{
			if(visited[j]==0 && low[j]>map[pos][j])
			{
				if(map[pos][j]!=0)
				{
					low[j]=map[pos][j];
				}
			}
		}
	}
	return dis;
	
}
int main()
{
	int N;
	cin >> N;
	int *map[N];
	for(int i=0;i<N;i++)
	map[i]=new int[N];
	
	for(int i=0;i<N;i++)
		for(int j=0;j<N;j++)
			cin >> map[i][j];
			
	cout << prim(map,N) << endl;
}


