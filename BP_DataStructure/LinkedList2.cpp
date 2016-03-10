#include <stdio.h>
#include <stdlib.h> // malloc

struct node{
	char data;
	struct node *next;
};
typedef struct node Node;

struct list{

	Node * head ;
	Node * cur;
	Node * tail;

	int number;
};
typedef struct list List;

void ListInit(List *list);
void Insert(List * list, char data);
void PrintList(List *list);

int a = 1;
int b = 1;

void ListInit(List *list){
	
	list->head = (Node*)malloc(sizeof(Node));
	list->cur = (Node*)malloc(sizeof(Node));
	list->tail = (Node*)malloc(sizeof(Node));


	list->head->next = NULL;
	list->cur->next = NULL;
	list->tail->next = NULL;

	list->number = 0;

}
//void Insert(Node *head, Node *tail, char data){ // 노드생성함수시작
void Insert(List * list, char data){ // 노드생성함수시작

	Node *temp = (Node*)malloc(sizeof(Node));

	temp->data = data;
	temp->next = NULL;

	//printf("===================================\n");
	// 맨처음이 아닐때 
	if (list->head->next != NULL){

		list->cur->next = list->head->next;

		//printf("while 시작전 커서 %c\n", list->cur->next->data);

		while (list->cur->next->next != NULL){
			
			list->cur->next = list->cur->next->next;
		//	printf("맨처음 아닐때 현재 커서 %c\n", list->cur->next->data);

		}

		list->cur->next->next = temp;
		list->tail->next = temp;
		//printf("지금 지금 %c\n", list->cur->next->next->data);
	}
	// 맨처음일때 
	else{

		list->head->next = temp;
		list->cur->next = temp;
		list->tail->next = temp;
		//printf("맨처음 %c \n", list->head->next->data);
		//printf("지금 지금 %c\n", list->cur->next->data);
	}
	//printf("%d 번째 문자 %c \n", a, head->next->data);
	//a++;

}

void PrintList(List *list){

	int i = 0;

	list->head = list->head->next;// 맨앞은 헤더니까 패스 

	/*
	while (list->head->next != NULL) // 맨뒤에 올때 까지 계속 반복
	{
	printf("%d 번째 값 - %c \n", b, list->head->data);
	list->head = list->head->next;
	b++;
	}

	printf("%d 번째 값 - %c \n", b, list->head->data);
	*/

	while (i < list->number){

		printf("%d 번째 값 - %c \n", i, list->head->data);
		list->head = list->head->next;

		i++;
	}
}

int main(){

	int n = 0;
	List list;
	char name[10] = { 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j' };


	ListInit(&list);

	for (n = 0; n < 10; n++){

		Insert(&list, name[n]);
	}

	PrintList(&list);


	return 0;
}