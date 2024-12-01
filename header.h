#ifndef HEADER_H
#define HEADER_H
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <regex.h>
#define MAXstr  4000
#define NBETATS 6
#define NBTYPES 5
// NAAUR
// NA+UA*R
// NA+UA?U*R

typedef struct {
    int count;      
    int* pos; 
    char** matches; 
} MatchResult;

typedef struct {
    int start;
    int end;
    char *matched_str;
} MatchInfo;

typedef struct {
    MatchInfo *matches;
    int count;
} MatchResults;

extern int ttransit[NBETATS][NBTYPES];
extern int ttransit2[NBETATS][NBTYPES];
enum types get_type(char l);
char* generate_random_string();

enum types { N, A, U, R, AUTRE };

enum types get_type(char l);
MatchResult matchPattern1(const char* str);
void chercherpatern1();
MatchResult matchPattern2(const char* str);
MatchResults find_matches(const char *text, const char *pattern);
void chercherpatern2();
char* generate_random_string();
int countnb(char* str);
void freeMatchResult(MatchResult result);
int calculatePatternLength(const char* str, int start_index);
int compareMatchInfoStr(MatchInfo info, const char* str);
void free_match_results(MatchResults results);

#endif
