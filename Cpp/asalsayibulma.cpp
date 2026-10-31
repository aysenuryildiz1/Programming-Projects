#include <stdio.h>



int main() {
    int sayi, i, asal = 1;

   
    printf("Bir sayi girin: ");    // Kullanıcıdan sayı alalım.
    scanf("%d", &sayi);

    // sayı negatifse veya bir ise asal olmaz koşulu yazalım.
    if (sayi <= 1) {
    asal = 0;
    
    } else {
    // iki sayısından sayının kendisine kadar sayınıp bölünüp bölünmediğine bakalım
    
    for (i = 2; i <= sayi / 2; i++) 
	{
    if (sayi % i == 0) {
    asal = 0;
    break;
    
    
           }
        }
    }

    // sonucu yazdıralım.
    if (asal == 1) {
        printf("%d asaldir.\n", sayi);
    } else {
        printf("%d 1asal degildir.\n", sayi);
    }

    return 0;
}
