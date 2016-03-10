#include <stdio.h>

void showheap(int heap[]){

	int i = 0;
	for (i = 0; i < 10; i++){

		printf("%d ", heap[i]);
	}
	printf("\n");

	printf("==aa=========================================== \n");
}


void heap(int in[])
{
	//{1, 2, 10, 0, 7, 6, 3, 11, 8, 4};
	int heap[10] = { -1, -1, -1, -1, -1, -1, -1, -1, -1, -1 };
	int i = 0;
	int m, n, temp;


	// 비어 있는 곳에 
	for (i = 0; i < 10; i++){
		for (m = 0; m < 10; m++){
			if (heap[m] < 0){
				heap[m] = in[i];
				break;
			}
		}
		printf("%d 넣기  \n", in[i]);
	
		for (n = 0; n < 10; n++){
	
			printf("%d ", heap[n]);
		}
		printf("\n");


		// 루트랑 비교하여 바꾸기 
		while (1){
			// 왼쪽
			if (m % 2 != 0){
				if (heap[m / 2] > heap[m]){
					printf("왼쪽 변경전 : %d, %d, %d, %d\n", m / 2, m, heap[m], heap[m / 2]);
					temp = heap[m];
					heap[m] = heap[m / 2];
					heap[m / 2] = temp;
					printf("변경후 : %d, %d, %d, %d\n", m / 2, m, heap[m], heap[m / 2]);
	
				}
				m = m / 2;
			}
			// 오른쪽
			else
			{
				if (heap[(m / 2)-1] > heap[m]){
					printf("오른쪽 변경전 : %d, %d, %d, %d\n", (m / 2) - 1, m, heap[m], heap[(m / 2) - 1]);
					temp = heap[m];
					heap[m] = heap[(m / 2) - 1];
					heap[(m / 2) - 1] = temp;
					printf("변경후 : %d, %d, %d, %d\n", (m / 2) - 1, m, heap[m], heap[(m / 2) - 1]);

				}
				m = (m / 2) -1;

			}
		
			if (m < 1)
				break;
	}
	printf(" 정렬후  \n");
	////
	for (n = 0; n < 10; n++){

		printf("%d ", heap[n]);
	}
	printf("\n");

	printf("============================================= \n");
		
	}
}


void minheap(int in[])
{
	int heap[20] = { -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1 };
	int i = 0;
	int m,n,  temp;

	int root = 0; 


	// 비어 있는 곳에 
	for (i = 0; i < 10; i++){
		for (m = 0; m < 10; m++){
			if (heap[m] < 0){
				heap[m] = in[i];
				break;
			}
		}
		printf("m - %d", m);
		showheap(heap);

		// 루트랑 비교하여 바꾸기 
		while (1){
			// 왼쪽
			if (m % 2 != 0){
				if (heap[m / 2] > heap[m]){
					temp = heap[m];
					heap[m] = heap[m / 2];
					heap[m / 2] = temp;
				}
				m = m / 2;
			}
			// 오른쪽
			else
			{
				if (heap[(m / 2) - 1] > heap[m]){
					temp = heap[m];
					heap[m] = heap[(m / 2) - 1];
					heap[(m / 2) - 1] = temp;

				}
				m = (m / 2) - 1;

			}

			if (m < 1)
				break;
		}

	}

	showheap(heap);
	/*
	///// 정렬된거 보여주기 
	for (n = 0; n < 10; n++){
		if (heap[n] >-1)
			printf("%d ", heap[n]);
	}

	printf("============================================= \n");
	*/
	
	//////////////// min 힙

	for (m = 9; m > -1; m--){

		root = 0; 
		// 꺼내기 
		printf("팝! : %d \n", heap[root]);
	
		// 맨 끝에거 루트로 올리기 
		heap[root] = heap[m];
		
	//	printf("%d 번째 %d를 %d로 올리고 !\n", m, heap[m], root );

		heap[m] = -1;
		for (n = 0; n < 20; n++){
			if (heap[n] >-1)
				printf("%d ", heap[n]);
		}
		printf("\n");

		//printf("정렬 시작 \n");

		//// 루트랑 아래랑 비교 해서 바꾸기 
		// 반복 
		while(1){



			// 맨 아래 까지 갈때 
			// 오른쪽것이 더 작을때 
			if (heap[(root * 2) + 1] > heap[(root * 2) + 2]){

				// 음수면 없는거니까 브레이크
				if (heap[(root * 2) + 2] < 0)
					break;
				
				if (heap[root] > heap[(root * 2) + 2])
				{
					//printf("오른쪽 변경전 : %d -> %d, %d -> %d\n", root, (root * 2) + 2, heap[root], heap[(root * 2) + 2]);

					temp = heap[(root * 2) + 2];
					heap[(root * 2) + 2] = heap[root];
					heap[root] = temp;
					//printf(" 변경후 :  %d -> %d, %d -> %d\n", root, (root * 2) + 2, heap[root], heap[(root * 2) + 2]);

				}
	
				root = (root * 2) + 2;
			}
			// 왼쪽쪽이 더 작을때 
			else
			{
				// 음수면 없는거니까 브레이크 
				if ((heap[(root * 2) + 1]) < 0)
					break;


				if (heap[root] > heap[(root * 2) + 1])
				{
					//printf("왼쪽 변경전 :  %d -> %d, %d -> %d\n", root, (root * 2) + 1, heap[root], heap[(root * 2) + 1]);

					temp = heap[(root * 2) + 1];
					heap[(root * 2) + 1] = heap[root];
					heap[root] = temp;
					//printf(" 변경후 :  %d -> %d, %d -> %d\n", root, (root * 2) + 1, heap[root], heap[(root * 2) + 1]);

				}

				root = (root * 2) + 1;
			}
			
			// 보여주기 
			/*
			for (n = 0; n < 20; n++){
				if (heap[n] >-1)
					printf("%d ", heap[n]);
			}

			printf("\n");
			*/
		}
		for (n = 0; n < 20; n++){
			if (heap[n] >-1)
				printf("%d ", heap[n]);
		}

		printf("\n");

		printf("============================================= \n");

	}
	
}


int main()
{
	
	int input[10] = {1, 2, 10, 0, 7, 6, 3, 11, 8, 4};
	heap(input);
//minheap(input);


	return 0; 
}