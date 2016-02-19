#include "bag.h"

std::ostream &operator<<(std::ostream& out, object const & other)
{
	re(i, other.num)
		out
		<< "��ֵ��" << other.value / (other.num) << " "
		<< "����: " << other.weight / (other.num)
		//<< " ƽ����ֵ�� " << other.value / other.weight
		<< std::endl;
	return out;
}
std::istream &operator>>(std::istream& in, object &other)
{
	return in >> other.value >> other.weight;
}

double BagState::CounRestValue()const
{
	if (RestNum < 0)
		return MyValue;
	double restValue = 0, room = RestRoom;
	unsigned int i = MyLocation->Height();
	re(j,RestNum)
	{
		if (room >= AllObject[i + j].weight)
		{
			//���������;
			restValue += AllObject[i + j].value;
			room -= AllObject[i + j].weight;
		}
		else
			return restValue + AllObject[i].value / AllObject[i].weight;//û�п����ꡣ
	}
	return restValue;//��ʱ�Ѿ���������
}

BagState BagState::insert(bool flag)const
{
	BagState ans = *this;//��һ������
	int i = 0;
	if (RestNum == 0)
		throw "�Ѿ��������ˣ��޷����롣";
	if (flag)//Ҫ���벢���ܲ���
	{
		ans.MyLocation = SolutionTree->leftinsert(true, MyLocation);
		i = MyLocation->Height();
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
	:RestNum(Num+1), AllObject(things), RestRoom(limit),//�����������о���һֱҪ�õġ�
	MyValue(0)
{
	SolutionTree = new FreeTree<bool>(0);
	MyLocation=SolutionTree->Root();
	MaxValue = CounRestValue();
}

std::ostream& operator<<(std::ostream& out, BagState const & other)
{
	treeNode<bool>* temp = other.MyLocation;
	temp = temp->Parent();
	while (temp->Height()>0)//������parentҲ���ԡ�
	{
		if (temp->Data())
			out << other.AllObject[temp->Height()-1];
		temp = temp->Parent();
	}
	return out << std::endl;
}
BagState Solve(unsigned int n, double limit, object* thing)
{
	object *m_thing = new object[n + 1];
	memcpy(m_thing, thing, n*sizeof(object));
	//����ѹ������
	Qsort(m_thing, 0, n - 1);
	object temp; bool flag = 0;
	unsigned int i = 0, j = 0, k = 0, ObjectNum = 0;
	int delta = 0;
	while (j < n)
	{
		//������ͬ����,i��¼��㣬j��¼�յ�
		for (i = j, temp = m_thing[j]; j < n; j++)
			if (m_thing[j]!=temp)
				break;
		//�ϲ�n����ͬ���塣
		for (k = 0, delta = j - i; (1 << k) <= delta; delta -= (1 << k), k++)//delta���ϼ���
			m_thing[ObjectNum++] = (m_thing[i] * (1 << k));
		if (delta > 0)//�������ʣ��
			m_thing[ObjectNum++] = m_thing[i] * delta;
	}
	//solve
	//unsigned int ObjectNum = n;
	BagState one(ObjectNum, limit, m_thing);
	MaxHeap<BagState> Heap_State;
	double CurrentMaxValue = 0;
	while (!one.isEnd())
	{
		//ȡ�����Žڵ�
		CurrentMaxValue = CurrentMaxValue < one.value() ? one.value() : CurrentMaxValue;
		if (one.restroom()>=thing[one.level()].weight)//����Խ�粻����
			Heap_State.push(one.insert(true));
		Heap_State.push(one.insert(false));
		one = Heap_State.pop();//��Ϊ��������ж�ʱ���Ѿ������յ㡣
	}
	return one;
}