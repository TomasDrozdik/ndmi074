#include <stdio.h>
#include <string.h>

struct osoba {
    char jmeno[20];
    int cislo_bot;
};

#define SORT_PREFIX podle_cisla
#define SORT_KEY(x) ((x).cislo_bot)
#define SORT_TYPE struct osoba
#include "gsort.h"

#undef SORT_PREFIX
#undef SORT_TYPE
#undef SORT_CMP
#define SORT_PREFIX podle_jmena
#define SORT_TYPE struct osoba
#define SORT_CMP(x,y) (strcmp((x).jmeno, (y).jmeno))
#include "gsort.h"

struct osoba pole[3] = {
    {"Franta", 42},
    {"Pepa",   38},
    {"Lenka",  40},
};

void vypis() {
    for (int i = 0; i < 3; i++) {
        printf("%-10s %3d\n", pole[i].jmeno, pole[i].cislo_bot);
    }
}

int main() {
    podle_cisla_sort(pole, 3);
    vypis();
    podle_jmena_sort(pole, 3);
    vypis();
}
