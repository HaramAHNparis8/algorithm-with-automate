#include "header.h"
#include "haskcode.h"
#include "tableau.h"
// La fonction pour afficher les résultats de la fonction

MatchResult affiresetape2() {
    MatchResult res;
    int i;
    char str[MAXstr + 1]; // 스택에 메모리 할당
    printf("étape 2\n");
    printf("--------------------------------------\n");
    printf("\nAlphabet : NARU\nMotif 1 : NA+UA*R\nMotif 2 : NA+UA?U*R\n");
    strcpy(str, generate_random_string());
    printf("\nTableau de 4000 caractères :\n\n");
    printf("%s\n", str);

    // 패턴 1 매칭 결과 얻기
    res = matchPattern1(str);
    printf("Affichage table des occurrences du motif 1\n");
    printf("occ                                 [pos pts]\n");
    printf("------------------------------------------\n");
    int points[res.count];  
    for(i = 0; i < res.count; i++){
		points[i] = countnb(res.matches[i]);
	}
    
    for (i = 0; i < res.count; i++) {
        printf("%s\t\t\t\t[%d %d]\n", res.matches[i], res.pos[i], points[i]);
        insertOrUpdate(res.matches[i]);
        recordScore(points[i]);
       
    }
    printf("%d occ du 1er motif trouvees\n", res.count);
    freeMatchResult(res);


    return res;
}

MatchResult affiresetape3() {
	MatchResult res;
	int i;
	char str[MAXstr + 1]; // 스택에 메모리 할당
    printf("étape 3\n");
	printf("--------------------------------------\n");

	strcpy(str, generate_random_string());
	printf("Tableau de 4000 caractères :\n");
	printf("%s\n", str);
	// 패턴 2 매칭 결과 얻기
	res = matchPattern2(str);
	printf("\nAffichage table des occurrences du motif 2\n");
	printf("occ                                 [pos pts]\n");
	printf("------------------------------------------\n");
	int points[res.count]; 
   
	for(i = 0; i < res.count; i++){
		points[i] = countnb(res.matches[i]);
        
	}
	for (i = 0; i < res.count; i++) {
        
		printf("%s\t\t\t\t\t[%d %d]\n", res.matches[i], res.pos[i], points[i]);
        insertOrUpdate(res.matches[i]);
        recordScore(points[i]);
        
	}
	// 메모리 해제
	printf("%d occ du 2er motif trouvees\n", res.count);
	freeMatchResult(res);

	return res;

}

void affiresetape4(const char* pattern, MatchResult (*matchFunction)(const char*), const char* input, MatchResults res) {
    int i, score, score2,j;
    printf("\n----------------------------------------\n");
    printf("Étape 4 - Test: %s\n", pattern);

    MatchResult result = matchFunction(input);


    printf("Occurrences trouvée par hashtable: %d\n", result.count);
    printf("Occurrences trouvée par regex function: %d\n", res.count);
    
    printf("\nles résultat trouvé par le hastable\n");
    printf("\n-----------------------------------\n");
    for (i = 0; i < result.count; i++) {
        score = countnb(result.matches[i]);
        printf("%s\t\t[%d %d]\n", result.matches[i], result.pos[i], score);
    }



    int minCount = (result.count < res.count) ? result.count : res.count;
    
    printf("\n-----------------------------------\n");
    printf("\n les résultate après avoir vérifié par la fonction regex function\n");
    printf("\n-----------------------------------\n");
        for(i = 0; i < minCount; i++){
            // MatchInfo와 char*를 비교
            if (!compareMatchInfoStr(res.matches[i], result.matches[i])){
                printf("\n %s ->non correct\n",result.matches[i]);
            }
            else{
                printf("\n %s -> correct\n",result.matches[i]);
            }
        }
    
        
       
    
  
    printf("\n------------------------------------- \n");
    printf("\nles résultat de la regex function\n\n");
    
    for (i = 0; i < minCount; i++) {
        score2 = countnb(res.matches[i].matched_str);
        printf("%s\t\t[%d %d]\n", res.matches[i].matched_str, res.matches[i].start, score2);
    }

    freeMatchResult(result);
    free_match_results(res);
}


void affichageresexo6(){
    int nodeCount;
    double n;
    HashNode **nodes;
    printf("\n Étape 6\n");
    printf("\nOccurences differentes triees par ordre croissant du nb d'occurences Occ Nb d'occurrences\n");
    printf("---------------------------------\n");
    nodeCount = collectNodes(&nodes);
    quickSort(nodes, 0, nodeCount - 1);
    printSortedHashResults(nodes, nodeCount);
    free(nodes);
}

void affichageresexo7(){
    int nodeCount;
    double moyen;
    HashNode **nodes;
    nodeCount = collectNodes(&nodes);
    moyen = moyenoccurence(nodes);
    printf("\nÉtape 7\n");
    printf("\nle nombre d'occurence : %d\nle moyen : %f\n ",nodeCount,moyen);
    free(nodes);
}


int main(void) {
    char str[MAXstr + 1];
    strcpy(str,generate_random_string());
    const char *pattern1 = "NA+UA*R";
    const char *pattern2 = "NA+UA?U*R";
    MatchResults results1 = find_matches(str, pattern1);
    MatchResults results2 = find_matches(str, pattern2);

    initScoresAndOccurrences();
    
    initHashTable();
    affiresetape2();
    affiresetape3();
    affiresetape4("\nPattern 1\n", matchPattern1, str,results1);
    affiresetape4("\nPattern 2\n", matchPattern2, str,results2);
    
    printHashResults();
    affichageresexo6();
    affichageresexo7();
    affichageOccurrencesetcalculation(); // 평균 출력
    affichageHashTablecomparasion();
    affichagetabComparisons();
    freeHashTable();
    
    return 0;
}


