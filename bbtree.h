#pragma once
#include "btree.cpp"



TEMP
class bbtree :public btree < T > 
{
public:
	void insert(T const & x);
	bbtree(T const a[] = NULL, int n = 0);
	void printdiffer()const
	{
		const btree<T>* temp;
		queue<const btree<T>*> Queue;
		Queue.push(this);
		while (!Queue.isEmpty())
		{
			temp = Queue.pop();
			std::cout << temp->differ() << " ";
			if (temp->left)
				Queue.push(temp->left);
			if (temp->right)
				Queue.push(temp->right);
		}
	}
	~bbtree();
};