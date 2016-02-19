#include "..\Data Sturcture\heap.cpp"
#include "..\Data Sturcture\freetree.cpp"

struct object
{
	unsigned int num;//��¼�ں��˶��ٸ�����
	double weight, value;
	object(double value = 0, double weight = 0, unsigned int num = 1) :
		value(value), weight(weight), num(num){}
	bool operator>(object const & other)const{//�ü�ֵ�ܶ���Ϊ��׼
		if (value*other.weight == other.value*weight)return value > other.value;//����ѹ�������õġ�
		return value*other.weight > other.value*weight;
	}
	object operator*(unsigned int n){
		return object(value*n, weight*n, num*n);
	}
};
bool operator==(object const & a, object const & b);
//�����ʽ�� ��ֵ��? ����: ? *��Ŀ
std::ostream &operator<<(std::ostream& out, object const & other);
//�����ʽ��vlaue weight
std::istream &operator>>(std::istream& in, object &other);

class BagState
{
	double MaxValue, MyValue, RestRoom;
	unsigned int RestNum;
	treeNode<bool>* MyLocation;
	//һ�µ�Ҫ����delete
	FreeTree<bool>* SolutionTree;
	object* AllObject;
	//����ʣ���ֵ
	double CounRestValue()const;
public:
	//�Ż��ڴ档
	void keepSolution();
	void clear(){ if (AllObject)delete[]AllObject; }
	BagState(){}
	BagState(unsigned int thingNum, double limit,object things[]);
	//���ص�ǰ������ֵ
	double value()const{ return MyValue; }
	//�����ж��Ƿ��Ѿ�װ��
	double restroom()const{ return RestRoom; }
	//�����ж��Ƿ��˵ײ�
	bool isEnd()const{ return RestNum ==0; }
	//��ʵisEnd()������������桭��
	unsigned int height()const { return MyLocation->Height(); }
	//�������塣�����µı�����flag=1����롣flag=0���Թ���
	BagState insert(bool flag)const;
	//�����������ȶ��е����ȼ�����������ѣ��б��׼�����ֵ�Ͻ�(MaxValue)
	bool operator>(BagState const & other)const
	{
		return MaxValue > other.MaxValue;
	}
	//�������״̬
	friend std::ostream& operator<<(std::ostream& out, BagState const & other);
};


//�ؼ�������ͨ���ýӿ�������������⡣
BagState Solve(unsigned int n, double limit, object* thing);