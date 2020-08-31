//链表----这里只讨论下单链表
//操作:构造，增删改查，反转，判断回环节点
#pragma once
#include <iostream>
using namespace std;


//原始结构
struct Node
{
	Node*next_node = NULL;
	int value = 0;
};


//构造一个例子:10个项的简单链表
Node*head=NULL;

void CreateNode()
{
	head = new Node;
	Node*now_node = NULL; //追踪指针
	now_node = head;
	for (int i = 0; i < 9; i++)
	{
		Node*cur_node = new Node;
		cur_node->value = i + 1;
		now_node->next_node = cur_node;
		now_node = cur_node;//追踪指针移动到当前

		if (i == 8) //最后一个节点下一个直接指向空
		{
			cur_node->next_node = NULL;
		}
	}
}

void PrintNode(Node*head)
{
	cout << "current linklist:";
	Node*position_node = head; //定位指针
	while (position_node)
	{
		cout << position_node->value << " ";
		position_node = position_node->next_node;
	}
	cout << endl;
}

Node* AddNode(Node*head, int n, int value)
{
	cout << "Add node:"<<to_string(n)<<" ";;
	//TOD:这里传入的是指针副本 头插入需要传出head 而不能直接更改head
	//先判断head有多少项
	int node_num = 0;
	Node*positon_node = head;
	while (positon_node)
	{
		node_num++; //计数加1
		positon_node = positon_node->next_node;//指向下个节点
	}

	if (0 == node_num) //表示传入的是空头 直接return
	{
		return head;
	}

	//接下来判断插入位置
	if (0 == n)  //插在链表头
	{
		Node*new_node = new Node;
		new_node->value = value;
		new_node->next_node = head;
		head = new_node;
	}

	if (n == node_num - 1)//插在链表尾部
	{
		Node*last_node = NULL; //找到最后面那个节点
		Node*positon_node2 = head; //定位指针
		while (positon_node2)
		{
			if (positon_node2->next_node == NULL)     //如果该节点下一个位是NULL 就是我们要找的那个节点
			{
				last_node = positon_node2;
				break;
			}
			positon_node2 = positon_node2->next_node;
		}
		//插入
		Node*new_last_node = new Node;
		new_last_node->value = value;
		last_node->next_node = new_last_node;
		new_last_node->next_node = NULL;
	}

	if (n > 0 && n < node_num - 1) //链表中间
	{
		//一定存在插入的左右两个节点
		Node*front_node = NULL;
		Node*behiend_node = NULL;

		Node*positon_node3 = head;//定位指针
		int index = 0;
		while (positon_node3)
		{
			if (n == index)  //查找到对应节点
			{
				front_node = positon_node3;
				behiend_node = positon_node3->next_node;
				break;
			}

			//移到下一个节点
			positon_node3 = positon_node3->next_node;
			index++;
		}

		//插入新节点
		Node*new_node = new Node;
		new_node->value = value;
		front_node->next_node = new_node;
		new_node->next_node = behiend_node;
	}
	return head;
}

Node*DeleteNode(Node*head, int n)
{
	cout << "Delete node:"<<to_string(n) << " ";;
	//先判断head有多少项
	int node_num = 0;
	Node*positon_node = head;
	while (positon_node)
	{
		node_num++; //计数加1
		positon_node = positon_node->next_node;//指向下个节点
	}

	if (0 == node_num) //表示传入的是空头 直接return
	{
		return head;
	}


	if (0 == n)  //删除链表头
	{
		if (1 == node_num) //只有一个节点
		{
			delete head;
			return NULL;
		}
		else //大于一个节点
		{
			Node *new_head = head->next_node;
			delete head;
			return new_head;
		}
	}

	if (n == node_num - 1)//删除链表尾部
	{
		//只有一个节点的情况上一步if中已经判断 这里一定是节点数大于1的情况

		Node*front_node = NULL;//找到倒数第二个节点
		Node*behiend_node = NULL;//最后一个节点
		Node*positon_node2 = head; //定位指针
		while (positon_node2)
		{
			if (positon_node2->next_node->next_node == NULL)     //如果该节点下一个位的下一位是NULL 就是我们要找的那个节点
			{
				front_node = positon_node2;
				behiend_node = positon_node2->next_node;
				break;
			}
			positon_node2 = positon_node2->next_node;
		}
		//删除
		front_node->next_node = NULL;
		delete behiend_node;
		behiend_node = NULL;
	}

	if (n > 0 && n < node_num - 1) //链表中间
	{
		Node*front_node = NULL;//删除节点左节点
		Node*delete_node = NULL;//待删除节点
		Node*positon_node2 = head; //定位指针

		int index = 0;
		while (positon_node2)
		{
			if (index == n - 1)     //定位到删除节点前的那个节点
			{
				front_node = positon_node2;
				delete_node = positon_node2->next_node;
				break;
			}
			positon_node2 = positon_node2->next_node;
			index++;
		}
		//删除
		front_node->next_node = delete_node->next_node;
		delete delete_node;
		delete_node = NULL;
	}
	return head;
}

bool EditNode(Node*head, int n, int value)
{
	cout << "Edit node:" << to_string(n)<<" ";
	//先判断head有多少项
	int node_num = 0;
	Node*positon_node = head;
	while (positon_node)
	{
		node_num++; //计数加1
		positon_node = positon_node->next_node;//指向下个节点
	}

	if (0 == node_num) //表示传入的是空头 直接return
	{
		return false;
	}

	if (0 == n)  //修改链表头
	{
		head->value = value;
	}

	if (n == node_num - 1)//修改链表尾部
	{
		//只有一个节点的情况上一步if中已经判断 这里一定是节点数大于1的情况
		Node*positon_node2 = head; //定位指针
		while (positon_node2)
		{
			if (positon_node2->next_node == NULL)     //如果该节点下一个位的下一位是NULL 就是我们要找的那个节点
			{
				positon_node2->value = value;
				break;
			}
			positon_node2 = positon_node2->next_node;
		}
	}

	if (n > 0 && n < node_num - 1) //链表中间
	{
		int index = 0;
		Node*positon_node2 = head; //定位指针
		while (positon_node2)
		{
			if (index == n)     //定位到删除节点前的那个节点
			{
				positon_node2->value = value;
				break;
			}
			positon_node2 = positon_node2->next_node;
			index++;
		}
	}
	return true;
}

Node* ReverseNode(Node*head)
{
	cout << "linlist reverse:" << " ";
	//先判断head有多少项
	int node_num = 0;
	Node*positon_node = head;
	while (positon_node)
	{
		node_num++; //计数加1
		positon_node = positon_node->next_node;//指向下个节点
	}

	if (0 == node_num) //表示传入的是空头 直接return
	{
		return false;
	}

	if (1 == node_num) //只有一项 无需反转
	{
		return head;
	}

	if (node_num > 1) //开始反转
	{
		Node*left_node = NULL;     //左节点
		Node*right_node = NULL;  //右节点

		//初始结构
		right_node = head->next_node;
		head->next_node = NULL;
		left_node = head;

		while (right_node)
		{
			Node*next_node = right_node->next_node; //记录右指针下一个节点
			right_node->next_node = left_node;//右节点指针指向左节点
			left_node = right_node;//左节点指向右节点位置
			if (next_node == NULL)
			{
				break;
			}
			right_node = next_node;//右节点指向右节点的下一个位置
		}
		return right_node;
	}
}


//快慢指针的思想
/**解题思想：
*这里也是用到两个指针。如果一个链表中有环，
*也就是说用一个指针去遍历，是永远走不到头的。
*因此，我们可以用两个指针去遍历，
*一个指针一次走两步，一个指针一次走一步，
*如果有环，两个指针肯定会在环中相遇。
*时间复杂度为O（n）。
*/

bool HasLoop(Node *pHead)
{
	cout << "has loop:";

	if (pHead == NULL || pHead->next_node == NULL)
	{
		return false;
	}
	Node *pFast = pHead; //快指针每次前进两步 
	Node *pSlow = pHead; //快指针每次前进一步 
	while (pFast != NULL && pSlow !=NULL)
	{
		//快指针走一步
		pFast = pFast->next_node;
		if (pFast == NULL)
		{
			return false;
		}
		//慢指针走一步
		pSlow = pSlow->next_node;
		//快指针再走一步
		if (pFast->next_node != NULL)
		{
			pFast = pFast->next_node;
		}
		if (pFast == pSlow)
		{
			return true;
		}
	}
	return false;
}