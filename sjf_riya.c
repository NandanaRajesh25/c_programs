#include <stdio.h>

struct Process {
    int id[100];
    int arrival[100];
    int burst[100];
    int wait[100];
    int tat[100];
    int complete[100];
};

typedef struct Process pr;

void chart(pr *p, int n) {
    int beginning = 1;
    int y = p->arrival[0];
    printf("\n\tGANTT CHART\n");

    for (int q = 0; q < n; q++) {
        if (y != 0 && beginning == 1) {
            printf("---");
            beginning = 0;
            q = -1;
        } else {
            printf("-----");
            for (int i = 0; i < p->burst[q] + 1; i++) {
                printf("--");
            }
        }
    }

    printf("\n");
    beginning = 1;
    for (int q = 0; q < n; q++) {
        if (y != 0 && beginning == 1) {
            printf("///");
            beginning = 0;
            q = -1;
        } else {
            printf("|  p(%d)", p->id[q]);

            for (int i = 0; i < p->burst[q]; i++) {
                printf("  ");
            }
        }
    }
    printf("|");

    printf("\n");
    beginning = 1;
    for (int q = 0; q < n; q++) {
        if (y != 0 && beginning == 1) {
            printf("---");
            beginning = 0;
            q = -1;
        } else {
            printf("-----");
            for (int i = 0; i < p->burst[q] + 1; i++) {
                printf("--");
            }
        }
    }
    printf("\n");

    for (int q = 0; q < n; q++) {
        if (y < 10 && p->complete[q] >= 10) {
            printf("  0%d-%d", y, p->complete[q]);
        } else if (y < 10 && p->complete[q] < 10) {
            printf("  0%d-0%d", y, p->complete[q]);
        } else {
            printf("  %d-%d", y, p->complete[q]);
        }
        y = p->complete[q];
        for (int i = 0; i < p->burst[q]; i++) {
            printf("  ");
        }
    }
    printf("\n");
}

void sort(pr *p, int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (p->arrival[j] > p->arrival[j + 1] || 
                (p->arrival[j] == p->arrival[j + 1] && p->burst[j] > p->burst[j + 1])) {
                int temp = p->arrival[j];
                p->arrival[j] = p->arrival[j + 1];
                p->arrival[j + 1] = temp;

                temp = p->id[j];
                p->id[j] = p->id[j + 1];
                p->id[j + 1] = temp;

                temp = p->burst[j];
                p->burst[j] = p->burst[j + 1];
                p->burst[j + 1] = temp;
            }
        }
    }
}

int main() {
    float avgwait = 0, avgturn = 0;
    int total_wt = 0, total_tat = 0;
    int n;

    pr p;

    printf("Enter no. of processes: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        printf("Enter process id: ");
        scanf("%d", &p.id[i]);
        printf("Enter arrival time: ");
        scanf("%d", &p.arrival[i]);
        printf("Enter burst time: ");
        scanf("%d", &p.burst[i]);
    }

    sort(&p, n);

    int time = 0;
    for (int i = 0; i < n; i++) {
        if (p.arrival[i] > time) {
            time = p.arrival[i];
        }

        p.wait[i] = time - p.arrival[i];
        time += p.burst[i];
        p.complete[i] = time;
        p.tat[i] = p.complete[i] - p.arrival[i];
        total_wt += p.wait[i];
        total_tat += p.tat[i];
    }

    avgwait = (float)total_wt / n;
    avgturn = (float)total_tat / n;

    printf("\nProcess ID  Arrival Time  Burst Time  Waiting Time  Turnaround Time  Completion Time\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t\t%d\t\t%d\t\t%d\t\t%d\t\t%d\n", p.id[i], p.arrival[i], p.burst[i], p.wait[i], p.tat[i], p.complete[i]);
    }
    printf("\nAverage Waiting Time: %.2f", avgwait);
    printf("\nAverage Turnaround Time: %.2f", avgturn);

    chart(&p, n);

    return 0;
}