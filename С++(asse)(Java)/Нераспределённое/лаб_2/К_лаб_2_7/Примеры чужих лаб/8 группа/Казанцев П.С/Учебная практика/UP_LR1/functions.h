#pragma once
void single_spaces(char*, char *);
void string_recover(char*, int);
char *search_word(char *, char *);
char *search_word_from_n(char *, char *, int);
char *delete_word(char *, char *);
char* delete_word_from_n(char *, char *, int, int);
int is_palindrom(char *);
char *insert_word_after_given_word(char *, char *, char *);
char *swap_words(char *, char *, char *, int, int);
char *change_words(char *, char *, int, char *);
void search_word_number(char *, char *);
int is_word_number(char*);
int comparator(const void *, const void *);
void my_sort_with_qsort(char *, char *);
void sort_by_number_of_digits(char *, char *);
int asmStrlen(const char *s); // длина строки
void asmStrcpy(char *str1, const char* str2); // копирование строки
void asmStrcat(char *str1, const char* str2); // добавление str2 к str1
