/*
�׷���
�����������ũ�� �ٸ�����
- �������� ����� �����Ǽ��� ��� ¦���̾��, ������ �� ������ ������ ó�� ����ߴ� �������� ���ƿ� �� �ִ�.

�׷����� ����
- ������ �׷���(undirected graph)
������迡 �־ ���⼺�� ���� �׷���
- ���� �׷���(directedgraph) ���̱׷���(digraph)
������ ���������� ���Ե� �׷���
- �����׷���
������ �������� �ٸ� ��� ������ ������ �׷���
���� �׷����� ��쿡�� ������ �׷����� ������ �ι谡 �ȴ�.

����ġ �׷���(Weight Graph)�� �κ� �׷���(Sub Graph)
- ����ġ(Weight Graph)
������ ��ġ������ �ξ �����ϴ� �׷���
�̵��ϴµ� �ɸ��� �ð��̳� �� ���������� �Ÿ�
- �κб׷���(Sub Graph)

*/
#include <stdio.h>
#include <stdlib.h> // malloc

enum { A, B, C, D, E, F };

#define MAX_SIZE 40
#define MIN_SIZE 0

struct node{
	int data;
	struct node *next;
};
typedef struct node Node;

struct list{

	Node * head;
	Node * cur;
	Node * tail;

	int number;
};
typedef struct list List;

struct graph{
	int numV; // ������ �� 
	int numE; // ������ ��

	List * adjList;
};
typedef struct graph Graph;

void ListInit(List *list);
void Insert(List * list, int data);
void PrintList(List *list);

void GraphInit(Graph * gp);
void AddEdge(Graph *gp, int from, int to);
void ShowGraph(Graph *gp);

void GraphInit(Graph * gp, int num){

	int i;

	gp->numV = num;
	gp->numE = 0;

	gp->adjList = (List*)malloc(sizeof(List)*num); // ������ ������ŭ ����Ʈ ���� 

	for (i = 0; i < num; i++){
		ListInit(&(gp->adjList[i]));

	}
}
void AddEdge(Graph *gp, int from, int to){

	Insert(&gp->adjList[from], to);

	gp->numE++;

}
void ShowGraph(Graph *gp)
{
	int i;
	Node *temp;
	for (i = 0; i < gp->numV; i++){
		printf("���� %c�� ���� \n", i + 65);

		PrintList(&gp->adjList[i]);

	}
}
void ListInit(List *list){

	list->head = (Node*)malloc(sizeof(Node));
	list->cur = (Node*)malloc(sizeof(Node));
	list->tail = (Node*)malloc(sizeof(Node));


	list->head->next = NULL;
	list->cur->next = NULL;
	list->tail->next = NULL;

	list->head->data = 0;
	list->cur->data = 0;
	list->tail->data = 0;

	list->number = 0;

}

void Insert(List * list, int data){ // �������Լ�����

	Node *temp = (Node*)malloc(sizeof(Node));

	temp->data = data;
	temp->next = NULL;

	// ��ó���ƴҶ�
	if (list->head->next != NULL){

		list->cur->next = list->head->next;

		while (list->cur->next->next != NULL){
			list->cur->next = list->cur->next->next;
		}

		list->cur->next->next = temp;
		list->tail->next = temp;
	}
	// ��ó���϶� 
	else{

		list->head->next = temp;
		list->cur->next = temp;
		list->tail->next = temp;
	}

	list->number++;

}

void PrintList(List *list){

	int i = 0;

	list->head = list->head->next;// �Ǿ��� ����ϱ� �н� 

	while (i < list->number){

		printf(" %c ", list->head->data + 65);
		list->head = list->head->next;

		i++;
	}

	printf("\n");
}

int main(){

	Graph gp;
	GraphInit(&gp, 6);

	AddEdge(&gp, A, B);
	AddEdge(&gp, A, C);
	AddEdge(&gp, A, D);
	AddEdge(&gp, B, C);

	ShowGraph(&gp);

	List list;
	
	return 0;

}