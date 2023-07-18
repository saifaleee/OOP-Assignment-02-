#pragma once
struct Address {


};
struct CustomerAccount {

};

void OpenCustomerAccount(CustomerAccount *[], int, char*, char*, char*, char*, int, long long, float);
int SearchCustomer(CustomerAccount* [], int,char*);
bool UpdateCustomerAccount(CustomerAccount* [], int, char*, Address);
bool UpdateCustomerAccount(CustomerAccount* [], int, char*, long long);
bool UpdateCustomerAccount(CustomerAccount* [], int, char*, float);
void DisplayAllCustomers(CustomerAccount* [], int);


