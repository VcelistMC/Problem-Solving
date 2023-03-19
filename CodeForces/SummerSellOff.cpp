#include<iostream>
#include<vector>
#include<algorithm>
//#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define loop(i,n) for(ll i=0; i<n; i++) 
#define fillArray(n,arr) int arr[n]; for(int ii=0; ii<n; ii++)cin>>arr[ii]
//#include <bits/stdc++.h> 
using namespace std; 
 
struct Day
{
    int products;
    int clients;
    int salse;
};
 
int min(int one, int two)
{
    if(one > two)
        return two;
    return one;
}
bool compare(Day a, Day b)
{
    if(a.salse > b.salse)
        return 1;
    return 0;
}
 
int main() 
{
    int n,f;
    cin>>n>>f;
    Day arr[n];
    loop(i,n)
    {
        cin>>arr[i].products>>arr[i].clients;
        arr[i].salse = min(arr[i].clients , 2*arr[i].products) - min(arr[i].clients, arr[i].products);
 
    }
    sort(arr, arr +n, compare);
    ll sum =0;
    loop(i,f)
    {
        sum+= min(arr[i].clients , 2*arr[i].products);
    }
    for(int i=f; i<n; i++)
    {
        sum+= min(arr[i].clients, arr[i].products);
    }
    cout<<sum;
 
 
}