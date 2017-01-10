#include<bits/stdc++.h>
using namespace std;

int main()
{
	int N,M;
	while(cin >> N)
	{
		if(N==0) break;
		int map[N][N];
		memset(map,0,sizeof(map));
		
		cin >> M;
		int a,b;
		for(int i=0;i<M;i++)
		{
			cin >> a >> b;
			map[a][b]=1;
		}
		
		for(int k=0;k<N;k++)
			for(int i=0;i<N;i++)
				for(int j=0;j<N;j++)
					if(map[i][k]==1 && map[k][j]==1)
					map[i][j]=1;  //将节点连通                               					
		if(map[0][N-1])//直接判断                      		
		cout << "I can post the letter" << endl;
		else
		cout << "I can't post the letter" << endl;
	}
	return 0;
}
