#include <stdio.h>


int main() 
{
    int sayi, i;     //değişkenleri tanımlıyoruz.
    long int faktoriyel = 1;

   
    printf("Bir sayi girin: ");   // kullanıcıdan sayı istiyoruz.
    scanf("%d", &sayi);           //kullanıcıdan sayı alıyoruz.

    // sayının negatif olup olmadığını kontrol edelim(negatif sayının fak. hesaplanmaz)
    
    if (sayi < 0) {
          printf("Negatif sayılar icin faktoriyel tanimlanmaz.\n");
          
           // faktöriyeli hesaplayalım
          
    } else {
       
        for (i=1; i<=sayi; i++) {
            faktoriyel *= i;
        }
        printf("%d sayisinin faktoriyeli: %ld dir\n", sayi, faktoriyel);
    }

    return 0;
}
