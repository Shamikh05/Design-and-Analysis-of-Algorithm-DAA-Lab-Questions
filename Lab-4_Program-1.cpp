#include <iostream>
#include <bits/stdc++.h>
using namespace std;

long long int step = 0;

void merge(int *arr,int start,int end) {

	int mid = (start + end)/2;

	int i = start;
	int j = (mid + 1);
	int k = start;

	int temp[100000];

	while(i<=mid && j<=end) {

                step++;

		if(arr[i]<=arr[j]) {
			temp[k] = arr[i];
			k++;
                        i++;
		}

		else {
			temp[k++] = arr[j++];
		}
	}

        while (i<=mid) {
                step++;
                temp[k++] = arr[i++];
        }

        while (j<=end) {
                step++;
                temp[k++] = arr[j++];
        }

	for(int i=start;i<=end;i++) {
                step++;
		arr[i] = temp[i];
	}
}

void merge_sort(int *a,int start, int end) {

        int mid = (start + end)/2;

	if(start >= end) {
		return;
	}

	merge_sort(a,start,mid);
	merge_sort(a,mid+1,end);

	// for merging
	merge(a,start,end);
}


int search_key(int *arr, int s, int e, int &x) {

        while(s <= e) {

                step++;

                int mid = (s + e)/2;

                if(x==arr[mid]) {
                        return 1;
                }
                if(x > arr[mid]) {
                        s = mid + 1;
                }
                if(x < arr[mid]) {
                        e = mid - 1;
                }
        }
        return 0;
}

int main() {

        int n;
        cout << "Enter the size of array : ";
        cin >> n;

        int a[n];

        for(int i=0;i<n;i++) {
                a[i] = rand() % 100;
        }

        cout << "Entered array is :\n";
        for(int i=0;i<n;i++) {
                cout << a[i] << " ";
        }

        cout << endl;

        int key;
        cout << "Enter the element to search : ";
        cin >> key;

        merge_sort(a,0,n-1);

        if(search_key(a,0,n-1,key)) {
                cout << key << " is present in the array !!" << endl;
        }
        else {
                cout << key << " is not present in the array !!" << endl;
        }

        cout << "Total steps taken : " << step << endl;

        return 0;
}
