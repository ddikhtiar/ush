#ifndef USH_H
#define USH_H

#include "../libmx/inc/libmx.h"
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdbool.h>
#include <wchar.h>
#include <fcntl.h>
#include <stdio.h>
#include <string.h>
#include <dirent.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/xattr.h>
#include <sys/ioctl.h>
#include <sys/types.h>
#include <pwd.h>
#include <uuid/uuid.h>
#include <grp.h>
#include <errno.h>
#include <time.h>
#include <sys/types.h>
#include <sys/acl.h>

typedef struct s_parse {    //Лист списка фрагментов исходной строки
    char *frgmnt;           //Строка-фрагмент исходной строки, содержащий 1 процесс
    struct s_parse *next_f; //Следующий лист
}              t_parse;

typedef struct s_bin {    //Лист списка исполнения процессов 
    int status;           //Зависимость вызова процесса [-1 - зависит от "||"; 0 - не вызывается; 1 - зависит от "&&"; 2 - независим]
    char *commandor;      //Название процесса
    char **solders;       //Массив строк с аргументами, которые будут переданы процессу при вызове
    struct s_bin *next_c; //Следующий лист
}              t_bin;

t_bin *mx_parser(const char *str);                            // Переводит входящую строку в список функций с аргументами
t_parse *mx_separate(const char *str);                        // Разделяет входящую строку на фрагменты по делиметрам: ";", "&&", "||"
void mx_push_parse_back(t_parse **sep_list, const char *str); // Добавляет фрагмент в конец списка фрагментов
bool mx_quotes(int *q, char c);                               // Меняет значение переменной, означающей наличие кавычек
// void mx_quotes(int *q, char c);
void mx_del_parse_list(t_parse **sep_list);                   // Удаляет список фрагментов
void mx_replacement(char **str);                              // Заменяет участки с вызовом переменных или функций их значениями: &(...); `...`
void mx_metamorph(t_bin **army, t_parse *puzzle);             // Выделяет из строки название вызываемой функции и передаваемые ей аргументы
t_bin *mx_parse_to_bin(char **str);                           // Преобразовывет строку в лист исполнительного списка
int mx_status(char **str);                                    // Возвращает число, соответствующее выполняемости вызываемого процесса и переводит указатель
char *mx_commandor(char **str);                               // Возвращает строку с именем выполняемого процесса и переводит указатель
char **mx_solders(const char *str);                           // Возвращает массив аргументов, передаваемых процессу
void mx_shift_spaces(char **str);                             // Сдвигает указатель на начало следующего слова, пропуская пробелы
int mx_substr_lenght(const char *str);                        // Считает длину слова
void mx_push_army_back(t_bin **nest, t_bin *chick);           // Добавляет лист в конец исполнительного списка

void mx_no_such_user(char *str);
char *mx_tilda(char *str);
char *mx_dollar(char *str);

#endif
