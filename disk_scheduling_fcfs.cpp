#include<cmath>
#include<iostream>
using namespace std;

int main()
{
    int cur,s,ans=0;
    cout<<"Enter size of queue:";cin>>s;
    int arr[s];
    cout<<"Enter the requests values\n";
    for(int i=0;i<s;i++){cin>>arr[i];}
    cout<<"Enter the current pointer position:";cin>>cur;
    for(int i=0;i<s;i++)
    {
        ans+=abs(arr[i]-cur);
        cur=arr[i];
    }
    cout<<"\nCylinders used:"<<ans;
}
