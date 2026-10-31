#include <stdio.h>


int main()
 {
 	
 int baslangicsayi, bitissayi;
 
 printf("Lutfen baslangic ve bitis sayilarini giriniz: ");
 scanf("%d%d", &baslangicsayi, &bitissayi);
 printf("%d ile %d arasindaki palindromik sayilar:\n", baslangicsayi, bitissayi);
 
 
 int bulundu = 0;
 for (int sayi = baslangicsayi; sayi <= bitissayi; sayi++) 
 {
 int ters = 0;
 int gecicisayi = sayi;
 while (gecicisayi > 0) {
 ters = (ters * 10) + (gecicisayi % 10);
 gecicisayi /= 10;
 }
 if (sayi == ters) {
 printf("%d\n", sayi);
 bulundu = 1; }
 }
 if (!bulundu) {
 printf("Bu aralikta palindromik sayi bulunamadi.\n");
 }
 return 0;
}
