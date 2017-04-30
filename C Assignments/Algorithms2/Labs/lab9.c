/*
Title:	lab9.c
Author:	Dilpreet Chana
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Structs
struct student {
   int ID;
   char name[40];
   struct student *next;
};
typedef struct student Student;

//Prototypes
int getChoice();                    //display the menu and get the user choice
Student *addToList(Student *List);  //add the user given information to the linked list
void printList(Student *List);      //print the contents of the list from beginning to end
void printListRR(Student *List);    //print the contents of the list from the end to the beginning recursively
void searchList(Student *List);     //search the list using a ID given by the user

int main()
{
    	int choice = 0;
   	Student *SLIST = NULL;

    	choice = getChoice();

    	while(choice >= 0) {
		switch(choice) {
		case 0 : exit(0);
		case 1 : SLIST = addToList(SLIST); break;
		case 2 : printList(SLIST); break;
		case 3 : printListRR(SLIST); break;
		case 4 : searchList(SLIST); break;
		default: printf("Invalid choice\n");
		}
		choice = getChoice();
	}

    	if(SLIST) free(SLIST);
    	return 0;
}

/* 
  Objective: Display the menu and get the user choice
  Input: none
  Output: the user choice
*/
int getChoice()
{
    int choice = 0;

    printf("1. Add new student to list.\n");
    printf("2. Print the student list, beginning to end.\n");
    printf("3. Recursively print the student list from the end.\n");
    printf("4. Search the list for a student.\n");
    printf("0. Quit.\n");
    printf("\nEnter your choice: ");

    scanf("%d", &choice);

    return choice;
}

/* 
  Objective: Add the user given information to the linked list
  Input: a pointer to the linked list
  Output: a pointer to the linked list
*/
Student *addToList(Student *List) {
	int id;
	char name[40];

	printf("Enter ID and Name of student (ID Name): ");
	scanf("%d %s", &id, name);

    	if(List == NULL)    //case 1: the linked list is empty we need to make a root pointer
    	{
		List = malloc(sizeof(Student)) ;
		List->ID = id;
		strcpy((List->name),name); 
		List->next = NULL; 

    	}
    
    	else {              //Case 2: add to the end of a linked list
		Student * NPtr = List;
		while (NPtr->next != NULL)
		{
	    		NPtr = NPtr->next;
		}
		Student *NodePtr = malloc(sizeof(Student));

		NodePtr->ID = id;
		strcpy((NodePtr->name),name);

		NPtr->next = NodePtr;
		NPtr = NodePtr;
		NPtr->next = NULL;
    	}

    	return List;
}

/* 
  Objective: Print the contents of the list from beginning to end
  Input: a pointer to the linked list
  Output: print the contents of the list
*/
void printList(Student *List)
{
    Student * current = List;

    while (current != NULL)
    {
	printf("%d %s\n", current->ID, current->name);
	current = current->next;
    }

    return;
}

/* 
  Objective: Print the contents of the list from the end to the beginning recursively
  Input: a pointer to the linked list
  Output: print the contents of the list
*/
void printListRR(Student *List)
{
    if(List == NULL)
	return;

    printListRR(List->next);
    printf("%d %s\n", List->ID, List->name);

    return;
}

/* 
  Objective: Search the list using a ID given by the user
  Input: a pointer to the linked list
  Output: print the found element if it exists
*/
void searchList(Student *List)
{
    Student * current = List;

    int id;

    printf("Enter ID: ");
    scanf("%d", &id);

    while (current != NULL)
    {
	if(current->ID == id)
	{
	    printf("%d %s\n", current->ID, current->name);
	    return;
	}
	current = current->next;
    }

    printf("ID \"%d\" not found\n", id);
    return;
}
