#include <bits/stdc++.h> 
using namespace std;

template<class T>
struct BT_Node{
	T data; 
	BT_Node *lchild;
	BT_Node *rchild;
};


//先序遍历
template<class T>
void PreOrder(BT_Node<T> bt) //递归 
{
	if(bt==NULL) return;
	cout << bt->data << " ";
	PreOrder(bt->lchild);
	PreOrder(bt->rchild); 
}

template<class T>
void PreOrder_Non_recursive(BT_Node<T> *p)  //非递归 
{
	stack<BT_Node<T>* > S;
	if(!p)
	return; // 空树
	S.push(NULL); 
	while(p)
	{
		cout << p->data << " ";
		if(p->rchild);
		S.push(p->rchild);
		if(p->lchild)
		p=p->lchild;
		else
		S.pop(p);
	} 
	
} 


//中序遍历
template<class T>
void InOrder(BT_Node<T> bt) //递归 
{
	if(bt==NULL) return;
	InOrder(bt->lchild);
	cout << bt->data << " ";
	InOrder(bt->rchild); 
}

template<class T>
void InOrder_Non_recursive(BT_Node<T> *p)  //非递归 
{
	stack<BT_Node<T>* > S;
	if(!p)
	return; // 空树
	do{
		while(p!=NULL)
		{
			S.push(p);
			p=p->lchild;
		}
		if(!S.empty())
		{
			cout << S.top()->data;
			S.pop();
			p=p->rchild;
		}
	}while( p!=NULL || !S.empty());
	
} 

//后序遍历 
template<class T>
void PostOrder(BT_Node<T> bt) //递归 
{
	if(bt==NULL) return;
	PostOrder(bt->lchild);
	PostOrder(bt->rchild);
	cout << bt->data << " ";
}

template<class T>
void InOrder_Non_recursive(BT_Node<T> *p)  //非递归 
{
	stack<BT_Node<T>* > S;
	if(!p)
	return; // 空树
	
	BT_Node<T> *cur=NULL; //当前结点 
	BT_Node<T> *pre=NULL; //前一次访问的结点
	
	S.push(p);
	while(!S.empty())
	{
		cur=S.top();
		if((cur->lchild==NULL && cur->rchild==NULL) || (pre!=NULL && (pre==cur->lchild || pre==cur->rchild)))
		{
			cout << cur->data << " "; 
			S.pop();
			pre=cur;
		}  // 如果P不存在左孩子和右孩子，则可以直接访问它；或者P存在左孩子或者右孩子，但是其左孩子和右孩子都已被访问过了，则同样直接访问该结点
		else
		{
			if(cur->rchild!=NULL)
			S.push(cur->rchild);
			if(cur->lchild!=NULL)
			S.push(cur->lchild); //若非上述两种情况，则将P的右孩子和左孩子依次入栈
		}//保证了每次取栈顶元素的时候，左孩子和右孩子都在根结点前面被访问 
	} 
	//这种思路与老师上课所讲有所不同 ，老师的方法是通过标记结点，确定右结点是否已经访问 
} 

int main()
{
	
}
