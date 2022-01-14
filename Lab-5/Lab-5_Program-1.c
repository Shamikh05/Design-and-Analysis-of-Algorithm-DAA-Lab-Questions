#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX 100000
int a[MAX];

long long int step_count = 0;

void Array_input(int n) {
        for (int i = 0; i < n; i++) {
                a[i] = rand() % 1000;
        }
}

void swap(int *a, int *b) {
        int temp;
        temp = *a;
        *a = *b;
        *b = temp;
}

void heapify(int n, int i) {

        int largest = i;
        int l = 2 * i + 1;
        int r = 2 * i + 2;

        if (l < n && a[l] > a[largest]) {
                largest = l;
                step_count++;
        }
        if (r < n && a[r] > a[largest]) {
                largest = r;
                step_count++;
        }
        if (largest != i) {
                swap(&a[i], &a[largest]);
                heapify(n, largest);
                step_count++;
        }
}

void sortAsc(int n){
        step_count = 0;

        for (int i = n / 2 - 1; i >= 0; i--) {
                step_count++;
                heapify(n, i);
        }
        for (int i = n - 1; i > 0; i--) {
                step_count++;
                swap(&a[0], &a[i]);
                heapify(i, 0);
        }
}

void sortDsc(int n) {
        step_count = 0;
        for (int i = 0; i < n; i++) {
                int key = a[i];
                int j = i - 1;
                while (j >= 0 && a[j] < key) {
                        step_count++;
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
        int i = 1;
        clock_t start,end;
        double d;
        printf("\nSerial No.\tValue of n\tTime Complexity (Random Data)\tTime Complexity (Data in ascending)\tTime Complexity (Data in descending)\n\n");
        printf("---------------------------------------------------------------------------------------------------------------------------------------------\n");
        for (int k = 5000; k <= 50000; k+=5000) {

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

                printf("%d\t\t%d\t\t%lf\t\t\t%lf\t\t\t\t\t%lf\n", i, k, a, b, c);
                i++;
        }
}

void largest_element(int n) {

        int ans = a[0];

        for (int i = 1; i < n; ++i) {
                if (a[i] > ans) {
                        ans = a[i];
                }
        }
        printf("Largest element = %d", ans);
        printf("\n");
}

void insert_element(int n) {
        int k;
        printf("Enter the element to be inserted : \n");
        scanf("%d", &k);
        n = n - 1;
        a[n - 1] = k;
        heapify(n, n - 1);
}

void delete_node(int n) {
        int last = a[n - 1];
        a[0] = a[last];
        n = n - 1;
        heapify(n, 0);
}

int main() {
        int ch;
        int n;
        while (1) {

                printf("\nSelect any option :\n");
                printf("\n0. Quit\n1. Create an array\n2. display the array\n3. Sort in ascending order\n4. Sort in descending order\n5. Time Complexity to sort ascending random data\n6. Time complexity to sort ascending data already sorted in ascending order\n7. Time complexity to sort ascending data already sorted in descending order\n8. Print the table\n9. Find Largest element\n10. Insert an element\n11. Delete a node\n");
                printf("\nEnter your choice : ");
                scanf("%d", &ch);

                switch (ch) {
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
                        case 9:
                               printf("Largest element from the array\n");
                               largest_element(n);
                               break;

                       case 10:
                               printf("Insert an element in a node\n");
                               insert_element(n);
                               display(n);
                               break;
                       case 11:
                               printf("Delete a node from the heap\n");
                               delete_node(n);
                               break;

                        default:
                                printf("Invalid entry!!\n");
                }
        }
        return 0;
}
