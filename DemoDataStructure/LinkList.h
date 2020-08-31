//����----����ֻ�����µ�����
//����:���죬��ɾ�Ĳ飬��ת���жϻػ��ڵ�
#pragma once
#include <iostream>
using namespace std;


//ԭʼ�ṹ
struct Node
{
	Node*next_node = NULL;
	int value = 0;
};


//����һ������:10����ļ�����
Node*head=NULL;

void CreateNode()
{
	head = new Node;
	Node*now_node = NULL; //׷��ָ��
	now_node = head;
	for (int i = 0; i < 9; i++)
	{
		Node*cur_node = new Node;
		cur_node->value = i + 1;
		now_node->next_node = cur_node;
		now_node = cur_node;//׷��ָ���ƶ�����ǰ

		if (i == 8) //���һ���ڵ���һ��ֱ��ָ���
		{
			cur_node->next_node = NULL;
		}
	}
}

void PrintNode(Node*head)
{
	cout << "current linklist:";
	Node*position_node = head; //��λָ��
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
	//TOD:���ﴫ�����ָ�븱�� ͷ������Ҫ����head ������ֱ�Ӹ���head
	//���ж�head�ж�����
	int node_num = 0;
	Node*positon_node = head;
	while (positon_node)
	{
		node_num++; //������1
		positon_node = positon_node->next_node;//ָ���¸��ڵ�
	}

	if (0 == node_num) //��ʾ������ǿ�ͷ ֱ��return
	{
		return head;
	}

	//�������жϲ���λ��
	if (0 == n)  //��������ͷ
	{
		Node*new_node = new Node;
		new_node->value = value;
		new_node->next_node = head;
		head = new_node;
	}

	if (n == node_num - 1)//��������β��
	{
		Node*last_node = NULL; //�ҵ�������Ǹ��ڵ�
		Node*positon_node2 = head; //��λָ��
		while (positon_node2)
		{
			if (positon_node2->next_node == NULL)     //����ýڵ���һ��λ��NULL ��������Ҫ�ҵ��Ǹ��ڵ�
			{
				last_node = positon_node2;
				break;
			}
			positon_node2 = positon_node2->next_node;
		}
		//����
		Node*new_last_node = new Node;
		new_last_node->value = value;
		last_node->next_node = new_last_node;
		new_last_node->next_node = NULL;
	}

	if (n > 0 && n < node_num - 1) //�����м�
	{
		//һ�����ڲ�������������ڵ�
		Node*front_node = NULL;
		Node*behiend_node = NULL;

		Node*positon_node3 = head;//��λָ��
		int index = 0;
		while (positon_node3)
		{
			if (n == index)  //���ҵ���Ӧ�ڵ�
			{
				front_node = positon_node3;
				behiend_node = positon_node3->next_node;
				break;
			}

			//�Ƶ���һ���ڵ�
			positon_node3 = positon_node3->next_node;
			index++;
		}

		//�����½ڵ�
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
	//���ж�head�ж�����
	int node_num = 0;
	Node*positon_node = head;
	while (positon_node)
	{
		node_num++; //������1
		positon_node = positon_node->next_node;//ָ���¸��ڵ�
	}

	if (0 == node_num) //��ʾ������ǿ�ͷ ֱ��return
	{
		return head;
	}


	if (0 == n)  //ɾ������ͷ
	{
		if (1 == node_num) //ֻ��һ���ڵ�
		{
			delete head;
			return NULL;
		}
		else //����һ���ڵ�
		{
			Node *new_head = head->next_node;
			delete head;
			return new_head;
		}
	}

	if (n == node_num - 1)//ɾ������β��
	{
		//ֻ��һ���ڵ�������һ��if���Ѿ��ж� ����һ���ǽڵ�������1�����

		Node*front_node = NULL;//�ҵ������ڶ����ڵ�
		Node*behiend_node = NULL;//���һ���ڵ�
		Node*positon_node2 = head; //��λָ��
		while (positon_node2)
		{
			if (positon_node2->next_node->next_node == NULL)     //����ýڵ���һ��λ����һλ��NULL ��������Ҫ�ҵ��Ǹ��ڵ�
			{
				front_node = positon_node2;
				behiend_node = positon_node2->next_node;
				break;
			}
			positon_node2 = positon_node2->next_node;
		}
		//ɾ��
		front_node->next_node = NULL;
		delete behiend_node;
		behiend_node = NULL;
	}

	if (n > 0 && n < node_num - 1) //�����м�
	{
		Node*front_node = NULL;//ɾ���ڵ���ڵ�
		Node*delete_node = NULL;//��ɾ���ڵ�
		Node*positon_node2 = head; //��λָ��

		int index = 0;
		while (positon_node2)
		{
			if (index == n - 1)     //��λ��ɾ���ڵ�ǰ���Ǹ��ڵ�
			{
				front_node = positon_node2;
				delete_node = positon_node2->next_node;
				break;
			}
			positon_node2 = positon_node2->next_node;
			index++;
		}
		//ɾ��
		front_node->next_node = delete_node->next_node;
		delete delete_node;
		delete_node = NULL;
	}
	return head;
}

bool EditNode(Node*head, int n, int value)
{
	cout << "Edit node:" << to_string(n)<<" ";
	//���ж�head�ж�����
	int node_num = 0;
	Node*positon_node = head;
	while (positon_node)
	{
		node_num++; //������1
		positon_node = positon_node->next_node;//ָ���¸��ڵ�
	}

	if (0 == node_num) //��ʾ������ǿ�ͷ ֱ��return
	{
		return false;
	}

	if (0 == n)  //�޸�����ͷ
	{
		head->value = value;
	}

	if (n == node_num - 1)//�޸�����β��
	{
		//ֻ��һ���ڵ�������һ��if���Ѿ��ж� ����һ���ǽڵ�������1�����
		Node*positon_node2 = head; //��λָ��
		while (positon_node2)
		{
			if (positon_node2->next_node == NULL)     //����ýڵ���һ��λ����һλ��NULL ��������Ҫ�ҵ��Ǹ��ڵ�
			{
				positon_node2->value = value;
				break;
			}
			positon_node2 = positon_node2->next_node;
		}
	}

	if (n > 0 && n < node_num - 1) //�����м�
	{
		int index = 0;
		Node*positon_node2 = head; //��λָ��
		while (positon_node2)
		{
			if (index == n)     //��λ��ɾ���ڵ�ǰ���Ǹ��ڵ�
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
	//���ж�head�ж�����
	int node_num = 0;
	Node*positon_node = head;
	while (positon_node)
	{
		node_num++; //������1
		positon_node = positon_node->next_node;//ָ���¸��ڵ�
	}

	if (0 == node_num) //��ʾ������ǿ�ͷ ֱ��return
	{
		return false;
	}

	if (1 == node_num) //ֻ��һ�� ���跴ת
	{
		return head;
	}

	if (node_num > 1) //��ʼ��ת
	{
		Node*left_node = NULL;     //��ڵ�
		Node*right_node = NULL;  //�ҽڵ�

		//��ʼ�ṹ
		right_node = head->next_node;
		head->next_node = NULL;
		left_node = head;

		while (right_node)
		{
			Node*next_node = right_node->next_node; //��¼��ָ����һ���ڵ�
			right_node->next_node = left_node;//�ҽڵ�ָ��ָ����ڵ�
			left_node = right_node;//��ڵ�ָ���ҽڵ�λ��
			if (next_node == NULL)
			{
				break;
			}
			right_node = next_node;//�ҽڵ�ָ���ҽڵ����һ��λ��
		}
		return right_node;
	}
}


//����ָ���˼��
/**����˼�룺
*����Ҳ���õ�����ָ�롣���һ���������л���
*Ҳ����˵��һ��ָ��ȥ����������Զ�߲���ͷ�ġ�
*��ˣ����ǿ���������ָ��ȥ������
*һ��ָ��һ����������һ��ָ��һ����һ����
*����л�������ָ��϶����ڻ���������
*ʱ�临�Ӷ�ΪO��n����
*/

bool HasLoop(Node *pHead)
{
	cout << "has loop:";

	if (pHead == NULL || pHead->next_node == NULL)
	{
		return false;
	}
	Node *pFast = pHead; //��ָ��ÿ��ǰ������ 
	Node *pSlow = pHead; //��ָ��ÿ��ǰ��һ�� 
	while (pFast != NULL && pSlow !=NULL)
	{
		//��ָ����һ��
		pFast = pFast->next_node;
		if (pFast == NULL)
		{
			return false;
		}
		//��ָ����һ��
		pSlow = pSlow->next_node;
		//��ָ������һ��
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