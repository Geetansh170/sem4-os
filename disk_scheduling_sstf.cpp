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
    bool next=true;
    while(next)
    {
        next=false;int mini=-1;
        for(int i=0;i<s;i++)
        {
            if(arr[i]==-1){continue;}
            if((mini==-1) || (abs(cur-arr[mini])>abs(cur-arr[i])))
            {
                mini=i;
                next=true;
            }
        }
        if(next==true)
        {ans+=abs(cur-arr[mini]);cur=arr[mini];arr[mini]=-1;}
    }
    cout<<"\nCylinders used:"<<ans;
}
