#include<cmath>
#include<iostream>
#include<map>
using namespace std;

int main()
{
    cout<<"**************ASSUSMPTIONS********************\nhead of disk is at 0 and end is at 199\n***********************************************************\n\n";
    int cur,s,ans=0,big=INT_MIN,small=INT_MAX;
    cout<<"Enter size of queue:";cin>>s;
    map<int,bool>arr;
    cout<<"Enter the requests values\n";
    for(int i=0;i<s;i++)
    {
        int temp;cin>>temp;arr[temp]=true;
        if(temp>big){big=temp;}
        if(temp<small){small=temp;}
    }
    cout<<"Enter the current pointer position:";cin>>cur;
    while(arr.size()>0)
    {
        for(;cur<=big && arr.size()>0;cur++)
        {
            if(arr.find(cur)!=arr.end()){arr.erase(cur);}
            if(arr.size()==0){break;}
            if(cur<big)
            {ans++;}
        }
        if(arr.size()==0){break;}
        cur=small;
        ans+=(big-small);
    }
    cout<<"\nCylinders used:"<<ans;
}

