#pragma  once
#include "btree.h"
#include "Stack.cpp"//ǰ�к������
#include "queue.cpp"//�������
char BTree<char>::endFlag = '#';

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
}

//////////////////////////////////////////////////////////////////////////

TEMP
BTree<T>::BTree(BTree<T> const & other) 
{
	if (other.height == 0)return;
	const BTree<T>* temp = &other;
	BTree<T>* pthis = this;
	stack<const BTree<T>*> Stack_other;
	stack<BTree<T>*> Stack_this;
	pthis->data = temp->data;
	pthis->height = temp->height;
	Stack_other.push(temp);
	Stack_this.push(this);
	temp = temp->left;
	while (temp != NULL || !Stack_other.isEmpty())
	{
		while (temp!=NULL)//��һֱ������
		{
			pthis->left = new BTree < T > (temp->data,pthis,temp->height);
			pthis = pthis->left;
			Stack_other.push(temp);
			Stack_this.push(pthis);
			temp = temp->left;
		}
		if (!Stack_other.isEmpty())
		{
			temp = Stack_other.pop()->right;//ȡ��·�����ĵ��Ѿ����ƹ��ˡ����Ը�����ߵġ�
			pthis = Stack_this.pop();
			if (temp != NULL)//�ұ��ж���
			{
				pthis->right = new BTree < T >(temp->data, pthis, temp->height);
				pthis = pthis->right;
				Stack_other.push(temp);
				Stack_this.push(pthis);
				temp = temp->left;
			}
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
	stack<Tree<T>*> Stack;
	Tree<T>* temp = const_cast<BTree<T>*>(this);
	while (temp != NULL || !Stack.isEmpty())
	{
		while (temp != NULL)//�����������������¼·��
		{
			if (temp->data == x)
				return temp;
			//std::cout << (temp->data) << " ";
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
//////////////////////////////////////////////////////////////////////////
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

//TODO
TEMP void NormalTree<T>::post()const //ǰ������������ҡ�������תǰ������������󡣺�������������С�
{
	stack<const treeNode<T>*> Stack;
	stack<const T*> OutPut;
	const treeNode<T>* temp = root;
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
