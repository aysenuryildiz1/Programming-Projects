#include <stdio.h>

struct Course {
    char studentName[20];
    char courseName[20];
    int vize;
    int final;
    float average;
    char status[10];
};

void addRecord(struct Course courses[], int *count) {
    printf("Ogrenci Adi: ");
    scanf("%s", courses[*count].studentName);

    printf("Ders Adi: ");
    scanf("%s", courses[*count].courseName);

    printf("Vize Notu: ");
    scanf("%d", &courses[*count].vize);

    printf("Final Notu: ");
    scanf("%d", &courses[*count].final);

    courses[*count].average =
        courses[*count].vize * 0.3 +
        courses[*count].final * 0.7;

    if (courses[*count].average >= 50)
        sprintf(courses[*count].status, "Gecti");
    else
        sprintf(courses[*count].status, "Kaldi");

    (*count)++;
}

void listRecords(struct Course courses[], int count) {
    for (int i = 0; i < count; i++) {
        printf("%s | %s | Vize: %d | Final: %d | Ort: %.2f | %s\n",
               courses[i].studentName,
               courses[i].courseName,
               courses[i].vize,
               courses[i].final,
               courses[i].average,
               courses[i].status);
    }
}

int main() {
    struct Course courses[30];
    int count = 0;
    int choice;

    do {
        printf("\n1-Kayit Ekle");
        printf("\n2-Kayitlari Listele");
        printf("\n0-Cikis\n");
        printf("Secim: ");
        scanf("%d", &choice);

        if (choice == 1)
            addRecord(courses, &count);
        else if (choice == 2)
            listRecords(courses, count);

    } while (choice != 0);

    return 0;
}

