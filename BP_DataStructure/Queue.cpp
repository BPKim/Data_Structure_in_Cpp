#include <stdio.h>
#define MAX_SIZE 10
#define MIN_SIZE 0

typedef struct QUEUE
{
	int queue[MAX_SIZE];
	int front=0;
	int rear = 0;

	void init(){
		
		front = 0;
		rear = 0;
	}

	int push(int in){
		if (rear > MAX_SIZE - 1)
		{
			printf("FULL QUEUE \n");
			return -1;
		}

		queue[rear] = in;
		rear++;

		return 0;
	}
	void pop(){
		int result;

		if (front == rear)
		{
			printf("EMPTY QUEUE \n");
			return;
		}

		result = queue[front];
		queue[front] = 0;
		front++;

		printf("%d \n", result);
	}

}q;

int main(){

	int a = 0;
	/*
	init();

	for (a = 0; a < MAX_SIZE; a++)
		push(a+1);

	for (a = 0; a < MAX_SIZE ; a++)
		pop();
		*/
	QUEUE q; 
	for (a = 0; a < MAX_SIZE; a++)
		q.push(a + 1);

	for (a = 0; a < MAX_SIZE; a++)
		q.pop();
	return 0;

}