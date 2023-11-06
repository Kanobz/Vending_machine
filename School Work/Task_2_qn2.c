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
void calculateGrade(int aggregateMarks, char grade[]) {
    if (aggregateMarks >= 85) {
        strcpy(grade, "HD");
    } else if (aggregateMarks >= 75) {
        strcpy(grade, "D");
    } else if (aggregateMarks >= 65) {
        strcpy(grade, "C");
    } else if (aggregateMarks >= 50) {
        strcpy(grade, "P");
    } else {
        strcpy(grade, "F");
    }
}

void searchAndUpdate(struct Student students[], int numOfStudents) {
    char searchChoice[5];
    printf("Search by StudentID or LastName? (ID/name): ");
    scanf("%s", searchChoice);

    if (strcmp(searchChoice, "ID") == 0) {
        int searchID;
        printf("Enter StudentID to search: ");
        searchID = validateInput();

        for (int i = 0; i < numOfStudents; ++i) {
            if (students[i].StudentID == searchID) {
                printf("Student Found:\n");
                printf("Name: %s %s\n", students[i].FirstName, students[i].LastName);
                printf("Student ID: %d\n", students[i].StudentID);
                printf("Aggregate Marks: %d\n", students[i].AggregateMarks);
                printf("Grade: %s\n", students[i].Grade);

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

                return;  
            }
        }
    } else if (strcmp(searchChoice, "name") == 0) {
        char searchLastName[50];
        printf("Enter LastName to search: ");
        scanf("%s", searchLastName);

        for (int i = 0; i < numOfStudents; ++i) {
            if (strcasecmp(students[i].LastName, searchLastName) == 0) {
                printf("Student Found:\n");
                printf("Name: %s %s\n", students[i].FirstName, students[i].LastName);
                printf("Student ID: %d\n", students[i].StudentID);
                printf("Aggregate Marks: %d\n", students[i].AggregateMarks);
                printf("Grade: %s\n", students[i].Grade);

                // Prompt for attribute update
                char updateChoice[2];
                printf("Do you want to update any attributes? (y/n): ");
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

                return;
            }
        }
    }

    printf("Student not found.\n");
}


void TopScorers(struct Student students[], int numOfStudents) {
    int highestMarks = -1;
    for (int i = 0; i < numOfStudents; ++i) {
        if (students[i].AggregateMarks > highestMarks) {
            highestMarks = students[i].AggregateMarks;
        }
    }

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
    int totalStudents = 0;

    int menu;

    while (1) {
        printf("\n\nHi! Welcome to the UOWD Records list of Year 2 Students!\n");

        printf("\nWhat would you like to do?\n");
        printf("1. Enroll students\n");
        printf("2. Search and/or update student records\n");
        printf("3. Look at the list of students with the highest aggregate marks\n");
        printf("4. Exit\n\n");
        printf("Select an option: ");
        scanf("%d", &menu);

        switch (menu) {
            case 1: // Enrolling the students
                if (totalStudents >= MAX_STUDENTS) {
                    printf("Maximum number of students reached.\n");
                    break;
                }

                for (int i = 0; i < MAX_STUDENTS; ++i) {
                    printf("\n\nEnter details for student %d>>\n", i + 1);
                    printf("Student ID: ");
                    scanf("%d", &students[i].StudentID);
                    
                    printf("First Name: ");
                    scanf("%s", students[i].FirstName);

                    printf("Last Name: ");
                    scanf("%s", students[i].LastName);

                    printf("\n");

                    printf("Enter Subject Marks (0 to skip the subject, -1 to mark the subject as incomplete):\n");

                    float totalMarks = 0;

                    for (int j = 0; j < numOfSubjects; j++) {
                        printf("Subject %d: ", j + 1);
                        scanf("%f", &students[i].SubjectMarks[j]);
                        if (students[i].SubjectMarks[j] == -1) {
                            students[i].AggregateMarks = -1;
                            strcpy(students[i].Grade, "undefined");
                            break;
                        }
                        totalMarks += students[i].SubjectMarks[j];
                    }

                    if (students[i].AggregateMarks != -1) {
                        students[i].AggregateMarks = (int)(totalMarks / numOfSubjects + 0.5);
                        calculateGrade(students[i].AggregateMarks, students[i].Grade);
                    }

                    totalStudents++;
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

            case 2: // Search and/or Update
                searchAndUpdate(students, totalStudents);
                break;

            case 3: // Top Students
                TopScorers(students, totalStudents);
                break;

            case 4: // Exit
                printf("\nExiting the program. Thank you!\n");
                exit(0);
                break;

            default:
                printf("Invalid option. Please choose a valid option.\n");
                break;
        }
    }

    return 0;
}
