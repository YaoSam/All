#include "Arrange.h"
int AllSolution(int m, int n)//�൱�ڶ���ȫn������ǰ�����
{
	stack<int> Stack;
	int temp = 0, count = 0;
	while (temp < n || !Stack.isEmpty())//�������Ȼ��Ȼ��ջΪ�գ�Ҳ�������һ�ж���pop�ˣ�
	{
		while (Stack.Top() < m&&temp < n)//��һ������ָ �ǿ�λ�á�
		{
			Stack.push(temp);
			temp = 0;
		}
		if (Stack.Top() == m - 1)
		{
			std::cout << Stack;
			count++;
		}
		if (!Stack.isEmpty())//������һ��ȡ�Ա�һ���ڵ㡣
			temp = Stack.pop() + 1;
	}
	return count;//��ʵֱ��return n^mҲ�ǿ��Եġ���
}

int Combination(int m, int n)
{
	stack<int> Stack;
	int count = 0, temp = 0;
	int flag[100] = { 0 }; 
	while (temp < n||!Stack.isEmpty())
	{
		while (Stack.Number() < m&&temp<n)
		{
			if (flag[temp] == 0)
			{
				Stack.push(temp);
				flag[temp] = 1;
			}
			temp++;
		}
		if (Stack.Number() == m)
		{
			std::cout << Stack;
			count++;
		}
		if (!Stack.isEmpty())
		{
			temp = Stack.pop() + 1;
			flag[temp - 1] --;
		}
	}
	return count;
}

int Permutation(int m, int n)
{
	stack<int> Stack;
	int count = 0, temp = 0, ok = 0;
	bool flag[100] = { 0 }; 
	while (temp < n || !Stack.isEmpty())
	{
		while (Stack.Number() < m&&temp<n)
		{
			if (flag[temp] == 0)
			{
				Stack.push(temp);
				flag[temp] = 1;
				if (ok > 1)temp = -1;//������������pop()��û��push����Ҫ������
				ok = 0;
			}
			++temp;
		}
		if (Stack.Number() == m)
		{
			std::cout << Stack;
			count++;
		}
		if(!Stack.isEmpty())
		{
			temp = Stack.pop() + 1;
			flag[temp - 1] = 0;
			ok++;
		}
	}
	return count;
}