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
SegmentTree::SegmentTree(int a, int b) :BTree(Segment(a,b))
{
	if (a + 1 < b)
	{
		left = new SegmentTree(a, (a + b) / 2);
		right = new SegmentTree((a + b) / 2, b);
	}
	return;
}

void SegmentTree::insert(const Segment &x)
{
	if (data == x)
		data.cover++;
	else if (data.left + 1 == data.right) return;
	else
	{
		int mid = (data.left + data.right) / 2;
		SegmentTree* L = static_cast<SegmentTree*>(left), *R = static_cast<SegmentTree*>(right);
		if (mid > x.right)
			L->insert(x);
		else if (mid < x.left)
			R->insert(x);
		else
		{
			L->insert(Segment(x.left, mid));
			R->insert(Segment(mid, x.right));
		}
	}
	return;
}

void SegmentTree::del(const Segment& x)
{
	if (data == x)
	{
		if (data.cover>0)
			data.cover--;
		else 
			return;
	}
	else if (data.left + 1 == data.right) return;
	else
	{
		int mid = (data.left + data.right) / 2;
		SegmentTree* L = static_cast<SegmentTree*>(left), *R = static_cast<SegmentTree*>(right);
		if (mid > x.right)
			L->del(x);
		else if (mid < x.left)
			R->del(x);
		else
		{
			L->del(Segment(x.left, mid));
			R->del(Segment(mid, x.right));
		}
	}
	return;
}
int SegmentTree::count()const
{
	if (data.cover>0)
		return data.lenght();
	else if (data.lenght() == 1)return 0;
	else
	{
		SegmentTree* L = static_cast<SegmentTree*>(left), *R = static_cast<SegmentTree*>(right);
		return (left ? L->count() : 0) + (right ? R->count() : 0);
	}
}

