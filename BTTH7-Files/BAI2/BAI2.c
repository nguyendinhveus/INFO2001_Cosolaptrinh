#include <stdio.h>
#include <stdlib.h>

struct Student {
    char name[50];
    char id[20];
    float score;
};

void writeStudentDataToFile(const char* filename) {
    FILE* file = fopen(filename, "wb");
    if (file == NULL) {
        printf("Khong the mo file.\n");
        return;
    }

    struct Student student;

    printf("Nhap ten sinh vien: ");
    fgets(student.name, sizeof(student.name), stdin);

    printf("Nhap ma sinh vien: ");
    fgets(student.id, sizeof(student.id), stdin);

    printf("Nhap diem sinh vien: ");
    scanf("%f", &student.score);
    getchar(); // Xoa bo nho dem

    fwrite(&student, sizeof(struct Student), 1, file);

    fclose(file);
}

void readStudentDataFromFile(const char* filename) {
    FILE* file = fopen(filename, "rb");
    if (file == NULL) {
        printf("Khong the mo file.\n");
        return;
    }

    struct Student student;

    while (fread(&student, sizeof(struct Student), 1, file) == 1) {
        printf("Ten: %s", student.name);
        printf("Ma: %s", student.id);
        printf("Diem: %.2f\n", student.score);
    }

    fclose(file);
}

int main() {
    const char* filename = "student_data.txt";

    printf("GHI DU LIEU\n");
    writeStudentDataToFile(filename);

    printf("\nDOC DU LIEU\n");
    readStudentDataFromFile(filename);

    return 0;
}
