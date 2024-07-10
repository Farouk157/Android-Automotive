#include <stdio.h>

#define MAX_SIZE  10

void sorting(int *ptr);
int binary_search(int key, int *ptr);

int main(void)
{
	int arr[MAX_SIZE] = {15, 4, 2, 100, 70, 13, 1, 6, 3, 10};
	int key;


	printf("Please enter the key: ");
	scanf("%i", &key);

	int ret = binary_search(key, arr);

	if(ret == -1)
	{
		printf("sorry the element you want doesn't exist!! \n");
	}
	else
	{
		printf("your element is in index: [%i]\n", ret);	
	}
	
	return 0;
}

void sorting (int *ptr)
{
	for(int i = 0; i < MAX_SIZE-1; i++)
	{
		for(int j = 0; j < MAX_SIZE-i-1; j++)
		{
			if(ptr[j] > ptr[j+1])
			{
				int temp = ptr[j+1];
				ptr[j+1] = ptr[j];
				ptr[j] = temp;
			}
			else
			{
				//nothing
			}
		}
	}	
}

int binary_search(int key, int *ptr)
{
	sorting(ptr);
	int left = 0; 
	int right = MAX_SIZE - 1;

	while(left <= right)
	{
		int mid = left + (right - left) / 2;

		if(key == ptr[mid])
		{
			return mid;
		}
		
		if(key > ptr[mid])
		{
			left = mid + 1;
		}
		else
		{
			right = mid - 1;
		}
	}

	return -1;
}
