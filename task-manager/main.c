#include <stdio.h>
#include <stdbool.h>
void addTask();

int main() {

	printf("----------WELCOME----------\n");

	bool running = true;
	int userChoice;
	while (running) {
		printf("1. Add a task\n2. Remove a task\n3. Update a task\n4. Display all tasks\n5. Mark as completed\n6. Filter tasks\n9 to QUIT PROGRAM\n");;
		printf("Enter your choice: ");
		scanf_s("%d", &userChoice);

		if (userChoice == 9) {
			running = false; 
			printf("Exiting program!");
		}
	}

	return 0;
}