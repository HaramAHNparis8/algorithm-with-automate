#include "header.h"
char* generate_random_string() {
    static char str[MAXstr + 1];
    char chars[] = "NAUR";
    int i;
    srand(time(NULL));

    for (i = 0; i < MAXstr; i++) {
        str[i] = chars[rand() % (sizeof(chars) - 1)];
    }
    

    return str;
}
int countnb(char* str) {
    int i, count = 0;
    for (i = 0; str[i] != '\0'; i++) {
        switch (str[i]) {
            case 'A': count += 1; break;
            case 'U': count += 5; break;
            case 'N': count += 13; break;
            case 'R': count += 18; break;
        }
    }
    return count;
}



//int main(void) {
	//char* str = generate_random_string();// tester a generer le tableau
	//printf("%s\n", str);  
	//printf("res : %d ", countnb());
//
	//return 0;
//}

