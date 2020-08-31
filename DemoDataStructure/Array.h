//数组
//所有语言基本都会有这个基础结构
#pragma once
#include <iostream>
using namespace std;

//例子:
int test_array[30] = {0,3,2,12,32,21,1};

int aaa[10000000];

//数组信息
void GetArrayInfo(int arrray[],int length)
{
	cout << "array space:" << sizeof(arrray)<<endl;
}

//查找--下标访问  
void SearchArray(int index)
{
	cout << "array search:";
	if (index < 0 || index>299)
	{
		return;
	}
	cout << test_array[index]<<endl;
}

//遍历
void TraverseArray(int arrray[], int length)
{
	cout << "array traverse:";
	//一般用下标遍历
	for (size_t i = 0; i < length; i++)
	{
		cout << arrray[i] << " ";
	}
	cout <<endl;
}


//一般对于数组我们需要知道长度和名称两个信息
//数组删除新增一般不讨论
