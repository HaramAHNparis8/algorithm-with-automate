#include "header.h"
//motif 1
// NA+UA*R ttransit
int ttransit[NBETATS][NBTYPES] = {
    {1, 0, 0, 0, 0}, {0, 2, 0, 0, 0}, {0, 2, 3, 0, 0}, {0, 3, 0, 5, 0},
};

MatchResult matchPattern1(const char* str) {
    MatchResult res;
    int state = 0, i, st_pos = -1;  // st_pos를 반복문 시작 전에 초기화
    res.count = 0;
    res.pos = malloc(MAXstr * sizeof(int));
    res.matches = malloc(MAXstr * sizeof(char*));

    if (!res.pos || !res.matches) {
        fprintf(stderr, "Memory allocation failed.\n");
        return res;
    }
    
    for (i = 0; str[i] != '\0'; i++) {
        state = ttransit[state][get_type(str[i])];
        if (state == 1) {
            st_pos = i;  // 패턴 시작 위치 갱신
        }
        if (state == 5) {  // 최종 상태에 도달했을 때
            res.pos[res.count] = st_pos;
            res.matches[res.count] = strndup(str + st_pos, i - st_pos + 1);
            if (!res.matches[res.count]) {
                fprintf(stderr, "Memory allocation for string copy failed.\n");
                freeMatchResult(res);
                return res;
            }
            res.count++;
            state = 0;  // 상태 초기화
            st_pos = -1;  // 시작 위치 초기화
        }
    }

    return res;
}

