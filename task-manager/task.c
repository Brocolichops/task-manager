#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "task.h"


void addTask(Task** taskArray, int* taskCount)
{
	Task* temp;

	temp = realloc(*taskArray, (*taskCount + 1) * sizeof(Task));

	if (temp == NULL) {
		printf("Memory allocation failed.\n");
		return;
	}

	*taskArray = temp;
	Task* newTask = &((*taskArray)[*taskCount]);

	char input[INPUT_SIZE];
	while (1)
	{
		printf("Enter Task ID: ");
		fgets(input, sizeof(input), stdin);

		input[strcspn(input, "\n")] = '\0';

		if (sscanf_s(input, "%d", &newTask->id) != 1 || newTask->id <= 0)
		{
			printf("INVALID INPUT! Please enter a valid positive number for Task ID.\n");
			continue;
		}
		break;
	}


	printf("Enter Description: ");
	fgets(newTask->description, DESC_SIZE, stdin);

	newTask->description[strcspn(newTask->description, "\n")] = '\0';


	printf("Enter Priority (LOW, MED, HIGH): ");
	while (1)
	{
		fgets(newTask->priority, PRIORITY_SIZE, stdin);
		newTask->priority[strcspn(newTask->priority, "\n")] = '\0';

		if (_stricmp(newTask->priority, "LOW") == 0 || _stricmp(newTask->priority, "MED") == 0 || _stricmp(newTask->priority, "HIGH") == 0)
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
	int id;
	char input[INPUT_SIZE];
	if (*taskCount == 0) {
		printf("No tasks to remove.\n");
		return;
	}

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

	for (int i = 0; i < *taskCount; i++)
	{
		if (taskArray[i].id == id)
		{
			for (int j = i; j < *taskCount - 1; j++)
			{
				taskArray[j] = taskArray[j + 1];
			}

			(*taskCount)--;

			printf("Task removed.\n");
			return;
		}
	}

	printf("Task not found.\n");
}

void updateTask(Task* taskArray, int taskCount)
{
	int id;
	int userChoice;
	char input[INPUT_SIZE];

	if (taskCount == 0) 
	{
		printf("No tasks to update.\n");
		return;
	}

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
	
	
	for (int i = 0; i < taskCount; i++) {
		
		if (taskArray[i].id == id) {
			printf("Task ID found!\n");

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

			if (userChoice == 1) {
				printf("Current description: %s\n", taskArray[i].description);

				printf("Enter new description: ");
				fgets(taskArray[i].description, DESC_SIZE, stdin);

				taskArray[i].description[strcspn(taskArray[i].description, "\n")] = '\0';

				printf("Task description sucessfully updated.\n");
				return;
			}

			else if (userChoice == 2) {
				printf("Current priority: %s\n", taskArray[i].priority);

				while (1)
				{
					printf("Enter new priority (LOW, MED, OR HIGH): ");
					fgets(taskArray[i].priority, PRIORITY_SIZE, stdin);
					taskArray[i].priority[strcspn(taskArray[i].priority, "\n")] = '\0';

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
	if (taskCount == 0) 
	{
		printf("No tasks available to display.\n");
		return;
	}

	printf("----------------------------------------------------\n");
	printf("                    TO DO LIST\n");
	printf("----------------------------------------------------\n");
	for (int i = 0; i < taskCount; i++) {
		printf("-----------------------------------------------------------------------------\n");
		printf("ID: %d\tDescription: %s\tPriority: %s\tStatus: %s\n", taskArray[i].id, taskArray[i].description, taskArray[i].priority, taskArray[i].status);
		printf("-----------------------------------------------------------------------------\n");
	}
}

void markAsCompleted(Task* taskArray, int taskCount)
{
	int taskId;
	char input[INPUT_SIZE];

	if(taskCount == 0)
	{
		printf("No tasks available to mark as completed.\n");
		return;
	}

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
	
	for (int i = 0; i < taskCount; i++) {
		if (taskArray[i].id == taskId) {
			strcpy_s(taskArray[i].status, STATUS_SIZE, "Completed");
			printf("Task %d completed. Congratulations!\n", taskId);
			return;
		}
	}
	printf("Task ID not found!\n");
}


void filterTasks(Task* taskArray, int taskCount)
{ 
	int userChoice;
	char input[INPUT_SIZE];

	if (taskCount == 0)
	{
		printf("No tasks available to filter.\n");
		return;
	}

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

	if (userChoice == 1) {
		char filterPriority[PRIORITY_SIZE];
		
		while (1)
		{
			printf("Enter the priority to filter by (LOW, MED, HIGH): ");
			fgets(filterPriority, PRIORITY_SIZE, stdin);
			filterPriority[strcspn(filterPriority, "\n")] = '\0';

			if (strcmp(filterPriority, "LOW") == 0 || strcmp(filterPriority, "MED") == 0 || strcmp(filterPriority, "HIGH") == 0) 
			 {
				break;
			 }
			printf("INVALID PRIORITY! Please enter LOW, MED, or HIGH.\n");
		}

		printf("----------------------------------------------------\n");
		printf("		TASKS WITH PRIORITY: %s\n", filterPriority);
		printf("----------------------------------------------------\n");

		int found = 0;
		for (int i = 0; i < taskCount; i++) {
			if (_stricmp(taskArray[i].priority, filterPriority) == 0) {
				printf("---------------------------------------------------------------------\n");
				printf("ID: %d\tDescription: %s\tPriority: %s\tStatus: %s\n",
					taskArray[i].id, taskArray[i].description,
					taskArray[i].priority, taskArray[i].status);
				printf("---------------------------------------------------------------------\n");
				found = 1;
			}
		}
		if (!found) 
		{
			printf("No task found with that priority.\n");
		}
	}
	else if (userChoice == 2) 
	{
		char filterStatus[STATUS_SIZE];

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

		printf("----------------------------------------------------\n");
		printf("		TASKS WITH STATUS: %s\n", filterStatus);
		printf("----------------------------------------------------\n");

		int found = 0;
		for (int i = 0; i < taskCount; i++) {
			if (_stricmp(taskArray[i].status, filterStatus) == 0) 
			{
				printf("----------------------------------------------------------------------\n");
				printf("ID: %d\tDescription: %s\tPriority: %s\tStatus: %s\n",
					taskArray[i].id, taskArray[i].description,
					taskArray[i].priority, taskArray[i].status);
				printf("----------------------------------------------------------------------\n");
				found = 1;
			}
		}
		if (!found)
		{
			printf("No tasks found with that status.\n");
		}
	}
}