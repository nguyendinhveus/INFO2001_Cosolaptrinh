#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STUDENTS 100

struct Student {
    char name[50];
    char id[20];
    float score;
};

void writeStudentData(struct Student student) {
    FILE* file = fopen("student_data.txt", "a");
    if (file == NULL) {
        printf("Khong the mo file.\n");
        return;
    }

    fprintf(file, "%s", student.name);
    fprintf(file, "%s", student.id);
    fprintf(file, "%.2f\n", student.score);

    fclose(file);
}

void readStudentData() {
    FILE* file = fopen("student_data.txt", "r");
    if (file == NULL) {
        printf("Khong the mo file.\n");
        return;
    }

    struct Student students[MAX_STUDENTS];
    int count = 0;
    char line[100];

    while (fgets(line, sizeof(line), file) != NULL) {
        strcpy(students[count].name, line);
        fgets(students[count].id, sizeof(students[count].id), file);
        fscanf(file, "%f", &students[count].score);
        fgetc(file); 

        count++;
    }

    fclose(file);

    if (count == 0) {
        printf("Danh sach sinh vien trong.\n");
    } else {
        printf("Danh sach sinh vien:\n");
        int i; 
		for ( i = 0; i < count; i++) {
            printf("Ten: %s", students[i].name);
            printf("Ma: %s", students[i].id);
            printf("Diem: %.2f\n", students[i].score);
        }
    }
}

void updateStudentData(char *id) {
    FILE *file = fopen("student_data.txt", "r");
    if (file == NULL) {
        printf("Khong the mo file.\n");
        return;
    }

    FILE *tempFile = fopen("temp_data.txt", "w");
    if (tempFile == NULL) {
        printf("Khong the tao file tam.\n");
        fclose(file);
        return;
    }

    char line[100];
    int found = 0;
    while (fgets(line, sizeof(line), file)) {
        char *token = strtok(line, "|");
        struct Student student;
        strcpy(student.name, token);

        token = strtok(NULL, "|");
        strcpy(student.id, token);

        token = strtok(NULL, "|");
        student.score = atof(token);

        if (strcmp(student.id, id) == 0) {
            found = 1;

            printf("Nhap ten moi: ");
            fgets(student.name, sizeof(student.name), stdin);
            printf("Nhap diem moi: ");
            scanf("%f", &student.score);
            getchar();

            fprintf(tempFile, "%s|%s|%.2f\n", student.name, student.id, student.score);
        } else {
            fprintf(tempFile, "%s|%s|%.2f\n", student.name, student.id, student.score);
        }
    }

    fclose(file);
    fclose(tempFile);

    if (found) {
        remove("student_data.txt");
        rename("temp_data.txt", "student_data.txt");
        printf("Cap nhat sinh vien thanh cong.\n");
    } else {
        remove("temp_data.txt");
        printf("Khong tim thay sinh vien co ma so %s.\n", id);
    }
}

void deleteStudentData(char *id) {
    FILE *file = fopen("student_data.txt", "r");
    if (file == NULL) {
        printf("Khong the mo file.\n");
        return;
    }

    FILE *tempFile = fopen("temp_data.txt", "w");
    if (tempFile == NULL) {
        printf("Khong the tao file tam.\n");
        fclose(file);
        return;
    }

    char line[100];
    int found = 0;
    while (fgets(line, sizeof(line), file)) {
        char *token = strtok(line, "|");
        struct Student student;
        strcpy(student.name, token);

        token = strtok(NULL, "|");
        strcpy(student.id, token);

        token = strtok(NULL, "|");
        student.score = atof(token);

        if (strcmp(student.id, id) == 0) {
            found = 1;
        } else {
            fprintf(tempFile, "%s|%s|%.2f\n", student.name, student.id, student.score);
        }
    }

    fclose(file);
    fclose(tempFile);

    if (found) {
        remove("student_data.txt");
        rename("temp_data.txt", "student_data.txt");
        printf("Xoa sinh vien thanh cong.\n");
    } else {
        remove("temp_data.txt");
        printf("Khong tim thay sinh vien co ma so %s.\n", id);
    }
}
int main() {
    int choice;
    char studentId[20];

    do {
        printf("======= MENU =======\n");
        printf("1. Them sinh vien\n");
        printf("2. Hien thi danh sach sinh vien\n");
        printf("3. Cap nhat thong tin sinh vien\n");
        printf("4. Xoa sinh vien\n");
        printf("0. Thoat\n");
        printf("Nhap lua chon cua ban: ");
        scanf("%d", &choice);
        getchar(); // Xoa bo nho dem

        switch (choice) {
            case 1: {
                struct Student student;

                printf("Nhap ten sinh vien: ");
                fgets(student.name, sizeof(student.name), stdin);

                printf("Nhap ma sinh vien: ");
                fgets(student.id, sizeof(student.id), stdin);

                printf("Nhap diem sinh vien: ");
                scanf("%f", &student.score);
                getchar(); // Xoa bo nho dem

                writeStudentData(student);
                printf("Them sinh vien thanh cong.\n");
                break;
            }
            case 2: {
                readStudentData();
                break;
            }
            case 3: {
                printf("Nhap ma sinh vien can cap nhat: ");
                fgets(studentId, sizeof(studentId), stdin);
                updateStudentData(studentId);
                break;
            }
            case 4: {
                printf("Nhap ma sinh vien can xoa: ");
                fgets(studentId, sizeof(studentId), stdin);
                deleteStudentData(studentId);
                break;
            }
            case 0: {
                printf("Thoat chuong trinh.\n");
                break;
            }
            default:
                printf("Lua chon khong hop le. Vui long chon lai.\n");
        }
    } while (choice != 0);

    return 0;
}

