#include <stdio.h>

struct Student {
    char name[20];
    int vize;
    int final;
    float average;
};

void addStudent(struct Student students[], int *count) {
    printf("Ogrenci Adi: ");
    scanf("%s", students[*count].name);

    printf("Vize Notu: ");
    scanf("%d", &students[*count].vize);

    printf("Final Notu: ");
    scanf("%d", &students[*count].final);

    students[*count].average =
        students[*count].vize * 0.4 +
        students[*count].final * 0.6;

    (*count)++;
}

void listStudents(struct Student students[], int count) {
    for (int i = 0; i < count; i++) {
        printf("%s | Vize: %d | Final: %d | Ortalama: %.2f\n",
               students[i].name,
               students[i].vize,
               students[i].final,
               students[i].average);
    }
}

int main() {
    struct Student students[30];
    int count = 0;
    int choice;

    do {
        printf("\n1-Ogrenci Ekle");
        printf("\n2-Ogrencileri Listele");
        printf("\n0-Cikis\n");
        printf("Secim: ");
        scanf("%d", &choice);

        if (choice == 1) {
            addStudent(students, &count);
        }
        else if (choice == 2) {
            listStudents(students, count);
        }

    } while (choice != 0);

    return 0;
}

