#include "header.h"
#include "haskcode.h"
//le code hascode
int hashTablecompara = 0;
int calculationnbnode(){

    int count = 0,i;
    for (i = 0; i < HASH_SIZE; i++) {
        for (HashNode *node = hashTable[i]; node != NULL; node = node->next) {
            count++;
        }
    }
    return count;

}
void initHashTable() {
    for (int i = 0; i < HASH_SIZE; i++) {
        hashTable[i] = NULL;
    }
}

unsigned int hash(const char *key) {
    unsigned long int value = 0;
    while (*key != '\0') {
        value =
        value * 37 
        + *key++;
    }
    return value % HASH_SIZE;
}

void insertOrUpdate(const char *key) {
    unsigned int index = hash(key);
    HashNode *node = hashTable[index];
    while (node != NULL && strcmp(node->key, key) != 0) {
        node = node->next;
    }
    if (node == NULL) {
        node = (HashNode*) malloc(sizeof(HashNode));
        if (node == NULL) {
            fprintf(stderr, "Failed to allocate memory for HashNode\n");
            return;
        }
        strcpy(node->key, key);
        node->count = 1;
        node->next = hashTable[index];
        hashTable[index] = node;
        hashTablecompara++;
    } else {
        node->count++;
    }
}

void printHashResults() {
    printf("\nÉtape 5\n");
    printf("Ensemble des occurrences differentes (sans doublons) Occ Nb d'occurrences\n");
    printf("---------------------------------\n");
    int uniqueCount = calculationnbnode(),i;
    printf("--> %d occurrences differentes.\n", uniqueCount);
}

void swap(HashNode **a, HashNode **b) {
    HashNode *temp = *a;
    *a = *b;
    *b = temp;
}

int partition(HashNode **array, int low, int high) {
    HashNode *pivot = array[high];
    int i = low - 1;
    for (int j = low; j < high; j++) {
        if (array[j]->count < pivot->count) {
            i++;
            swap(&array[i], &array[j]);
        }
    }
    swap(&array[i + 1], &array[high]);
    return i + 1;
}

// QuickSort function to sort based on the number of occurrences
void quickSort(HashNode **array, int low, int high) {
    if (low < high) {
        int pi = partition(array, low, high);
        quickSort(array, low, pi - 1);
        quickSort(array, pi + 1, high);
    }
}

int collectNodes(HashNode ***nodeArray) {
    int count = calculationnbnode();
    *nodeArray = malloc(sizeof(HashNode*) * count);
    int idx = 0;
    for (int i = 0; i < HASH_SIZE; i++) {
        for (HashNode *node = hashTable[i]; node != NULL; node = node->next) {
            (*nodeArray)[idx++] = node;
        }
    }
    return idx;
}

void printSortedHashResults(HashNode **nodeArray, int n) {
    for (int i = 0; i < n; i++) {
        printf("%s\t\t\t %d\n", nodeArray[i]->key, nodeArray[i]->count);
    }
}

double moyenoccurence(HashNode **tab){
    int counttotal = calculationnbnode(),i,total = 0;
    double moyen;
    for (i = 0; i < counttotal; i++) {
           total += tab[i]->count;
       }
    printf("------------------------------\n");
    printf("\ntotal occurence : %d", total);
    moyen = (double)total  / counttotal;
    return moyen;
    
}


void affichageHashTablecomparasion() {
    printf("\nÉtape 8\n");
    printf("\n\n----------------------------------\n");
    printf("\nEnsemble des nb de points differents : \n");
    int uniqueCount = 0;
    printf("\n");
    for (int i = 0; i < HASH_SIZE; i++) {
        for (HashNode *node = hashTable[i]; node != NULL; node = node->next) {
            printf("%s ", node->key);  // 키는 점수를 나타내는 문자열
            uniqueCount++;
        }
    }
    printf("\n\n--> soit %d nb de points differents \n", uniqueCount);
}


void freeHashTable() {
    for (int i = 0; i < HASH_SIZE; i++) {
        HashNode *node = hashTable[i];
        while (node != NULL) {
            HashNode *temp = node;
            node = node->next;
            free(temp);
        }
        hashTable[i] = NULL;
    }
}

