#include <iostream>
#include <bits/stdc++.h>
using namespace std;

#define N 100000
int a[N];
int n;

int k = 0;

void merge(int start,int end) {

	int mid = (start + end)/2;

	int i = start;
	int j = (mid + 1);
	int k = start;

	int temp[100000];

	while(i<=mid && j<=end) {

		if(a[i]<=a[j]) {
			temp[k] = a[i];
			k++;
                        i++;
		}

		else {
			temp[k++] = a[j++];
		}
	}

        while (i<=mid) {
                temp[k++] = a[i++];
        }

        while (j<=end) {
                temp[k++] = a[j++];
        }

	for(int i=start;i<=end;i++) {
		a[i] = temp[i];
	}
}

void merge_sort_modified(int start, int end) {

        int mid = (start + end)/2;

	if(start >= end) {
		return;
	}

	merge_sort_modified(start,mid);
	merge_sort_modified(mid+1,end);

	if(k >= (n/2) - 2) {
		return;
	}

	k++;

	merge(start,end);
}

void merge_sort(int start, int end) {

        int mid = (start + end)/2;

	if(start >= end) {
		return;
	}

	merge_sort(start,mid);
	merge_sort(mid+1,end);

	merge(start,end);
}

void Array_input() {

        cout << "Enter the elements of the array :" << endl;

        for(int i=0;i<n;i++) {
                cin >> a[i];
        }

}

void display() {

        cout << "The array is :\n" << endl;

        for(int i=0;i<n;i++) {
                cout << a[i] << " ";
        }
        cout << endl;
}



int main() {

        int ch;
        while (1) {

                cout << "\nSelect any option :\n";
                cout << "\n0. Quit\n1. Create an array\n2. Display the array\n3. Sort in ascending order\n4. Sort with modified merge procedure\n";
                cout << "\nEnter your choice : ";
                cin >> ch;

                switch (ch) {
                        case 0:
                                exit(1);
                                break;
                        case 1:
                                cout << "Enter the size of the array : ";
                                cin >> n;
                                Array_input();
                                break;
                        case 2:
                                display();
                                break;
                        case 3:
                                merge_sort(0,n-1);
                                break;
                        case 4:
                                merge_sort_modified(0,n-1);
                                break;

                        default:
                                cout << "Invalid entry!!\n";
                }
        }
}
