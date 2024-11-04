#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_EXPENSES 100
#define MAX_CATEGORY_LENGTH 50
#define MAX_DATE_LENGTH 11
typedef struct{
    char category[MAX_CATEGORY_LENGTH];
    float amount;
    char date[MAX_DATE_LENGTH];
} 
Expense;
Expense expenses[MAX_EXPENSES];
int expense_count = 0;
void add_expense();
void view_expenses();
void generate_report();
void save_to_file();
void load_from_file();
int main(){
    load_from_file();
    int choice;
    do {
        printf("Expense Tracker Menu:\n");
        printf("1. Add Expense\n");
        printf("2. View Expenses\n");
        printf("3. Generate Report\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
		switch (choice){
            case 1:
                add_expense();
                break;
            case 2:
                view_expenses();
                break;
            case 3:
                generate_report();
                break;
            case 4:
                save_to_file();
                printf("Exiting the application...\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while(choice != 4);
      return 0;
}
void add_expense(){
    if (expense_count >= MAX_EXPENSES){
        printf("Expense limit reached!\n");
        return;
    }
    Expense e;
    printf("Enter category: ");
    scanf("%s", e.category);
    printf("Enter amount: ");
    scanf("%f", &e.amount);
    printf("Enter date (YYYY-MM-DD): ");
    scanf("%s", e.date);

    expenses[expense_count++] = e;
    printf("Expense added successfully!\n");
}
void view_expenses(){
	int i;
    printf("Expenses:\n");
    printf("Category\tAmount\tDate\n");
    for (i = 0; i < expense_count; i++){
        printf("%s\t%.2f\t%s\n", expenses[i].category, expenses[i].amount, expenses[i].date);
    }
}
void generate_report(){
	int i;
    float total = 0;
    printf("Expense Report:\n");
    for (i = 0; i < expense_count; i++){
        total += expenses[i].amount;
    }
    printf("Total Expenses: %.2f\n", total);
}
void save_to_file(){
	int i;
    FILE *file = fopen("expenses.txt", "w");
    if (file == NULL){
        printf("Error saving data!\n");
        return;
    }
    for (i = 0; i < expense_count; i++){
        fprintf(file, "%s %.2f %s\n", expenses[i].category, expenses[i].amount, expenses[i].date);
    }
    fclose(file);
}
void load_from_file(){
    FILE *file = fopen("expenses.txt", "r");
    if (file == NULL){
        return;
    }
    while (fscanf(file, "%s %f %s", expenses[expense_count].category, &expenses[expense_count].amount, expenses[expense_count].date) != EOF){
        expense_count++;
    }
    fclose(file);
}
