#include <stdio.h>


int main()
 {
int sayi, yuzler, onlar, birler, rakamintoplami, rakamkupu ; //değişken tanımlıyoruz.


printf("Bir sayi giriniz: ");
scanf("%d", &sayi);


// sayiyi basamaklarina ayiralim
yuzler = sayi / 100;
onlar = (sayi / 10) % 10;
birler = sayi % 10;

// rakamların küplerinin toplamını hesaplayalım.

rakamkupu = (yuzler*yuzler*yuzler) + (onlar*onlar*onlar) + (birler*birler*birler);


// rakamların toplamını hesaplayalım
rakamintoplami = yuzler + onlar + birler;


// koşulları test edelim
if (rakamkupu == sayi) {
printf("Armstrong sayisidir.\n");
}
else{
	printf("Armstrong sayisi degildir.\n");
}

return 0;
}
