#pragma  once
#include "btree.h"
#include "Stack.h"//ǰ�к������
#include "queue.cpp"//�������
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
		while (temp != NULL)//�����������������¼·��
		{
			std::cout << (temp->data) << " ";
			Stack.push(temp);
			temp = temp->left;
		}
		if (!Stack.isEmpty())//����ȡһ���㡣������һ����
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
		while (temp != NULL)//���������ߣ�����ͷ�˲����
		{
			Stack.push(temp);
			temp = temp->left;
		}
		if (!Stack.isEmpty())//�����м䡣�����Ȼ������ұߡ�
		{
			temp = Stack.pop();
			std::cout << (temp->data) << " ";
			temp = temp->right;
		}
	}
	return;
}

TEMP void Tree<T>::post()const //ǰ������������ҡ�������תǰ������������󡣺�������������С�
{
	stack<const Tree<T>*> Stack;
	stack<const T*> OutPut;
	const Tree<T>* temp = this;
	while (temp != NULL || !Stack.isEmpty())//������ת��ǰ�����
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
	//�������������ת��ǰ�����
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
	parent = NULL;//���ﲢ���ǵݹ����=�����Ǹ��ƹ��캯������������һֱ��this
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