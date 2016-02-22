#include "bag.h"
bool operator==(object const & a, object const & b){
	return a.value == b.value&&a.weight == a.weight;
}
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
	unsigned int i = MyLocation->Height();//������һ������
	re(j,RestNum-1)
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
	if (RestRoom < 0)
		throw "�ռ�Ϊ��������";
	if (flag)//Ҫ���벢���ܲ���
	{
		ans.MyLocation = SolutionTree->leftinsert(true, MyLocation);//height���Ǳ������±��1
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
	:RestNum(Num), AllObject(things), RestRoom(limit),//�����������о���һֱҪ�õġ�
	MyValue(0)
{
	SolutionTree = new FreeTree<bool>(0);
	MyLocation=SolutionTree->Root();
	MaxValue = CounRestValue();
}

void BagState::keepSolution()
{
	treeNode<bool>* temp = MyLocation;
	unsigned int height=temp->Height();
	object *tempObject = new object[height];//����ڴ�����˰�.�ҷ������ͷ��ˡ����r(������")�q
	RestNum = 0; 
	while (height > 0)
	{
		if (temp->Data())
			tempObject[RestNum++] = AllObject[height- 1];//һ���Ӻ���ǰ��һ����ǰ����
		temp = temp->Parent();
		height--;
	}
	SolutionTree->~FreeTree();
	SolutionTree = NULL;
	AllObject = tempObject;
}

std::ostream& operator<<(std::ostream& out, BagState const & other)
{
	if (other.SolutionTree != NULL)
	{
		treeNode<bool>* temp = other.MyLocation;
		while (temp->Height() > 0)//������parentҲ���ԡ�
		{
			if (temp->Data())
				out << other.AllObject[temp->Height() - 1];
			temp = temp->Parent();
		}
	}
	else
	{
		re(i, other.RestNum)
			out << other.AllObject[i];
	}
	return out << std::endl;
}

BagState Solve(unsigned int n, double limit, object* thing)
{
	object *m_thing = new object[n + 1];
	memcpy(m_thing, thing, n*sizeof(object));
	Qsort_MaxToMin(m_thing, 0, n - 1);
	//����ѹ������
	unsigned int i = 0, j = 0, k = 0, ObjectNum = 0,count=0;
	int delta = 0;
	while (j < n)
	{
		//������ͬ����,i��¼��㣬j��¼�յ�
		for (i = j, j++; j < n; j++)
			if (m_thing[j]!=m_thing[i])
				break;
		//�ϲ�n����ͬ���塣
		for (k = 0, delta = j - i; (1 << k) <= delta; delta -= (1 << k), k++)//delta���ϼ���
			m_thing[ObjectNum++] = m_thing[i] * (1 << k);
		if (delta > 0)//�������ʣ��
			m_thing[ObjectNum++] = m_thing[i] * delta;
	}
	//solve
	BagState one(ObjectNum, limit, m_thing);
	MaxHeap<BagState> Heap_State;
	double CurrentMaxValue = 0;
	while (!one.isEnd())
	{
		count++;
		CurrentMaxValue = CurrentMaxValue < one.value() ? one.value() : CurrentMaxValue;
		if (one.restroom()>=m_thing[one.height()].weight)//����Խ�粻����
			Heap_State.push(one.insert(true));
		Heap_State.push(one.insert(false));
		//ȡ�����Žڵ�
		one = Heap_State.pop();//��Ϊ��������ж�ʱ���Ѿ������յ㡣
	}
	//std::cout << count << std::endl;
	one.keepSolution();
	delete[] m_thing;
	return one;
}