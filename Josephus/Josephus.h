#ifndef __JOSEPHUS_H
#define __JOSEPHUS_H
typedef struct node {
	int num;
	struct node *next;
}Node,*PNode;
void JOSEPHUS(int n,int k,int m);

#endif // !__JOSEPHUS_H
