#include <stdio.h>
#include <stdlib.h>
#include "Josephus.h"
/************************************************************************
约瑟夫问题，已知n个人，从编号为k的人开始报数，数到m的那个人出列；他的下一个又从1开始报数， 
数到m的那个人又出列，依此重复，直到所有的人出列。
(1)建立一个具有n个结点、无头结点的循环链表。
(2)确定第一个报数人的位置
(3)不断地从链表中删除结点，直到链表为空。
************************************************************************/
void JOSEPHUS(int n, int k, int m)
{
	//建立没有头结点的循环链表
	//int cnt = 0;
	PNode curr = NULL;
	PNode pHead = (PNode)malloc(sizeof(Node));
	if (pHead == NULL){
		printf("内存分配失败！\n");
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

	//把当前指针移动到第一个报数的人
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