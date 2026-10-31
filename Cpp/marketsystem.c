#include <stdio.h>
#include <string.h>

struct Product {
    char name[50];
    double price;
    int quantity;
};

int main() {
    struct Product product;
    double total = 0;
    int choice;

    printf("Urun adini girin: ");
    scanf("%s", product.name);

    printf("Urun fiyatini girin: ");
    scanf("%lf", &product.price);

    printf("Adet girin: ");
    scanf("%d", &product.quantity);

    do {
        printf("\n----- MENU -----\n");
        printf("1- Toplam Tutari Hesapla\n");
        printf("2- KDV'li Tutari Goster (%%18)\n");
        printf("3- Urun Bilgilerini Goster\n");
        printf("4- Cikis\n");
        printf("Secim: ");
        scanf("%d", &choice);

        switch (choice) {

            case 1:
                total = product.price * product.quantity;
                printf("Toplam Tutar: %.2lf TL\n", total);
                break;

            case 2:
                total = product.price * product.quantity;
                printf("KDV'li Tutar: %.2lf TL\n", total * 1.18);
                break;

            case 3:
                printf("Urun: %s\n", product.name);
                printf("Fiyat: %.2lf TL\n", product.price);
                printf("Adet: %d\n", product.quantity);
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
