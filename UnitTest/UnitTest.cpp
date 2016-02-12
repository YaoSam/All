#include "stdafx.h"
#include "../Data Sturcture/bbtree.cpp"
using namespace System;
using namespace System::Text;
using namespace System::Collections::Generic;
using namespace Microsoft::VisualStudio::TestTools::UnitTesting;

namespace UnitTest
{
	[TestClass]
	public ref class UnitTest
	{
	private:
		TestContext^ testContextInstance;

	public: 
		/// <summary>
		///��ȡ�����ò��������ģ����������ṩ
		///�йص�ǰ�������м��书�ܵ���Ϣ��
		///</summary>
		property Microsoft::VisualStudio::TestTools::UnitTesting::TestContext^ TestContext
		{
			Microsoft::VisualStudio::TestTools::UnitTesting::TestContext^ get()
			{
				return testContextInstance;
			}
			System::Void set(Microsoft::VisualStudio::TestTools::UnitTesting::TestContext^ value)
			{
				testContextInstance = value;
			}
		};

		#pragma region Additional test attributes
		//
		//��д����ʱ������ʹ�����¸�������: 
		//
		//���������еĵ�һ������֮ǰ��ʹ�� ClassInitialize �����д���
		//[ClassInitialize()]
		//static void MyClassInitialize(TestContext^ testContext) {};
		//
		//�����е����в��Զ�������֮��ʹ�� ClassCleanup �����д���
		//[ClassCleanup()]
		//static void MyClassCleanup() {};
		//
		//������ÿ������֮ǰ��ʹ�� TestInitialize �����д���
		[TestInitialize()]
		void MyTestInitialize() {
			srand(int(time(NULL)));
		};

		//��ÿ������������֮��ʹ�� TestCleanup �����д���
		//[TestCleanup()]
		//void MyTestCleanup() {};
		//
		#pragma endregion 
		[TestMethod]
		void TestMethod1()
		{
			//
			// TODO:  �ڴ˴���Ӳ����߼�
			//
			const unsigned int SizeofTest=10000;
			int a[SizeofTest];
			re(i, SizeofTest)
				a[i] = rand() % (SizeofTest*2);
			AVLtree<int> one(a, SizeofTest);
			re(i, SizeofTest)
			{
				treeNode<int>* temp = one.find(a[i]);
				assert(temp != NULL);
			}
		};
	};
}
