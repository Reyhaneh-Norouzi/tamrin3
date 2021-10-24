#include <conio.h>
#include <iostream>
#include <time.h>
using namespace std;

int main() {
	srand(time(0));
	int arr[4], i, j, t;
	for (i = 0; i < 4; i++)
		cin >> arr[i];

	for (i = 0; i < 4; i++)
		cout << arr[i] << "\t";
	cout << endl << endl;

	for (i = 0; i < 4; i++) {

		for (j = i + 1; j < 4; j++) {
			if (arr[i] > arr[j])
			{
				t = arr[i];
				arr[i] = arr[j];
				arr[j] = t;

			}
		}
	}

	cout << " array moratab " << endl;
	for (i = 0; i < 4; i++)
		cout << arr[i] << "\t";
	cout << endl;

	_getch();
}