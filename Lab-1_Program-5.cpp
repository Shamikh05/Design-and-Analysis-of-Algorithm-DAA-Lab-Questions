#include <iostream>
using namespace std;

void matrix(int a[][100], int n) {
        int i, j;
        for (i = 0; i < n; i++) {
                for (j = 0; j < n; j++) {
                        cout << "enter element a" << i + 1 << j + 1 << " : ";
                        cin >> a[i][j];
                }
        }
        cout << endl;
}

void display(int a[][100], int n) {
    int i, j;
    cout << "elements are : " << endl;
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            cout << a[i][j] << "\t";
        }
        cout << endl;
    }
    cout << endl;
}

void findnonzero(int a[][100], int n){
    int count = 0, i, j;

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            if (a[i][j] != 0)
            {
                count ++;
            }

        }
    }

    cout << "non zero elements are : " << count << endl;
}

void sumleadingdiago(int a[][100], int n){
    int i, j, sum = 0;

    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            if (j > i) {
                sum += a[i][j];
            }
        }
    }
    cout <<"sum of leading diagonal is : " << sum << endl;
}

void sumbellowdiago(int a[][100], int n) {

        int i, j, sum = 0;

        for(i = 0; i < n; i++) {
                for (j = 0; j < n; j++) {
                        if (i > j) {
                                sum += a[i][j];
                        }
                }
        }
        cout <<"sum of bellow diagonal is : " << sum << endl;
}

void productdiago(int a[][100], int n) {

        int product = 1;

        for(int i = 0; i < n; i++) {

                product = product * a[i][i];
                product = product * a[i][n - i - 1];
        }

        cout << "product of diagonal is : " << product;
}


int main() {

        int a[100][100], n;
        cout << "Enter the size of matrix : ";
        cin >> n;
        a[n][n];

        matrix(a, n);
        display(a, n);
        findnonzero(a, n);
        sumleadingdiago(a, n);
        sumbellowdiago(a, n);
        productdiago(a, n);

        return 0;
}
