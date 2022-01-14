#include <iostream>
#include <bits/stdc++.h>
using namespace std;

bool comp(vector<int> a, vector<int> b) {
        return a[3] > b[3];
}

int main() {

        int n;

        cout << "Enter number of items : ";
        cin >> n;

        vector<vector<int> > v(n,vector<int>(4,0));

        cout << "Enter id, value and weight of item" << " :" << endl;

        for(int i=0;i<n;i++) {

                char id;
                cin >> id >> v[i][1] >> v[i][2];
                v[i][0] = int(id);
                v[i][3] = (v[i][1] / v[i][2]);
        }

        int w;
        cout << "Enter the knapsack capacity : ";
        cin >> w;

        int c;
        cout << "Enter the choice : ";
        cin >> c;

        int ch = int(c);

        long long int result = 0;

        for(int i=0;i<n;i++) {

                if(v[i][0]==ch) {

                        if(v[i][2] <= w) {
                                w -= v[i][2];
                                result += v[i][2]*v[i][3];
                        }
                        else {
                                result += w*v[i][3];
                                w = 0;
                        }
                }
        }

        sort(v.begin(),v.end(),comp);

        for(int i=0;i<n and w;i++) {

                if(v[i][0]!=ch) {

                        if(v[i][2] <= w) {
                                w -= v[i][2];
                                result += v[i][2]*v[i][3];
                        }
                        else {
                                result += w*v[i][3];
                                w = 0;
                        }
                }

        }

        cout << "Maximum Value : " << result << endl;

        return 0;

}
