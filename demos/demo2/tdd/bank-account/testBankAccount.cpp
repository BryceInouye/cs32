#include "bankAccount.h"
#include "tddFuncs.h"
#include<iostream>
int main() {
    std::cout << "Testing class BankAccount..." << std::endl;

    // 1. check 0 balance upon creation
    BankAccount b1;
    assertEquals("check 0 balance upon creation", 0, b1.getBalance());

    // 2. deposit works correctly
    b1.deposit(100);
    assertEquals("normal deposit (100)", 100, b1.getBalance());

    // 3. withdraw works correctly
    b1.withdraw(50);
    assertEquals("valid withdraw (50)", 50, b1.getBalance());

    // 4. withdraw shouldn't lead to negative balance
    b1.withdraw(100);
    assertEquals("invalid withdraw (100)", 50, b1.getBalance());

    // 5. don't allow -ve amounts for withdrawal
    b1.deposit(-200);
    assertEquals("invalid deposit (-200)", 100, b1.getBalance());
    b1.withdraw(-1);
    assertEquals("invalid withdraw (-1)", 50, b1.getBalance());

    return 0;
}