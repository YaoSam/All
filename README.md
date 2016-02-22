﻿# My-Data-Structures

## 概述 ##
Data Structure这个文件夹里面包含了各种数据结构的实现。<br>
主要包括：**栈**，**循环队列**，**链表**，**二叉树（排序二叉树，平衡二叉树）**，**树的迭代器**，**堆**。<br>
以上的结构都用模板类实现，基本都是动态分配内存并释放，下面是对每一个的详细说明。


----------


## Stack ##
（难度级别：\*）<br>
没什么好说的。说一下接口
 - pop()
 - push()
 - TopData()：返回栈顶端元素。
 - clear()：只是简单的将Top置为-1而已……
 - Number()：返回栈元素数目。
 - Top()：返回Top也就是栈顶元素的下标。
 - isEmpty()：判断是否栈是否为空（也就是Top是否为空）。
 - operator[]：用来读取栈的某一个元素。
 - operator<<：用来输出怎一个栈。


----------


## Queue ##
（难度级别：\*）<br>
循环队列。但是也会动态申请内存。
 - push()
 - pop()
 - clear()：清空队列（只是简单的将front和rear置为0而已）
 - isEmpty():判断是否栈为空。


----------


##List##
（难度级别：\*）<br>
带头节点的链表，内置了一个迭代器（**pointer**）。
 - List()：可以直接输入整个数组。
 - Length()：返回链表的长度/节点的数目
 - HeadInsert()：从头部插入。
 - RearInsert()：从尾部插入。
 - find()：查找值为x的第一个节点。
 - delNode()：删除第一个值为x的节点。
 - earse()：删除所有值为x的节点。
 - operator<<：输出链表的所有节点。
 - resetPointer()：重置迭代器。
####list_iterator####
链表的迭代器。<br>
（难度级别：\*）
 - isEnd()：指针遍历完链表/指针是否为空。
 - operator\*：返回当前节点的元素。
 - reset()：重置迭代器。
 - operator++：指针指向下一个节点。


----------


##treeNode##
（难度级别\*\*\*，复制删除的实现较难）<br>
树的基本节点。用三个指针（**parent,left,right**）分别指向父亲，左右两个儿子。**height**代表当前结点高度。**data**储存数据。<br>
*内部接口(private)：*  <br>
 - CheckHeight()：通过检查左右儿子的高度来更新自身高度。
 - leftlink()，rightlink()：在链接**left**，**right**的同时维护**left**和**right**的**parent**。
 - Copy()：模仿前序遍历实现的复制。复制的是以该节点为根的树。
 - Del()：模仿后序遍历实现删除。删除的是该节点以下的所有节点。
*外部接口（public）：*
 - Left(),Right(),Parent(),Data(),Height()：分别返回对应变量。

##NormalTree##
（难度级别：\*\*\*\*，因为各种遍历的实现较难）<br>
抽象类，最基本的二叉树结构。基本可以说没有构造函数……需要直接去重载insert来构造自己的二叉树。但是实现了各种最通用的接口。
 - height()：返回树的高度。
 - NodeNum()：返回节点数目（**前序遍历**实现）。
 - Root()：返回根节点。
 - pre()：输出前序遍历（**非递归实现**）。
 - mid()：输出中序遍历（**非递归实现**）。
 - post()：输出后序遍历（**非递归实现**）。
 - print()：输出层序遍历。
 - find()：前序遍历查找结点（虚函数）

##bstree##
（难度级别：\*\*\*，删除较难）<br>
排序二叉树。继承自NormalTree。重载了insert接口。<br>
*内部接口(private)：*
 - FindRightNext()：返回该节点右边的第一个节点。
 - FindLeftNext()：返回该节点左边的第一个节点。
 - Maintain()：**虚函数**。在删除/插入节点后维护树的结构。为平衡二叉树做铺垫。<br>
*外部接口（public）：*
 - insert()：根据排序二叉树的性质插入节点。没什么好说的。插入后调用Maintain即可。
 - find()：根据排序二叉树的性质做的二分查找。
 - DelNode()：（**难点**）删除值为x的节点。实现细节：找到值最为接近的节点（**FindRightNext(),FindLeftNext()**）然后交换数据。删除找到的节点。但是要维护好删除节点的父亲的指针，并且要调用Maintain。
 
## AVLtree ##
（难度级别：\*\*\*\*，各种旋转还有**Maintain()**的烦死了……）<br>
平衡二叉树，继承自**bstree**。在排序二叉树的基础上加入各种旋转进行调整实现。<br>
具体有4种旋转:LL,RR,RL,LR.<br>
每次插入/删除之后用Maintain调整最小的不平衡二叉树，使得其平衡（只调整一次？！）<br>
最耗费资源的是每次检查是否平衡所用到的CheckHeight()。<br>
*内部接口(private)：*
 - differ()：返回左右高度的差（**左减右**）。
 - RorateRR(),RorateLL(),RorateRL(),RorateLR()：四种旋转。其中RL，LR都是用一次RR和LL来实现的。
 - Maintain()：沿着插入或者删除的位置回溯。维护高度并且检查是否有不平衡并用Rorate进行维护。<br>
*外部接口（public）：*
 - 并没有。相对于**bstree**只是**Maintain()**不同了。


----------
##iterator##
（难度级别：\*）<br>
树的迭代器。都继承自m_iterator。<br>
具有两个指针：**pCurrent**，**m_root**。一个是指向当前结点。一个指向树的根。用来初始化迭代器。<br>
*基础接口*
 - operator()：返回指向当前结点的指针（**treeNode**）。
 - operator*：返回当前指向的节点的元素。
 - isEnd()：判断是否已经到该种遍历的结尾（也就是指向NULL）。
 - goFirst()：纯虚函数。用来初始化迭代器。
 - operator++：纯虚函数。指向下一个元素。

####Pre_iterator####
前序遍历迭代器。（难度级别：\*\*）
####Mid_iterator####
中序遍历迭代器。（难度级别：\*\*）
####Post_iterator####
后序遍历迭代器（难度级别：\*\*\*）
####Level_iterator####
层序遍历迭代器。对平衡二叉树来说占用内存较大（难度界别：\*）


----------
##Heap##
（难度级别：\*\*\*）<br>
堆，基类型。通过初始化compare()比较函数来确定序。<br>
- *内部接口*
 - Down()：从上往下维护堆的结构 
 - Up()：从下往上维护堆的结构
 - expend()：申请内存。<br>
- *基础接口*
 - pop()
 - push()
 - isEmpty()：判断堆是否为空。

####MaxHeap####
最大堆。规定compare为<。
####MinHeap####
最小堆。规定compare为>。


----------
##normal.h##

设定了一些比较常用的宏定义和函数模板：<br>
- *函数模板：*<br>
 - Qsort()：快排。从小到大。
 - Qsort_MaxtoMin()：快排。从大到小。
 - operator<=,>=,<,!=：只需要规定>和==即可。因为感觉只有>的效率会比较低，所以还是实现一下==吧（待定）
 - Max()：返回较大值。
 - Swap()：交换两个元素的值。
 - printArray()：输出某个数组。
- *宏：*<br>
 - re(i,n) for(int i=0;i<n;i++)：用来实现n次循环。
 - TEMP template<class T>：因为基本都要用到模板。
 

 









