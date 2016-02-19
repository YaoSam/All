#include "bag.h"

std::ostream &operator<<(std::ostream& out, object const & other)
{
	re(i, other.num)
		out
		<< "价值：" << other.value / (other.num) << " "
		<< "重量: " << other.weight / (other.num)
		//<< " 平均价值： " << other.value / other.weight
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
			//放入该物体;
			restValue += AllObject[i + j].value;
			room -= AllObject[i + j].weight;
		}
		else
			return restValue + AllObject[i].value / AllObject[i].weight;//没有考虑完。
	}
	return restValue;//此时已经考虑完了
}

BagState BagState::insert(bool flag)const
{
	BagState ans = *this;//上一个物体
	int i = 0;
	if (RestNum == 0)
		throw "已经考虑完了，无法插入。";
	if (flag)//要插入并且能插入
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
	:RestNum(Num+1), AllObject(things), RestRoom(limit),//这三个变量感觉是一直要用的。
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
	while (temp->Height()>0)//这里用parent也可以。
	{
		if (temp->Data())
			out << other.AllObject[temp->Height()-1];
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
	while (!one.isEnd())
	{
		//取出最优节点
		CurrentMaxValue = CurrentMaxValue < one.value() ? one.value() : CurrentMaxValue;
		if (one.restroom()>=thing[one.level()].weight)//容量越界不插入
			Heap_State.push(one.insert(true));
		Heap_State.push(one.insert(false));
		one = Heap_State.pop();//因为弹出后得判断时候已经到了终点。
	}
	return one;
}