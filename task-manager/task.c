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


	printf("Enter Task ID: ");
	scanf_s("%d", &newTask->id);
	getchar();


	printf("Enter Description: ");
	fgets(newTask->description, DESC_SIZE, stdin);

	newTask->description[strcspn(newTask->description, "\n")] = '\0';


	printf("Enter Priority (LOW, MED, HIGH): ");
	fgets(newTask->priority, PRIORITY_SIZE, stdin);

	newTask->priority[strcspn(newTask->priority, "\n")] = '\0';

	strcpy_s(newTask->status, STATUS_SIZE, "to-do");
	(*taskCount)++;

	printf("Task added successfully.\n");
}



void removeTask(Task* taskArray, int* taskCount)
{
	int id;

	printf("Enter ID to remove: ");
	scanf_s("%d", &id);

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
	printf("Enter id of task: ");
	scanf_s("%d", &id);
	
	for (int i = 0; i < taskCount; i++) {
		
		if (taskArray[i].id == id) {
			printf("Task ID found!\nWhat would you like to update?\n1. Task name\n2. Task priority\nEnter number: ");
			scanf_s("%d", &userChoice);
			getchar();

			if (userChoice == 1) {
				printf("Current description: %s\n", taskArray[i].description);

				printf("Enter new description: ");
				fgets(taskArray[i].description, DESC_SIZE, stdin);

				taskArray[i].description[strcspn(taskArray[i].description, "\n")] = '\0';

				printf("Task description sucessfully.\n");
				return;
			}
			else if (userChoice == 2) {
				printf("Current priority: %s\n", taskArray[i].priority);

				printf("Enter new priority (LOW, MED OR HIGH): ");
				fgets(taskArray[i].priority, PRIORITY_SIZE, stdin);

				taskArray[i].priority[strcspn(taskArray[i].priority, "\n")] = '\0';

				printf("Task priority updated succesfully.\n");
				return;
			}
			else {
				printf("Invalid input. Returning to menu...\n");
				return;
			}
		}
	}
	printf("Task ID not found!\n");
	return;
}

void displayTasks(Task* taskArray,int taskCount)
{
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
	printf("Enter Task ID: ");
	scanf_s("%d", &taskId);
	getchar();

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
	printf("Filter by:\n1. Priority\n2. Status\nEnter Choice: ");
	scanf_s("%d", &userChoice);
	getchar();

	if (userChoice == 1) {
		char filterPriority[PRIORITY_SIZE];
		printf("Enter the priority to filter by (LOW, MED, HIGH): ");
		fgets(filterPriority, PRIORITY_SIZE, stdin);
		filterPriority[strcspn(filterPriority, "\n")] = '\0';

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
		if (!found) printf("No task found with that priority.\n");
	}
	else if (userChoice == 2) {
		char filterStatus[STATUS_SIZE];
		printf("Enter status to filter by (to-do, Completed): ");
		fgets(filterStatus, STATUS_SIZE, stdin);
		filterStatus[strcspn(filterStatus, "\n")] = '\0';

		printf("----------------------------------------------------\n");
		printf("		TASKS WITH STATUS: %s\n", filterStatus);
		printf("----------------------------------------------------\n");

		int found = 0;
		for (int i = 0; i < taskCount; i++) {
			if (_stricmp(taskArray[i].status, filterStatus) == 0) {
				printf("----------------------------------------------------------------------\n");
				printf("ID: %d\tDescription: %s\tPriority: %s\tStatus: %s\n",
					taskArray[i].id, taskArray[i].description,
					taskArray[i].priority, taskArray[i].status);
				printf("----------------------------------------------------------------------\n");
				found = 1;
			}
		}
		if (!found) printf("No tasks found with that status.\n");
	}
	else {
		printf("Invalid Choice. Returning to menu\n");
	}
}
