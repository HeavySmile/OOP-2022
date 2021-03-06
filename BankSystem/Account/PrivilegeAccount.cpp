#include "PrivilegeAccount.hpp"

PrivilegeAccount::PrivilegeAccount() : Account(), overdraft(DEFAULT_OVERDRAFT_SIZE) {}

bool PrivilegeAccount::withdraw(const double amount)
{
    if(getBalance() + overdraft < amount) return false;

    setAmount(getBalance() - amount);
    return true;
}
void PrivilegeAccount::display() const
{
    cout << "Account type : Privilege" << endl;
    cout << "Owner's ID : " << getId() << endl;
    Account::display();
}
