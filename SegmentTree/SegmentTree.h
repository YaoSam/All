#pragma once
#include "..\Data Sturcture\btree.cpp"
#include "..\Data Sturcture\normal.h"
struct Segment
{
	int left, right, cover;
	Segment(int L=0, int R=0, int C=0) :left(L), right(R), cover(C){}
	int lenght()const { return right - left; }
	bool operator>(const Segment& b)const{ return left + right > b.left + b.right; }
	bool operator==(const Segment& b)const { return left == b.left&&right == b.right; }//虽然说上面那个应该够用了。以防万一。
	friend std::ostream& operator<<(std::ostream& out, const Segment& other);
	friend std::istream& operator>>(std::istream& in, Segment &other);
};

class SegmentTree:public BTree<Segment>
{
public:
	SegmentTree(int a, int b);
	void insert(int a, int b){ insert(Segment(a, b)); }
	void insert(const Segment &x);
	void del(const Segment& x);
	int count()const;
};