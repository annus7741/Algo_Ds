//deletion of a middile element of single linked list(not necessary the exact middle)
//you have given acces to that node only



#include<bits/stdc++.h>

using namespace std;

struct linkNode{
	int data;
	struct linkNode* next;
};

struct linkNode* head;


struct linkNode *createList()
{
	struct linkNode* temp;
	struct linkNode* prev=head;
	temp = (struct linkNode*)malloc(sizeof(struct linkNode));
	int x;
	printf("\nEnter element to be inserted : ");
	scanf("%d",&x);
	printf("\n");
	temp->data = x;
	temp->next = NULL;
	if(head==NULL)  // for 1st node 
	head = temp;
	else {
		while(prev->next!=NULL){   // for inserting node at the end of list
	    prev=prev->next;
		}
	    prev->next=temp;
	}
	
	
	return temp;
}

//code for deleteing the middle node
bool delMidNode(linkNode *n)  // address of only element which is to be deleted 
{
	if(n==NULL || n->next==NULL)
	{
		return false;   // Failure case
	}
	struct linkNode* next=n->next;
	n->data=next->data;
	n->next=next->next;
	delete(next);
	return true;
}


void Print(){
	struct linkNode* temp = head;
	while(temp!=NULL){
		printf("%d  ",temp->data);
		temp = temp->next;
	}
	printf("\n");
}


// driver code for programm
int main(){
	head = NULL;
	printf("Enter number of nodes : ");
	int n,mid;
	scanf("%d",&n);
	printf("\n");
	int i;
	struct linkNode *nodeAdd[n];
	for(i=0;i<n;i++){
	    nodeAdd[i]=createList();
	}	
	printf("\n Enter the position of element to be deleted from middle : ");  // the node which u want to delete
	scanf("%d",&mid);
	printf("list before deletion :");
	Print();
	delMidNode(nodeAdd[mid-1]);
	printf("list after deletion :");
	Print();
}