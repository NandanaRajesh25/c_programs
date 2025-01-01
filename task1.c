#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef struct Node {
    int priority;
    char desc[50];
    struct tm completionTime;
    struct Node *next;
} Node;


struct Node* head = NULL;
struct Node* headpq = NULL;
void createSorted() {
    Node *newNode = (Node *)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("\nMemory allocation failed");
        exit(1);
    }
   
    printf("Enter task priority(Urgent:0 | Work:1 | Home:2):");
    scanf("%d", &newNode->priority);  // Use & to get the address of the priority variable
   
    printf("Enter task description: ");
    scanf(" %[^\n]s", newNode->desc);

    printf("Enter task completion time (DD-MM-YYYY HH:MM): ");
    scanf("%d-%d-%d %d:%d",
           &newNode->completionTime.tm_mday, &newNode->completionTime.tm_mon, &newNode->completionTime.tm_year,
           &newNode->completionTime.tm_hour, &newNode->completionTime.tm_min);
    newNode->completionTime.tm_year -= 1900;  // Adjust year
    newNode->completionTime.tm_mon -= 1;      // Adjust month
    newNode->completionTime.tm_sec = 0;
    newNode->completionTime.tm_isdst = -1;

    newNode->next = NULL;

    if (head == NULL || difftime(mktime(&head->completionTime), mktime(&newNode->completionTime)) > 0) {
        // Insert at the beginning of the list or if the new node's completion time is earlier than the head
        newNode->next = head;
        head = newNode;
    } else {
        Node *current = head;
        Node *prev = NULL;
        while (current != NULL && difftime(mktime(&current->completionTime), mktime(&newNode->completionTime)) < 0) {
            prev = current;
            current = current->next;
        }
        prev->next = newNode;
        newNode->next = current;
    }
}

void deleteTasksBeforeCurrentTime() {
    if (head == NULL) {
        // Linked list is empty, nothing to delete
        return;
    }
    struct tm currentTime;
    time_t t;
    time(&t);
    //localtime_r(&t, &currentTime);

    struct Node* current = head;
    struct Node* temp;

    while (current != NULL &&
           difftime(mktime(&current->completionTime), mktime(&currentTime)) < 0) {
        temp = current;
        current = current->next;
        free(temp); // Free memory of nodes with completion time before the current time
    }
    head = current;
}

void deleteTaskinADay() {
    if (head == NULL) {
        printf("No Tasks have been added.\n");
        return;
    }

    struct tm searchDate;
    printf("Enter the date to display tasks (DD-MM-YYYY): ");
    scanf("%d-%d-%d", &searchDate.tm_mday, &searchDate.tm_mon, &searchDate.tm_year);
    searchDate.tm_mon -= 1; // Adjust month
    searchDate.tm_year -= 1900; // Adjust year
    searchDate.tm_hour = 0;
    searchDate.tm_min = 0;
    searchDate.tm_sec = 0;
    searchDate.tm_isdst = -1;

    printf("Tasks for %02d-%02d-%04d:\n", searchDate.tm_mday, searchDate.tm_mon + 1, searchDate.tm_year + 1900);

    struct Node* current = head;
    struct Node* prev = head;
    int tasksFound = 0; // Flag to check if tasks are found for the given day

    while (current != NULL) {
        // Check if the task's completion date matches the search date
        if (current->completionTime.tm_mday == searchDate.tm_mday &&
            current->completionTime.tm_mon == searchDate.tm_mon &&
            current->completionTime.tm_year == searchDate.tm_year) {

            tasksFound = 1; // Set the flag to indicate tasks are found
            printf("\nPriority: %d, Description: %s ", current->priority, current->desc);
            printf("\nCompletion Time: %02d-%02d-%04d %02d:%02d\n",
                   current->completionTime.tm_mday, current->completionTime.tm_mon + 1,
                   current->completionTime.tm_year + 1900, current->completionTime.tm_hour, current->completionTime.tm_min);
            printf("Do you want to delete this task? (y/n): ");

            char choice;
            scanf(" %c", &choice); // Read the user's choice

            if (choice == 'y' || choice == 'Y') {
                // User wants to delete the task
                if (current == head) {
                    // If the task to be deleted is the head, update head
                    head = current->next;
                } else {
                    // Otherwise, update the previous node's next pointer
                    prev->next = current->next;
                }

                free(current); // Free the memory of the deleted node
                printf("Task deleted successfully.\n");
            }
        }

        prev = current;
        current = current->next;
    }

    if (!tasksFound) {
        printf("No Tasks Found for that day.\n");
        return;
    }
}

void copyNode(Node *destination, const Node *source) {
    if (destination != NULL && source != NULL) {
        destination->priority = source->priority;
        strncpy(destination->desc, source->desc, sizeof(destination->desc) - 1);
        destination->desc[sizeof(destination->desc) - 1] = '\0';
        destination->completionTime = source->completionTime;
        destination->next = NULL;  
    }
}

Node* pop(){  
    if(headpq!=NULL){
        Node *temp = headpq;
        headpq = headpq->next;
        return temp;
    }
    return NULL;  
}
void push(Node* node)  {  
    Node* start = headpq;  
   
    Node* temp = (Node *)malloc(sizeof(Node));
    copyNode(temp, node);
    int p = node->priority;
   
    if (headpq == NULL || (headpq)->priority > p) {  
        // Insert New Node as the head if the queue is empty or new node has higher priority
        temp->next = headpq;  
        headpq = temp;  
    }  
    else {  
        while (start->next != NULL && start->next->priority < p) {  
            start = start->next;  
        }  
        // Either at the ends of the list  
        // or at the required position  
        temp->next = start->next;  
        start->next = temp;  
    }  
}


void displayForADay() {
    if (head == NULL) {
        printf("No Tasks have been added.\n");
        return;
    }

    struct tm searchDate;
    printf("Enter the date to display tasks (DD-MM-YYYY): ");
    scanf("%d-%d-%d", &searchDate.tm_mday, &searchDate.tm_mon, &searchDate.tm_year);
    searchDate.tm_mon -= 1; // Adjust month
    searchDate.tm_year -= 1900; // Adjust year
    searchDate.tm_hour = 0;
    searchDate.tm_min = 0;
    searchDate.tm_sec = 0;
    searchDate.tm_isdst = -1;

    printf("Tasks for %02d-%02d-%04d:\n", searchDate.tm_mday, searchDate.tm_mon + 1, searchDate.tm_year + 1900);

    struct Node* current = head;
    int tasksFound = 0; // Flag to check if tasks are found for the given day
    while (current != NULL) {
        // Check if the task's completion date matches the search date
        if (current->completionTime.tm_mday == searchDate.tm_mday &&
            current->completionTime.tm_mon == searchDate.tm_mon &&
            current->completionTime.tm_year == searchDate.tm_year) {
            push(current);
            tasksFound = 1; // Set the flag to indicate tasks are found
        }
        current = current->next;
    }

    if (!tasksFound) {
        printf("No Tasks Found for that day.\n");
        return;
    }

    Node* removed = pop();
    while (removed != NULL) {
        printf("\nPriority: %d, Description: %s ", removed->priority, removed->desc);
        printf("\nCompletion Time: %02d-%02d-%04d %02d:%02d\n",
               removed->completionTime.tm_mday, removed->completionTime.tm_mon + 1,
               removed->completionTime.tm_year + 1900, removed->completionTime.tm_hour, removed->completionTime.tm_min);
        free(removed);  // Free the memory of the removed node
        removed = pop();
    }
}

void displayFortheWeek() {
    if (head == NULL) {
        printf("No Tasks have been added.\n");
        return;
    }

    time_t currentTime = time(NULL);
    time_t oneWeekInSeconds = 7 * 24 * 60 * 60;  // Number of seconds in a week

    time_t endTimeOfTheWeek = currentTime + oneWeekInSeconds;

    printf("Tasks for the Week:\n");

    struct Node* current = head;
    int tasksFound = 0; // Flag to check if tasks are found for the week

    while (current != NULL) {
        // Check if the task's completion time is before the end time of the week
        if (difftime(mktime(&current->completionTime), endTimeOfTheWeek) < 0) {
            push(current);
            tasksFound = 1; // Set the flag to indicate tasks are found
        }
        current = current->next;
    }

    if (!tasksFound) {
        printf("No Tasks Found for the week.\n");
        return;
    }

    Node* removed = pop();
    while (removed != NULL) {
        printf("\nPriority: %d, Description: %s ", removed->priority, removed->desc);
        printf("\nCompletion Time: %02d-%02d-%04d %02d:%02d\n",
               removed->completionTime.tm_mday, removed->completionTime.tm_mon + 1,
               removed->completionTime.tm_year + 1900, removed->completionTime.tm_hour, removed->completionTime.tm_min);
        free(removed);  // Free the memory of the removed node
        removed = pop();
    }
}

void displayAll() {
    if (head == NULL) {
        printf("\nNo Tasks have been created.\n");
        return;
    }
    printf("\nTasks:");
    Node* current = head;
    while (current != NULL) {
        printf("\nPriority: %d, Description: %s, Completion Time: %02d-%02d-%04d %02d:%02d",
               current->priority, current->desc,
               current->completionTime.tm_mday, current->completionTime.tm_mon + 1,
               current->completionTime.tm_year + 1900, current->completionTime.tm_hour, current->completionTime.tm_min);
        current = current->next;
    }
    printf("\n");
}

int main() {
    int n;

    while (1) {
        printf("\n1.Create task   2.View tasks   3.Delete tasks  4.Exit");
        printf("\nEnter choice: ");
        scanf("%d", &n);
        switch (n) {
            case 1:
                createSorted();
                break;
            case 2:
                printf("\n  1.Tasks for this week   2.Tasks for a day  3.Show all Tasks ");
                printf("\n  Enter choice:");
                scanf("%d", &n);
                if(n==1){
                    displayFortheWeek();
                }else if(n==2){
                    displayForADay();
                }else if(n==3){
                    displayAll();
                }else{
                    printf("\n  Enter a valid option ");
                }
               
                break;
            case 3:
               printf("\n  1.Delete all tasks from previous days   2.Mark tasks as completed ");
               printf("\n  Enter choice:");
               scanf("%d", &n);
               if(n==1){
                   deleteTasksBeforeCurrentTime();  
               }else if(n==2){
                   deleteTaskinADay();
               }else{
                    printf("\n  Enter a valid option ");
                }
               
               break;
	   case 4:
		exit(1);
            default:
                printf("Invalid choice\n");
                break;
        }
    }
    return 0;
}