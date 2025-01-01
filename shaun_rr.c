#include <stdio.h>

#define MAX_PROCESSES 10
#define tq 2

struct Process {
    int id;
    int bt;
    int at;
    int rt;
    int tat;
    int wt;
    int ct;
    int num;
    int completed;
};

void calculateWaitingTime(struct Process process[], int n) {
    int i,k,curr=0;
    float totalwt = 0, totaltat = 0;
    for(i=0;i<n;i++){
        process[i].num=0;
        process[i].rt=process[i].bt;
    }
if (process[0].at!=0) {
    curr=process[0].at;
}
else{
    curr=0;
}
    //printf("\nProcess\tArrival Time\tBurst Time\tCompletion Time\tWaiting Time\tTurnaround Time\n");
 while(1){
    for (i = 0; i < n; i++) {
      if(process[i].rt!=0){

        
        if(process[i].num==0){
            process[i].wt=curr-process[i].at;
            if(process[i].rt>tq){
                process[i].rt=process[i].rt-tq;
                process[i].num=process[i].num+1;
                process[i].ct=curr+tq;

                curr=curr+tq;
                
            }
            else{
                curr=curr+process[i].rt;
                process[i].rt=0;
                process[i].num=process[i].num+1;
                process[i].ct=curr;
            }
        }
        else{
            process[i].wt=process[i].wt+(curr-process[i].ct);
            if(process[i].rt>tq){
                process[i].rt=process[i].rt-tq;
                process[i].num=process[i].num+1;
                process[i].ct=curr+tq;

                curr=curr+tq;
                
            }
            else{
              
    process[i].ct = curr + process[i].rt;
    process[i].wt = process[i].wt + (curr - process[i].ct); // Update waiting time 
    curr = process[i].ct; // Update current time to the completion time of the current 
    process[i].rt = 0;
    process[i].num = process[i].num + 1;


                
            }
        }



       
      }
    }

    int f=0;
    for (k = 0; k < n; k++) {
        if(process[k].rt!=0){
            f=1;
        }
        
    }
    if(f==0){
        break;
    }
 }
 for (i = 0; i < n; i++) {
    process[i].tat=process[i].ct-process[i].at;
 }
    

 for(i=0;i<n;i++){
     printf("\nProcess\tArrival Time\tBurst Time\tCompletion Time\tWaiting Time\tTurnaround Time\n");
     printf("P%d\t%d\t\t%d\t\t%d\t\t%d\t\t%d\n", process[i].id, process[i].at, process[i].bt, process[i].ct, process[i].wt, process[i].tat);
     totalwt=totalwt+process[i].wt;
     totaltat=totaltat+process[i].tat;

 }
 


    
    

    printf("\nAverage Waiting Time: %.2f", totalwt / n);
    printf("\nAverage Turnaround Time: %.2f", totaltat / n);
}

int main() {
    int n, i,j;

    printf("Enter the number of processes: ");
    scanf("%d", &n);

    struct Process processes[MAX_PROCESSES];
    int processCompletionTimes[MAX_PROCESSES] = {0};

    printf("Enter arrival time and burst time for each process:\n");
    for (i = 0; i < n; i++) {
        printf("Arrival time for process %d: ", i + 1);
        scanf("%d", &processes[i].at);
        printf("Burst time for process %d: ", i + 1);
        scanf("%d", &processes[i].bt);
        processes[i].rt = processes[i].bt;
        processes[i].id = i + 1;
        processes[i].num=0;
        processes[i].completed = 0;
    }

    calculateWaitingTime(processes, n);
    //drawGanttChart(processes, n, processCompletionTimes);
// print top bar
    printf(" ");
    if (processes[0].at != 0) {
        for (j = 0; j < processes[0].at; j++) printf("--");
        printf(" ");
    }
    for (i = 0; i < n; i++) {
        for (j = 0; j < processes[i].bt; j++) printf("--");
        printf(" ");
    }
    printf("\n|");

    // printing processesess id in the middle
    if (processes[0].at != 0) {
        int k = 0;
        while (k < processes[0].at) {
            printf("/");
            k++;
        }
        printf(" |");
    }

    for (i = 0; i < n; i++) {
        for (j = 0; j < processes[i].bt - 1; j++) printf(" ");
        printf("P%d", processes[i].id);
        for (j = 0; j < processes[i].bt - 1; j++) printf(" ");
        printf("|");
    }
    printf("\n ");
    // printing bottom bar
    if (processes[0].at != 0) {
        for (j = 0; j < processes[0].at; j++) printf("--");
        printf(" ");
    }
    for (i = 0; i < n; i++) {
        for (j = 0; j < processes[i].bt; j++) printf("--");
        printf(" ");
    }
    printf("\n");

    // printing the time line
    int sum = 0;
    printf("0");
    if (processes[0].at != 0) {
        for (j = 0; j < processes[0].at; j++) printf("  ");
        printf("%d", processes[0].at);
        for (j = 0; j < processes[0].bt; j++) printf("  ");
        if (processes[i].tat > 9) printf("\b");
        sum = processes[0].at + processes[0].bt;
        printf("%d", sum);
        for (i = 1; i < n; i++) {
            for (j = 0; j < processes[i].bt; j++) printf("  ");
            if (processes[i].tat > 9) printf("\b");
            sum = sum + processes[i].bt;
            printf(" %d", sum);
        }
    } else {
        for (i = 0; i < n; i++) {
            for (j = 0; j < processes[i].bt; j++) printf("  ");
            if (processes[i].tat > 9) printf("\b"); // backspace : remove 1 space
            if (i == 0) {
                printf("%d", processes[i].bt);
            } else {
                int sum = processes[i - 1].ct + processes[i].bt;
                printf("%d", sum);
            }

        }
    }
    printf("\n");
    printf("\n");


    return 0;
}