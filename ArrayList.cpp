#include<iostream>  
using namespace std;  
  
template<class Type>  
class SeqList  
{  
public:  
    SeqList(size_t sz=INIT_SIZE);  
public:  
    bool isfull()const  
    {return size>=capacity;}  
    bool isempty()const  
    {return size==0;}  
public:  
    void quit_system();  
    void push_back(const Type &x);  
    void push_front(const Type &x);  
    void show_list();  
    void pop_back();  
    void pop_front();  
    void insert_pos(int pos,const Type &x);  
    void insert_val(const Type &x);  
    void delete_pos(int pos);  
    void delete_val(const Type &x);  
    int  find(const Type &key);  
    int  length()const;  
    void clear();  
    void destroy();  
    void reserv();  
    void sort();  
private:  
    enum{INIT_SIZE=8};  
    Type *base;  
    size_t capacity;  
    size_t size;  
};  
  
template<class Type>  
SeqList<Type>::SeqList(size_t sz)//分配空间  
{  
    capacity = sz > INIT_SIZE ? sz : INIT_SIZE;  
    base = new Type[capacity];  
    size = 0;  
}  
  
template<class Type>  
void SeqList<Type>::quit_system()//退出  
{  
    return;  
}  
  
template<class Type>  
void SeqList<Type>::push_back(const Type &x)//后插  
{  
    if(isfull())  
    {  
        cout<<"顺序表已满,不能插入!"<<endl;  
        return;  
    }  
    base[size++] = x;  
}  
  
template<class Type>  
void SeqList<Type>::push_front(const Type &x)//前插  
{  
    if(isfull())  
    {  
        cout<<"顺序表已满,不能插入!"<<endl;  
        return;  
    }  
  
    for(int i=size; i>0; --i)  
    {  
        base[i] = base[i-1];  
    }  
    base[0] = x;  
    size++;  
}  
  
template<class Type>  
void SeqList<Type>::show_list()//显示  
{  
    for(int i=0; i<size; ++i)  
    {  
        cout<<base[i]<<" ";  
    }  
    cout<<endl;  
}  
  
template<class Type>  
void SeqList<Type>::pop_back()//后删  
{  
    size = size-1;  
}  
  
template<class Type>  
void SeqList<Type>::pop_front()//前删  
{  
    int i;  
    for(i = 0;i<size-1;i++)  
    {  
        base[i]=base[i+1];  
    }  
    size--;  
}  
  
template<class Type>  
void SeqList<Type>::insert_pos(int pos,const Type &x)//按位置插入  
{  
    if(pos<0 || pos>size)  
    {  
        cout<<"要插入的位置非法!"<<endl;  
        return;  
    }  
    if(isfull())  
    {  
        cout<<"顺序表已满,不能插入!"<<endl;  
        return;  
    }  
  
    for(int i=size; i>pos; --i)  
    {  
        base[i] = base[i-1];  
    }  
    base[pos] = x;  
    size++;  
}  
  
template<class Type>  
void SeqList<Type>::insert_val(const Type &x)//按值插入  
{  
    int pos;  
    pos = find(x);  
    insert_pos(pos,x);  
}  
  
template<class Type>  
void SeqList<Type>::delete_pos(int pos)//按位置删除  
{  
    int i;  
    for(i = pos;i<size-1;++i)  
    {  
        base[i] = base[i+1];  
    }  
    size--;  
}  
  
template<class Type>  
void SeqList<Type>::delete_val(const Type &x)//按值删除  
{  
    int pos = find(x);  
    if(pos == -1)  
    {  
        return;  
    }  
  
    for(int i=pos; i<size; ++i)  
    {  
        base[i] = base[i+1];  
    }  
    size--;  
}  
  
template<class Type>  
int SeqList<Type>::find(const Type &key)//查找  
{  
    for(int i=0; i<size; ++i)  
    {  
        if(base[i] == key)  
            return i;  
    }  
    return -1;  
}  
  
template<class Type>  
int SeqList<Type>::length()const//求长  
{  
    cout<<size<<endl;  
    return size;  
}  
  
template<class Type>  
void SeqList<Type>::clear()//清除数据  
{  
    while(size)  
    {  
        base[size--] = NULL;  
    }  
}  
  
template<class Type>  
void SeqList<Type>::destroy()//摧毁顺序表  
{  
    int i;  
    delete base;  
    base = NULL;  
    capacity = 0;  
    size = 0;  
}  
  
template<class Type>  
void SeqList<Type>::reserv()//逆序  
{  
    int i = 0;  
    int m=size-1;  
    int x=size;  
    for(;i<=(m/2);++i)  
        {  
            int tmp = base[i];  
            base[i] = base[x-1];  
            base[x-1] = tmp;  
            x--;  
        }  
}  
  
template<class Type>  
void SeqList<Type>::sort()//排序  
{  
  
    int tmp;  
    for (int i=0;i<=size;i++)  
        for (int j=i+1;j<=size-1;j++)  
        {  
            if(base[i]>base[j])  
            {  
                tmp = base[j];  
                base[j]=base[i];  
                base[i]=tmp;  
            }  
        }  
}

int main()  
{  
    SeqList<int> mylist;  
    int select = 1;  
    int Item;  
    int pos;  
    while(select)  
    {  
        cout<<"**************************************"<<endl;  
        cout<<"* [1] push_back       [2] push_front *"<<endl;  
        cout<<"* [3] show_list       [0] quit_system*"<<endl;  
        cout<<"* [4] pop_back        [5] pop_front  *"<<endl;  
        cout<<"* [6] insert_pos      [7] insert_val *"<<endl;  
        cout<<"* [8] delete_pos      [9] delete_val *"<<endl;  
        cout<<"* [10] find           [11]length     *"<<endl;  
        cout<<"* [12] clear          [13]destroy    *"<<endl;  
        cout<<"* [14] reserv         [15]sort       *"<<endl;  
        cout<<"**************************************"<<endl;  
        cout<<"请选择:>";  
        cin>>select;  
        switch(select)  
        {  
        case 0:  
                mylist.quit_system();  
                break;  
        case 1:  
            cout<<"请输入要插入的值(-1结束):>";  
            while(cin>>Item, Item!=-1)  
            {  
                mylist.push_back(Item);  
            }  
            break;  
        case 2:  
            cout<<"请输入要插入的值(-1结束):>";  
            while(cin>>Item, Item!=-1)  
            {  
                mylist.push_front(Item);  
            }  
            break;  
        case 3:  
            mylist.show_list();  
            break;  
        case 4:  
            mylist.pop_back();  
            break;  
        case 5:  
            mylist.pop_front();  
            break;  
        case 6:  
            cout<<"请输入要插入的位置:>";  
            cin>>pos;  
            cout<<"请输入要插入的值:>";  
            cin>>Item;  
            mylist.insert_pos(pos,Item);  
            break;  
        case 7:  
            cout<<"请输入要插入的值:>";  
            cin>>Item;  
            mylist.insert_val(Item);  
        case 8:  
            cout<<"请输入要删除的位置:>";  
            cin>>pos;  
            mylist.delete_pos(pos);  
            break;  
        case 9:  
            cout<<"请输入要删除的值:>";  
            cin>>Item;  
            mylist.delete_val(Item);  
            break;  
        case 10:  
            cout<<"请输入要查找的值:>";  
            cin>>Item;  
            int pos;  
            pos = mylist.find(Item);  
            break;  
        case 11:  
            mylist.length();  
            break;  
        case 12:  
            mylist.clear();  
            break;  
        case 13:  
            mylist.destroy();  
            break;  
        case 14:  
            mylist.reserv();  
            break;  
        case 15:  
            mylist.sort();  
        default:  
            break;  
        }  
    }  
} 
