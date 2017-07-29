#include <stdio.h>
#include <stdlib.h>
#include "Josephus.h"
/************************************************************************
Լɪ�����⣬��֪n���ˣ��ӱ��Ϊk���˿�ʼ����������m���Ǹ��˳��У�������һ���ִ�1��ʼ������ 
����m���Ǹ����ֳ��У������ظ���ֱ�����е��˳��С�
(1)����һ������n����㡢��ͷ����ѭ������
(2)ȷ����һ�������˵�λ��
(3)���ϵش�������ɾ����㣬ֱ������Ϊ�ա�
************************************************************************/
void JOSEPHUS(int n, int k, int m)
{
	//����û��ͷ����ѭ������
	//int cnt = 0;
	PNode curr = NULL;
	PNode pHead = (PNode)malloc(sizeof(Node));
	if (pHead == NULL){
		printf("�ڴ����ʧ�ܣ�\n");
		exit(EXIT_FAILURE);
	}
	
	pHead->num = 1;
	pHead->next = pHead;
	curr = pHead;

	for (int i = 2;i <= n;++i) {
		PNode pNew = (PNode)malloc(sizeof(Node));
		pNew->num = i;
		curr->next = pNew;
		curr = pNew;
		pNew->next = pHead;
	}

	//�ѵ�ǰָ���ƶ�����һ����������
	curr = pHead;
	while (curr->num != k)
		curr = curr->next;
	while (curr->next != curr){
		for (int i = 1;i < m;++i) {
			curr = pHead;
			pHead = pHead->next;
		}
		printf("%d ",pHead->num);
		//cnt++;
		//if (cnt == 20) {
		//	printf("\n");
		//	cnt = 0;
		//}
		curr->next = pHead->next;
		free(pHead);
		pHead = curr->next;
	}
	printf("%d \n",pHead->num);
	free(pHead);
}