#include <stdio.h>
int main(){
	

    float a,b,sonuc;
	char islem;
	
    printf("Iki sayi giriniz: ");
    scanf("%f %f", &a, &b);
    printf("Yapmak istediginiz islemi giriniz (+, -, *, /): ");
    scanf(" %c", &islem);

	if(islem=='+'){
		sonuc=a+b;
		printf("sonuc: %.2f",sonuc);
	}
	else if(islem== '-'){
	
		sonuc=a-b;
		printf("sonuc: %.2f",sonuc);
	}
	
	else if(islem== '*'){
		sonuc=a*b;
		printf("sonuc: %.2f",sonuc);
	}
	else{
		sonuc=a/b;
		printf("sonuc: %.2f",sonuc);
	}
	
	
		return 0;
}
