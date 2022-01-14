#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX 100000
int a[MAX];

long long int step_count = 0;

void Array_input(int n) {
        for (int i = 0; i < n; i++) {
                a[i] = rand() % 100;
        }
}

void sortAsc(int n){
        step_count = 0;
        for (int i = 0; i < n; i++){
                int key = a[i];
                int j = i - 1;
                while (j >= 0 && a[j] > key) {
                        a[j + 1] = a[j];
                        j--;
                        step_count++;
                }
                a[j + 1] = key;
        }
}

void sortDsc(int n) {
        for (int i = 0; i < n; i++) {
                int key = a[i];
                int j = i - 1;
                while (j >= 0 && a[j] < key) {
                        a[j + 1] = a[j];
                        j--;
                }
                a[j + 1] = key;
        }
}

void display(int n) {
        for (int i = 0; i < n; i++) {
                printf("%d ", a[i]);
        }
        printf("\n");
}

void display_table() {
        clock_t start,end;
        double d;
        printf("\nSerial No.\tValue of n\tTime Complexity (Random Data)\tTime Complexity (Data in ascending)\tTime Complexity (Data in descending)\n\n");
        printf("---------------------------------------------------------------------------------------------------------------------------------------------\n");
        int k = 5000;
        for (int i = 1; i <= 10; i++) {
                Array_input(k);
                start=clock();
                sortAsc(k);
                end=clock();
                double a = (end-start)/(double)CLOCKS_PER_SEC;
                start=clock();
                sortAsc(k);
                end=clock();
                double b = (end-start)/(double)CLOCKS_PER_SEC;
                start=clock();
                sortDsc(k);
                sortAsc(k);
                end=clock();
                double c = (end-start)/(double)CLOCKS_PER_SEC;
                printf("%d\t\t%d\t\t%lf\t\t\t\t%lf\t\t\t\t\t%lf\n", i, k, a, b, c);
                k += 5000;
        }
}

int main() {
        int ch;
        int n;
        while (1) {

                printf("\nSelect any option :\n");
                printf("\n0. Quit\n1. Create an array\n2. display the array\n3. Sort in ascending order\n4. Sortin descending order\n5. Time Complexity to sort ascending random data\n6. Time complexity to sort ascending data already sorted in ascending order\n7. Time complexity to sort ascending data already sorted in descending order\n8. Print the table\n");
                printf("\nEnter your choice : ");
                scanf("%d", &ch);
        switch (ch)
        {
        case 0:
            exit(1);
            break;
        case 1:
            printf("Enter the size of the array : ");
            scanf("%d", &n);
            Array_input(n);
            break;
        case 2:
            display(n);
            break;
        case 3:
            sortAsc(n);
            break;
        case 4:
            sortDsc(n);
            break;
        case 5:
            sortAsc(n);
            printf("Time Complexity to sort ascending of random data : %lld\n", step_count);
            break;
        case 6:
            sortAsc(n);
            sortAsc(n);
            printf("Time complexity to sort ascending of data already sorted in ascending order : %lld\n", step_count);
            break;
        case 7:
            sortDsc(n);
            sortAsc(n);
            printf("Time complexity to sort ascending of data already sorted in descending order : %lld\n",step_count);
            break;
        case 8:
            display_table();
            break;
        default:
            printf("Invalid entry!!\n");
        }
    }
    return 0;
}
