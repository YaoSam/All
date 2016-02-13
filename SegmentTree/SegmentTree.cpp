#pragma once
#include "SegmentTree.h"

std::ostream& operator<<(std::ostream& out, const Segment& other)
{
	return out << "( " << other.left << " , " << other.right << " )";
}
std::istream& operator>>(std::istream& in, Segment &other)
{
	return in >> other.left >> other.right;
}
SegmentTree::SegmentTree(int a, int b) :NormalTree(Segment(a,b))//先用宽度优先吧……懒得想了。
{
	queue<treeNode<Segment>*> Queue;
	treeNode<Segment>* temp = root;
	Segment tempSeg; 
	int mid;
	Queue.push(temp);
	while (!Queue.isEmpty())
	{
		temp = Queue.pop();
		tempSeg = temp->data;
		if (tempSeg.right - tempSeg.left > 1)
		{
			mid = (tempSeg.right + tempSeg.left) / 2;
			temp->leftlink(new treeNode<Segment>(Segment(tempSeg.left, mid)));
			temp->rightlink(new treeNode<Segment>(Segment(mid, tempSeg.right)));
			Queue.push(temp->left);
			Queue.push(temp->right);
		}
	}
}

void SegmentTree::insert(const Segment &x, treeNode<Segment>* node)
{
	if (node->data == x)
		(node->data).cover++;
	else if ((node->data).left + 1 == (node->data).right) return;
	else
	{
		int mid = ((node->data).left + (node->data).right) / 2;
		if (mid > x.right)
			insert(x, node->left);
		else if (mid < x.left)
			insert(x, node->right);
		else
		{
			insert(Segment(x.left, mid),node->left);
			insert(Segment(mid, x.right),node->right);
		}
	}
	return;
}

void SegmentTree::insert(const Segment &x)
{
	insert(x, root);
}

void SegmentTree::del(const Segment& x,treeNode<Segment>* node)
{
	if (node->data == x)
	{
		if ((node->data).cover>0)
			(node->data).cover--;
		else 
			return;
	}
	else if ((node->data).left + 1 == (node->data).right) return;
	else
	{
		int mid = ((node->data).left + (node->data).right) / 2;
		if (mid > x.right)
			del(x, node->left);
		else if (mid < x.left)
			del(x, node->right);
		else
		{
			del(Segment(x.left, mid),node->left);
			del(Segment(mid, x.right),node->right);
		}
	}
	return;
}

void SegmentTree::del(const Segment& x)
{
	del(x, root);
}
int SegmentTree::count(const treeNode<Segment>* node)const
{
	if (this == NULL)
		throw "count 出错……跳进了空指针";
	if ((node->data).cover>0)
		return (node->data).lenght();
	else if ((node->data).lenght() == 1)return 0;
	else
	{
		return count(node->left) + count(node->right);
	}
}
int SegmentTree::count()const
{
	return count(root);
}
