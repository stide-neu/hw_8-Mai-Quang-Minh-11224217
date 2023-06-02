#include <stdio.h>
#include <string.h>

#define MAX_STUDENTS 100
//struct//
typedef struct {
    char name[20];
    int eng;
    int math;
    int phys;
} Student;
//
void inputStudents(Student students[], int n);
void printStudents(Student students[], int n);
char getGrade(int score);

int main() {
    Student students[MAX_STUDENTS];
    int n;

    printf("Enter number of students: ");
    scanf("%d", &n);

    inputStudents(students, n);
    printf("\nStudent Information:\n");
    printStudents(students, n);

    return 0;
}
//accept the in4mation + array//
void inputStudents(Student students[], int n) {
    int i;
    for (i = 0; i < n; i++) {
        printf("\nEnter name and scores of student %d: ", i+1);
        scanf("%s %d %d %d", students[i].name, &students[i].eng, &students[i].math, &students[i].phys);
    }
}
//cal mean//
void printStudents(Student students[], int n) {
    int i;
    for (i = 0; i < n; i++) {
        float mean = (students[i].eng + students[i].math + students[i].phys) / 3.0;
        char grade = getGrade(mean);

        printf("\nName: %s\n", students[i].name);
        printf("English: %d\n", students[i].eng);
        printf("Math: %d\n", students[i].math);
        printf("Physics: %d\n", students[i].phys);
        printf("Mean: %.2f\n", mean);
        printf("Grade: %c\n", grade);
    }
}
//determine//
char getGrade(int score) {
    if (score >= 90 && score <= 100) {
        return 'S';
    } else if (score >= 80 && score < 90) {
        return 'A';
    } else if (score >= 70 && score < 80) {
        return 'B';
    } else if (score >= 60 && score < 70) {
        return 'C';
    } else {
        return 'D';
    }
}
