#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include "task.h"

int main() {

	printf("----------WELCOME----------\n");
	Task *taskArray = NULL;
	int taskCount = 0;
	bool running = true;
	int userChoice;
	char input[INPUT_SIZE];

	while (running) {
		printf("1. Add a task\n2. Remove a task\n3. Update a task\n4. Display all tasks\n5. Mark as completed\n6. Filter tasks\n9 to QUIT PROGRAM\n");;
		printf("Enter your choice: ");

		fgets(input, sizeof(input), stdin);
		if (sscanf_s(input, "%d", &userChoice) != 1) {
			printf("INVALID INPUT! Please enter a number from 1-6 or 9 to QUIT\n\n");
			continue;
		}

		switch (userChoice) {
		case 1:
			addTask(&taskArray, &taskCount);
			break;

		case 2:
			removeTask(taskArray, &taskCount);
			break;

		case 3:
			updateTask(taskArray, taskCount);
			break;

		case 4:
			displayTasks(taskArray, taskCount);
			break;

		case 5:
			markAsCompleted(taskArray, taskCount);
			break;

		case 6: 
			filterTasks(taskArray, taskCount);
			break;

		case 9:
			running = false;
			printf("EXITING PROGRAM!");
			break;
		default:
			printf("INVALID INPUT! Please enter a number from 1-6 or 9 to QUIT\n\n");
			continue;
		}

	}

	free(taskArray);
	return 0;
}