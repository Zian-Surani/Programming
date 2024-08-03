#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the structure for a product
struct Product {
    char name[100];
    char id[10];
    float price;
};

// Function to input details for a product
void inputProduct(struct Product *p, int index) {
    printf("Enter details for product %d:\n", index + 1);
    printf("Product Name: ");
    fgets(p->name, sizeof(p->name), stdin);
    p->name[strcspn(p->name, "\n")] = 0; // Remove newline character
    printf("Product ID: ");
    fgets(p->id, sizeof(p->id), stdin);
    p->id[strcspn(p->id, "\n")] = 0; // Remove newline character
    printf("Price: ");
    scanf("%f", &p->price);
    getchar(); // Consume newline character
}

// Function to display product details
void displayProduct(struct Product *p) {
    printf("Product Name: %s, Product ID: %s, Price: %.2f\n", p->name, p->id, p->price);
}

// Function to find the most expensive and least expensive products
void findMostAndLeastExpensive(struct Product *products, int n, struct Product **mostExpensive, struct Product **leastExpensive) {
    *mostExpensive = products;
    *leastExpensive = products;
    for (int i = 1; i < n; i++) {
        if (products[i].price > (*mostExpensive)->price) {
            *mostExpensive = &products[i];
        }
        if (products[i].price < (*leastExpensive)->price) {
            *leastExpensive = &products[i];
        }
    }
}

int main() {
    int n;
    printf("Enter the number of products: ");
    scanf("%d", &n);
    getchar(); // Consume newline character

    // Allocate memory for products
    struct Product *products = (struct Product *)malloc(n * sizeof(struct Product));

    // Input details for each product
    for (int i = 0; i < n; i++) {
        inputProduct(&products[i], i);
    }

    // Display product details
    printf("Product Details:\n");
    for (int i = 0; i < n; i++) {
        displayProduct(&products[i]);
    }

    // Find the most expensive and least expensive products
    struct Product *mostExpensive, *leastExpensive;
    findMostAndLeastExpensive(products, n, &mostExpensive, &leastExpensive);

    // Display the most expensive and least expensive products
    printf("Most Expensive Product: ");
    displayProduct(mostExpensive);
    printf("Least Expensive Product: ");
    displayProduct(leastExpensive);

    // Calculate the total cost of all products
    float totalCost = 0;
    for (int i = 0; i < n; i++) {
        totalCost += products[i].price;
    }
    printf("Total Cost of All Products: %.2f\n", totalCost);

    // Free allocated memory
    free(products);

    return 0;
}   