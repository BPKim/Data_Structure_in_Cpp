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


	// ��� �ִ� ���� 
	for (i = 0; i < 10; i++){
		for (m = 0; m < 10; m++){
			if (heap[m] < 0){
				heap[m] = in[i];
				break;
			}
		}
		printf("%d �ֱ�  \n", in[i]);
	
		for (n = 0; n < 10; n++){
	
			printf("%d ", heap[n]);
		}
		printf("\n");


		// ��Ʈ�� ���Ͽ� �ٲٱ� 
		while (1){
			// ����
			if (m % 2 != 0){
				if (heap[m / 2] > heap[m]){
					printf("���� ������ : %d, %d, %d, %d\n", m / 2, m, heap[m], heap[m / 2]);
					temp = heap[m];
					heap[m] = heap[m / 2];
					heap[m / 2] = temp;
					printf("������ : %d, %d, %d, %d\n", m / 2, m, heap[m], heap[m / 2]);
	
				}
				m = m / 2;
			}
			// ������
			else
			{
				if (heap[(m / 2)-1] > heap[m]){
					printf("������ ������ : %d, %d, %d, %d\n", (m / 2) - 1, m, heap[m], heap[(m / 2) - 1]);
					temp = heap[m];
					heap[m] = heap[(m / 2) - 1];
					heap[(m / 2) - 1] = temp;
					printf("������ : %d, %d, %d, %d\n", (m / 2) - 1, m, heap[m], heap[(m / 2) - 1]);

				}
				m = (m / 2) -1;

			}
		
			if (m < 1)
				break;
	}
	printf(" ������  \n");
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


	// ��� �ִ� ���� 
	for (i = 0; i < 10; i++){
		for (m = 0; m < 10; m++){
			if (heap[m] < 0){
				heap[m] = in[i];
				break;
			}
		}
		printf("m - %d", m);
		showheap(heap);

		// ��Ʈ�� ���Ͽ� �ٲٱ� 
		while (1){
			// ����
			if (m % 2 != 0){
				if (heap[m / 2] > heap[m]){
					temp = heap[m];
					heap[m] = heap[m / 2];
					heap[m / 2] = temp;
				}
				m = m / 2;
			}
			// ������
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
	///// ���ĵȰ� �����ֱ� 
	for (n = 0; n < 10; n++){
		if (heap[n] >-1)
			printf("%d ", heap[n]);
	}

	printf("============================================= \n");
	*/
	
	//////////////// min ��

	for (m = 9; m > -1; m--){

		root = 0; 
		// ������ 
		printf("��! : %d \n", heap[root]);
	
		// �� ������ ��Ʈ�� �ø��� 
		heap[root] = heap[m];
		
	//	printf("%d ��° %d�� %d�� �ø��� !\n", m, heap[m], root );

		heap[m] = -1;
		for (n = 0; n < 20; n++){
			if (heap[n] >-1)
				printf("%d ", heap[n]);
		}
		printf("\n");

		//printf("���� ���� \n");

		//// ��Ʈ�� �Ʒ��� �� �ؼ� �ٲٱ� 
		// �ݺ� 
		while(1){



			// �� �Ʒ� ���� ���� 
			// �����ʰ��� �� ������ 
			if (heap[(root * 2) + 1] > heap[(root * 2) + 2]){

				// ������ ���°Ŵϱ� �극��ũ
				if (heap[(root * 2) + 2] < 0)
					break;
				
				if (heap[root] > heap[(root * 2) + 2])
				{
					//printf("������ ������ : %d -> %d, %d -> %d\n", root, (root * 2) + 2, heap[root], heap[(root * 2) + 2]);

					temp = heap[(root * 2) + 2];
					heap[(root * 2) + 2] = heap[root];
					heap[root] = temp;
					//printf(" ������ :  %d -> %d, %d -> %d\n", root, (root * 2) + 2, heap[root], heap[(root * 2) + 2]);

				}
	
				root = (root * 2) + 2;
			}
			// �������� �� ������ 
			else
			{
				// ������ ���°Ŵϱ� �극��ũ 
				if ((heap[(root * 2) + 1]) < 0)
					break;


				if (heap[root] > heap[(root * 2) + 1])
				{
					//printf("���� ������ :  %d -> %d, %d -> %d\n", root, (root * 2) + 1, heap[root], heap[(root * 2) + 1]);

					temp = heap[(root * 2) + 1];
					heap[(root * 2) + 1] = heap[root];
					heap[root] = temp;
					//printf(" ������ :  %d -> %d, %d -> %d\n", root, (root * 2) + 1, heap[root], heap[(root * 2) + 1]);

				}

				root = (root * 2) + 1;
			}
			
			// �����ֱ� 
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