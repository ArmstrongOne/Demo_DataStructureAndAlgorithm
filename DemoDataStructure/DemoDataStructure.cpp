//ѧϰ���ݽṹ��������һ����Ŀ-Ŀ��������ѧϰ���飬ջ�����У�������ϣ������ͼ���еĻ�������(��ɾ�Ĳ�)�ͽṹ���еĲ�����----Tom
//Ϊ����ѧϰ���ӽṹȫ����int��
#include<string>
#include <iostream>
using namespace std;


#include "Array.h"
#include "LinkList.h"

int main()
{
	//**********************************����
	cout << "**********************************Array********************************"<<endl;

	SearchArray(3);
	GetArrayInfo(test_array, 30);
	TraverseArray(test_array, 30);


	cout << "\n\n";

	//**********************************����
	cout << "**********************************LinkList*******************************" << endl;;
	//����һ����������
	CreateNode();
	PrintNode(head);	
	//����һ�����
	head = AddNode(head, 0, 999);	
	PrintNode(head);
	//ɾ���ڵ�
	head = DeleteNode(head, 4);
	PrintNode(head);
	//���Ľڵ���ֵ
	EditNode(head, 9, 1800);
	PrintNode(head);
	//��ת
	head = ReverseNode(head);
	PrintNode(head);
	//�ж��Ƿ��л�
	bool is_loop = HasLoop(head);
	cout << is_loop<<endl;

	//**********************************��




	system("Pause");
    return 0;
}

