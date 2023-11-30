#include <stdio.h>
#include <string.h>

struct Student {
char name[50];
char id[50];
};

void initStudent(struct Student lst[], int index) {
	getchar();
	printf("Nhap ten sinh vien: ");
	fgets(lst[index].name, 50, stdin);
	printf("Nhap ma sinh vien: ");
	fgets(lst[index].id, 50, stdin);
}

void displayStudent(struct Student lst[], int index) {
	printf("Ten sinh vien: %s", lst[index].name);
	printf("Ma sinh vien: %s", lst[index].id);
}

void updateStudent(struct Student lst[], int index) {
	getchar();
	printf("Cap nhat ten sinh vien: ");
	fgets(lst[index].name, 50, stdin);
	printf("Cap nhat ma sinh vien: ");
	fgets(lst[index].id, 50, stdin);

}

int main() {
	int MAX_STUDENT = 100;
	struct Student listOfStudent[MAX_STUDENT];
	int numberOfStudent = 0;
	char choice;


	do {
	    printf("======= MENU =======\n");
	    printf("1. Nhap thong tin sinh vien\n");
	    printf("2. Hien thi thong tin sinh vien\n");
	    printf("3. Cap nhat thong tin sinh vien\n");
	    printf("0. Thoat chuong trinh\n");
	    printf("Nhap lua chon cua ban: ");
	    scanf("%c", &choice);
	    getchar(); 
	
	    switch (choice) {
	        case '1':
	            if (numberOfStudent < MAX_STUDENT) {
					printf("Nhan Enter de bat dau nhap thong tin cho sinh vien %d\n", numberOfStudent + 1);
	                initStudent (listOfStudent, numberOfStudent);
	                numberOfStudent++;
	            } else {
	                printf("Da vuot qua so luong sinh vien toi da!\n");
	            }
	            break;
	        case '2':
	            if (numberOfStudent > 0) {
	                printf("Danh sach sinh vien:\n");
	                int i;
	                for ( i = 0; i < numberOfStudent; i++) {
	                    printf("Thong tin sinh vien %d:\n", i + 1);
	                    displayStudent(listOfStudent, i);
	                }
	            } else {
	                printf("Chua co sinh vien trong danh sach!\n");
	            }
	            break;
	        case '3': 
	            if (numberOfStudent > 0) {
	                int sequenceStudent;
	                printf("Nhap so thu tu sinh vien can cap nhat: ");
	                scanf("%d", &sequenceStudent);
	                getchar();
	
	                if (sequenceStudent >= 1 && sequenceStudent <= numberOfStudent) {
	                    printf("Nhan Enter de cap nhat thong tin cho sinh vien %d\n", sequenceStudent);
	                    updateStudent(listOfStudent, sequenceStudent - 1);
	                } else {
	                    printf("Khong ton tai sinh vien co so thu tu %d\n", sequenceStudent);
	                }
	            } else {
	                printf("Chua co sinh vien trong danh sach!\n");
	            }
	            break;
	        case '0': 
	            printf("Cam on ban da su dung chuong trinh!\n");
	            break;
	        default:
	            printf("Lua chon khong hop le!\n");
	    }
	
	    printf("\n");
	} while (choice != '0');
	
	return 0;
}
