#include "bag.h"

std::ostream &operator<<(std::ostream& out, object const & other)
{
	re(i, other.num)
		out
		<< "��ֵ��" << other.value / (other.num) << " "
		<< "����: " << other.weight / (other.num) << std::endl
		/*<< " ƽ����ֵ�� " << other.value / other.weight*/;
	return out;
}
std::istream &operator>>(std::istream& in, object &other)
{
	return in >> other.value >> other.weight;
}

double BagState::CounRestValue()const
{
	if (RestNum == 0)
		return MyValue;
	double restValue = 0, room = RestRoom,num=RestNum;
	unsigned int i = MyLocation->Height() + 1;
	while (num > 0 && room >= AllObject[i].weight)
	{
		//���������;
		restValue += AllObject[i].value;
		room -= AllObject[i].weight;
		i++;
		num--;
	}
	if (i == 0)//�Ѿ���������
		return restValue;
	else //û�п����ꡣ�����¡�
		return restValue + AllObject[i].value / AllObject[i].weight;
}

BagState BagState::insert(bool flag)const
{
	BagState ans = *this;//��һ������
	int i = 0;
	if (flag&&RestNum > 0)//Ҫ���벢���ܲ���
	{
		ans.MyLocation = SolutionTree->leftinsert(true, MyLocation);
		i = MyLocation->Height() + 1;
		ans.MyValue += AllObject[i].value;
		ans.RestRoom -= AllObject[i].weight;
	}
	else
	{
		ans.MyLocation = SolutionTree->rightinsert(false, MyLocation);
	}
	ans.RestNum--;
	ans.MaxValue = MyValue + CounRestValue();
	return ans;
}

BagState::BagState(unsigned int Num, double limit,object things[])
	:RestNum(Num), AllObject(things), RestRoom(limit),//�����������о���һֱҪ�õġ�
	MyValue(0)
	//SolutionTree(new FreeTree<bool>(0)),
	//MyLocation(SolutionTree->Root()),
	//MaxValue(CounRestValue())
{
	SolutionTree = new FreeTree<bool>(0);
	MyLocation=SolutionTree->Root();
	MaxValue = CounRestValue();
}

std::ostream& operator<<(std::ostream& out, BagState const & other)
{
	treeNode<bool>* temp = other.MyLocation;
	while (temp->Height() > 0)//������parentҲ���ԡ�
	{
		if (temp->Data())
			out << other.AllObject[temp->Height() - 1];
		temp = temp->Parent();
	}
	return out << std::endl;
}
BagState Solve(unsigned int n, double limit, object* thing)
{
	Qsort(thing, 0, n - 1);
	BagState one(n, limit, thing);
	MaxHeap<BagState> Heap_State;
	double CurrentMaxValue = 0;
	Heap_State.push(one);
	while (!one.isEnd())
	{
		//ȡ�����Žڵ�
		one = Heap_State.pop();
		CurrentMaxValue = CurrentMaxValue < one.value() ? one.value() : CurrentMaxValue;
		if (one.restroom()>thing[one.level()].weight)//����Խ�粻����
			Heap_State.push(one.insert(true));
		Heap_State.push(one.insert(false));
	}
	return one;
}