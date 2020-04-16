#include<cmath>
#include<iostream>
#include<map>
using namespace std;

int main()
{
    cout<<"**************ASSUSMPTIONS********************\nhead of disk is at 0 and end is at 199\n***********************************************************\n\n";
    int cur,s,ans=0;
    cout<<"Enter size of queue:";cin>>s;
    map<int,bool>arr;
    cout<<"Enter the requests values\n";
    for(int i=0;i<s;i++){int temp;cin>>temp;arr[temp]=true;}
    cout<<"Enter the current pointer position:";cin>>cur;
    while(arr.size()>0)
    {
        for(;cur<=199 && arr.size()>0;cur++)
        {
            if(arr.find(cur)!=arr.end()){arr.erase(cur);}
            if(arr.size()==0){break;}
            if(cur<199)
            {ans++;}
        }
        if(arr.size()==0){break;}
        ans+=199;
        cur=0;
    }
    cout<<"\nCylinders used:"<<ans;
}
