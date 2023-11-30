#include <stdio.h>
#include <string.h>

#define MAX_STUDENTS 100

struct Student {
    char id[50];
    char name[50];
    float score;
};

void bubbleSort(struct Student lst[], int n) {
    int i, j;
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (strcmp(lst[j].name, lst[j + 1].name) > 0) {
                struct Student temp = lst[j];
                lst[j] = lst[j + 1];
                lst[j + 1] = temp;
            }
        }
    }
}

int linearSearchByName(struct Student lst[], int n, char name[]) {
    int i;
    for (i = 0; i < n; i++) {
        if (strcmp(lst[i].name, name) == 0) {
            return i;
        }
    }
    return -1;
}

int linearSearchById(struct Student lst[], int n, char id[]) {
    int i;
    for (i = 0; i < n; i++) {
        if (strcmp(lst[i].id, id) == 0) {
            return i;
        }
    }
    return -1;
}

int main() {
    struct Student lst[MAX_STUDENTS];
    int n, i, searchIndex;
    char choice;
    char searchName[50];
    char searchId[50];

    printf("Nhap so luong sinh vien: ");
    scanf("%d", &n);
    getchar(); 

    for (i = 0; i < n; i++) {
        
		printf("Nhap thong tin sinh vien thu %d:\n", i + 1);
        printf("ID: ");
        fgets(lst[i].id, 50, stdin);
        printf("Ten: ");
        fgets(lst[i].name, 50, stdin);
        printf("Diem so: ");
        scanf("%f", &lst[i].score);
        getchar(); 
    }

    
    bubbleSort(lst, n);

    printf("\nDanh sach sinh vien duoc sap xep theo ten:\n");
    for (i = 0; i < n; i++) {
        printf("ID: %sTen: %sDiem so: %.2f\n", lst[i].id, lst[i].name, lst[i].score);
    }

    do {
        printf("\nChon cach tim sinh vien:\n");
        printf("1. Tim kiem theo ten\n");
        printf("2. Tim kiem theo ID\n");
        printf("Nhap lua chon cua ban: ");
        scanf(" %c", &choice);
        getchar(); 

        switch (choice) {
            case '1':
                printf("Nhap ten sinh vien can tim: ");
                fgets(searchName, 50, stdin); 
                searchIndex = linearSearchByName(lst, n, searchName);
                break;
            case '2':
                printf("Nhap ID sinh vien can tim: ");
                fgets(searchId, 50, stdin);
                searchIndex = linearSearchById(lst, n, searchId);
                break;
            default:
                printf("Lua chon khong hop le\n");
                searchIndex = -1; 
        }
        if (searchIndex != -1) {
        	printf("Sinh vien duoc tim thay:\n");
        	printf("ID: %sTen: %sDiem so: %.2f\n", lst[searchIndex].id, lst[searchIndex].name, lst[searchIndex].score);
        	
    	} else {
        	printf("Khong tim thay sinh vien\n");
    	}
        
    } while (searchIndex != -1);

    

    return 0;
}
