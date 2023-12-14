#include <stdio.h>
#include <stdlib.h>


typedef struct {
    char title[100];
    char author[100];
    float price;
} Book;


void addBook(Book* books, int size) {
    int i;
	for ( i = 0; i < size; i++) {
        printf("Nhap thong tin sach thu %d:\n", i + 1);
        printf("Ten sach: ");
	getchar();
	fgets(books[i].title, 100, stdin);
        printf("Tac gia: ");
        getchar();
	fgets(books[i].author, 100, stdin);
        printf("Gia sach: ");
        scanf("%f", &books[i].price);
        printf("\n");
    }
}


void displayBook(Book* books, int size) {
    printf("Danh sach sach:\n");
    int i;
	for ( i = 0; i < size; i++) {
        printf("Sach thu %d:\n", i + 1);
        printf("Ten sach: %s\n", books[i].title);
        printf("Tac gia: %s\n", books[i].author);
        printf("Gia sach: %.2f\n", books[i].price);
        printf("\n");
    }
}

int main() {
    int size;
    printf("Nhap so luong sach: ");
    scanf("%d", &size);

 
 
    Book* books = (Book*) malloc(size * sizeof(Book));

    if (books == NULL) {
        printf("Khong the cap phat bo nho dong.\n");
        exit(1);
    }

    addBook(books, size);
    displayBook(books, size);

   
    free(books);

    return 0;
}
