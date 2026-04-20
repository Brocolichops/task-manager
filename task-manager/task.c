#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "task.h"


void addTask(Task** taskArray, int* taskCount)
{
	Task* temp;//Temporary pointer to struct

	temp = realloc(*taskArray, (*taskCount + 1) * sizeof(Task));//Reallocating memory to account for the new task to be added

	//Validating memory allocation
	if (temp == NULL) {
		printf("Memory allocation failed.\n");
		return;
	}

	*taskArray = temp;
	Task* newTask = &((*taskArray)[*taskCount]); 

	char input[INPUT_SIZE]; //Initializing input variable
	//While loop that validates user input
	while (1)
	{
		printf("Enter Task ID: ");
		fgets(input, sizeof(input), stdin);

		input[strcspn(input, "\n")] = '\0'; //Replacing the newline character with null terminating character

		if (sscanf_s(input, "%d", &newTask->id) != 1 || newTask->id <= 0)	//Checking if the user input is not a positive integer
		{
			//Error message 
			printf("INVALID INPUT! Please enter a valid positive number for Task ID.\n");
			continue;
		}
		break;
	}

	//Repeating the same process for the input validation of task description.
	printf("Enter Description: ");
	fgets(newTask->description, DESC_SIZE, stdin);

	newTask->description[strcspn(newTask->description, "\n")] = '\0';


	printf("Enter Priority (LOW, MED, HIGH): ");
	while (1)
	{
		fgets(newTask->priority, PRIORITY_SIZE, stdin);
		newTask->priority[strcspn(newTask->priority, "\n")] = '\0';

		if (_stricmp(newTask->priority, "LOW") == 0 || _stricmp(newTask->priority, "MED") == 0 || _stricmp(newTask->priority, "HIGH") == 0) //_stricmp allows both upper and lower case entries from the user.
		{
			break;
		}

		printf("INVALID PRIORITY! Please enter LOW, MED, or HIGH: ");
	}

	strcpy_s(newTask->status, STATUS_SIZE, "to-do");
	(*taskCount)++;

	printf("Task added successfully.\n");
}



void removeTask(Task* taskArray, int* taskCount)
{
	int id; //Variable to hold ID of task from user
	char input[INPUT_SIZE]; //Temp input variable to validate user input.

	//Exiting function if there are no tasks to remove.
	if (*taskCount == 0) {
		printf("No tasks to remove.\n");
		return;
	}

	//User input validation
	while (1)
	{
		printf("Enter ID to remove: ");
		fgets(input, sizeof(input), stdin);

		if (sscanf_s(input, "%d", &id) != 1) 
		{
			printf("INVALID INPUT! Please enter a valid task ID.\n");
			continue;
		}

		if (id <= 0) 
		{
			printf("INVALID ID! Please enter a positive integer.\n");
			continue;
		}

		break;
	}

	//Iterating through the array of tasks to search for the id entered by the user
	for (int i = 0; i < *taskCount; i++)
	{
		if (taskArray[i].id == id) 
		{
			//Shifting the desired element up one space repeatedly to remove it from the array
			for (int j = i; j < *taskCount - 1; j++)
			{
				taskArray[j] = taskArray[j + 1];
			}

			(*taskCount)--;//Decrementing the number of tasks in the array.

			
			printf("Task removed.\n"); 
			return;
		}
	}

	printf("Task not found.\n");
}

void updateTask(Task* taskArray, int taskCount)
{
	int id; //Variable to hold id from user.
	int userChoice; //Variable to hold choice input from user.
	char input[INPUT_SIZE]; //Variable to temporarily hold input for user validation.

	//Exiting function if there are no tasks.
	if (taskCount == 0) 
	{
		printf("No tasks to update.\n");
		return;
	}

	//User input validation
	while (1)
	{
		printf("Enter id of task: ");
		fgets(input, sizeof(input), stdin);

		if (sscanf_s(input, "%d", &id) != 1 || id <= 0)
		{
			printf("INVALID INPUT! Please enter a valid positive number.\n");
			continue;
		}
		break;
	}
	
	//Iterating through the loop to check for the ID entered by user.
	for (int i = 0; i < taskCount; i++) {
		
		if (taskArray[i].id == id) {
			printf("Task ID found!\n"); //Printing message if task was found
			//User input validation
			while (1)
			{
				printf("What would you like to update ? \n1.Task name\n2.Task priority\nEnter number : ");
				fgets(input, sizeof(input), stdin);

				if (sscanf_s(input, "%d", &userChoice) != 1 || (userChoice != 1 && userChoice != 2))
				{
					printf("INVALID INPUT! Please enter 1 or 2.\n");
					continue;
				}
				break;
			}

			//Code for updating description of the task.
			if (userChoice == 1) {
				//Displaying current description to user
				printf("Current description: %s\n", taskArray[i].description);

				//Getting new description from the user
				printf("Enter new description: ");
				fgets(taskArray[i].description, DESC_SIZE, stdin);
				taskArray[i].description[strcspn(taskArray[i].description, "\n")] = '\0';

				printf("Task description sucessfully updated.\n");
				return;
			}

			//Code for updating the priority of the task.
			else if (userChoice == 2) {
				//Displaying current priority to user.
				printf("Current priority: %s\n", taskArray[i].priority);

				while (1)
				{
					//Getting new priority from the user.
					printf("Enter new priority (LOW, MED, OR HIGH): ");
					fgets(taskArray[i].priority, PRIORITY_SIZE, stdin);
					taskArray[i].priority[strcspn(taskArray[i].priority, "\n")] = '\0';

					//User input validation.
					if (strcmp(taskArray[i].priority, "LOW") == 0 || strcmp(taskArray[i].priority, "MED") == 0 || strcmp(taskArray[i].priority, "HIGH") == 0)
					{
						break;
					}
					printf("INVALID PRIORITY! Please enter LOW, MED, or HIGH: ");
				}

				printf("Task priority updated succesfully.\n");
				return;
			}
		}
	}

	printf("Task ID not found!\n");
	return;
}

void displayTasks(Task* taskArray,int taskCount)
{
	//Exiting function if no tasks are present.
	if (taskCount == 0) 
	{
		printf("No tasks available to display.\n");
		return;
	}

	//Displaying menu with all tasks
	printf("----------------------------------------------------\n");
	printf("                    TO DO LIST\n");
	printf("----------------------------------------------------\n");
	//Iterating through taskArray and displaying each element in a formatted manner.
	for (int i = 0; i < taskCount; i++) {
		printf("-----------------------------------------------------------------------------\n");
		printf("ID: %d\tDescription: %s\tPriority: %s\tStatus: %s\n", taskArray[i].id, taskArray[i].description, taskArray[i].priority, taskArray[i].status);
		printf("-----------------------------------------------------------------------------\n");
	}
}

void markAsCompleted(Task* taskArray, int taskCount)
{
	int taskId; //Variable to hold taskId user input.
	char input[INPUT_SIZE]; //Temporary variable for input validation.

	//Exiting function if no tasks available.
	if(taskCount == 0)
	{
		printf("No tasks available to mark as completed.\n");
		return;
	}

	//User input validation.
	while (1)
	{
		printf("Enter Task ID: ");
		fgets(input, sizeof(input), stdin);

		if (sscanf_s(input, "%d", &taskId) != 1 || taskId <= 0)
		{
			printf("INVALID INPUT! Please enter a valid positive number.\n");
			continue;
		}
		break;
	}
	
	//Iterating through taskArray to find the task with the user ID input.
	for (int i = 0; i < taskCount; i++) {
		if (taskArray[i].id == taskId) {
			if (strcmp(taskArray[i].status, "Completed") == 0) {
				//Exiting function if task is already completed.
				printf("This task is already completed!\n");
				return;
			}
			//Updating status of the task to "Completed"
			strcpy_s(taskArray[i].status, STATUS_SIZE, "Completed");
			printf("Task %d completed. Congratulations!\n", taskId);
			return;
		}
	}
	printf("Task ID not found!\n");
}


void filterTasks(Task* taskArray, int taskCount)
{ 
	int userChoice; //Variable to hold user input
	char input[INPUT_SIZE]; //Temporary variable for input validation.

	//Exiting function if no tasks are available.
	if (taskCount == 0)
	{
		printf("No tasks available to filter.\n");
		return;
	}

	//User input validation.
	while (1)
	{
		printf("Filter by:\n1. Priority\n2. Status\nEnter Choice: ");
		fgets(input, sizeof(input), stdin);

		if (sscanf_s(input, "%d", &userChoice) != 1 || (userChoice != 1 && userChoice != 2))
		{
			printf("INVALID INPUT! Please enter 1 or 2.\n");
			continue;
		}
		break;
	}

	//Code if user would like to filter by priority.
	if (userChoice == 1) {
		char filterPriority[PRIORITY_SIZE]; //Variable to hold user input for priority.
		
		//User input validation.
		while (1)
		{
			//Prompt for user to enter the priority they would like to filter by
			printf("Enter the priority to filter by (LOW, MED, HIGH): ");
			fgets(filterPriority, PRIORITY_SIZE, stdin);
			filterPriority[strcspn(filterPriority, "\n")] = '\0';

			if (strcmp(filterPriority, "LOW") == 0 || strcmp(filterPriority, "MED") == 0 || strcmp(filterPriority, "HIGH") == 0) 
			 {
				break;
			 }
			printf("INVALID PRIORITY! Please enter LOW, MED, or HIGH.\n");
		}
		//Display formatting to show the desired information.
		printf("----------------------------------------------------\n");
		printf("		TASKS WITH PRIORITY: %s\n", filterPriority);
		printf("----------------------------------------------------\n");

		int found = 0; //Variable that tracks whether or not a task with the priority is present.
		//Iterating through taskArray.
		for (int i = 0; i < taskCount; i++) {
			//Condition to check if priority of each task is equal to the user's input. (_stricmp avoids case sensitivity).
			if (_stricmp(taskArray[i].priority, filterPriority) == 0) {
				//Display formatting to show the desired information.
				printf("---------------------------------------------------------------------\n");
				printf("ID: %d\tDescription: %s\tPriority: %s\tStatus: %s\n",
					taskArray[i].id, taskArray[i].description,
					taskArray[i].priority, taskArray[i].status);
				printf("---------------------------------------------------------------------\n");
				found = 1; //Updating the "found" variable since a task was found.
			}
		}
		//Displaying a message to the user if no task was found with the provided parameters.
		if (!found) 
		{
			printf("No task found with that priority.\n");
		}
	}
	//Code to filter tasks by status.
	else if (userChoice == 2) 
	{
		char filterStatus[STATUS_SIZE]; //Variable to hold user input for status.

		//User input validation.
		while (1)
		{
			printf("Enter the status to filter by (to-do, Completed): ");
			fgets(filterStatus, STATUS_SIZE, stdin);
			filterStatus[strcspn(filterStatus, "\n")] = '\0';
			if (strcmp(filterStatus, "to-do") == 0 || strcmp(filterStatus, "Completed") == 0) 
			{
				break;
			}
			printf("INVALID STATUS! Please enter 'to-do' or 'Completed'.\n");
		}
		//Display formatting
		printf("----------------------------------------------------\n");
		printf("		TASKS WITH STATUS: %s\n", filterStatus);
		printf("----------------------------------------------------\n");

		int found = 0; //Variable to track whether a task was found with the given status.
		//Iterating through taskArray.
		for (int i = 0; i < taskCount; i++) {
			//Condition to check if each task's status is equal to the user input. 
			if (_stricmp(taskArray[i].status, filterStatus) == 0) 
			{
				printf("----------------------------------------------------------------------\n");
				printf("ID: %d\tDescription: %s\tPriority: %s\tStatus: %s\n",
					taskArray[i].id, taskArray[i].description,
					taskArray[i].priority, taskArray[i].status);
				printf("----------------------------------------------------------------------\n");
				found = 1; //Updating found variable since a task was found
			}
		}
		//Displaying message to the user since no tasks met the parameters defined by the user.
		if (!found)
		{
			printf("No tasks found with that status.\n");
		}
	}
}