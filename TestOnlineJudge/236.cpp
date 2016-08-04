//
// Created by Wayne Tu on 5/15/16.
//

struct Student;
void swap(Student& student1, Student& student2) {
    Student temp;
    temp = student1;
    student1 = student2;
    student2 = temp;
}

void admissionListSort(Student student[], int sizeOfStudent) {
    for (int i = 0; i < sizeOfStudent; ++i) {
        for (int j = i + 1; j < sizeOfStudent; ++j) {
            if (student[i].score > student[j].score) {
                swap(student[i], student[j]);
            }
            else if (student[i].name > student[j].name) {
                swap(student[i], student[j]);
            }
        }
    }
}