
#include<iostream>
using namespace std;

void findWaitingTime(int processes[], int n,
			int bt[], int wt[], int quanta)
{

	int rem_bt[n];
	for (int i = 0 ; i < n ; i++)
		rem_bt[i] = bt[i];

	int t = 0;


	while (1)
	{
		bool done = true;


		for (int i = 0 ; i < n; i++)
		{

			if (rem_bt[i] > 0)
			{
				done = false;

				if (rem_bt[i] > quanta)
				{

					t += quanta;


					rem_bt[i] -= quanta;
				}


				else
				{

					t = t + rem_bt[i];




					rem_bt[i] = 0;
				}
			}
		}


		if (done == true)
		break;
	}
}

void findTurnAroundTime(int processes[], int n,
						int bt[], int wt[], int tat[])
{
	]
	for (int i = 0; i < n ; i++)
		tat[i] = bt[i] + wt[i];
}


void findavgTime(int processes[], int n, int bt[],
									int quanta)
{
	int wt[n], tat[n], total_wt = 0, total_tat = 0;


	findWaitingTime(processes, n, bt, wt, quanta);


	findTurnAroundTime(processes, n, bt, wt, tat);


	cout << "Processes "<< " Burst time "
		<< " Waiting time " << " Turn around time\n";


	for (int i=0; i<n; i++)
	{
		total_wt = total_wt + wt[i];
		total_tat = total_tat + tat[i];
		cout << " " << i+1 << "\t\t" << bt[i] <<"\t "
			<< wt[i] <<"\t\t " << tat[i] <<endl;
	}

	cout << "Average waiting time = "
		<< (float)total_wt / (float)n;
	cout << "\nAverage turn around time = "
		<< (float)total_tat / (float)n;
}

// Driver code
int main()
{
	 int n;
    cout <<"enter the number of processes"<<endl;
    cin>>n;
	int processes[100];
	//int n = sizeof processes / sizeof processes[0];
cout<<"enter the processes"<<endl;
for(int i = 0 ; i<n ; i++){
cin>>processes[i];
}
 cout<<"enter the bursts times"<<endl;

	int burst_time[100] ;
for(int i = 0 ; i<n ; i++){
cin>>burst_time[i];
}
	int quanta ;
        cout<<"enter the time quanta"<<endl;
cin>>quanta;
	findavgTime(processes, n, burst_time, quanta);
	return 0;
}

