#include <bits/stdc++.h>
using namespace std;

class process
{
public:
    int burst_time,arrival_time,index;
};

bool cmp(process a,process b)
{
    if(a.arrival_time==b.arrival_time)
    {
        return a.index<b.index;
    }
    else
    {
        return a.arrival_time<b.arrival_time;
    }
}

int main()
{
    cout<<"Enter the number of processes:";
    int n;cin>>n;
    process arr[n];
    cout<<"Enter the arrival time and burst time\n";
    for(int i=0;i<n;i++)
    {
        cin>>arr[i].arrival_time>>arr[i].burst_time;
        arr[i].index=i;
    }
    sort(arr,arr+n,cmp);
    int ans[n];
    memset(ans,0,sizeof(int)*n);
    int time=0;
    for(int i=0;i<n;i++)
    {
        ans[i]=time-arr[i].arrival_time;
        time+=arr[i].burst_time;
    }
    int avg=0;
    for(int i=0;i<n;i++)
    {
        cout<<"Waiting time of process "<<i+1<<" is "<<ans[i]<<endl;
        avg+=ans[i];
    }
    cout<<"Average waiting time is "<<avg/n;
}

