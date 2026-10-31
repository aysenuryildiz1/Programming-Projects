#include<stdio.h>
int main(){
	
	//Kullanıcıdan alınan 5 tamsayı değerini bir dizide saklayan ve bu değerlerin ortalamasını bulan bir program
	int dizi[5];
	int i,toplam=0;
	float ort;
	
	printf("bes adet sayi girin: ");
	
	for (i=0; i<5; i++){
		scanf("%d",&dizi[i]);
	}
	
	for(i=0; i<5; i++){
		toplam+=dizi[i];
	}
	ort= toplam/5.0;
	printf("dizi elemanlari ortalamasi : %.2f",ort);
	
	
	
	
		return 0;
}
