#include <stdio.h>
#include <stdbool.h>
void addTask();
void removeTask();
void updateTask();
void displayTasks();
void markAsCompleted();
void filterTasks();

int main() {


	printf("----------WELCOME----------\n");

	bool running = true;
	int userChoice;
	while (running) {
		printf("1. Add a task\n2. Remove a task\n3. Update a task\n4. Display all tasks\n5. Mark as completed\n6. Filter tasks\n9 to QUIT PROGRAM\n");;
		printf("Enter your choice: ");
		scanf_s("%d", &userChoice);


		switch (userChoice) {
		case 1:
			addTask();
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

void addTask() {

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