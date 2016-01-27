#pragma  once
#include "btree.h"
#include "Stack.h"//前中后序输出
#include "queue.cpp"//层序遍历
char BTree<char>::endFlag = '#';

TEMP inline T Max(T const &a, T const &b)
{
	return a > b ? a : b;
}

TEMP 
unsigned int Tree<T>::NodeNum()const
{
	if (height == 0)
		return 0;
	return (left ? left->NodeNum() : 0) + (right ? right->NodeNum() : 0) + 1;
}

TEMP void Tree<T>::pre()const
{
	stack<const Tree<T>*> Stack;
	const Tree<T>* temp =this;
	while (temp != NULL || !Stack.isEmpty())
	{
		while (temp != NULL)//不断向左遍历，并记录路径
		{
			std::cout << (temp->data) << " ";
			Stack.push(temp);
			temp = temp->left;
		}
		if (!Stack.isEmpty())//往回取一个点。向右走一步。
		{
			temp = Stack.pop();
			temp = temp->right;
		}
	}
	return;
}

TEMP void Tree<T>::mid()const
{
	stack<const Tree<T>*> Stack;
	const Tree<T>* temp = this;
	while (temp != NULL || !Stack.isEmpty())
	{
		while (temp != NULL)//不断向左走，到尽头了才输出
		{
			Stack.push(temp);
			temp = temp->left;
		}
		if (!Stack.isEmpty())//到了中间。输出。然后输出右边。
		{
			temp = Stack.pop();
			std::cout << (temp->data) << " ";
			temp = temp->right;
		}
	}
	return;
}

TEMP void Tree<T>::post()const //前序遍历：中左右。左右逆转前序遍历：中右左。后序遍历：左右中。
{
	stack<const Tree<T>*> Stack;
	stack<const T*> OutPut;
	const Tree<T>* temp = this;
	while (temp != NULL || !Stack.isEmpty())//左右逆转的前序遍历
	{
		while (temp != NULL)
		{
			OutPut.push(&(temp->data));
			Stack.push(temp);
			temp = temp->right;
		}
		if (!Stack.isEmpty())
		{
			temp = Stack.pop();
			temp = temp->left;
		}
	}
	//逆序输出左右逆转的前序遍历
	while (!OutPut.isEmpty())
	{
		std::cout << (*OutPut.pop()) << " ";
	}
	return;
}

TEMP void Tree<T>::print()const
{
	if (height == 0)return;
	const Tree<T>* temp;
	queue<const Tree<T>*> Queue;
	Queue.push(this);
	while (!Queue.isEmpty())
	{
		temp = Queue.pop();
		if (temp->left)
			Queue.push(temp->left);
		if (temp->right)
			Queue.push(temp->right);
		std::cout << (temp->data) << " ";
	}
	std::cout << std::endl;
}

//////////////////////////////////////////////////////////////////////////

TEMP
BTree<T>::BTree(BTree<T> const & other) 
{
	if (other.height == 0)return;
	const BTree<T>* temp = &other;
	queue<const BTree<T>*> Queue_other;
	BTree<T>* pthis = this;
	queue<BTree<T>*> Queue_this;
	data = other.data;
	height = other.height;
	Queue_other.push(temp);
	Queue_this.push(pthis);
	while (!Queue_other.isEmpty())
	{
		temp = Queue_other.pop();
		pthis = Queue_this.pop();
		if (temp->left)
		{
			Queue_other.push(temp->left);
			pthis->leftLink(new BTree<T>(temp->left->data));
			pthis->left->height = pthis->height + 1;
			Queue_this.push(pthis->left);
		}
		if (temp->right)
		{
			Queue_other.push(temp->right);
			pthis->rightLink(new BTree<T>(temp->right->data));
			Queue_this.push(pthis->right);
		}
	}
	//if (&other == NULL)return;
	//data = other.data;
	//height = other.height;
	//parent = P;
	//if (other.left)
	//	left = new BTree<T>(*other.left,this);
	//if (other.right)
	//	right = new BTree<T>(*other.right,this);
}
TEMP
BTree<T>& BTree<T>::operator=(BTree<T> const & other)
{
	if (this == NULL || this == &other)return *this;
	this->del();
	data = other.data;
	height = other.height;
	parent = NULL;//这里并不是递归进入=，而是复制构造函数。所以这里一直是this
	if(other.left)leftLink(new BTree<T>(*other.left));
	if(other.right)rightLink(new BTree<T>(*other.right));
	return *this;
}

TEMP
Tree<T>* BTree<T>::find(T const &x)const
{
	if (height == 0)return NULL;
	BTree<T>* temp;
	queue<BTree<T>*> Queue;
	Queue.push(const_cast<BTree*>(this));
	while (!Queue.isEmpty())
	{
		temp = Queue.pop();
		if (temp->data == x)
			return temp;
		if (temp->left)
			Queue.push(temp->left);
		if (temp->right)
			Queue.push(temp->right);
	}
	return NULL;
}

TEMP void BTree<T>::del()
{
	Tree<T>* L = static_cast<Tree<T>*>(left), *R = static_cast<Tree<T>*>(right);
	if (left)
	{
		left->del();
		delete L;
		left = NULL;
	}
	if (right)
	{
		right->del();
		delete R;
		right = NULL;
	}
}

TEMP BTree<T>::~BTree()
{
	this->del();
}