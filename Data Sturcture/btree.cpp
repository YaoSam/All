#pragma  once
#include "btree.h"
TEMP void treeNode<T>::Del(treeNode<T>*& root)
{
	stack<const treeNode<T>*> Stack;
	const treeNode<T>* temp = root, *temp2;
	if (root == NULL)return;
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
		temp2 = temp; delete temp2; //��Ϊ���滹Ҫ�õ�temp����Ϣ��
		if (Stack.isEmpty())break;
		if (temp == Stack.topData()->left)
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
	root = NULL;
}
TEMP void treeNode<T>::Copy(treeNode<T>*& root, const treeNode<T>* otherRoot)
{
	stack<const treeNode<T>*> Stack_other;
	const treeNode<T>* temp_other = otherRoot;
	stack<treeNode<T>*> Stack_this;
	treeNode<T> *temp_this=NULL;
	if (temp_other){
		temp_this = root = new treeNode<T>(temp_other->data, 1);
		Stack_other.push(temp_other);
		Stack_this.push(temp_this);
		temp_other = temp_other->left;
	}
	else root = NULL;
	while (temp_other != NULL || !Stack_other.isEmpty())
	{
		while (temp_other != NULL)//��ʱһ���������ߵġ�
		{
			temp_this->left = new treeNode<T>(temp_other->data, temp_other->height, temp_this);
			temp_this = temp_this->left;//����temp_other�Ĳ���
			Stack_this.push(temp_this);
			Stack_other.push(temp_other);
			temp_other = temp_other->left;
		}
		if (!Stack_other.isEmpty())//����ȡһ���㡣������һ����
		{
			temp_other = Stack_other.pop()->right;
			temp_this = Stack_this.pop();
			if (temp_other)
			{
				temp_this->right = new treeNode<T>(temp_other->data, temp_other->height, temp_this);
				temp_this = temp_this->right;
				Stack_other.push(temp_other);
				Stack_this.push(temp_this);
				temp_other = temp_other->left;//�����ߡ�
			}
		}
	}
}

TEMP void treeNode<T>::leftlink(treeNode<T>* other)
{
	left = other;
	if (other)
		other->parent = this;
}

TEMP void treeNode<T>::rightlink(treeNode<T>* other)
{
	right = other;
	if (other)
		other->parent = this;
}

TEMP NormalTree<T>& NormalTree<T>::operator=(NormalTree<T> const & other)
{
	if (this == &other)return *this;
	root->Del(root);
	root->Copy(root, other.root);
	return *this;
}
TEMP  NormalTree<T>::NormalTree(const NormalTree<T> & other)
{
	root->Copy(root, other.root);
}
TEMP NormalTree<T>::~NormalTree()
{
	root->Del(root);
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
			temp = Stack.pop()->right;
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
	if (root == NULL)return;
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
