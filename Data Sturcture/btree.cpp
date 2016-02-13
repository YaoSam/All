#pragma  once
#include "btree.h"
#include "Stack.cpp"//ǰ�к������
#include "queue.cpp"//�������
TEMP void treeNode<T>::Del()
{
	if (left)
	{
		left->Del();
		delete left;
		left = NULL;
	}
	if (right)
	{
		right->Del();
		delete right;
		right = NULL;
	}
}
TEMP void treeNode<T>::Copy(treeNode<T>*& root, treeNode<T>* const other, treeNode<T>* P)
{
	if (other)
		root = new treeNode<T>(other->data,other->height,P);
	else
		return;
	Copy(root->left, other->left,root);
	Copy(root->right, other->right,root);
}
TEMP
void treeNode<T>::leftlink(treeNode<T>* other)
{
	left = other;
	if (other)
		other->parent = this;
}

TEMP
void treeNode<T>::rightlink(treeNode<T>* other)
{
	right = other;
	if (other)
		other->parent = this;
}

TEMP NormalTree<T>& NormalTree<T>::operator=(NormalTree<T> const & other)
{
	if (this == &other)return *this;
	if (root)
	{
		root->Del();
		delete root;
		root = NULL;
	}
	root->Copy(root, other.root);
	return *this;
}
TEMP  NormalTree<T>::NormalTree(const NormalTree<T> & other)
{
	root->Copy(root, other.root);
}
TEMP NormalTree<T>::~NormalTree()
{
	if (root)
	{
		root->Del();
		delete root;
	}
}

TEMP unsigned int NormalTree<T>::NodeNum()const
{
	stack<const treeNode<T>*> Stack;
	const treeNode<T>* temp = root;
	unsigned int ans=0;
	while (temp != NULL || !Stack.isEmpty())
	{
		while (temp != NULL)
		{
			ans++;//�������
			Stack.push(temp);
			temp = temp->left;
		}
		if (!Stack.isEmpty())
		{
			temp = Stack.pop();
			temp = temp->right;
		}
	}
	return ans;
}

TEMP void NormalTree<T>::pre()const
{
	stack<const treeNode<T>*> Stack;
	const treeNode<T>* temp = root;
	while (temp != NULL || !Stack.isEmpty())
	{
		while (temp != NULL)//�����������������¼·��
		{
			std::cout << (temp->data) << " ";//�ؼ����������
			Stack.push(temp);
			temp = temp->left;
		}
		if (!Stack.isEmpty())//����ȡһ���㡣������һ����
		{
			temp = Stack.pop();
			temp = temp->right;
		}
	}
	std::cout << std::endl;
}

TEMP void NormalTree<T>::mid()const
{
	stack<const treeNode<T>*> Stack;
	const treeNode<T>* temp = root;
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
	std::cout << std::endl;
}

TEMP void NormalTree<T>::post()const
{
	stack<const treeNode<T>*> Stack;
	const treeNode<T>* temp = root;
	while (temp != NULL)
	{
		while (temp != NULL)
		{
			Stack.push(temp);
			temp = temp->left;
		}
		temp = Stack.topData()->right;
	}
	temp = Stack.pop();
	while (temp != NULL)
	{
		std::cout << (temp->data) << " ";
		if (Stack.isEmpty())break;
		if(temp == Stack.topData()->left)
		{
			temp = Stack.topData()->right;
			while (temp != NULL)
			{
				while (temp != NULL)
				{
					Stack.push(temp);
					temp = temp->left;
				}
				temp = Stack.topData()->right;
			}
		}
		temp = Stack.pop();
	}
	std::cout << std::endl;
}

TEMP void NormalTree<T>::print()const
{
	if (root==NULL)return;
	const treeNode<T>* temp;
	queue<const treeNode<T>*> Queue;
	Queue.push(root);
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

TEMP treeNode<T>* NormalTree<T>::find(T const & x)const
{
	stack<treeNode<T>*> Stack;
	treeNode<T>* temp = root;
	while (temp != NULL || !Stack.isEmpty())
	{
		while (temp != NULL)//�����������������¼·��
		{
			if (temp->data == x)
				return temp;
			Stack.push(temp);
			temp = temp->left;
		}
		if (!Stack.isEmpty())//����ȡһ���㡣������һ����
		{
			temp = Stack.pop();
			temp = temp->right;
		}
	}
	return NULL;
}
