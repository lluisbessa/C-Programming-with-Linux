#include <curses.h>
#include <menu.h>
#include <stdlib.h>
#include <form.h>
#include <ctype.h>
#include <string.h>
#include <json-c/json.h>

void doFormSearch();
void doFormSearchNoGrade();
int searchStudent(char *, char *, char *);
int searchStudentNoSubject(char *, char *);
void doFormAdd();
void addStudent(char *, char *);
void changeStudent();
void updateStudent(char *, char *, char *, char *, char *, char *);
void doFormRemove();
void removeStudent(char *, char *, char *);
char* trim_whitespaces(char *);
