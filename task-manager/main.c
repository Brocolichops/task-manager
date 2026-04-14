#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

void addTask(int id, char name[25], char priority[4], char completion_status[10], char* task_array);
void removeTask();
void updateTask();
void displayTasks();
void markAsCompleted();
void filterTasks();

int main() {


	printf("----------WELCOME----------\n");
	char *task_array = malloc(43);
	bool running = true;
	int userChoice;
	while (running) {
		printf("1. Add a task\n2. Remove a task\n3. Update a task\n4. Display all tasks\n5. Mark as completed\n6. Filter tasks\n9 to QUIT PROGRAM\n");;
		printf("Enter your choice: ");
		scanf_s("%d", &userChoice);

		int id;
		char name[25];

		char priority[4];
		char completion_status[10];
		switch (userChoice) {
		case 1:
			printf("ID: ");
			scanf_s("%d", &id);
			getchar();

			printf("Name: ");
			fgets(name, 25, stdin);

			printf("Priority (LOW, MED OR HIGH): ");
			fgets(priority, 4, stdin);

			strcpy(completion_status, "to-do");
			addTask(id, name, priority, completion_status, *task_array);

			break;

		case 2:
			removeTask();
			break;

		case 3:
			updateTask();
			break;

		case 4:
			displayTasks();
			break;

		case 5:
			markAsCompleted();
			break;

		case 6: 
			filterTasks();
			break;

		case 9:
			running = false;
			printf("EXITING PROGRAM!");
			break;
		default:
			printf("INVALID INPUT! Please enter a number from 1-6 or 9 to QUIT\n");
			continue;
		}

	}

	return 0;
}

void addTask(int id, char name[25], char priority[4], char completion_status[10], char* task_array){

	return;
}

void removeTask() {
	return;
}

void updateTask() {
	return;
}

void displayTasks() {

	return;
}

void markAsCompleted() {

	return;
}

void filterTasks() {

	return;
}