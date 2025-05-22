#include <stdio.h>

struct Book {
    char title[200],author[200];
      float price;
};

int main() {
    struct Book y;
    FILE *file;

    // Input book details
    printf("Enter book title: ");
    fgets(y.title, sizeof(y.title), stdin);

    printf("Enter author name: ");
    fgets(y.author, sizeof(y.author), stdin);

    printf("Enter price: ");
    scanf("%f", &y.price);

    // Save to file
    file = fopen("book.txt", "w");
    if (file == NULL) {
        printf("Error opening file!\n");
        return 1;
    }
    fprintf(file, "%s%s%.2f\n", y.title, y.author, y.price);
    fclose(file);

    // Read from file and display
    file = fopen("book.txt", "r");
    if (file == NULL) {
        printf("Error opening file!\n");
        return 1;
    }

    printf("\nSaved Book Details:\n");
    fgets(y.title, sizeof(y.title), file);
    fgets(y.author, sizeof(y.author), file);
    fscanf(file, "%f", &y.price);

    printf("Title: %s", y.title);
    printf("Author: %s", y.author);
    printf("Price: %.2f\n", y.price);

    fclose(file);

    return 0;
}