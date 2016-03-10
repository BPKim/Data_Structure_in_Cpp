#include <stdio.h>
#include <stdlib.h> // malloc

struct node{
	char data;
	struct node *next;
};
typedef struct node Node;

struct list{

};
typedef struct list List;

void insert(Node *head, Node *tail, char data);
void printList(Node *p);

int a = 1;
int b = 1;


void insert(Node *head, Node *tail, char data){ // 노드생성함수시작

	Node *temp = (Node*)malloc(sizeof(Node));

	temp->data = data;
	temp->next = NULL;

	if (head->next == NULL){

	}
	else{

		while (head->next != NULL){
			head = head->next;
		}
	}
	head->next = temp;
	tail->next = head->next;
	//printf("%d 번째 문자 %c \n", a, head->next->data);
	//a++;

}

void printList(Node *head){

	head = head->next;// 맨앞은 헤더니까 패스 
	while (head->next != NULL) // 맨뒤에 올때 까지 계속 반복
	{
		printf("%d 번째 값 - %c \n", b, head->data);
		head = head->next;
		b++;
	}

	printf("%d 번째 값 - %c \n", b, head->data);

}

int main(){

	int n = 0;
	Node * head = (Node*)malloc(sizeof(Node));
	Node * tail = (Node*)malloc(sizeof(Node));
	char name[10] = { 'c', 'd', 'w', 'j', 'h', 'u', 'p', 'l', 'e', 'b' };


	head->next = NULL;
	tail->next = NULL;

	for (n = 0; n < 10; n++){

		insert(head, tail, name[n]);
	}

	printf("===========\n");
	printList(head);
	printf("===========\n");
	printf("tail 이 가리키는 값 - %c", tail->next->data);


	return 0;
}