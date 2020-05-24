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

typedef struct s_parse {    // Лист списка фрагментов исходной строки
    char *frgmnt;           // Строка - фрагмент исходной строки, содержащая 1 процесс
    struct s_parse *next_f; // Следующий лист
}              t_parse;

typedef struct s_bin {      // Структура исполнения процессов 
    int status;             // Зависимость вызова процесса [-1 - зависит от "||"; 0 - не вызывается; 1 - зависит от "&&"; 2 - независим]
    char *commandor;        // Название процесса
    char **solders;         // Массив строк с аргументами, которые будут переданы процессу при вызове
}              t_bin;

t_parse *mx_separate(char *str);                                  // Разделяет входящую строку на фрагменты по делиметрам: ";", "&&", "||" и "&"
bool mx_correct_delimeter(const char *str);                       // Проверяет на корректность использования делиметров "&&", "||" и "&"
int mx_delim(const char *str);                                    // Проверяет строку на делиметр и возвращает его длину при нахождении (1 или 2)
bool mx_close_brackets(char c, int *r_b, int *f_b, int sw_quote); // Проверяет входящую строку на закрытие скоб
void mx_print_parse_error(const char *str);                       // Выводит ошибку парсинга около скобы или делиметра
void mx_push_parse_back(t_parse **sep_list, const char *str);     // Добавляет фрагмент в конец списка фрагментов
bool mx_quotes(int *q, char c);                                   // Меняет значение переменной, означающей наличие кавычек
t_bin *mx_metamorph(t_parse *puzzle);                             // Выделяет из строки название вызываемой функции и передаваемые ей аргументы
void mx_replacement(char **str);                                  // Находит и заменяет в строке "~" и "$"(из environ)
char *mx_tilda(char *str);                                        // Заменяет "~" в строке 
void mx_no_such_user(char *str);                                  // Выводит ошибку при неправильном использовании "~"
char *mx_dollar(char *str);                                       // Заменяет "$"(из environ) в строке
t_bin *mx_parse_to_bin(char **str);                               // Преобразовывет строку в структуру для запуска нового процесса
int mx_status(char **str);                                        // Возвращает число, соответствующее выполняемости вызываемого процесса и переводит указатель
char *mx_commandor(char **str);                                   // Возвращает строку с именем выполняемого процесса и переводит указатель
char **mx_solders(const char *str);                               // Возвращает массив аргументов, передаваемых процессу
void mx_shift_spaces(char **str);                                 // Сдвигает указатель на начало следующего слова, пропуская пробелы
int mx_substr_lenght(const char *str);                            // Считает длину слова
void mx_postparse(t_bin *strct);                                  // Убирает кавычки и бэкслеш после основного парса, а также раскрывает диапазон
void mx_del_quotes(t_bin *strct);                                 // Удаляет кавычки после основного парсинга
void mx_del_backslash(t_bin *strct);                              // Удаляет бэкслеш и заменяет конструкции с ним на соответствующие символы ASCII 
int mx_del_character(char **str, char c);                         // Находит в строке первое вхождение указанного символа, удаляет его и возваращает его индекс
void mx_range(t_bin *strct);                                      // Раскрывает конструкцию диапазона {}
void mx_del_struct_bin(t_bin **army);                             // Удаляет структуру типа t_bin и очищает память
void mx_del_parse_list(t_parse **sep_list);                       // Удаляет список фрагментов

#endif
