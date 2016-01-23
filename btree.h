#pragma once
#include <iostream>
#include <time.h>
#include <math.h>
#define TEMP template <class T>
#define re(i,n) for(unsigned int i=0;i<n;i++)
TEMP class bbtree ;
TEMP class btree;
TEMP
class btree
{
protected: 
	T data;
	btree<T> *right,*left;
	unsigned int nodeNum;
	unsigned int height;
	unsigned int CheckHeight()//���¸߶�
	{
		return height = Max((left ? left->height : 0), (right ? right->height : 0)) + 1;
	}
	//����Ϊƽ�������Ҫ�õĲ������
	friend class btree<T> ;
	friend class bbtree<T>;
	void del();
	unsigned int OtherHeight()const//�ݹ����߶ȡ�
	{
		return Max(left ? left->Hei() : 0, right ? right->Hei() : 0) + 1;
	}
public:
	static T endFlag;//��ͨ����������ʱ��Ľ�������
	btree() :nodeNum(0),height(0),left(NULL), right(NULL){}
	btree(T const &x) :data(x),height(1),nodeNum(1),left(NULL), right(NULL){}
	btree(btree<T> const & other);
	virtual ~btree();
	btree<T>& operator=(btree<T> const & other);

	unsigned int Height()const{ return height; }
	unsigned int NodeNum()const{ return nodeNum; }
	void pre()const;//ǰ�����
	void mid()const;//�������
	void back()const;//�������
	void print()const;//��α������
	const btree<T>* find(T const &x)const;//Ŀǰ�ǳ����������
	//virtual void del(T const &x);
	friend std::istream& operator>>(std::istream& in, btree<T> &other)//ͨ��endFlag������
	{
		int leftH = 0, rightH = 0;
		in >> other.data;
		if (other.data == endFlag) return in;
		else
		{
			other.left = new btree < T > ;
			other.right = new btree < T > ;
			in >> (*other.left) >> (*other.right);
			leftH = other.left->height; rightH = other.right->height;
			if ((*other.left).data == endFlag)
			{
				delete other.left;
				other.left = NULL;
				leftH = 0;
			}
			if ((*other.right).data == endFlag)
			{
				delete other.right;
				other.right = NULL;
				rightH = 0;
			}
		}
		other.nodeNum = (other.left ? other.left->nodeNum : 0) + (other.right ? other.right->nodeNum : 0) + 1;
		other.CheckHeight();
		return in;
	}
};
