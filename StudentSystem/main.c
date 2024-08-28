#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int facultyNumber;
    char fullName[50];
    char specialty[11];
    char birthday[11];
    int course;
    char gender;
    int grade;

}Student;

int CountStudentsInFile(const char* filename){
    FILE* file = fopen(filename, "r");
    if (!file){
        printf("Can't open the file: %s\n",filename);
        return -1;
    }

    int count = 0;
    char buffer[200];
    while (fgets(buffer, sizeof(buffer), file)) {
        count++;
    }

    fclose(file);
    return count;
}

int main()
{
//    Student studenta = {501218049, "Vasil", "ITI", "14.08.1899", 2, 'M', 5};
//    printf("Faculty number: %d\n", studenta.facultyNumber);
//    printf("Fullname: %s\n", studenta.fullName);
//    printf("Specialty: %s\n", studenta.specialty);
//    printf("Birthday: %s\n", studenta.birthday);
//    printf("Course: %d\n", studenta.course);
//    printf("Gender: %c\n", studenta.gender);
//    printf("Grade: %d\n", studenta.grade);
//    return 0;
    const char* filename = "students.txt";
    int studentCount = CountStudentsInFile(filename);

    if (studentCount != -1) {
        printf("Current count in file %s is: %d\n", filename, studentCount);
    }
}


