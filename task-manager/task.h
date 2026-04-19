#ifndef TASK_H
#define TASK_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define DESC_SIZE 50
#define PRIORITY_SIZE 6
#define STATUS_SIZE 12

typedef struct {
    int id;
    char description[DESC_SIZE];
    char priority[PRIORITY_SIZE];
    char status[STATUS_SIZE];
} Task;


/* Function Prototypes */

void addTask(Task** taskArray, int* taskCount);

void removeTask(Task* taskArray, int* taskCount);

void updateTask(Task* taskArray, int taskCount);

void displayTasks(Task* taskArray, int taskCount);

void markAsCompleted(Task* taskArray, int taskCount);

void filterTasks(Task* taskArray, int taskCount);
/*

void loadTasksFromFile(Task** taskArray, int* taskCount);*/

#endif