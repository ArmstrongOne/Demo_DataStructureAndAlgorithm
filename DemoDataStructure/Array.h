//����
//�������Ի�����������������ṹ
#pragma once
#include <iostream>
using namespace std;

//����:
int test_array[30] = {0,3,2,12,32,21,1};

int aaa[10000000];

//������Ϣ
void GetArrayInfo(int arrray[],int length)
{
	cout << "array space:" << sizeof(arrray)<<endl;
}

//����--�±����  
void SearchArray(int index)
{
	cout << "array search:";
	if (index < 0 || index>299)
	{
		return;
	}
	cout << test_array[index]<<endl;
}

//����
void TraverseArray(int arrray[], int length)
{
	cout << "array traverse:";
	//һ�����±����
	for (size_t i = 0; i < length; i++)
	{
		cout << arrray[i] << " ";
	}
	cout <<endl;
}


//һ���������������Ҫ֪�����Ⱥ�����������Ϣ
//����ɾ������һ�㲻����
