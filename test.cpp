#pragma  once
#include "queue.cpp"
#include "stack.cpp"
#include "list.cpp"
#include "btree.cpp"
#include "btree.h"
#include "bstree.cpp"
#include "bbtree.cpp"
#include <algorithm>
#include <math.h>
TEMP void Swap(T & a, T &b)
{
	T temp = a; a = b; b = temp;
}

int minHeight_bbtree(int n)
{
	int i = 0;
	for (; n > 0;i++)
		n -= (1<<i);
	return i;
}
int Fibonacci(int n)
{
	return (n == 1 || n == 0) ? n : Fibonacci(n - 1) + Fibonacci(n - 2);
}
int maxHeight_bbtree(int n)
{
	int height=0;
	while ((Fibonacci(height + 2)-1) < n)	height++;
	return height-1;
}

TEMP
void Qsort(T a[], int left, int right)
{
	T mid = a[(left + right) / 2];
	int l = left, r = right;
	do
	{
		while (a[l] > mid)l++;
		while (a[r] < mid)r--;
		if (l <= r)
			Swap(a[l++], a[r--]);
	} while (l <= r);
	if (r > left)		Qsort(a, left, r);
	if (l < right)	Qsort(a, l, right);
	return;
}

void TestOfQueue()//修改后请通过该函数进行测试。
{
	srand(unsigned(time(NULL)));
	queue<int> a, b;
	unsigned int SizeOfTest = 100;
	re(i, SizeOfTest)
		a.push(rand() % 1000);
	queue<int> c = a;
	re(i, 1000)
	{
		while (!a.isEmpty())
			b.push(a.pop());
		while (!b.isEmpty())
			a.push(b.pop());
	}
	re(i, SizeOfTest)
		std::cout << a.pop() << " ";
	std::cout << std::endl;
	re(i, SizeOfTest)
		std::cout << c.pop() << " ";
	std::cout << std::endl;
}

void TestOfStack()
{
	srand(unsigned(time(NULL)));
	stack<int> a, b;
	unsigned int n = 100;
	re(i, n)
		a.push(rand() % 1000);
	std::cout << a;
	while (!a.isEmpty())
		b.push(a.pop());
	re(i, n)
		std::cout << b.pop() << " ";
	std::cout << std::endl;
}

void TestOfList()
{
	srand(int(time(NULL)));
	int a[1000];
	unsigned int SizeOfTest = 100;
	re(i, SizeOfTest)
		a[i] = rand() % 1000;
	list<int> one(a, SizeOfTest);
	std::cout << one;
	re(i, SizeOfTest)
		one.RearInsert(rand() % 1000);
	std::cout << one;
	re(i, SizeOfTest)
		one.HeadInsert(rand() % 1000);
	std::cout << one;
	list<int> two = one;
	std::cout << two;
	two = one;
	std::cout << one << std::endl;
}

void TestOfBtree()
{
	//输入可参考
	//a b c # # d # # e f # # g # #
	BTree<char> one;
	std::cin >> one;
	std::cout << std::endl;
	one.mid();
	std::cout << std::endl;
	one.pre();
	std::cout << std::endl;
	one.back();
	std::cout << std::endl;
	one.print();
	std::cout << std::endl;
	std::cout << "树高度：" << one.Height() << std::endl;
	std::cout << "节点数：" << one.NodeNum() << std::endl;
	return;
}

void TestOfBstree()
{
	srand(int(time(NULL)));
	int a[100000];
	unsigned int SizeOfTest = 200;
	re(i, SizeOfTest)
		a[i] = rand() % 100;
	re(i, SizeOfTest)
		std::cout << a[i] << " ";
	std::cout << std::endl;
	BSTree<int> one(a, SizeOfTest);
	//std::cout << std::endl;
	//one.pre();
	//std::cout << std::endl;
	//one.mid();
	//std::cout << std::endl;
	//one.back();
	//std::cout << std::endl;
	//one.print();
	//std::cout << std::endl;
	std::cout << "树高度：" << one.Height() << std::endl;
	std::cout << "节点数：" << one.NodeNum() << std::endl;
	//Qsort(a, 0, SizeOfTest - 1);
	re(i, SizeOfTest)
	{
		const Tree<int>* temp = one.find(a[i]);
		if (temp == NULL)
			std::cout << "无法找到！" << std::endl;
	}
	re(i, SizeOfTest)
	{
		one.DelNode(a[i]);
		//one.mid();
		//std::cout << std::endl;
	}
	std::cout << "树高度：" << one.Height() << std::endl;
	std::cout << "节点数：" << one.NodeNum() << std::endl;
	std::cin >> SizeOfTest;//测试内存释放
	re(j, SizeOfTest)
		a[j] = rand() % 10000;
	re(j, SizeOfTest)
	{
		BSTree<int> two(a, SizeOfTest);
		std::cout << "节点数：" << two.NodeNum() << " ";
	}

	return;

}

void TestOfBbtree()
{
	srand(int(time(NULL)));
	int a[10000];
	unsigned int SizeOfTest = 100;
	re(i, SizeOfTest)
		a[i] = rand() % 10000;
	Qsort(a, 0, SizeOfTest-1); //这时候出来的一般就是理想高度了。
	AVLTree<int> one(a, SizeOfTest);
	//std::cout << std::endl;
	//one.pre();
	//std::cout << std::endl;
	//one.mid();
	//std::cout << std::endl;
	//one.back();
	//std::cout << std::endl;
	//one.print();
	//std::cout << std::endl;
	re(i, SizeOfTest)
	{
		const Tree<int>* temp = one.find(a[i]);
		if (temp == NULL)
			std::cout << "无法找到！" << std::endl;
	}
	std::cout << "树高度：" << one.Height() << std::endl;
	std::cout << "最大高度：" << maxHeight_bbtree(SizeOfTest) << std::endl;
	std::cout << "最低高度：" << minHeight_bbtree(SizeOfTest) << std::endl;
	std::cout << "节点数：" << one.NodeNum() << std::endl;
	std::cout << "当前高度的最少节点：" << Fibonacci(one.Height()+2)-1 << std::endl;
	std::cout << std::endl;
	re(i, SizeOfTest)
		one.insert(rand() % 10000);
	std::cout << "树高度：" << one.Height() << std::endl;
	std::cout << "节点数：" << one.NodeNum() << std::endl;

	//re(i, SizeOfTest)
	//	one.delNode(a[i]);
	//one.mid();
	//std::cout << std::endl;
	//std::cout << "树高度：" << one.Height() << std::endl;
	//std::cout << "节点数：" << one.NodeNum() << std::endl;
}

void Test()
{
	try{
		//std::cout << "测试栈" << std::endl;
		//TestOfStack();
		//std::cout << "测试堆" << std::endl;
		//TestOfQueue();
		//std::cout << "测试链表" << std::endl;
		//TestOfList();
		std::cout << "测试二叉树" << std::endl;
		TestOfBtree();
		std::cout << "测试排序二叉树" << std::endl;
		TestOfBstree();
		std::cout << "测试平衡二叉树" << std::endl;
		TestOfBbtree();
	}
	catch (const char *a){
		std::cout << a << std::endl;
	}
}
