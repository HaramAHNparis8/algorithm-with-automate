#include "header.h"
#include "tableau.h"
#include "haskcode.h"

#define MAX_SCORE 100  // 점수 최대 범위

int occurrences[MAX_SCORE];  // 점수 발생 횟수 저장(tab pour stocker occurence)
int scores[MAX_SCORE];       // 각 점수 저장(tab pour stocker la note)
int totalCount = 0;          // 발생한 점수 종류 수(tab pour stocker nb de l'occurence)
int tabComparisons = 0;


void initScoresAndOccurrences() {
    memset(occurrences, 0, sizeof(occurrences));
    totalCount = 0;
}


void recordScore(int score) {
    
    if (occurrences[score] == 0) {
        scores[totalCount++] = score;
        
    }
    occurrences[score]++;
    tabComparisons++;
}

// 발생 횟수에 따라 정렬하는 함수


void echange(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}


void sortOccurrences() {
    int i,j;
    for (i = 0; i < totalCount - 1; i++) {
        for (j = i + 1; j < totalCount; j++) {
            if (occurrences[scores[i]] > occurrences[scores[j]]) {
       
                echange(&occurrences[scores[i]], &occurrences[scores[j]]);
            }
        }
    }
}


void affichageOccurrencesetcalculation() {
    sortOccurrences();
    int i;
    double total = 0,moyen;
    printf("\n----------------------------\n");
    for (i = 0; i < totalCount; i++) {
        printf("%d\t\t\t%d\n", scores[i], occurrences[scores[i]]);
        total += scores[i];
    }
    moyen = total / totalCount;
    printf("\n\nle total : %.1f\n", total);
    printf("le nombre d'occurence: %d\n",totalCount);
    printf("le moyen: %.1f\n",  moyen);
}

void affichagetabComparisons(){
    int i;
    
    printf("\n\n-----------------------------------\n");
    printf("\nEnsemble des nb de points differents : \n\n");
    for (i = 0; i < totalCount; i++) {
        printf("%d ", scores[i]);
    }
    printf("\n");
    printf("\n--> soit %d nb de points differents\n", totalCount);
}
