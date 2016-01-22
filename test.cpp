#include "queue.cpp"
#include "stack.cpp"
#include "list.cpp"


void TestOfQueue()//修改后请通过该函数进行测试。
{
	try{
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
	}
	catch (char const * a){ std::cout << a << std::endl; }
}

void TestOfStack()
{
	try
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
	catch (char const * a){ std::cout << a << std::endl; }

}

void TestOfList()
{
	srand(int(time(NULL)));
	try
	{
		int a[10000];
		unsigned int SizeOfTest = 10000;
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
	catch (char const *a)
	{
		std::cout << a << std::endl;
	}
}
