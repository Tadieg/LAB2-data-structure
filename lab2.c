#include <stdio.h>
#include <stdlib.h>
struct node {
	int data;
	struct node *next;
}*head;
void createList(int n);
void traverseList();
void insertNodeAtBeginning(int data);
void insertNodeAtMiddle(int data,int position);
void insertNodeAtEnd(int data);
void deleteFirstNode();
void deleteLastNode();
int main(){
	int n,data,ch,position;
	printf("enter the number of the nodes you want to create ");
	scanf("%d",&n);
	createList(n);
	printf("data int the list\n ");
	traverseList();
	label:
	printf(" enter 1 for insert at the begginning \n ");
	printf("enter 2 for insert at the begginning \n ");
	printf("enter 3 for insert at the middle \n ");
	printf("enter 4 for delete the first node \n ");
	printf("enter 5 for delete the last node \n ");
	printf("enter 6 for delete the last node \n ");
	scanf("%d",&ch);
	switch(ch){
		case 1:
			printf("enter the data to insert at the beginning of the list ");
	        scanf("%d",&data);
	        insertNodeAtBeginning(data);
	        traverseList();
	        break;
	    case 2:
	    	printf("enter the data to insert at the at end of the list ");
	        scanf("%d",&data);
	        insertNodeAtEnd(data);
	        traverseList();
	        break;
	    case 3:
	     printf("nEnter data to insert at middle of the list: ");
         scanf("%d", &data);
         printf("Enter the position to insert new node: " );
         scanf("%d", &position);
         insertNodeAtMiddle(data, position);
         traverseList();
	        break;
	    case 4:
              deleteFirstNode();
              traverseList();
	        break;
	    case 5:
              deleteLastNode();
              traverseList();
	        break;
	}
  goto label;
	return 0;
}
void createList(int n){
	struct node *newnode,*temp;
	int data,i;
	head=(struct node *)malloc(sizeof(struct node));
	if(head==NULL){
		printf("you have no engough memory ");
		exit(0);
	}
	printf("enter the data of node 1:");
	scanf("%d",&data);
	head->data=data;
	head->next=NULL;
	temp=head;
	for(i=2;i<=n;i++){
	newnode=(struct node*)malloc(sizeof(struct node));
	if(newnode==NULL){
		printf("you have not enougn memory to enter the next node ");
		exit(0);
	}
		printf("enter the data of the node %d: ",i);
		scanf("%d",&data);
		newnode->data=data;
		newnode->next=NULL;
		temp->next=newnode;
		temp=temp->next;
}
  
}
void traverseList(){
	struct node *temp;
	if(head==NULL){
		printf("list is empty ");
	}
	temp=head;
	while(temp!=NULL){
		printf("%d,",temp->data);
		temp=temp->next;
		
	}
	printf("\n");
	
}
void insertNodeAtBeginning(int data)
{
struct node *newnode;
newnode=(struct node *)malloc(sizeof(struct node));
if(newnode==NULL){
	printf("you have no memory to enter ");
}else{
newnode->data=data;
newnode->next=head;	
head=newnode;
printf("Entered successfully ");
}
}
void insertNodeAtEnd(int data)
{
	//printf("we are in the lab");
	struct node *newnode,*temp;
	newnode=(struct node*)malloc(sizeof(struct node));
	if(newnode==NULL){
		printf("unable to allocate memory");
	}else{
		newnode->data=data;
		newnode->next=NULL;
		temp=head;
		while(temp->next!=NULL){
			temp=temp->next;
			}
		temp->next=newnode;
		printf("Data inserted at the end succussfully ");
	}
}
void insertNodeAtMiddle(int data, int position)
{
    int i;
    struct node *newNode, *temp;
    newNode = (struct node*)malloc(sizeof(struct node));
    if(newNode == NULL)
    {
        printf("Unable to allocate memory.");
    }
    else
    {
        newNode->data = data; 
        newNode->next = NULL;
        temp = head;
        for(i=2; i<=position-1; i++)
        {
            temp = temp->next;
            if(temp == NULL)
                break;
        }
        if(temp != NULL)
        {
            newNode->next = temp->next; 
            temp->next = newNode;
            printf("DATA INSERTED SUCCESSFULLY\n");
        }
        else
        {
            printf("UNABLE TO INSERT DATA AT THE GIVEN POSITION\n");
        }
    }
}
void deleteFirstNode()
{
struct node *delete;
if(head==NULL){
	printf("Nothing to delete");
}else{
	delete=head;
	head=head->next;
	printf("data deleted successfully");
	free(delete);
}
}
void deleteLastNode()
{
	
}
