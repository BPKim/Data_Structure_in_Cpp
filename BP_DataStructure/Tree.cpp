#include <stdio.h>

#include <stdio.h>
#define MAX_SIZE 40
#define MIN_SIZE 0

typedef struct QUEUE
{
	int queue[MAX_SIZE];
	int front = 0;
	int rear = 0;

	void init(){

		front = 0;
		rear = 0;
	}

	int push(int in){
		if (rear > MAX_SIZE - 1)
		{
			//printf("FULL QUEUE \n");
			return -1;
		}

		queue[rear] = in;
		rear++;

		return 0;
	}
	int pop(){
		int result;

		if (front == rear)
		{
			printf("EMPTY QUEUE \n");
			return -10;
		}

		result = queue[front];
		queue[front] = 0;
		front++;

		//printf("%d \n", result);

		return result;
	}

}q;


typedef struct Stack
{

	int stack[MAX_SIZE];
	int top;

	Stack(){

		top = -1;
	}

	int push(int in){
		if (top > MAX_SIZE - 1)
			return -1;
		
		stack[++top] = in;
		//top++;
		//printf("push top %d \n", top);
		return 0;
	}
	int pop(){
		int result;
		
		if (top < MIN_SIZE )
		{
			//printf("EMPTY STACK \n");
			return -10;
		}

		result = stack[top--];
		//printf("pop result %d \n",result);
		//printf("pop top %d \n", top);

		//printf("%d \n", result);
		//stack[top] = 0;
		//top--;

		//printf("%d \n", result);
		return result;
	}

};

void BFS(int Tarray[]){
	
	QUEUE q;
	int n = 0;
	int out;
	int temp;

	// push
	q.push(Tarray[0]);

	while (true){
		// pop
		out = q.pop();
	
		// 큐 인덱스 위치 확인 큐 비면 종료 
		if (out < -9){
			return;
		}

		printf("%d ", out);

		// 자식확인 	// 있으면 push 
		if ((temp = Tarray[((out * 2) + 1)]) > 0){
			q.push(temp);
		}
		if ((temp = Tarray[((out * 2) + 2)]) > 0){
			q.push(temp);
		}
		n++;
	}
}


void DFS(int Tarray[]){

	Stack s;
	int n = 0;
	int out;
	int temp;

	// push
	s.push(Tarray[0]);

	while (true){
		// pop
		out = s.pop();
		// 스택 인덱스 위치 확인 비면 종료 
		if (out < -9){
			return;
		}

		printf("%d ", out);

		// 자식확인 	// 있으면 push 
		if ((temp = Tarray[((out * 2) + 1)]) > 0){
			s.push(temp);
		}
		if ((temp = Tarray[((out * 2) + 2)]) > 0){
			s.push(temp);
		}
		n++;
	}
	
}
int main(){

	int tree[34] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1};

	//BFS(tree);

	DFS(tree);

	return 0;

}