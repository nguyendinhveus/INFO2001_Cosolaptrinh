#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Contact {
    char name[50];
    char phone[20];
    char email[50];
    struct Contact* next;
};

struct Contact* createContact(const char* name, const char* phone, const char* email) {
    struct Contact* contact = (struct Contact*)malloc(sizeof(struct Contact));
    strcpy(contact->name, name);
    strcpy(contact->phone, phone);
    strcpy(contact->email, email);
    contact->next = NULL;
    return contact;
}

void addContact(struct Contact** head, const char* name, const char* phone, const char* email) {
    struct Contact* contact = createContact(name, phone, email);

    if (*head == NULL) {
        *head = contact;
    } else {
        struct Contact* current = *head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = contact;
    }

    printf("Them lien lac thanh cong.\n");
}

void deleteContact(struct Contact** head, const char* name) {
    if (*head == NULL) {
        printf("Danh sach lien lac rong.\n");
        return;
    }

    struct Contact* prev = NULL;
    struct Contact* current = *head;

    while (current != NULL) {
        if (strcmp(current->name, name) == 0) {
            if (prev == NULL) {
                *head = current->next;
            } else {
                prev->next = current->next;
            }

            free(current);
            printf("Xoa lien lac thanh cong.\n");
            return;
        }

        prev = current;
        current = current->next;
    }

    printf("Khong tim thay thong tin lien lac co ten \"%s\".\n", name);
}

struct Contact* findContact(struct Contact* head, const char* name) {
    struct Contact* current = head;

    while (current != NULL) {
        if (strcmp(current->name, name) == 0) {
            return current;
        }

        current = current->next;
    }

    return NULL;
}

void updateContact(struct Contact* head, const char* name, const char* phone, const char* email) {
    struct Contact* contact = findContact(head, name);

    if (contact != NULL) {
        strcpy(contact->phone, phone);
        strcpy(contact->email, email);
        printf("Cap nhat thong tin lien lac thanh cong.\n");
    } else {
        printf("Khong tim thay lien lac có ten \"%s\".\n", name);
    }
}

void saveContactsToFile(struct Contact* head, const char* filename) {
    FILE* file = fopen(filename, "wb");
    if (file == NULL) {
        printf("Khong the mo tep tin.\n");
        return;
    }

    struct Contact* current = head;
    // Trong hàm saveContactsToFile
	while (current != NULL) {
	    fwrite(current->name, sizeof(current->name), 1, file);
	    fwrite(current->phone, sizeof(current->phone), 1, file);
	    fwrite(current->email, sizeof(current->email), 1, file);
	    current = current->next;
	}


    fclose(file);
}

struct Contact* loadContactsFromFile(const char* filename) {
    FILE* file = fopen(filename, "rb");
    if (file == NULL) {
        printf("Khong the mo tep tin.\n");
        return NULL;
    }

    struct Contact* head = NULL;
    struct Contact* current = NULL;

    while (1) {
        struct Contact* contact = (struct Contact*)malloc(sizeof(struct Contact));
        size_t elements_read = fread(contact, sizeof(struct Contact), 1, file);
        
        if (elements_read < 1) {
            free(contact);
            break;
        }

        contact->next = NULL;

        if (head == NULL) {
            head = contact;
            current = contact;
        } else {
            current->next = contact;
            current = contact;
        }
    }

    fclose(file);
    return head;
}

void freeContacts(struct Contact* head) {
    struct Contact* current = head;
    while (current != NULL) {
        struct Contact* next = current->next;
        free(current);
        current = next;
    }
}

int main() {
    const char* filename = "contacts.bin";
    struct Contact* contacts = loadContactsFromFile(filename);

    int choice;
    char name[50];
    char phone[20];
    char email[57];

    while (1) {
        printf("\nChuong trinh quan li so lien lac\n");
        printf("1. Them lien lac\n");
        printf("2. Xoa lien lac\n");
        printf("3. Tim kiem lien lac\n");
        printf("4. Cap nhat thong tin lien lac\n");
        printf("5. Luu danh sach lien lac vao tap tin\n");
        printf("0. Thoat\n");
        printf("Lua chon cua ban: ");
        scanf("%d", &choice);

        switch (choice) {

		case 1:
		    printf("Nhap ten: ");
		    scanf("%s", name);
		    printf("Nhap so dien thoai: ");
		    scanf("%s", phone);
		    printf("Nhap email: ");
		    scanf("%s", email);
		    addContact(&contacts, name, phone, email);
		    break;
		case 2:
		    printf("Nhap ten lien lac can xoa: ");
		    scanf("%49s", name);
		    deleteContact(&contacts, name);
		    break;
		case 3:
            printf("Nh?p tên liên l?c c?n t?m: ");
            scanf("%49s", name);
            contacts = findContact(contacts, name); // Gán giá tr? m?i cho contact
            if (contacts != NULL) {
                printf("Tên: %s\n", contacts->name);
                printf("S? ði?n tho?i: %s\n", contacts->phone);
                printf("Email: %s\n", contacts->email);
            } else {
                printf("Không t?m th?y liên l?c có tên \"%s\".\n", name);
            }
            break;
		case 4:
		    printf("Nhap ten lien lac can cap nhat: ");
		    scanf("%49s", name);
		    printf("Nhap so dien thoai moi: ");
		    scanf("%19s", phone);
		    printf("Nhap email moi: ");
		    scanf("%49s", email);
		    updateContact(contacts, name, phone, email);
		    break;

            case 5:
                saveContactsToFile(contacts, filename);
                printf("Danh sach lien lac da duoc luu vao tep tin \"%s\".\n", filename);
                break;
            case 0:
                saveContactsToFile(contacts, filename);
                freeContacts(contacts);
                printf("Thoat chuong trinh.\n");
                return 0;
            default:
                printf("Lua chon khong hop le. Vui long chon lai.\n");
        }
    }
}
