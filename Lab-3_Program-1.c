#include <stdio.h>
#include <time.h>

void insertion_sort_array(int *arr,int n) {

        for(int i=0;i<n;i++) {

                int key = arr[i];
                int j = i - 1;

                while(j>=0 && arr[j]>key) {
                        arr[j+1] = arr[j];
                        j--;
                }

                arr[j+1] = key;
        }

}

int main() {

        int n;
        printf("Enter the size of the array : ");
        scanf("%d",&n);

        int a[n];

        printf("Enter the elements of the array :\n");

        for(int i=0;i<n;i++) {
                scanf("%d",&a[i]);
        }

        clock_t start = clock();
        printf("\nStarting of the Insertion sort, clock = %ld\n", start);

        insertion_sort_array(a,n);

        printf("\nAfter sorting the array :\n");

        for(int i=0;i<n;i++) {
                printf("%d ",a[i]);
        }

        clock_t end = clock();
        printf("\n\nEnding of the Insertion sort, clock = %ld\n", end);

        clock_t total = (double)(end - start) / CLOCKS_PER_SEC;
        printf("\nTotal time taken by CPU: %f\n", total);

        return 0;

}
