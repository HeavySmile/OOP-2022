#include "Log.hpp"

Log::Log() : text(nullptr) {}
Log::~Log()
{
    delete[] text;
}

void Log::write(const char* operation)
{
    if(text == nullptr)
    {
        text = new char[strlen(operation) + 1];
        strcpy(text, operation);
    }
    else
    {
        char* text_cpy = new char[strlen(text) + strlen(operation) + 2];
        strcpy(text_cpy, text);
        strcat(text_cpy, "|");
        strcat(text_cpy, operation);

        delete[] text;
        text = text_cpy;
    }
}
void Log::print() const
{
    cout << text << endl;
}

void Log::writeAddCustomer(const char* name, const char* address)
{
    char* log_text = new char[strlen("add customer: , ") + strlen(name) + strlen(address) + 1];
    strcpy(log_text, "add customer: ");
    strcat(log_text, name);
    strcat(log_text, ", ");
    strcat(log_text, address);
    write(log_text);

    delete[] log_text;
}
void Log::writeDeleteCustomer(const char* name, const char* address)
{
    char* log_text = new char[strlen("delete customer: , ") + strlen(name) + strlen(address) + 1];
    strcpy(log_text, "delete customer: ");
    strcat(log_text, name);
    strcat(log_text, ", ");
    strcat(log_text, address);
    write(log_text);

    delete[] log_text;
}
void Log::writeAddAccount(const char* name, const char* IBAN, const char* type)
{
    char* log_text = new char[strlen("add account for : , ") + strlen(name) + strlen(IBAN) + strlen(type) + 1];
    strcpy(log_text, "add account for ");
    strcat(log_text, name);
    strcat(log_text, ": ");
    strcat(log_text, IBAN);
    strcat(log_text, ", ");
    strcat(log_text, type);
    write(log_text);

    delete[] log_text;
}
void Log::writeDeleteAccount(const char* IBAN)
{
    char* log_text = new char[strlen("delete account: ") + strlen(IBAN) + 1];
    strcpy(log_text, "delete account: ");
    strcat(log_text, IBAN);
    write(log_text);

    delete[] log_text;
}
void Log::writeDeposit(const double amount, const char* IBAN)
{
    char* log_text = new char[strlen("deposit to ") + strlen(IBAN) + 1];
    strcpy(log_text, "deposit to ");
    strcat(log_text, IBAN);
    write(log_text);

    cout << log_text << endl;

    delete[] log_text;
}
void Log::writeTransfer(const double amount, const char* fromIBAN, const char* toIBAN)
{
    char* log_text = new char[strlen("transfer from  to ") + strlen(fromIBAN) + strlen(toIBAN) + 1];
    strcpy(log_text, "transfer from ");
    strcat(log_text, fromIBAN);
    strcat(log_text, " to ");
    strcat(log_text, toIBAN);
    write(log_text);

    delete[] log_text;
}
void Log::writeWithdraw(const double amount, const char* IBAN)
{
    char* log_text = new char[strlen("withdraw from ") + strlen(IBAN) + 1];
    strcpy(log_text, "withdraw from ");
    strcat(log_text, IBAN);
    write(log_text);

    delete[] log_text;
}

void Log::writeToFile(const char* filepath)
{
    ofstream file(filepath, ios::trunc);
    
    for (int i = 0; i < strlen(text); i++)
    {
        if(text[i] == '|')
        {
            file << '\n';
            continue;
        }

        file << text[i];
    }

    file.close();
}