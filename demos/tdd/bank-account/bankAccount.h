class BankAccount {
    private:
        double balance;

    public:
        BankAccount();

        double getBalance() const;
        void deposit(double amount);
        void withdraw(double amount);
};
