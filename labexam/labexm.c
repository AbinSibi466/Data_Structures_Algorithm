#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node{
	char name[25];
	int mark;
	int rollno;
	struct node *next;
};

struct node *head = NULL;

void printNodes(){
   if (head == NULL) {
       printf("The list is empty.\n");
       return;
   }

   struct node *ptr = head;
   do {
       printf("%s,%d\n",ptr->name,ptr->mark);
       ptr = ptr->next;
   } while (ptr != head);
}

int findMaxMark(){
	struct node *ptr = head;
	int maxMark = ptr->mark;
	do {
		if(ptr->mark > maxMark){
			maxMark = ptr->mark;
		}
		ptr = ptr->next;
	} while (ptr != head);
	return maxMark;
}

struct node *insertinto(const char name[25],int mark,int rollno) {
	struct node *link = (struct node*) malloc(sizeof(struct node));
	if (link == NULL) {
		printf("Memory allocation failed\n");
	}

	strncpy(link->name,name,sizeof(link->name)-1);
	link->name[sizeof(link->name)-1] ='\0';
	link->mark = mark;
	link->rollno = rollno;
	if (head == NULL) {
		head = link;
		return head;
	}

	head->next = link->next; 
	link->next = head; 
}

void insertStud(){
	char name[25];
	int mark;
	int rollno;
	printf("Enter the name:");
	scanf("%s",name);
	printf("Enter the mark:");
	scanf("%d",&mark);
	if(mark<0||mark>100){
		printf("Invalid");
		return;
	}
	printf("Enter the rollno:");
	scanf("%d",&rollno);
	insertinto(name,mark,rollno);
}

int main(){
	int c;
	while(1){
		printf("Enter the choice:\n");
		printf("1.insertStudent\n");
		printf("2.print All\n");
		printf("3.print Max Mark\n");
		printf("4.Exit\n");
		scanf("%d",&c);
		switch(c){
			case 1:	insertStud();
			        break;
			case 2: printNodes();
					break;
			case 3: printf("Max Mark: %d\n", findMaxMark());
					break;
			case 4: return 0;
			default:printf("Invalid");
		}
	}
}
