#include <stdio.h>

struct Expense {
    char note[30];     //to write notes after entering expenses
    int category;      //to choose category in which we have to enter the expenses
    float amount;
};

char categoryNames[4][15] = {"Food", "Travel", "Books", "Entertainment"};
float categoryTotal[4];
struct Expense expenses[100];
int expenseCount;
float budget;

/* Remove leftover characters (like the Enter key) from input */
void clearBuffer() {
    while (getchar() != '\n');
}

//take the input until the given value is more than 0
float readPositiveAmount(char message[]) {
    float value;
    printf("%s", message);
    while (scanf("%f", &value) != 1 || value <= 0) {
        clearBuffer();
        printf("Invalid input! Enter a number greater than 0: ");
    }
    clearBuffer();
    return value;
}

// Add a new expense
void addExpense() {
    int cat;
    struct Expense *e = &expenses[expenseCount];

    if (expenseCount == 100) {
        printf("Expense list is full!\n");
        return;
    }
    printf("\nCategories: 1.Food  2.Travel  3.Books  4.Entertainment\n");
    printf("Enter category number (1-4): ");
    while (scanf("%d", &cat) != 1 || cat < 1 || cat > 4) {
        clearBuffer();
        printf("Invalid category! Enter 1-4: ");
    }
    clearBuffer();

    //it will not leave any empty or blank space within the string
    printf("Enter short description (e.g. Lunch): ");
    scanf(" %29[^\n]", e->note);
    clearBuffer();

    e->amount = readPositiveAmount("Enter amount (Rs): ");
    e->category = cat - 1;
    categoryTotal[cat - 1] += e->amount;
    expenseCount++;

    
    printf("Expense added successfully!\n");
}

// Show every expense done
void viewExpenses() {
    printf("\n%-4s %-15s %-30s %s\n", "No.", "Category", "Description", "Amount");
    for (int i = 0; i < expenseCount; i++) {
        printf("%-4d %-15s %-30s Rs %.2f\n", i + 1,
               categoryNames[expenses[i].category],
               expenses[i].note, expenses[i].amount);
    }
    if (expenseCount == 0) {
        printf("No expenses recorded yet.\n");
    }
}

// Show summary 
void showSummary() {
    float totalSpent = 0;
    int highest = 0;

    printf("\n========== EXPENSE SUMMARY ==========\n");
    printf("Monthly budget   : Rs %.2f\n", budget);
    for (int i = 0; i < 4; i++) {
        printf("  %-15s: Rs %.2f\n", categoryNames[i], categoryTotal[i]);
        totalSpent += categoryTotal[i];
        if (categoryTotal[i] > categoryTotal[highest]) {
            highest = i;
        }
    }
    printf("Total spent      : Rs %.2f\n", totalSpent);
    printf("Remaining budget : Rs %.2f\n", budget - totalSpent);

    if (totalSpent > 0) {
        printf("Highest spending category: %s (Rs %.2f)\n",
            categoryNames[highest], categoryTotal[highest]);
    }
    if (totalSpent > budget) {
        printf("WARNING: You have exceeded your budget by Rs %.2f!\n",
               totalSpent - budget);
    } else {
        printf("Status: You are within your budget.\n");
    }
    printf("=====================================\n");
}
//main menu
int main() {
    int choice = 0;

    printf("===== PERSONAL EXPENSE TRACKER =====\n");
    budget = readPositiveAmount("Enter your monthly budget (Rs): ");

    while (choice != 4) {
        printf("\n1. Add expense\n2. View all expenses\n3. View summary\n4. Exit\n");
        printf("Enter your choice: ");
        if (scanf("%d", &choice) != 1) {
            choice = 0;               /* non-number is treated as invalid */
        }
        clearBuffer();

        if (choice == 1)      addExpense();
        else if (choice == 2) viewExpenses();
        else if (choice == 3) showSummary();
        else if (choice == 4) printf("Thank you for using the Expense Tracker. Goodbye!\n");
        else                  printf("Invalid choice! Please enter a number from 1 to 4.\n");
    }
    return 0;
}