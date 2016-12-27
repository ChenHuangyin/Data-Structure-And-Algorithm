#include<bits/stdc++.h>
using namespace std;

template<class DT>
struct Node
{
	DT info;
	Node<DT> *next;
};

template<class DT>
class LinkedList
{
public:
	LinkedList();
	LinkedList(const LinkedList<DT> &aplist);
	~LinkedList();
	LinkedList<DT>& operator=(const LinkedList<DT> &rlist);
	void insert(const DT &element);  //在链表的头部之前插入
	void insert_end(const DT &element);  //在链表的尾部插入
	bool first(DT &listEl);     //得到对头的数据
	inline bool getNext(DT &listEl);   //得到当前指针所指的下一个数据
	bool find(const DT &element);    //查找一个数据
	bool retrieve(DT &element);       //检索一个数据
	bool replace(const DT &newElement);    //更改一个数据
	bool remove(DT &element);
	bool isEmpty() const;
	void makeEmpty();
private:
	Node<DT> *start;   //指向头结点
	Node<DT> *current;    //指向当前的结点
	inline void deepCopy(const LinkedList<DT> &original);   //"深复制"
};

template<class DT>
LinkedList<DT>::LinkedList()
{
	start = current = NULL;
}

template<class DT>
LinkedList<DT>::LinkedList(const LinkedList<DT> &aplist)
{
	deepCopy(aplist);
}

template<class DT>
LinkedList<DT>::~LinkedList()
{
	makeEmpty();
}

template<class DT>
LinkedList<DT>& LinkedList<DT>::operator =(const LinkedList<DT> &rlist)
{
	if(this == &rlist)
		return this;
	makeEmpty();
	deepCopy(rlist);
	return this;
}
//在链表的表头插入DT &element，插入后没有当前位置
template<class DT>
void LinkedList<DT>::insert(const DT &element)
{
	current = NULL;
	Node<DT> *NNode = new Node<DT>;
	NNode->info = element;
	NNode->next = start;
	start = NNode;
}
////在链表的尾部插入
template<class DT>
void LinkedList<DT>::insert_end(const DT &element)
{
	current = NULL;
	Node<DT> *NNode = new Node<DT>;
	NNode->info = element;
	NNode->next = NULL;
	Node<DT> *temp;
	DT item;
	if(start == NULL)
	{
		start = NNode;
		temp = start;
		return;
	}
	temp = start;
	while(temp->next != NULL)
	{
		temp = temp->next;
	}
	temp->next = NNode;
}
//把链表中的第一个元素存放在listEl中，并且把第一个元素的位置置为current
template<class DT>
bool LinkedList<DT>::first(DT &listEl)
{
	if(start == NULL)
		return false;
	current = start;
	listEl = start->info; 
	return true;
}
//把链表中current的下个元素放在listEl中，current指向下一个元素
template<class DT>
bool LinkedList<DT>::getNext(DT &listEl)
{
	if(current == NULL)
		return false;
	if(current->next == NULL)
	{
		current = NULL;
		return false;
	}
	listEl = current->next->info;
	current = current->next;
	return true;
}
//如果找到elment，返回true,current在getNext()中设置
template<class DT>
bool LinkedList<DT>::find(const DT &element)
{
	DT item;
	if(!first(item))
		return false;  //检查是否为空
	do{
		if(item == element)
			return true;
	}while(getNext(item));
	return false;
}

template<class DT>
bool LinkedList<DT>::retrieve(DT &element)
{
	if(!find(element))
		return false;
		
	element = current->info;
	return true;
}

template<class DT>
bool LinkedList<DT>::replace(const DT &newElement)
{
	if(current == NULL)
		return false;
	current->info = newElement;
	return true;
}

template<class DT>
bool LinkedList<DT>::remove(DT &element)
{
	current = NULL;
	if(start == NULL)
		return false;
	Node<DT> *ptr = start;
	if(start->info == element)
	{
		element = start->info;
		start = ptr->next;
		delete ptr;
		return true;
	}
	while(ptr->next != NULL){
		if(ptr->next->info == element)
		{
			Node<DT> *tempptr = ptr->next;
			element = tempptr->info;
			ptr->next = tempptr->next;
			delete tempptr;
			return true;
		}
		ptr = ptr->next;
	}	
	return false;
}

template<class DT>
bool LinkedList<DT>::isEmpty() const
{
	 return start == NULL;
}

template<class DT>
void LinkedList<DT>::makeEmpty()
{
	while(start != NULL)
	{
		current = start;
		start = start->next;
		delete current;
	}
	current = NULL;
}

template<class DT>
void LinkedList<DT>::deepCopy(const LinkedList<DT> &original)
{
	start = current = NULL;
	if(original.start == NULL)
		return;
	Node<DT> *copyptr = start = new Node<DT>;
	Node<DT> *originalptr = original.start;
	copyptr->info = originalptr->info;
	if(originalptr == original.current)
		current = copyptr;
	while(originalptr->next  != NULL)
	{
		copyptr->next = new Node<DT>;  
		originalptr = originalptr->next;
		copyptr = copyptr->next;
		copyptr->info = originalptr->info;
		if(originalptr == original.current)
			current = copyptr;
	}
	copyptr->next = NULL;
}

int main()
{
	string str[5] = {"hello","world","welcome","to","beijing"};

	LinkedList<string> strLL;
	for(int ix=0;ix<5;++ix)
//		strLL.insert(str[ix]);         //调用insert()，依次插入在链表的头部
        strLL.insert_end(str[ix]);
	//遍历链表
	cout<<"遍历链表: ";
	string listEl;
	if(strLL.first(listEl))
		cout<<listEl<<" ";    //获得current
	while(strLL.getNext(listEl))
		cout<<listEl<<" ";
	cout<<endl;
	LinkedList<string> strLL2(strLL);  //调用构造函数初始化
	LinkedList<string> strLL3 = strLL;  //调用重载“=”操作符
    strLL2.first(listEl);
	cout<<"ListEl = "<<listEl<<endl;
	strLL3.first(listEl);
	cout<<"ListEl = "<<listEl<<endl;
	if(strLL2.find(str[3]))              //调用find()
		cout<<"str[3] = "<<str[3]<<endl;
	if(strLL3.retrieve(str[2]))          //调用retrieve()
		cout<<"str[2] = "<<str[2]<<endl;
	if(strLL.remove(str[1]))
	{
		strLL.first(listEl);
 		cout<<"ListEl after remove is "<<listEl<<endl;
	}
	if(strLL.isEmpty())
		cout<<"List is Empty!"<<endl;
	strLL.makeEmpty();
	strLL2.makeEmpty();
	strLL3.makeEmpty();
	cout<<"hello"<<endl;
}
