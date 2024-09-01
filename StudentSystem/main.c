#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int facultyNumber;
    char fullName[50];
    char specialty[11];
    char birthdDate[11];
    int course;
    char gender;
    int grade;

}Student;

int CountStudentsInFile(const char* filename)
{
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

*Student readStudentsFromFile(const char* filename, int* studentCount)
{
    *studentCount = CountStudentsInFile(filename);
    if (*studentCount <= 0)
    {
        printf("Can't open the file.")
        return NULL;
    }

    Student* students = (Student*)malloc(studentCount*sizeof(Student));

    if (!students)
    {
        printf("Insufficient memory");
    }

    FILE* file = fopen(filename,"r");

    if (!file)
    {
        printf("Can't open the file");
        free(students);
        return NULL;
    }


    for(int i=0,i<*studentCount,i++)
    {
        fscanf(file, "%s %d %s %s %d %c %d",
            students[i].name,
           &students[i].facultyNumber,
           students[i].specialty,
           students[i].birthDate,
           &students[i].course,
           &students[i].gender,
           &students[i].grade);
    }
    fclose(file);
    return students;
}

*Student filteredStudents(*Student students, int* studentCount, const char* speciality, char gender, int birthYear, int* filderedCount )
{
    Student* filteredStudents = (Student*)malloc(studentCount*sizeof(Student));
    if (!filteredStudents)
    {
        printf("Insufficient memory");
        return NULL;
    }

    *filteredCount = 0;
    for(int i=0; i<studentCount; i++)
    {
        sscanf(students[i].birthDate+6,"%d",&studentBirthYear);
        if (strcmp(students[i].specialty, specialty) == 0 && students[i].gender == gender && studentBirthYear > birthYear) {
            filteredStudents[(*filteredCount)++] = students[i];
        }
    }

    if (*filteredCount == 0) {
        free(filteredStudents);
        return NULL;
    }

    return filteredStudents;

}

int main()
{

}


