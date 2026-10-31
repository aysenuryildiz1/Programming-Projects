#include <stdio.h>
int main() {

//5 elemanlý iki dizinin toplamýný üçüncü bir diziye yazan program.

int A[5], B[5],C[5];
int i;


printf("A dizinin elemanlarini giriniz");

for(i=0;i<5;i++)
{ 
   printf("A[%d]=", i);
   scanf ("%d",&A[i]);
}

printf("B dizisi elemanlarý girin:");

for(i=0;i<5;i++){
	
	  printf("B[%d]=", i);
      scanf ("%d",&B[i]);
}


// Iki dizinin elemanlarinin toplanmasi
for(i=0;i<5;i++)
C[i]=A[i]+B[i];

printf("C dizisi:\n");
for(i=0;i<5;i++)
printf("%d\t",C[i]);






	return 0;
}
