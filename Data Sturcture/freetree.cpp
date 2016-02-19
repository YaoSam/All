#include "freetree.h"
TEMP 
treeNode<T>* FreeTree<T>::leftinsert(T const &x,treeNode<T>* y_node )
{
	if (y_node == NULL)
		throw "�սڵ��޷�����";
	if (y_node->left)
		throw "��ڵ�ǿգ����ܲ���";
	return y_node->left = new treeNode<T>(x, y_node->height + 1, y_node);
}

TEMP
treeNode<T>* FreeTree<T>::rightinsert(T const &x, treeNode<T>* y_node)
{
	if (y_node == NULL)
		throw "�սڵ��޷�����";
	if (y_node->right)
		throw "�ҽڵ�ǿգ����ܲ���";
	return y_node->right = new treeNode<T>(x, y_node->height + 1, y_node);
}
