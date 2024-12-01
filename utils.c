#include"header.h"

enum types get_type(char l) {
  switch (l) {
    case 'N':
      return N;
    case 'A':
      return A;
    case 'U':
      return U;
    case 'R':
      return R;
    default:
      return AUTRE;
  }
}

//la fonction regx pour trouver le pattern match

MatchResults find_matches(const char *text, const char *pattern) {
    regex_t regex;
    regmatch_t pmatch;
    MatchResults results;
    int status, offset = 0;

    results.matches = NULL;
    results.count = 0;

    if (regcomp(&regex, pattern, REG_EXTENDED) != 0) {
        return results;
    }

    while ((status = regexec(&regex, text + offset, 1, &pmatch, 0)) == 0) {
        if (results.matches == NULL) {
            results.matches = malloc(sizeof(MatchInfo));
            
        } 
        else {
            results.matches = realloc(results.matches, sizeof(MatchInfo) * (results.count + 1));
        }
        
        int match_start = offset + pmatch.rm_so;
        int match_end = offset + pmatch.rm_eo;

        results.matches[results.count].start = match_start;
        results.matches[results.count].end = match_end;
        results.matches[results.count].matched_str = strndup(text + match_start, match_end - match_start);

        results.count++;
        offset += pmatch.rm_eo; // 검색 시작 위치 업데이트
    }

    regfree(&regex);
    return results;
}
//liberer les mémoires alluées
void free_match_results(MatchResults results) {
    for (int i = 0; i < results.count; i++) {
        free(results.matches[i].matched_str);
    }
    free(results.matches);
}
int compareMatchInfoStr(MatchInfo info, const char* str) {
    if (strcmp(info.matched_str, str) == 0) {
        return 1; // 문자열이 같다면 1을 반환
    }
    return 0; // 다르면 0을 반환
}
void freeMatchResult(MatchResult result) {
	int i;
	for (i = 0; i < result.count; i++) {

		free(result.matches[i]);  
	}
	free(result.pos);
	free(result.matches);
}
