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

*Student filterStudents(*Student students, int* studentCount, const char* speciality, char gender, int birthYear, int* filderedCount )
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

void saveStudentsToBinary(Student* students, int count, int course, char initial) {
    FILE* file = fopen("students_info.bin", "wb");
    if (!file) {
        printf("Error in opening the binary file.\n");
        return;
    }

    // Reviewing and saving the students matched the criteria.
    for (int i = 0; i < count; i++) {
        if (students[i].course == course && students[i].name[0] == initial) {
            fwrite(&students[i], sizeof(Student), 1, file);
        }
    }

    fclose(file);
}

Student* addStudent(Student* students, int* count) {
    // Increasing the size of the array
    Student* newStudents = (Student*)realloc(students, (*count + 1) * sizeof(Student));
    if (!newStudents) {
        printf("Error increasing the array.\n");
        return NULL;
    }

    // Input data for the new student
    printf("Type data for the new student:\n");
    printf("Name: ");
    scanf(" %[^\n]", newStudents[*count].name);
    printf("Faculty number: ");
    scanf("%d", &newStudents[*count].facultyNumber);
    printf("Specialty: ");
    scanf(" %[^\n]", newStudents[*count].specialty);
    printf("Birthday (DD.MM.YYYY): ");
    scanf(" %[^\n]", newStudents[*count].birthDate);
    printf("Course: ");
    scanf("%d", &newStudents[*count].course);
    printf("Gender(M/F): ");
    scanf(" %c", &newStudents[*count].gender);
    printf("Grade: ");
    scanf("%f", &newStudents[*count].grade);

    // Saving the data to text file.
    FILE* file = fopen("students.txt", "a");
    if (!file) {
        printf("Error in opening the file for save.\n");
        return students;  // We move back to the old array if we can't save
    }

    fprintf(file, "%s;%d;%s;%s;%d;%c;%.2f\n",
            newStudents[*count].name, newStudents[*count].facultyNumber,
            newStudents[*count].specialty, newStudents[*count].birthDate,
            newStudents[*count].course, newStudents[*count].gender,
            newStudents[*count].grade);
    fclose(file);

    (*count)++;
    return newStudents;
}

int main()
{

}


