#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char universitate[100];
    char facultate[100];
    char departament[100];
    char nume[100];
    char prenume[100];
    int varsta;
    char liceu[200];
    double media_bac;
} Formular;

void statistici() {
    Formular formulare[100];
    int n = 0;

    FILE *file = fopen("formulare.txt", "r");
    printf("\033[33m///// Statistici Formulare /////\033[0m\n\n");
    if (!file) {
        printf("\033[41mNu exista formulare pentru a genera statistici.\033[0m\n");
    }

    char linie[256];
    while (fgets(linie, sizeof(linie), file)) {
        Formular *f = &formulare[n];
        strcpy(f->universitate, linie);
        f->universitate[strcspn(f->universitate, "\n")] = 0;

        fgets(f->facultate, sizeof(f->facultate), file);
        f->facultate[strcspn(f->facultate, "\n")] = 0;

        fgets(f->departament, sizeof(f->departament), file);
        f->departament[strcspn(f->departament, "\n")] = 0;

        fgets(f->nume, sizeof(f->nume), file);
        fgets(f->prenume, sizeof(f->prenume), file);
        fgets(linie, sizeof(linie), file);
        f->varsta = atoi(linie);
        fgets(f->liceu, sizeof(f->liceu), file);
        fgets(linie, sizeof(linie), file);
        f->media_bac = atof(linie);

        n++;
    }
    fclose(file);

    struct {
        char facultate[100];
        char departament[100];
        int count;
    } statistici[100];
    int nr_stat = 0;

    for (int i = 0; i < n; ++i) {
        int gasit = 0;
        for (int j = 0; j < nr_stat; ++j) {
            if (strcmp(statistici[j].facultate, formulare[i].facultate) == 0 &&
                strcmp(statistici[j].departament, formulare[i].departament) == 0) {
                statistici[j].count++;
                gasit = 1;
                break;
            }
        }
        if (!gasit) {
            strcpy(statistici[nr_stat].facultate, formulare[i].facultate);
            strcpy(statistici[nr_stat].departament, formulare[i].departament);
            statistici[nr_stat].count = 1;
            nr_stat++;
        }
    }

    for (int i = 0; i < nr_stat; ++i) {
        printf("\033[32mFacultate:\033[0m %s\n", statistici[i].facultate);
        printf("\033[34mSpecializare:\033[0m %s\n", statistici[i].departament);
        printf("\033[35mNumar formulare:\033[0m %d\n\n", statistici[i].count);
    }

    int opt = 0;
    do {
        printf("\033[96m1.\033[0m \033[91mInapoi\033[0m\n");
        printf("Introduceti alegerea: ");
        scanf("%d", &opt);
    } while (opt != 1);

    system("cls");
}

void afiseaza_intreg_fisierul() {
    Formular formulare[100];
    int n = 0;

    FILE *file = fopen("formulare.txt", "r");
    if (!file) {
        printf("\033[33mNu exista formulare.\033[0m\n");
        return;
    }

    char linie[256];
    while (fgets(linie, sizeof(linie), file)) {
        Formular *f = &formulare[n];
        strcpy(f->universitate, linie);
        f->universitate[strcspn(f->universitate, "\n")] = 0;

        fgets(f->facultate, sizeof(f->facultate), file);
        f->facultate[strcspn(f->facultate, "\n")] = 0;

        fgets(f->departament, sizeof(f->departament), file);
        f->departament[strcspn(f->departament, "\n")] = 0;

        fgets(f->nume, sizeof(f->nume), file);
        f->nume[strcspn(f->nume, "\n")] = 0;

        fgets(f->prenume, sizeof(f->prenume), file);
        f->prenume[strcspn(f->prenume, "\n")] = 0;

        fgets(linie, sizeof(linie), file);
        f->varsta = atoi(linie);

        fgets(f->liceu, sizeof(f->liceu), file);
        f->liceu[strcspn(f->liceu, "\n")] = 0;

        fgets(linie, sizeof(linie), file);
        f->media_bac = atof(linie);

        n++;
    }
    fclose(file);

    for (int i = 0; i < n; ++i) {
        printf("\033[0;31m=== FORMULAR\033[0m \033[96m%d \033[0;31m===\033[0m\n", i + 1);
        printf("\033[32m%s\033[0m\n", formulare[i].universitate);
        printf("\033[33m%s\n\033[0m", formulare[i].facultate);
        printf("\033[34m%s\n\033[0m", formulare[i].departament);
        printf("\033[36mNume:\033[0m %s\n", formulare[i].nume);
        printf("\033[36mPrenume:\033[0m %s\n", formulare[i].prenume);
        printf("\033[35mVarsta:\033[0m %d\n", formulare[i].varsta);
        printf("\033[33mLiceu Absolvit:\033[0m %s\n", formulare[i].liceu);
        printf("\033[34mMedia BAC\033[0m %.2f\n\n", formulare[i].media_bac);
    }
}

void formulare(const char* text) {
    FILE *file = fopen("formulare.txt", "a");
    fprintf(file, "%s\n", text);
    fclose(file);
}

void date() {
    char nume[100], prenume[100], liceu[200];
    int varsta;
    double media;

    system("cls");
    printf("\033[33m///// Creare Formular /////\033[0m\n\n");
    printf("\033[35mIntroduceti datele	\033[0m\n");

    printf("\033[36mNume: \033[0m");
    scanf("%s", nume); getchar();

    printf("\033[36mPrenume: \033[0m");
    scanf(" %[^\n]", prenume); getchar();

    printf("\033[36mVarsta: \033[0m");
    scanf("%d", &varsta); getchar();

    printf("\033[36mLiceu Absolvit: \033[0m");
    scanf(" %[^\n]", liceu); getchar();

    printf("\033[36mMedia BAC \033[0m(x.xx): ");
    scanf("%lf", &media); getchar();

    FILE *file = fopen("formulare.txt", "a");
    fprintf(file, "%s\n", nume);
    fprintf(file, "%s\n", prenume);
    fprintf(file, "%d\n", varsta);
    fprintf(file, "%s\n", liceu);
    fprintf(file, "%.2f\n", media);
    fclose(file);

    printf("Formular salvat cu succes\n");
    getchar();
    system("cls");
}

void d1_1() {
    system("cls");
    int departament = 0;
    char optiune[100];
    printf("\033[33m///// Creare Formular /////\033[0m\n\n");
    printf("\033[35mAlegeti departamentul\033[0m\n");
    printf("\033[96m1.\033[0m Matematica\n");
    printf("\033[96m2.\033[0m Matematica si Informatica\n");
    printf("\033[96m3.\033[0m Informatica Romana\n");
    printf("\033[96m4.\033[0m Informatica Engleza\n");
    printf("\033[96m5.\033[0m Informatica ID\n");
    printf("\033[96m6.\033[0m Iesire\n");
    printf("Introduceti alegerea: ");
    scanf("%d", &departament);

    if (departament == 6) {
        system("cls");
        return;
    }

    switch (departament) {
        case 1: strcpy(optiune, "Matematica"); break;
        case 2: strcpy(optiune, "Matematica si Informatica"); break;
        case 3: strcpy(optiune, "Informatica Romana"); break;
        case 4: strcpy(optiune, "Informatica Engleza"); break;
        case 5: strcpy(optiune, "Informatica ID"); break;
        default: printf("Alegeti o optiune valida!\n"); return;
    }
    formulare(optiune);
    date();
}
void d1_2() {
    system("cls");
    int departament = 0;
    char optiune[100];
    printf("\033[33m///// Creare Formular /////\033[0m\n\n");
    printf("\033[35mAlegeti specializarea\033[0m\n");
    printf("\033[96m1.\033[0m Arte plastice (Fotografie)\n");
    printf("\033[96m2.\033[0m Arte plastice (Pictura)\n");
    printf("\033[96m3.\033[0m Arte plastice (Grafica)\n");
    printf("\033[96m4.\033[0m Arte plastice (Sculptura)\n");
    printf("\033[96m5.\033[0m Conservare - Restaurare\n");
    printf("\033[96m6.\033[0m \033[91mIesire\033[0m\n");
    printf("Introduceti alegerea: ");
    scanf("%d", &departament);

    if (departament == 6) {
        system("cls");
        return;
    }

    switch (departament) {
        case 1: strcpy(optiune, "Arte plastice(Fotografie)"); break;
        case 2: strcpy(optiune, "Arte plastice(Pictura)"); break;
        case 3: strcpy(optiune, "Arte plastice(Grafica)"); break;
        case 4: strcpy(optiune, "Arte plastice(Sculptura)"); break;
        case 5: strcpy(optiune, "Conservare-Restaurare"); break;
        default: printf("Alegeti o optiune valida!\n"); return;
    }

    formulare(optiune);
    date();
}

void d1_3() {
    system("cls");
    int departament = 0;
    char optiune[100];
    printf("\033[33m///// Creare Formular /////\033[0m\n\n");
    printf("\033[35mAlegeti specializarea\033[0m\n");
    printf("\033[96m1.\033[0m Fizica\n");
    printf("\033[96m2.\033[0m Fizica Informatica\n");
    printf("\033[96m3.\033[0m Fizica Medicala\n");
    printf("\033[96m4.\033[0m \033[91mIesire\033[0m\n");
    printf("Introduceti alegerea: ");
    scanf("%d", &departament);

    if (departament == 4) {
        system("cls");
        return;
    }

    switch (departament) {
        case 1: strcpy(optiune, "Fizica"); break;
        case 2: strcpy(optiune, "Fizica Informatica"); break;
        case 3: strcpy(optiune, "Fizica Medicala"); break;
        default: printf("Alegeti o optiune valida!\n"); return;
    }

    formulare(optiune);
    date();
}

void d1_4() {
    system("cls");
    int departament = 0;
    char optiune[100];
    printf("\033[33m///// Creare Formular /////\033[0m\n\n");
    printf("\033[35mAlegeti specializarea\033[0m\n");
    printf("\033[96m1.\033[0m Biochimie\n");
    printf("\033[96m2.\033[0m Biologie\n");
    printf("\033[96m3.\033[0m Chimie\n");
    printf("\033[96m4.\033[0m Chimie Medicala\n");
    printf("\033[96m5.\033[0m Stiinte aplicate in criminalistica\n");
    printf("\033[96m6.\033[0m Geografie\n");
    printf("\033[96m7.\033[0m Geografia turismului\n");
    printf("\033[96m8.\033[0m Planificare teritoriala\n");
    printf("\033[96m9.\033[0m Geoinformatica\n");
    printf("\033[96m10.\033[0m Cartografie\n");
    printf("\033[96m11.\033[0m \033[91mIesire\033[0m\n");
    printf("Introduceti alegerea: ");
    scanf("%d", &departament);

    if (departament == 11) {
        system("cls");
        return;
    }

    switch (departament) {
        case 1: strcpy(optiune, "Biochimie"); break;
        case 2: strcpy(optiune, "Biologie"); break;
        case 3: strcpy(optiune, "Chimie"); break;
        case 4: strcpy(optiune, "Chimie Medicala"); break;
        case 5: strcpy(optiune, "Stiinte aplicate in criminalistica"); break;
        case 6: strcpy(optiune, "Geografie"); break;
        case 7: strcpy(optiune, "Geografia turismului"); break;
        case 8: strcpy(optiune, "Planificare teritoriala"); break;
        case 9: strcpy(optiune, "Geoinformatica"); break;
        case 10: strcpy(optiune, "Cartografie"); break;
        default: printf("Alegeti o optiune valida!\n"); return;
    }

    formulare(optiune);
    date();
}
void d1_5() {
    system("cls");
    int departament = 0;
    char optiune[100];
    printf("\033[33m///// Creare Formular /////\033[0m\n\n");
    printf("\033[35mAlegeti specializarea\033[0m\n");
    printf("\033[96m1.\033[0m Contabilitate si Informatica de Gestiune\n");
    printf("\033[96m2.\033[0m Economia Comertului, Turismului si Serviciilor\n");
    printf("\033[96m3.\033[0m Econimie generala si Comunicare Economica\n");
    printf("\033[96m4.\033[0m Economie si Afaceri Internationale\n");
    printf("\033[96m5.\033[0m Finante si Banci\n");
    printf("\033[96m6.\033[0m Informatica Economica\n");
    printf("\033[96m7.\033[0m Management\n");
    printf("\033[96m8.\033[0m Marketing\n");
    printf("\033[96m9.\033[0m \033[91mIesire\033[0m\n");
    printf("Introduceti alegerea: ");
    scanf("%d", &departament);

    if (departament == 9) {
        system("cls");
        return;
    }

    switch (departament) {
        case 1: strcpy(optiune, "Contabilitate si Informatica de Gestiune"); break;
        case 2: strcpy(optiune, "Economia Comertului, Turismului si Serviciilor"); break;
        case 3: strcpy(optiune, "Econimie generala si Comunicare Economica"); break;
        case 4: strcpy(optiune, "Economie si Afaceri Internationale"); break;
        case 5: strcpy(optiune, "Finante si Banci"); break;
        case 6: strcpy(optiune, "Informatica Economica"); break;
        case 7: strcpy(optiune, "Management"); break;
        case 8: strcpy(optiune, "Marketing"); break;
        default: printf("Alegeti o optiune valida!\n"); return;
    }

    formulare(optiune);
    date();
}

void d1_6() {
    system("cls");
    int departament = 0;
    char optiune[100];
    printf("\033[33m///// Creare Formular /////\033[0m\n\n");
    printf("\033[35mAlegeti specializarea\033[0m\n");
    printf("\033[96m1.\033[0m Educatie Fizica si Sportiva ZI\n");
    printf("\033[96m2.\033[0m Educatie Fizica si Sportiva IFR\n");
    printf("\033[96m3.\033[0m Kinetoterapie si Motricitate Speciala\n");
    printf("\033[96m4.\033[0m Sport si Performanta Motrica\n");
    printf("\033[96m5.\033[0m \033[91mIesire\033[0m\n");
    printf("Introduceti alegerea: ");
    scanf("%d", &departament);

    if (departament == 5) {
        system("cls");
        return;
    }

    switch (departament) {
        case 1: strcpy(optiune, "Educatie Fizica si Sportiva ZI"); break;
        case 2: strcpy(optiune, "Educatie Fizica si Sportiva IFR"); break;
        case 3: strcpy(optiune, "Kinetoterapie si Motricitate Speciala"); break;
        case 4: strcpy(optiune, "Sport si Performanta Motrica"); break;
        default: printf("Alegeti o optiune valida!\n"); return;
    }

    formulare(optiune);
    date();
}

void d1_7() {
    system("cls");
    int departament = 0;
    char optiune[100];
    printf("\033[33m///// Creare Formular /////\033[0m\n\n");
    printf("\033[35mAlegeti specializarea\033[0m\n");
    printf("\033[96m1.\033[0m Interpretare Muzicata - Instrumente\n");
    printf("\033[96m2.\033[0m Interpretare Muzicala - Canto\n");
    printf("\033[96m3.\033[0m Muzica\n");
    printf("\033[96m4.\033[0m Artele Spectacolului(actorie)\n");
    printf("\033[96m5.\033[0m \033[91mIesire\033[0m\n");
    printf("Introduceti alegerea: ");
    scanf("%d", &departament);

    if (departament == 5) {
        system("cls");
        return;
    }

    switch (departament) {
        case 1: strcpy(optiune, "Interpretare Muzicata - Instrumente"); break;
        case 2: strcpy(optiune, "Interpretare Muzicala - Canto"); break;
        case 3: strcpy(optiune, "Muzica"); break;
        case 4: strcpy(optiune, "Artele Spectacolului(actorie)"); break;
        default: printf("Alegeti o optiune valida!\n"); return;
    }

    formulare(optiune);
    date();
}

void d1_8() {
    system("cls");
    int departament = 0;
    char optiune[100];
    printf("\033[33m///// Creare Formular /////\033[0m\n\n");
    printf("\033[35mAlegeti specializarea\033[0m\n");
    printf("\033[96m1.\033[0m Limba si Literatura Romana\n");
    printf("\033[96m2.\033[0m Filologie clasica\n");
    printf("\033[96m3.\033[0m Istorie\n");
    printf("\033[96m4.\033[0m Teologie Ortodoxa\n");
    printf("\033[96m5.\033[0m Filosofie\n");
    printf("\033[96m6.\033[0m \033[91mIesire\033[0m\n");
    printf("Introduceti alegerea: ");
    scanf("%d", &departament);

    if (departament == 6) {
        system("cls");
        return;
    }

    switch (departament) {
        case 1: strcpy(optiune, "Limba si Literatura Romana"); break;
        case 2: strcpy(optiune, "Filologie clasica"); break;
        case 3: strcpy(optiune, "Istorie"); break;
        case 4: strcpy(optiune, "Teologie Ortodoxa"); break;
        case 5: strcpy(optiune, "Filosofie"); break;
        default: printf("Alegeti o optiune valida!\n"); return;
    }

    formulare(optiune);
    date();
}

void d1_9() {
    system("cls");
    int departament = 0;
    char optiune[100];
    printf("\033[33m///// Creare Formular /////\033[0m\n\n");
    printf("\033[35mAlegeti specializarea\033[0m\n");
    printf("\033[96m1.\033[0m Asistenta Sociala\n");
    printf("\033[96m2.\033[0m Asistenta Sociala ID\n");
    printf("\033[96m3.\033[0m Psihologie\n");
    printf("\033[96m4.\033[0m Resurse Umane\n");
    printf("\033[96m5.\033[0m Sociologie\n");
    printf("\033[96m6.\033[0m Pedagogie\n");
    printf("\033[96m7.\033[0m Psihopedagogie Speciala\n");
    printf("\033[96m8.\033[0m Pedagogia Invatamantului Primar si Prescolar\n");
    printf("\033[96m9.\033[0m \033[91mIesire\033[0m\n");
    printf("Introduceti alegerea: ");
    scanf("%d", &departament);

    if (departament == 9) {
        system("cls");
        return;
    }

    switch (departament) {
        case 1: strcpy(optiune, "Asistenta Sociala"); break;
        case 2: strcpy(optiune, "Asistenta Sociala ID"); break;
        case 3: strcpy(optiune, "Psihologie"); break;
        case 4: strcpy(optiune, "Resurse Umane"); break;
        case 5: strcpy(optiune, "Sociologie"); break;
        case 6: strcpy(optiune, "Pedagogie"); break;
        case 7: strcpy(optiune, "Psihopedagogie Speciala"); break;
        case 8: strcpy(optiune, "Pedagogia Invatamantului Primar si Prescolar"); break;

        default: printf("Alegeti o optiune valida!\n"); return;
    }

    formulare(optiune);
    date();
}

void d1_10() {
    system("cls");
    int departament = 0;
    char optiune[100];
    printf("\033[33m///// Creare Formular /////\033[0m\n\n");
    printf("\033[35mAlegeti specializarea\033[0m\n");
    printf("\033[96m1.\033[0m Administratie Publica\n");
    printf("\033[96m2.\033[0m Comunicare si Relatii Publice\n");
    printf("\033[96m3.\033[0m Jurnalism\n");
    printf("\033[96m4.\033[0m Media Digitala\n");
    printf("\033[96m5.\033[0m Publicitate\n");
    printf("\033[96m6.\033[0m Relatii Internationale si Studii Europene\n");
    printf("\033[96m7.\033[0m Stiinte Politice\n");
    printf("\033[96m8.\033[0m Studii de Securitate\n");
    printf("\033[96m9.\033[0m \033[91mIesire\033[0m\n");
    printf("Introduceti alegerea: ");
    scanf("%d", &departament);

    if (departament == 9) {
        system("cls");
        return;
    }

    switch (departament) {
        case 1: strcpy(optiune, "Administratie Publica"); break;
        case 2: strcpy(optiune, "Comunicare si Relatii Publice"); break;
        case 3: strcpy(optiune, "Jurnalism"); break;
        case 4: strcpy(optiune, "Media Digitala"); break;
        case 5: strcpy(optiune, "Publicitate"); break;
        case 6: strcpy(optiune, "Relatii Internationale si Studii Europene"); break;
        case 7: strcpy(optiune, "Stiinte Politice"); break;
        case 8: strcpy(optiune, "Studii de Securitate"); break;
        default: printf("Alegeti o optiune valida!\n"); return;
    }

    formulare(optiune);
    date();
}



void f1() {
    system("cls");
    int facultate = 0;
    printf("\033[33m///// Creare Formular /////\033[0m\n\n");
    printf("\033[35m Alegeti facultatea\033[0m\n");
    printf("\033[96m1.\033[0m Facultatea de Matematica si Informatica\n");
    printf("\033[96m2.\033[0m Facultatea de Arte si Design\n");
    printf("\033[96m3.\033[0m Facultatea de Fizica\n");
    printf("\033[96m4.\033[0m Facultatea de Chimie, Biologie, Geografie\n");
    printf("\033[96m5.\033[0m Facultatea de Economie si de Administrare a Afacerilor\n");
    printf("\033[96m6.\033[0m Facultatea de Educatie Fizica si Sport\n");
    printf("\033[96m7.\033[0m Facultatea de Muzica si Teatru\n");
    printf("\033[96m8.\033[0m Facultatea de Litere, Istorie, Filosofie si Teologie\n");
    printf("\033[96m9.\033[0m Facultatea de Sociologie si Psihologie\n");
    printf("\033[96m10.\033[0m Facultatea de Stiinte ale Guvernarii si Comunicarii\n");
    printf("\033[96m11.\033[0m \033[31mIesire\033[0m\n");
    printf("Introduceti alegerea: ");
    scanf("%d", &facultate);

    switch (facultate) {
        case 1:
            formulare("Facultatea de Matematica si Informatica");
            d1_1();
            break;
        case 2:
            formulare("Facultatea de Arte si Design");
            d1_2();
            break;
        case 3:
            formulare("Facultatea de Fizica");
            d1_3();
            break;
        case 4:
            formulare("Facultatea de Chimie, Biologie, geografie");
            d1_4();
            break;
        case 5:
            formulare("Facultatea de Economie si de Administrare a afacerilor");
            d1_5();
            break;
        case 6:
            formulare("Facultatea de educatie Fizica si Sport");
            d1_6();
            break;
        case 7:
            formulare("Facultatea de Muzica si Teatru");
            d1_7();
            break;
        case 8:
            formulare("Facultatea de Litere, Istorie, Filosofie si Teologie");
            d1_8();
            break;
        case 9:
            formulare("Facultatea de Sociologie si Psihologie");
            d1_9();
            break;
        case 10:
            formulare("Facultatea de Stiinte ale Guvernarii si Comunicarii");
            d1_10();
            break;
        case 11:
            system("cls");
            return;
        default:
            printf("Alegeti o optiune valida!\n");
    }
}

void v2_1() {
    system("cls");
    int universitate = 0;
    printf("\033[33m///// Creare Formular /////\033[0m\n\n");
    printf("\033[35mAlegeti universitatea: \033[0m\n");
    printf("\033[96m1.\033[0m Universitatea de Vest Timisoara\n");
    printf("\033[96m2.\033[0m \033[91mIesire\033[0m\n");
    printf("Introduceti alegerea: ");
    scanf("%d", &universitate);

    if (universitate == 2) {
        system("cls");
        return;
    }

    if (universitate == 1) {
        formulare("Universitatea de Vest Timisoara");
        f1();
    } else {
        printf("Alegeti o optiune valida!\n");
    }
}

void v1_1() {
    int choice_2 = 0;
    printf("\033[33m///// Creare Formular /////\033[0m\n\n");
    printf("\033[96m1.\033[0m Creati un formular\n");
    printf("\033[96m2.\033[0m \033[91mInapoi\033[0m\n");
    printf("Introduceti alegerea: ");
    scanf("%d", &choice_2);

    switch (choice_2) {
        case 1:
            v2_1();
            break;
        case 2:
            system("cls");
            break;
        default:
            printf("Alegeti o optiune valida!\n");
    }
}

void v1_2() {
    system("cls");
    afiseaza_intreg_fisierul();
    int choice_2 = 0;
    do {
        printf("\n\033[96m1.\033[0m \033[91mInapoi\033[0m\n");
        printf("Introduceti alegerea: ");
        scanf("%d", &choice_2);
        if (choice_2 != 1)
            printf("Alegeti o optiune valida!\n");
    } while (choice_2 != 1);
    system("cls");
}

int main() {
    int choice_1 = 0;
    while (1) {
        printf("\n\033[33m///// MENIU /////	\033[0m\n");
        printf("\033[96m1.\033[0m Inscriere facultate\n");
        printf("\033[96m2.\033[0m Vizualizare formulare precedente\n");
        printf("\033[96m3.\033[0m Statistici\n");
        printf("\033[96m4.\033[0m \033[91mIesire\033[0m\n");
        do {
            printf("Introduceti alegerea: ");
            scanf("%d", &choice_1);
        } while (choice_1 < 1 || choice_1 > 4);

        system("cls");

        switch (choice_1) {
            case 1:
                v1_1();
                break;
            case 2:
                v1_2();
                break;
            case 3:
                statistici();
                break;
            case 4:
                printf("\033[33mIesire...\033[0m\n");
                return 0;
        }
    }
    return 0;
}
