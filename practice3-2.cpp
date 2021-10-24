#include <stdlib.h>  

#include <time.h>  

#include <stdio.h>

int* sample(int n);

int main() {

	int n = 9;

	int* arr1;

	arr1 = sample(n);

	for (int i = 0; i < 9; i++) printf("%d", arr1[i]);

}

int* sample(int n) {

	int* arr = (int*)calloc(n, sizeof(int));

	for (int i = 0; i < n; i++) arr[i] = i;

	srand(time(NULL));

	int tmp, dex;

	while (n > 0) {

		dex = rand() % (n--);

		tmp = arr[dex];

		arr[dex] = arr[n];

		arr[n] = tmp;

	}

	return arr;

}