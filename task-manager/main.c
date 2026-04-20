#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include "task.h"

int main() {
	//Welcome message
	printf("----------WELCOME----------\n");
	Task *taskArray = NULL; //Initializing task array to NULL.
	int taskCount = 0; //Initializing number of tasks to 0.
	bool running = true; //Initializing the program loop variable to true.
	int userChoice; //Variable to hold user choice.
	char input[INPUT_SIZE]; //Variable for user input validation.

	//Program loop
	while (running) {
		//Displaying menu with numbered choices.
		printf("1. Add a task\n2. Remove a task\n3. Update a task\n4. Display all tasks\n5. Mark as completed\n6. Filter tasks\n9 to QUIT PROGRAM\n");;
		printf("Enter your choice: ");

		//User input validation.
		fgets(input, sizeof(input), stdin);
		if (sscanf_s(input, "%d", &userChoice) != 1) {
			printf("INVALID INPUT! Please enter a number from 1-6 or 9 to QUIT\n\n");
			continue;
		}

		//Switch-case to run required tasks based on user inputs
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
			//Exiting loop if user inputs 9.
			running = false;
			printf("EXITING PROGRAM!");
			break;
		default:
			//Displying invalid message if 
			printf("INVALID INPUT! Please enter a number from 1-6 or 9 to QUIT\n\n");
			continue;
		}

	}
	//Freeing pointer to avoid memory leaks
	free(taskArray);
	return 0;
}