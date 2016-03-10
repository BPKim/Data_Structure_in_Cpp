#include <stdio.h>
#include <stdlib.h> // malloc

struct node{
	char data;
	struct node *next;
};

typedef struct node NODE;

void insert(NODE *head, NODE* cur, NODE *tail, char data);
void printList(NODE *p, NODE* cur, NODE *tail);

int a = 0;
int b = 1;

// 리스트에 노드 붙이기 
void insert(NODE *head, NODE* cur, NODE *tail, char data){ 

	NODE *temp = (NODE*)malloc(sizeof(NODE));

	temp->data = data;
	temp->next = NULL;

	// 맨처음 이 아닐때 
	if (head->next != NULL){
		cur->next = head->next;
//		printf("while 시작전 커서 %c\n", cur->next->data);
		while (cur->next != tail->next){
			cur = cur->next;
//			printf("맨처음 아닐때 현재 커서 %c\n", cur->next->data);
		}
		cur->next->next= temp;
		//cur->next = cur->next->next;
		temp->next = head->next;
		tail->next = temp;
//		printf("지금 지금 %c\n", cur->next->next->data);

	}
	// 맨처음 
	else{
		head->next = temp;
		cur->next = temp;
		tail->next = temp;

//		printf("맨처음 %c \n", head->next->data);
//		printf("지금 지금 %c\n", cur->next->data);

	}
//	printf("%d\n", a);

	
	a++;

}

void printList(NODE *head, NODE * cur, NODE * tail){

	cur->next = head->next;

	while (cur->next != tail->next) // 맨뒤에 올때 까지 계속 반복
	{
		printf("%d 번째 값 - %c \n", b, cur->next->data);
		cur = cur->next;
		b++;
	}

	printf("%d 번째 값 - %c \n", b, cur->next->next->data); 
	printf("%d 번째 값 - %c \n", b, cur->next->next->next->data);

}

int main(){

	int n = 0;
	int l = 0; 
	int m ;

	NODE * cur = (NODE*)malloc(sizeof(NODE));
	NODE * head = (NODE*)malloc(sizeof(NODE));
	NODE * tail = (NODE*)malloc(sizeof(NODE));
	char name[10] = { 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j' };

	cur -> next = NULL;
	head -> next = NULL;
	tail -> next = NULL;

	for (n = 0; n < 25; n++){
		m = n % 10;
		insert(head, cur, tail, name[m]);
		//printf("n : %d, m : %d \n", n, m);
	}

	cur->next = head->next;


	for (l = 0; l < 24; l++){
		printf("%d 번째 값 - %c \n", l, cur->next->data);
		cur->next = cur->next->next;
	}

	printList(head, cur, tail);

	return 0;
}