//现有一链表的头指针 ListNode* pHead，给一定值x，编写一段代码将所有小于x的结点排在其余结点之前，
//且不能改变原来的数据顺序，返回重新排列后的链表的头指针。
#include<stdio.h>
#include<stdlib.h>
 struct ListNode 
 {
      int val;
     struct ListNode *next;
 };
 
void ListPrint(struct ListNode* head)
{
	struct ListNode* cur=head;
	while(cur)
	{
		printf("%d",cur->val);
		cur=cur->next;
	}
}
void ListDestroy(struct ListNode** tmp)
{
	struct ListNode* cur=*tmp;
	while(cur)
	{
		*tmp=(*tmp)->next;
		free(cur);
		cur=(*tmp);
	}
}
struct ListNode* partition(struct ListNode* pHead, int x)
{
	struct ListNode* cur=pHead;
	struct ListNode* small=NULL;
	struct ListNode* large=NULL;
	struct ListNode* head=NULL;
	struct ListNode* largehead=NULL;
	while(cur)
	{
	if(cur->val<x&&small==NULL)
	{
		head=small=cur;
		cur=cur->next;
		if(cur==NULL)
			break;
	}
	if(cur->val<x)
	{
		small->next=cur;
		small=cur;
		cur=cur->next;
	}
	else
	{
		if(large==NULL)
		{largehead=large=cur;
		cur=cur->next;continue;}
		large->next=cur;
		large=cur;
		cur=cur->next;
	}
	}
    if(head==NULL)
    {
        head=largehead;
    }
    if(large!=NULL)
	{large->next=NULL;}
    if(small!=NULL)
	{small->next=largehead;	}
	return head;
		
}
int main()
{
	struct ListNode* n1=(struct ListNode*)malloc(sizeof(struct ListNode));
	struct ListNode* n2=(struct ListNode*)malloc(sizeof(struct ListNode));
	struct ListNode* n3=(struct ListNode*)malloc(sizeof(struct ListNode));
	struct ListNode* n4=(struct ListNode*)malloc(sizeof(struct ListNode));
	struct ListNode* n5=(struct ListNode*)malloc(sizeof(struct ListNode));
	struct ListNode* n6=(struct ListNode*)malloc(sizeof(struct ListNode));
	struct ListNode* tmp;
	int x;
	printf("请输入数字");
	scanf("%d",&x);
	n1->val=1;
	n2->val=4;
	n3->val=3;
	n4->val=2;
	n5->val=5;
	n6->val=2;
	n1->next=n2;
	n2->next=n3;
	n3->next=n4;
	n4->next=n5;
	n5->next=n6;
	n6->next=NULL;
	tmp=partition(n1,x);
	ListPrint(tmp);
	ListDestroy(&tmp);
	return 0;
}