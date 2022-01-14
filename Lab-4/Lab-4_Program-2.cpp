#include <iostream>
using namespace std;

long long int step = 0;
int n;

void merge(int *arr,int start,int end) {

	/*if(start==0 and end==n-1) {
		return;
	}*/

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

int main() {

        cout << "Enter the size of the array : ";
        cin >> n;

        int a[n];

        for(int i=0;i<n;i++) {
                a[i] = rand() % 100;
        }

	cout << endl << "Unsorted array : " << endl;
        for(int i=0;i<n;i++) {
                cout << a[i] << " ";
        }

        merge_sort(a,0,n-1);

        cout << endl << "Sorted array : " << endl;
        for(int i=0;i<n;i++) {
                cout << a[i] << " ";
        }

        cout << endl;

        cout << endl << "Total steps taken : " << step << endl;

	return 0;
}
