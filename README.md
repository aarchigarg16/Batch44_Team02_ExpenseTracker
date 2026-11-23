# Batch44_Team02_ExpenseTracker
Personal Expense Tracker - C Programming Mini Hackathon
# Personal Expense Tracker

## Problem Statement
Build a simple expense tracker to help a student manage a monthly budget.

## Team Details
- Batch: 44
- Team No: 02 (Expense Experts)
- Members: Aarchi Garg, Akshay Jain, Pragyan Shukla

## Objectives and Features
- Accept a monthly budget
- Record multiple expenses with category, description and amount
- Categories: Food, Travel, Books, Entertainment
- View all recorded expenses
- Show category-wise totals, total spent and remaining budget
- Show the highest spending category
- Warn when the budget is exceeded
- Input validation for invalid numbers, categories and menu choices

## Algorithm
1. Start
2. Input monthly budget (must be greater than 0)
3. Show menu: 1. Add expense, 2. View expenses, 3. View summary, 4. Exit
4. Add expense: choose category (1-4), enter description and amount, add amount to that category's total
5. View expenses: print all stored expenses
6. Summary: calculate total spent, remaining budget and highest category; if total > budget, print warning
7. Repeat the menu until the user chooses Exit
8. Stop

## C Concepts Used
Variables, operators, if-else, loops (while, for), arrays, strings, functions, structures, input validation

## How to Compile and Run
gcc expense_tracker.c -o expense_tracker.exe
./expense_tracker.exe

## Sample Test Case 
| Input | Expected Output | Actual Output |
|-------|-----------------|---------------|
| Budget 5000, add Food 1200 | Remaining 3800, within budget | Remaining Rs 3800.00, within budget |
| Budget 1000, add Travel 1500 | Warning: exceeded by Rs 500 | Warning: exceeded by Rs 500.00 |
| Amount = -50 or "abc" | "Invalid input" message | "Invalid input!" shown, asks again |
| Category = 7 | "Invalid category" message | "Invalid category!" shown, asks again |
| Menu choice = 9 | "Invalid choice" message | "Invalid choice!" shown |
| View expenses with none added | "No expenses recorded yet." | "No expenses recorded yet." |
