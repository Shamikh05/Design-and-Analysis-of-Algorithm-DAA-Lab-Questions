#include <stdio.h>
#include <stdlib.h>

#define MAX 100000
int a[MAX];

long long int asc_step = 0;

void create_array(int n) {

        for(int i=0;i<n;i++) {
                a[i] = rand() % 100;
        }

}

void insertion_sort_array(int n) {

        asc_step = 0;

        for(int i=0;i<n;i++) {

                int key = a[i];
                int j = i - 1;

                while(j>=0 && a[j]>key) {
                        a[j+1] = a[j];
                        j--;

                        asc_step++;
                }

                a[j+1] = key;
        }

}

void descending_sort_array(int n) {

        for(int i=0;i<n;i++) {

                int key = a[i];
                int j = i - 1;

                while(j>=0 && a[j]<key) {
                        a[j+1] = a[j];
                        j--;
                }

                a[j+1] = key;
        }
}

void display_array(int n) {

        for(int i=0;i<n;i++) {
                printf("%d ",a[i]);
        }

        printf("\n");

}

void print_table() {

        printf("\nSerial No.\tValue of n\tTime Complexity (Random Data)\tTime Complexity (Data in ascending)\tTime Complexity (Data in descending)\n\n");
        printf("---------------------------------------------------------------------------------------------------------------------------------------------\n");

        int k = 5000;

        for(int i=1;i<=10;i++) {

                create_array(k);
                insertion_sort_array(k);
                long long int a = asc_step;
                insertion_sort_array(k);
                long long int b = asc_step;
                descending_sort_array(k);
                insertion_sort_array(k);
                long long int c = asc_step;
                printf("%d\t\t%d\t\t%lld\t\t\t\t%lld\t\t\t\t\t%lld\n",i,k,a,b,c);

                k += 5000;

        }
}

int main() {

        int ch;

        int n;

        while(1) {

                printf("\nSelect a option from below :\n");
                printf("\n0. Quit\n1. Create an array\n2. Display the array\n3. Sort in ascending order\n4. Sort the array in descending order\n5. Time Complexity to sort ascending of random data\n6. Time complexity to sort ascending of data already sorted in ascending order\n7. Time complexity to sort ascending of data already sorted in descending order\n8. Print the table\n");

                printf("\nEnter your choice : ");
                scanf("%d",&ch);

                switch(ch) {

                        case 0 :
                                exit(1);
                                break;

                        case 1 :
                                printf("Enter the size of the array : ");
                                scanf("%d",&n);
                                create_array(n);
                                break;

                        case 2 :
                                display_array(n);
                                break;

                        case 3 :
                                insertion_sort_array(n);
                                break;

                        case 4 :
                                descending_sort_array(n);
                                break;

                        case 5 :
                                insertion_sort_array(n);
                                printf("Time Complexity to sort ascending of random data : %lld\n",asc_step);
                                break;

                        case 6 :
                                insertion_sort_array(n);
                                insertion_sort_array(n);
                                printf("Time complexity to sort ascending of data already sorted in ascending order : %lld\n",asc_step);
                                break;

                        case 7 :
                                descending_sort_array(n);
                                insertion_sort_array(n);
                                printf("Time complexity to sort ascending of data already sorted in descending order : %lld\n",asc_step);
                                break;

                        case 8 :
                                print_table();
                                break;

                        default : printf("Invalid entry!!\n");
                }
        }

        return 0;

}
