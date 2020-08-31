//学习数据结构而建立的一个项目-目的是深入学习数组，栈，队列，链表，哈希表，树，图所有的基本操作(增删改查)和结构特有的操作。----Tom
//为方便学习，子结构全部用int型
#include<string>
#include <iostream>
using namespace std;


#include "Array.h"
#include "LinkList.h"

int main()
{
	//**********************************数组
	cout << "**********************************Array********************************"<<endl;

	SearchArray(3);
	GetArrayInfo(test_array, 30);
	TraverseArray(test_array, 30);


	cout << "\n\n";

	//**********************************链表
	cout << "**********************************LinkList*******************************" << endl;;
	//创建一个链表例子
	CreateNode();
	PrintNode(head);	
	//增加一个结点
	head = AddNode(head, 0, 999);	
	PrintNode(head);
	//删除节点
	head = DeleteNode(head, 4);
	PrintNode(head);
	//更改节点数值
	EditNode(head, 9, 1800);
	PrintNode(head);
	//反转
	head = ReverseNode(head);
	PrintNode(head);
	//判断是否有环
	bool is_loop = HasLoop(head);
	cout << is_loop<<endl;

	//**********************************树




	system("Pause");
    return 0;
}

