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

/************************************************************************/
/*                                                                      */
/************************************************************************/

TEMP
T tree_iterator<T>::operator*()const
{
	if (Pcurrent)
		return Pcurrent->data;
	else
		throw "\niterator range erreor\n";
}

TEMP
Tree<T>* tree_iterator<T>::operator()()const
{
	if (Pcurrent)
		return Pcurrent;
	else 
		throw "\niterator range erreor\n";
}

TEMP
tree_iterator<T>& PreOrder_iterator<T>::operator++()
{
	if (Pcurrent == NULL)	throw "\niterator range erreor\n";
	Stack.push(Pcurrent);
	Pcurrent = Pcurrent->left;
	if (Pcurrent)//���������ߡ��˳�
		return *this;
	//��ʱPΪ��
	while (Pcurrent == NULL&&!Stack.isEmpty())//�ܷ��ȥ
	{
		Pcurrent = Stack.pop();
		Pcurrent = Pcurrent->right;
		if (Pcurrent)return *this;
	}
	return *this;
	//��ʱ���ܻ�ȥ��PΪ�ա�������
}

/************************************************************************/
/*                                                                      */
/************************************************************************/
TEMP
BTree<T>::BTree(BTree<T> const & other, BTree<T>* P/* =NULL */) 
{
	if (&other == NULL)return;
	data = other.data;
	height = other.height;
	parent = P;
	if (other.left)
		left = new BTree<T>(*other.left,this);
	if (other.right)
		right = new BTree<T>(*other.right,this);
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