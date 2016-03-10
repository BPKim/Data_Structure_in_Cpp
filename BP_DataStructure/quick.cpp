#include<stdio.h>

//int quick(int Array[] ,int inArray[], int arraySize)
int *quick(int * inArray, int l, int r, int arraySize)
{

	int i=0;
	int temp;
	int left = l;
	int right = r;
	//int arraySize = sizeof(inArray) / 4;
	int pivot = inArray[arraySize - 1];


	printf("정렬전 \n ");
	for (i = 0; i < arraySize; i++){
		printf("%d  ", inArray[i]);
	}

	printf("\n==============\n");

	while (true)
	{
		if (inArray[left]<pivot)
		{
			left++;
		}
		if (inArray[right] > pivot)
		{
			right--;
		}

		if ((inArray[left] > pivot) && (inArray[right] < pivot))
		{
			temp = inArray[left];
			inArray[left] = inArray[right];
			inArray[right] = temp;
		}

		if (left == right){

			inArray[arraySize - 1] = inArray[left];
			inArray[left] = pivot;


			break;
		}
		if (left > right){

			inArray[arraySize - 1] = inArray[right];
			inArray[right] = pivot;

			break;
		}
	}
	/////////////////////////////////////////////////
	quick(inArray, , ,  arraySize - left -1);
	quick(&inArray[right + 1], arraySize - right -1);

	if (arraySize - 1 < 2)
		return 0;

	//quick(Array, inArray, arraySize - 1);
	//quick(inArray, arraySize-1 );

	

	
	return 0;
}

void ShowArray(int *Array){
	
	int i; 
	int arraySize = sizeof(Array) / 4;

	printf("Show Array =================");
	for (i = 0; i < arraySize; i++){
		printf("%d  ", Array[i]);
	}

}
int main()
{
	int i; 
	int temp;
	int left;
	int right;
	int array[7] = {5, 3, 7, 6, 2, 1, 4};

	quick(array, 7);
	/*
	int arraySize = sizeof(array)/4;
	int pivot = array[arraySize-1];

	printf("정렬전 \n ");
	for (i = 0; i < arraySize; i++){
		printf("%d  ", array[i]);
	}

	printf("\n");

	for (i = 0; i < arraySize/2; i++)
	{
		left = array[i];
		right = array[arraySize - 2 - i];
		if ((left > pivot) && (right < pivot))
		{
			temp = array[i];
			array[i] = array[arraySize -2 -i ];
			array[arraySize - 2 - i] = temp;
		}

		
	}*/
	printf("정렬후 \n ");
	for (i = 0; i < 7; i++){
		printf("%d  ", array[i]);
	}

	return 0; 
}