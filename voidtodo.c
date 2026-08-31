#include <stdio.h>
#include <string.h>
#include <stdbool.h>

int main(){
    printf("=======================\n"
        "WELCOME TO VOID's TO-DO LIST (Pre-alpha version)\n"
        "=======================\n");

    // create file for storing tasks

    FILE *tasks = fopen("myTasks.txt", "a");
    char task[1024];
    bool newTask = true;
    char response[5];
    char response2[5];
    char buffer[1024];

    if(tasks == NULL) {
        printf("Error opening the file!\n");
        return 1;
    }

    while(newTask) {
        printf("\nEnter a task: ");
        fgets(task, sizeof(task), stdin);
        task[strcspn(task, "\n")] = '\0';

        printf("Do you want add new task? (yes or no):");
        fgets(response, sizeof(response), stdin);
        response[strcspn(response, "\n")] = '\0';

        fprintf(tasks, "%s\n", task); 
        if (strcmp(response, "yes") != 0) {
          newTask= false;
        }
    }

    fclose(tasks);

    tasks = fopen("myTasks.txt", "r");
    if(tasks == NULL) {
      printf("Error open the file!\n");
      return 1;
    }

    printf("Do you want to see your tasks? (yes or no): ");
    fgets(response2, sizeof(response2), stdin);
    response2[strcspn(response2, "\n")] = '\0';

    if(strcmp(response2, "yes") == 0) {
        while(fgets(buffer, sizeof(buffer), tasks) != NULL){
          printf("%s", buffer);
        }
    } else {
        printf("Exiting the app!\n");
    }

    fclose(tasks);

    return 0;
}
