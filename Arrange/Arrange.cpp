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


int Combination(int m, int n)//��All�Ļ����ϼ����֦��
{
	stack<int> Stack;
	int temp = 0, count = 0;
	bool flag[100] = {0};
	while (temp < n || !Stack.isEmpty())
	{
		while (Stack.Top() < m&&temp < n&&flag[temp]==0)//��֤ǰ��û�в��������㡣
		{
			Stack.push(temp);
			flag[temp] = 1;
			temp = 0;
		}
		if (Stack.Top() == m - 1)
		{
			std::cout << Stack;
			count++;
		}
		if (!Stack.isEmpty())//������һ��ȡ�Ա�һ���ڵ㡣
		{
			temp = Stack.pop() + 1;
			flag[temp - 1] = 0;
		}
	}
	return count;//��ʵֱ��return n^mҲ�ǿ��Եġ���
}


int Combination2(int m, int n)
{
	m--;
	stack<int> Stack;
	int count = 0, temp = 0;
	int flag[100] = { 0 }; flag[n] = 1;
	while (temp < n||!Stack.isEmpty())
	{
		while (Stack.Top() < m&&temp<n)
		{
			if (flag[temp] == 0)
			{
				Stack.push(temp);
				flag[temp] = 1;
			}
			temp++;
		}
		if (Stack.Top() == m)
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
	int count = 0, temp = 0;
	bool flag[100] = { 0 }; 
	int ok = 0;
	m--;
	while (temp < n || !Stack.isEmpty())
	{
		while (Stack.Top() < m&&temp<n)
		{
			if (flag[temp] == 0)
			{
				Stack.push(temp);
				flag[temp] = 1;
				if (ok > 1)temp = -1;
				ok = 0;
			}
			++temp;
		}
		if (Stack.Top() == m)
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