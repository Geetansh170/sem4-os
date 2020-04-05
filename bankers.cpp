#include<iostream>
using namespace std;

bool banker(int available[3],int allocate[][3],int need[][3],int n)
{
    bool finish[n];
    for(int z=0;z<n;z++){finish[z]=false;}
    int i=0;
    bool again=true;
    while(again==true)
    {
        again=false;
        for(int s=0;s<n;s++)
        {
            //cout<<s<<" ";
            if(finish[i]==false && need[i][0]<=available[0] && need[i][1]<=available[1] && need[i][2]<=available[2])
            {
                again=true;
                finish[i]=true;
                available[0]+=allocate[i][0];available[1]+=allocate[i][1];available[2]+=allocate[i][2];
                i=(i+1)%n;
                break;
            }
            i=(i+1)%n;
        }
    }
    for(int z=0;z<n;z++)
    {
        if(finish[z]==false){return false;}
    }
    return true;
}

int main()
{
    cout<<"Enter the instances of 3 resources:";
    int available[3];
    cin>>available[0]>>available[1]>>available[2];
    cout<<"Enter the number of processes:";
    int n;cin>>n;
    cout<<"Enter max use of resources for each process:";
    int maxr[n][3];
    for(int i=0;i<n;i++)
    {
        cin>>maxr[i][0]>>maxr[i][1]>>maxr[i][2];
    }
    cout<<"Enter currently allocated instances of each process:";
    int allocate[n][3];
    for(int i=0;i<n;i++)
    {
        cin>>allocate[i][0]>>allocate[i][1]>>allocate[i][2];
        available[0]-=allocate[i][0];
        available[1]-=allocate[i][1];
        available[2]-=allocate[i][2];
    }
    int need[n][3];
    for(int i=0;i<n;i++)
    {
        need[i][0]=maxr[i][0]-allocate[i][0];
        need[i][1]=maxr[i][1]-allocate[i][1];
        need[i][2]=maxr[i][2]-allocate[i][2];
    }
    bool safe=banker(available,allocate,need,n);
    if(safe==false)
    {
        cout<<"Initial state is unsafe";return 0;
    }
    cout<<"Enter the index of process and its request:";
    int index,request[3];
    cin>>index>>request[0]>>request[1]>>request[2];
    if(need[index][0]<request[0] || need[index][1]<request[1] || need[index][2]<request[2])
    {
        cout<<index<<" is requesting for instances more than it claimed so request denied";
        return 0;
    }
    allocate[index][0]+=request[0];
    allocate[index][1]+=request[1];
    allocate[index][2]+=request[2];
    need[index][0]-=request[0];
    need[index][1]-=request[1];
    need[index][2]-=request[2];
    available[0]-=request[0];
    available[1]-=request[1];
    available[2]-=request[2];
    safe=banker(available,allocate,need,n);
    if(safe==true)
    {
        cout<<"Safe state after granting request";
    }
    else
    {
        cout<<"Request cannot be granted";
    }
}
