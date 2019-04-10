#include<stdio.h>

int main()
{
  int n;
  printf("Enter no of Processes : ");
  scanf("%d",&n);
    int i,j;
    int total_time=0;
    int time;
    int remain;
    int flag=0;
    int p;
    float avg_waiting_time=0;
    float avg_turnaround_time=0;
    int arrival_time[n];
    int burst_time[n];
    int responce_time[n];
    remain=n;

    printf("         ###        Enter the arrival time and burst time Process Id        ###\n");
        printf(" Process Id.   arrival time    burst time     \n");

    for(i=0;i<n;i++)
   {

               printf("process %d\t\t",i);
               scanf("%d",&arrival_time[i]);
               scanf("%d",&burst_time[i]);
              responce_time[i]=burst_time[i];
               total_time=total_time+responce_time[i];

          }
  printf("->->->   Enter time slice     <-<-<-\n");
  scanf("%d",&p);
  printf("\n\nProcess\t|Turnaround time|waiting time\n\n");

           for(time=0,i=0;remain!=0;)

              {

                  if(responce_time[i]<=p && responce_time[i]>0)

                         {
                            time+=responce_time[i];
                            responce_time[i]=0;
                            flag=1;


                             }
                   else if(responce_time[i]>0)

                     {
                         responce_time[i]= responce_time[i] -p;
                         time=time + p;

                         }
                 if(responce_time[i]==0 && flag==1)
                     {
                           remain--;

             printf("P[%d]\t|\t%d\t|\t%d\n",i+1,time-arrival_time[i],time-arrival_time[i]-burst_time[i]);

             avg_waiting_time= avg_waiting_time + time-arrival_time[i]-burst_time[i];

             avg_turnaround_time=avg_turnaround_time + time-arrival_time[i];



             flag=0;


                       }
              if(i==n-1)
              {

                i=0;
              }
            else if(arrival_time[i+1]<=time)
            {

              i++;
            }

            else
            {
               i=0;
            }
                 }
                 avg_waiting_time=avg_waiting_time/n;
                 avg_turnaround_time=avg_turnaround_time/n;

                printf("Avg  waiting time = %f\n",avg_waiting_time);
                printf("Avg turnaround time = %f\n",avg_turnaround_time);
                printf("avage total time taken by complet the process is :%d\n",total_time);

 }
