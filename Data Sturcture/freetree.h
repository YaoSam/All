#include "btree.cpp"
TEMP
class FreeTree :public NormalTree <T>
{
public:
	FreeTree(T const & x) :
		NormalTree<T>(x,0)//���0����ͦ��Ҫ�ġ�
	{}
	virtual ~FreeTree() {}
	virtual void insert(T const & x){ throw "δ������뷽������Sorry"; }
	treeNode<T>* leftinsert(T const &x,treeNode<T>* y_node );
	treeNode<T>* rightinsert(T const &x, treeNode<T>* y_node);
};