#include <iostream>
#include <bits/stdc++.h>
using namespace std;

bool comp(pair<int,float> a, pair<int,float> b) {
        return a.second > b.second;
}

int main() {

        int n;

        cout << "Enter number of items : ";
        cin >> n;

        vector<int> value(n), weight(n);

        for(int i=0;i<n;i++) {
                cout << "Enter value and weight of item - " << i+1 << " : ";
                cin >> value[i] >> weight[i];
        }

        int w;
        cout << "Enter the knapsack capacity : ";
        cin >> w;

        vector<pair<int,float> > v;

        for(int i=0;i<n;i++) {
                v.push_back({weight[i],value[i]/weight[i]});
        }

        sort(v.begin(),v.end(),comp);

        long long int result = 0;{

        }

        for(int i=0;i<n and w;i++) {

                if(v[i].first <= w) {
                        w -= v[i].first;
                        result += v[i].first*v[i].second;
                }
                else {
                        result += w*v[i].second;
                        w = 0;
                }
        }

        cout << "Maximum Value : " << result << endl;

        return 0;

}
