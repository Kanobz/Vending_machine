#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Student {
    char FirstName[50];
    char LastName[50];
    int StudentID;
    float SubjectMarks[5];
    int AggregateMarks;
    char Grade[12];
};

int validateInput() {
    int num;
    char buffer[256];
    while (1) {
        if (fgets(buffer, sizeof(buffer), stdin)) {
            if (sscanf(buffer, "%d", &num) == 1) {
                return num;
            } else {
                printf("Invalid input. Please enter a valid number: ");
            }
        } else {
            printf("Error reading input. Please try again: ");
        }
    }
}

void searchAndUpdate(struct Student students[], int numOfStudents) {
    char searchChoice[5];
    printf("Search by StudentID or LastName? (ID/Name): ");
    scanf("%s", searchChoice);

    if (strcmp(searchChoice, "ID") == 0) {
        int searchID;
        printf("Enter StudentID to search: ");
        searchID = validateInput();

        for (int i = 0; i < numOfStudents; ++i) {
            if (students[i].StudentID == searchID) {
                // Print student attributes
                printf("Student Found:\n");
                printf("Name: %s %s\n", students[i].FirstName, students[i].LastName);
                printf("Student ID: %d\n", students[i].StudentID);
                printf("Aggregate Marks: %d\n", students[i].AggregateMarks);
                printf("Grade: %s\n", students[i].Grade);

                // Prompt for attribute update
                char updateChoice[2];
                printf("Do you want to update any attributes? (y/n): \n");
                scanf("%s", updateChoice);

                if (strcmp(updateChoice, "y") == 0) {
                    printf("Update FirstName: ");
                    scanf("%s", students[i].FirstName);

                    printf("Update LastName: ");
                    scanf("%s", students[i].LastName);

                    printf("Update Student ID: ");
                    students[i].StudentID = validateInput();

                    // Update AggregateMarks and Grade
                    students[i].AggregateMarks = 0;
                    for (int j = 0; j < 5; ++j) {
                        if (students[i].SubjectMarks[j] != -1) {
                            students[i].AggregateMarks += students[i].SubjectMarks[j];
                        }
                    }

                    if (students[i].AggregateMarks >= 85) {
                        strcpy(students[i].Grade, "HD");
                    } else if (students[i].AggregateMarks >= 75) {
                        strcpy(students[i].Grade, "D");
                    } else if (students[i].AggregateMarks >= 65) {
                        strcpy(students[i].Grade, "C");
                    } else if (students[i].AggregateMarks >= 50) {
                        strcpy(students[i].Grade, "P");
                    } else {
                        strcpy(students[i].Grade, "F");
                    }

                    printf("Attributes updated successfully.\n");
                }

                return;  // Exit the function if the student is found
            }
        }
    } else if (strcmp(searchChoice, "Name") == 0) {
        char searchLastName[50];
        printf("Enter LastName to search: ");
        scanf("%s", searchLastName);

        for (int i = 0; i < numOfStudents; ++i) {
            if (strcasecmp(students[i].LastName, searchLastName) == 0) {
                // Print student attributes
                printf("Student Found:\n");
                printf("Name: %s %s\n", students[i].FirstName, students[i].LastName);
                printf("Student ID: %d\n", students[i].StudentID);
                printf("Aggregate Marks: %d\n", students[i].AggregateMarks);
                printf("Grade: %s\n", students[i].Grade);

                // Prompt for attribute update
                char updateChoice[5];
                printf("Do you want to update any attributes? (Yes/No): ");
                scanf("%s", updateChoice);

                if (strcmp(updateChoice, "Yes") == 0) {
                    printf("Update FirstName: ");
                    scanf("%s", students[i].FirstName);

                    printf("Update LastName: ");
                    scanf("%s", students[i].LastName);

                    printf("Update Student ID: ");
                    students[i].StudentID = validateInput();

                    // Update AggregateMarks and Grade
                    students[i].AggregateMarks = 0;
                    for (int j = 0; j < 5; ++j) {
                        if (students[i].SubjectMarks[j] != -1) {
                            students[i].AggregateMarks += students[i].SubjectMarks[j];
                        }
                    }

                    if (students[i].AggregateMarks >= 85) {
                        strcpy(students[i].Grade, "HD");
                    } else if (students[i].AggregateMarks >= 75) {
                        strcpy(students[i].Grade, "D");
                    } else if (students[i].AggregateMarks >= 65) {
                        strcpy(students[i].Grade, "C");
                    } else if (students[i].AggregateMarks >= 50) {
                        strcpy(students[i].Grade, "P");
                    } else {
                        strcpy(students[i].Grade, "F");
                    }

                    printf("Attributes updated successfully.\n");
                }

                return;  // Exit the function if the student is found
            }
        }
    }

    // Print "unfound" if no match is found
    printf("Student not found.\n");
}

void TopScorers(struct Student students[], int numOfStudents) {
    // Find the highest AggregateMarks
    int highestMarks = -1;
    for (int i = 0; i < numOfStudents; ++i) {
        if (students[i].AggregateMarks > highestMarks) {
            highestMarks = students[i].AggregateMarks;
        }
    }

    // Print details of students with the highest AggregateMarks
    printf("Top Scorers:\n");
    for (int i = 0; i < numOfStudents; ++i) {
        if (students[i].AggregateMarks == highestMarks) {
            printf("Name: %s %s\n", students[i].FirstName, students[i].LastName);
            printf("Student ID: %d\n", students[i].StudentID);
            printf("Aggregate Marks: %d\n", students[i].AggregateMarks);
            printf("Grade: %s\n", students[i].Grade);
            printf("\n");
        }
    }
}

int main() {
    const int MAX_STUDENTS = 3;
    int numOfSubjects = 3;
    struct Student students[MAX_STUDENTS];

    for (int i = 0; i < MAX_STUDENTS; ++i) {
        printf("\n\nHi! Enter details for student %d:\n", i + 1);

        printf("First Name: ");
        scanf("%s", students[i].FirstName);

        printf("Last Name: ");
        scanf("%s", students[i].LastName);

        printf("Student ID: ");
        students[i].StudentID = validateInput();
        
        printf("\n\n");

        // Initialize SubjectsMarks to -1
        for (int j = 0; j < numOfSubjects; ++j) {
            students[i].SubjectMarks[j] = -1;
        }
    }

    int menu;

    while (1) {
        printf("\n\nHi! Welcome to the UOWD Records list of Year 2 Students! \n\nWhat would you like to do? \n");
        printf("1. Enroll a new marks for student \n");
        printf("2. Search and/or update student records \n");
        printf("3. Look at the list of students with the highest aggregate marks\n");
        printf("4. Exit \n\n");
        printf("Select an option: ");
        scanf("%d", &menu);

        switch (menu) {
            case 1: //Enrolling the grades
                printf("Enter Student ID: ");
                scanf("%d", &students[MAX_STUDENTS - 1].StudentID);

                printf("\nDo you want to input the student's subject mark? (y/n) \n");
                char choice[1];
                scanf("%s", choice);

                while (strcmp(choice, "y") == 0) {
                    printf("Enter subject number (0 to %d): ", numOfSubjects - 1);
                    int subjectNum = validateInput();

                    if (subjectNum >= 0 && subjectNum < numOfSubjects) {
                        printf("Enter subject mark %d: ", subjectNum);
                        students[MAX_STUDENTS - 1].SubjectMarks[subjectNum] = validateInput();
                        printf("\n");
                        
                    } else {
                        printf("Invalid subject number. Please enter a number between 0 and %d.\n", numOfSubjects - 1);
                    }
                    printf("Would you like to put marks for another subject? (y/n): ");
                    scanf("%s", choice);
                }

                students[MAX_STUDENTS - 1].AggregateMarks = 0;
                int undefined = 0;

                for (int j = 0; j < numOfSubjects; ++j) {
                    if (students[MAX_STUDENTS - 1].SubjectMarks[j] != -1) {
                        students[MAX_STUDENTS - 1].AggregateMarks += students[MAX_STUDENTS - 1].SubjectMarks[j];
                    } else {
                        undefined = 1;
                    }
                }

                if (undefined) {
                    strcpy(students[MAX_STUDENTS - 1].Grade, "undefined");
                    students[MAX_STUDENTS - 1].AggregateMarks = -1;
                } else if (students[MAX_STUDENTS - 1].AggregateMarks >= 85 && students[MAX_STUDENTS - 1].AggregateMarks <= 100) {
                    strcpy(students[MAX_STUDENTS - 1].Grade, "HD");
                } else if (students[MAX_STUDENTS - 1].AggregateMarks >= 75) {
                    strcpy(students[MAX_STUDENTS - 1].Grade, "D");
                } else if (students[MAX_STUDENTS - 1].AggregateMarks >= 65) {
                    strcpy(students[MAX_STUDENTS - 1].Grade, "C");
                } else if (students[MAX_STUDENTS - 1].AggregateMarks >= 50) {
                    strcpy(students[MAX_STUDENTS - 1].Grade, "P");
                } else {
                    strcpy(students[MAX_STUDENTS - 1].Grade, "F");
                }

                printf("\n");

                printf("Student Records:\n");
                for (int j = 0; j < MAX_STUDENTS; ++j) {
                    printf("Student %d\n", j + 1);
                    printf("Name: %s %s\n", students[j].FirstName, students[j].LastName);
                    printf("Student ID: %d\n", students[j].StudentID);
                    printf("Aggregate Marks: %d\n", students[j].AggregateMarks);
                    printf("Grade: %s\n", students[j].Grade);
                    printf("\n");
                }

                break;

            case 2: //Search Update
                searchAndUpdate(students, MAX_STUDENTS);
                char searchChoice[3];

                printf("Student Records:\n");
                for (int j = 0; j < MAX_STUDENTS; ++j) {
                    printf("Student %d:\n", j + 1);
                    printf("Name: %s %s\n", students[j].FirstName, students[j].LastName);
                    printf("Student ID: %d\n", students[j].StudentID);
                    printf("Aggregate Marks: %d\n", students[j].AggregateMarks);
                    printf("Grade: %s\n", students[j].Grade);
                    printf("\n");
                }

                break;

            case 3: //Top Students
                TopScorers(students, MAX_STUDENTS);

                printf("Student Records:\n");
                for (int j = 0; j < MAX_STUDENTS; ++j) {
                    printf("Student %d:\n", j + 1);
                    printf("Name: %s %s\n", students[j].FirstName, students[j].LastName);
                    printf("Student ID: %d\n", students[j].StudentID);
                    printf("Aggregate Marks: %d\n", students[j].AggregateMarks);
                    printf("Grade: %s\n", students[j].Grade);
                    printf("\n");
                }

                break;

            case 4: //Exit
                printf("\nExiting the program. Thank you! \n");
                exit(0);
                break;

            default:
                printf("Invalid option. Please choose a valid option.\n");
                break;
        }
    }

    return 0;
}
