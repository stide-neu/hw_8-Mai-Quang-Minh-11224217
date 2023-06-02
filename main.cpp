#include <stdio.h>
#include <string.h>

struct student {
    char name[20];
    int eng;
    int math;
    int phys;
    char grade;
};

void get_student_info(struct student *s) {
    printf("Enter student name: ");
    scanf("%s", s->name);
    printf("Enter English score: ");
    scanf("%d", &s->eng);
    printf("Enter Math score: ");
    scanf("%d", &s->math);
    printf("Enter Physics score: ");
    scanf("%d", &s->phys);
}

char compute_grade(int mean) {
    if (mean >= 90) {
        return 'S';
    } else if (mean >= 80) {
        return 'A';
    } else if (mean >= 70) {
        return 'B';
    } else if (mean >= 60) {
        return 'C';
    } else {
        return 'D';
    }
}

void show_student_info(struct student s) {
    printf("Name: %s\n", s.name);
    printf("English score: %d\n", s.eng);
    printf("Math score: %d\n", s.math);
    printf("Physics score: %d\n", s.phys);
    printf("Grade: %c\n", s.grade);
}

int main() {
    int n;
    printf("Enter number of students: ");
    scanf("%d", &n);

    struct student students[n];

    for (int i = 0; i < n; i++) {
        printf("Enter information for student %d:\n", i + 1);
        get_student_info(&students[i]);
        float mean = (float)(students[i].eng + students[i].math + students[i].phys) / 3.0;
        printf("Mean score for %s is %.2f\n", students[i].name, mean);
        students[i].grade = compute_grade(mean);
    }

    for (int i = 0; i < n; i++) {
        printf("\nInformation for student %d:\n", i + 1);
        
        show_student_info(students[i]);
    }

    return 0;
}
