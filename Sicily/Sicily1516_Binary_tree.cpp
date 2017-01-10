#include<bits/stdc++.h>
using namespace std;

struct tree_node{
	tree_node *left;
	tree_node *right;
	char ch;
	bool is_root;        //根节点标致，初始化为1                      	
        tree_node():left(NULL),right(NULL),ch('^'),is_root(1){}
};

void pre_order(tree_node *T)  //递归 二叉树前序遍历
{
	if(!T)
	return;
	cout << T->ch;
	pre_order(T->left);
	pre_order(T->right);
}

int main()
{
	int n;
	while(cin >> n && n!=EOF)
	{
		tree_node *_list[1001];  
		_list[0]=NULL;
		for(int i=1;i<1001;i++)
		{
			_list[i]=new tree_node();
		}
		int num,l,r;
		char c;
		vector<int> root;  //存出现过的节点标号num                                     		                                
		for(int i=0;i<n;i++)
		{
			cin >> num >> c >> l >> r;
			root.push_back(num); //存入			
			_list[num]->ch=c;
			_list[num]->left=_list[l];
			_list[num]->right=_list[r];
			if(l!=0)
			_list[l]->is_root=0;   //作为子树的结点显然不可能是根节点                    
			if(r!=0)
			_list[r]->is_root=0;   //作为子树的结点显然不可能是根节点  
		
		}
		int root_num;
		for(int i=0;i<root.size();i++)
		{
			if(_list[root[i]]->is_root==1)  //根据is_root(bool）判断并寻找根节点                       
			root_num=root[i];
		}
		tree_node *_root=_list[root_num];
		pre_order(_root);
		cout << endl;
	}
	return 0;
}
