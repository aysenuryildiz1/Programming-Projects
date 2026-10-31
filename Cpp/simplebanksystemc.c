#include <stdio.h>
#include <string.h>

struct BankAccount {
    char name[50];
    double balance;
};

int main() {
    struct BankAccount account;

    printf("Isminizi girin: ");
    scanf("%s", account.name);

    printf("Baslangic bakiyesi girin: ");
    scanf("%lf", &account.balance);

    int choice;
    double amount;

    do {
        printf("\n----- MENU -----\n");
        printf("1- Para Yatir\n");
        printf("2- Para Cek\n");
        printf("3- Bakiye Goster\n");
        printf("4- Cikis\n");
        printf("Secim: ");
        scanf("%d", &choice);

        switch (choice) {

            case 1:
                printf("Yatirilacak miktar: ");
                scanf("%lf", &amount);
                if (amount > 0) {
                    account.balance += amount;
                    printf("Guncel bakiye: %.2lf\n", account.balance);
                } else {
                    printf("Gecersiz miktar!\n");
                }
                break;

            case 2:
                printf("Cekilecek miktar: ");
                scanf("%lf", &amount);
                if (amount > account.balance) {
                    printf("Yetersiz bakiye!\n");
                } else if (amount <= 0) {
                    printf("Gecersiz miktar!\n");
                } else {
                    account.balance -= amount;
                    printf("Guncel bakiye: %.2lf\n", account.balance);
                }
                break;

            case 3:
                printf("Guncel bakiye: %.2lf\n", account.balance);
                break;

            case 4:
                printf("Programdan cikiliyor...\n");
                break;

            default:
                printf("Gecersiz secim!\n");
        }

    } while (choice != 4);

    return 0;
}
