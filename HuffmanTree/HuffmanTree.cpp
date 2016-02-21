#pragma once
#include "HuffmanTree.h"

TEMP
HuffmanTree<T>::HuffmanTree(T const * Data, unsigned int n) 
{
	treeNode<T>** node = new treeNode<T>*[n], *left, *right;
	re(i, n)
	{
		node[i] = new treeNode<T>(Data[i], 1);
	}
	Heap<treeNode<T>*> heap(node, n, cmp);
	re(i, n - 1)
	{
		left = heap.pop(), right =heap.pop();
		heap.push(new treeNode<T>(left->data + right->data, left->height + 1, NULL, left, right));
	}
	root = heap.pop();
}