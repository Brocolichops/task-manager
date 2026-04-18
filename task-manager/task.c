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
	printf("displayTasks not implemented yet.\n");
}

void markAsCompleted(Task* taskArra, int taskCount)
{
	printf("markAsCompleted not implemented yet.\n");
}


void filterTasks(Task* taskArray, int taskCount)
{ 
	printf("filterTasks not implemented yet.\n");
}
