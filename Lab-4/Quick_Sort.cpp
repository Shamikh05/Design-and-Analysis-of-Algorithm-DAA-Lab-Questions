#include <iostream>
#include <bits/stdc++.h>
using namespace std;

#define N 100000
int a[N];
int n;
int pass = 0;

int partitions(int l,int r) {

        int pivot = a[l];
        int i = r + 1;  //last number which is greater than pivot

        for(int j=r;j>=l;j--) {

                if(a[j] > pivot) {
                        i--;
                        swap(a[i],a[j]);
                }
        }

        swap(a[i-1],a[r]);

        return i-1;
}

int partition(int l,int r) {

        int pivot = a[r];
        int i = l - 1;  //last number which is less than pivot

        for(int j=l;j<r;j++) {

                if(a[j] < pivot) {
                        i++;
                        swap(a[i],a[j]);
                }
        }

        swap(a[i+1],a[r]);

        return i+1;
}

void quick_sort(int l, int r) {

        if(l<r) {

                /*p++;

                if(p>5) {
                        return;
                }*/

                int pi = partition(l,r);

                quick_sort(l,pi-1);
                quick_sort(pi+1,r);
        }
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
                                quick_sort(0,n-1);
                                break;
                        case 4:
                                quick_sort(0,n-1);
                                break;

                        default:
                                cout << "Invalid entry!!\n";
                }
        }
}
