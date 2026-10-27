#include <stdio.h>

int main()
{
    float loanAmount, interestRate, monthlyPayment, ans;
    scanf("%f\n%f\n%f", &loanAmount, &interestRate, &monthlyPayment);
    ans = loanAmount;
    interestRate /= 12.0;
    ans = ans * (1.0 + interestRate / 100.0) - monthlyPayment;
    printf("Balance remaining after first payment: $%.2f\n", ans);
    ans = ans * (1.0 + interestRate / 100.0) - monthlyPayment;
    printf("Balance remaining after second payment: $%.2f\n", ans);
    ans = ans * (1.0 + interestRate / 100.0) - monthlyPayment;
    printf("Balance remaining after third payment: $%.2f\n", ans);
    return 0;
}