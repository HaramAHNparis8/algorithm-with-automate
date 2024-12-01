#define HASH_SIZE 100

typedef struct{
    char key[1024];
    int count;
    struct HashNode *next;
} HashNode;


HashNode *hashTable[HASH_SIZE];

void initHashTable();
unsigned int hash(const char *key);
void insertOrUpdate(const char *key);
void printHashResults();
void swap(HashNode **a, HashNode **b);
int partition(HashNode **array, int low, int high);
void quickSort(HashNode **array, int low, int high);
int collectNodes(HashNode ***nodeArray);
void freeHashTable();
void printSortedHashResults(HashNode **nodes, int nodeCount);
double moyenoccurence(HashNode **tab);
int calculationnbnode();
void affichageHashTablecomparasion();
