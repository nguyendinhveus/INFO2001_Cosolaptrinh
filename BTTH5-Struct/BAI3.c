#include <stdio.h>
#include <string.h>

#define MAX_EMPLOYEES 100

struct Employee {
    char id[50];
    char name[50];
    char position[50];
    float salary;
};

void addEmployee(struct Employee employees[], int *count) {
    if (*count < MAX_EMPLOYEES) {
        struct Employee newEmployee;

        printf("Nhap ma nhan vien: ");
        fgets(newEmployee.id, 50, stdin);

        printf("Nhap ten nhan vien: ");
        fgets(newEmployee.name, 50, stdin);

        printf("Nhap chuc vu: ");
        fgets(newEmployee.position, 50, stdin);

        printf("Nhap luong: ");
        scanf("%f", &newEmployee.salary);
        getchar();

        employees[*count] = newEmployee;
        (*count)++;
    } else {
        printf("Danh sach nhan vien da day\n");
    }
}

void deleteEmployee(struct Employee employees[], int *count, int index) {
    if (index >= 0 && index < *count) {
        int i;
		for (i = index; i < *count - 1; i++) {
            employees[i] = employees[i + 1];
        }
        (*count)--;
        printf("da xoa nhan vien thanh cong\n");
    } else {
        printf("Khong tim thay nhan vien  %d\n", index);
    }
}

void displayEmployees(struct Employee employees[], int count) {
    if (count > 0) {
        printf("Danh sach nhan vien:\n");
        int i;
		for (i = 0; i < count; i++) {
            printf("Nhan vien %d:\n", i + 1);
            printf("Ma nhan vien: %s", employees[i].id);
            printf("Ten nhan vien: %s", employees[i].name);
            printf("Chuc vu: %s", employees[i].position);
            printf("Luong: %.2f\n", employees[i].salary);
        }
    } else {
        printf("Chua co nhan vien trong danh sach\n");
    }
}

void sortEmployees(struct Employee employees[], int count) {
    int i, j;
	for ( i = 0; i < count - 1; i++) {
        for ( j = i + 1; j < count; j++) {
            if (strcmp(employees[i].name, employees[j].name) > 0) {
                struct Employee temp = employees[i];
                employees[i] = employees[j];
                employees[j] = temp;
            }
        }
    }
    printf("Danh sach nhan vien sap xep theo ten\n");
}

int main() {
    struct Employee employees[MAX_EMPLOYEES];
    int count = 0;
    int choice;

    do {
        printf("======= MENU =======\n");
        printf("1. Them nhan vien\n");
        printf("2. Xoa nhan vien\n");
        printf("3. Hien thi danh sach nhan vien\n");
        printf("4. Sap xep nhan vien\n");
        printf("0. Thoot chuong trinh\n");
        printf("Nhap lua chon cua ban: ");
        scanf("%d", &choice);
        getchar();

        switch (choice) {
            case 1:
                addEmployee(employees, &count);
                break;
            case 2: {
                int index;
                printf("Nhap so thu tu nhan vien can xoa: ");
                scanf("%d", &index);
                getchar();
                deleteEmployee(employees, &count, index - 1);
                break;
            }
            case 3:
                displayEmployees(employees, count);
                break;
            case 4:
                sortEmployees(employees, count);
                break;
            case 0:
                printf("Cam on ban da su dung chuong trinh\n");
                break;
            default:
                printf("Lua chon khong hop le\n");
        }

        printf("\n");
    } while (choice != 0);
	
	return 0;
}
