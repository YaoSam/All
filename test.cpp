#pragma  once
#include "queue.cpp"
#include "stack.cpp"
#include "list.cpp"
#include "btree.cpp"
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
	while (Fibonacci(height + 1) < n)	height++;
	return height;
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

void TestOfQueue()//�޸ĺ���ͨ���ú������в��ԡ�
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
	//����ɲο�
	//a b c # # d # # e f # # g # #
	btree<char> one;
	std::cin >> one;
	std::cout << std::endl;
	one.pre();
	std::cout << std::endl;
	one.mid();
	std::cout << std::endl;
	one.back();
	std::cout << std::endl;
	one.print();
	std::cout << std::endl;
	std::cout << "���߶ȣ�" << one.Height() << std::endl;
	std::cout << "�ڵ�����" << one.NodeNum() << std::endl;
	return;
}

void TestOfBstree()
{
	srand(int(time(NULL)));
	int a[10000];
	unsigned int SizeOfTest = 1000;
	re(i, SizeOfTest)
		a[i] = rand() % 10000;
	re(i, 100)
		std::cout << a[i] << " ";
	std::cout << std::endl;
	bstree<int> one(a, SizeOfTest);
	std::cout << std::endl;
	one.pre();
	std::cout << std::endl;
	one.mid();
	std::cout << std::endl;
	one.back();
	std::cout << std::endl;
	one.print();
	std::cout << std::endl;
	std::cout << "���߶ȣ�" << one.Height() << std::endl;
	std::cout << "�ڵ�����" << one.NodeNum() << std::endl;
	Qsort(a, 0, SizeOfTest - 1);
	//re(i, SizeOfTest)
	//{
	//	const btree<int>* temp = one.find(a[i]);
	//	temp->mid();
	//	std::cout << std::endl;
	//}
	return;
}

void TestOfBbtree()
{
	srand(int(time(NULL)));
	int a[10000];
	unsigned int SizeOfTest = 1000;
	re(i, SizeOfTest)
		a[i] = rand() % 10000;
	//Qsort(a, 0, SizeOfTest-1); //��ʱ�������һ���������߶��ˡ�
	bbtree<int> one(a, SizeOfTest);
	std::cout << std::endl;
	one.pre();
	std::cout << std::endl;
	one.mid();
	std::cout << std::endl;
	one.back();
	std::cout << std::endl;
	one.print();
	std::cout << std::endl;
	std::cout << "���߶ȣ�" << one.Height() << std::endl;
	std::cout << "���߶ȣ�" << maxHeight_bbtree(SizeOfTest) << std::endl;
	std::cout << "��͸߶ȣ�" << minHeight_bbtree(SizeOfTest) << std::endl;
	std::cout << "�ڵ�����" << one.NodeNum() << std::endl;
	std::cout << "��ǰ�߶ȵ����ٽڵ㣺" << Fibonacci(one.Height()) << std::endl;
	std::cout << std::endl;
	re(i, SizeOfTest)
		one.insert(rand() % 10000);
	std::cout << "���߶ȣ�" << one.Height() << std::endl;
	std::cout << "���߶ȣ�" << maxHeight_bbtree(SizeOfTest) << std::endl;
	std::cout << "��͸߶ȣ�" << minHeight_bbtree(SizeOfTest) << std::endl;
	std::cout << "�ڵ�����" << one.NodeNum() << std::endl;
	std::cout << "��ǰ�߶ȵ����ٽڵ㣺" << Fibonacci(one.Height()) << std::endl;
}

void Test()
{
	try{
		//std::cout << "����ջ" << std::endl;
		//TestOfStack();
		//std::cout << "���Զ�" << std::endl;
		//TestOfQueue();
		//std::cout << "��������" << std::endl;
		//TestOfList();
		//std::cout << "���Զ�����" << std::endl;
		//TestOfBtree(); 
		std::cout << "�������������" << std::endl;
		TestOfBstree();
		std::cout << "����ƽ�������" << std::endl;
		TestOfBbtree();
	}
	catch (const char *a){
		std::cout << a << std::endl;
	}
}
