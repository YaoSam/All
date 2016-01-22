#include "btree.cpp"

TEMP
class bstree : public btree < T >
{
protected:
	unsigned int nodeNum;
public:
	bstree(T const x) :btree(x), nodeNum(1){}
	bstree(T const a[]=NULL,unsigned int n=0);
	unsigned int NodeNum()const{ return nodeNum; }
	~bstree();
};