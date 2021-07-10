#ifndef __STRUCS_H__

#define __STRUCS_H__

// ---error_codes---------------
#define OK              0
#define ARGS_ERROR      1
#define FILE_ERROR      2
#define ALLOC_ERROR     3
#define UNEXISTING_FILE 4
#define INPUT_ERROR     5
#define INCORECT_DATE   6
#define FILE_INF_ERROR  7
//------------------------------

// ---other constants-----------------
#define CINEMA_INVENTION_DATE 1891
#define FILENAME_SIZE   80
//------------------------------------

// structures--------------
typedef struct{
    char *title;
    char *director_name;
    int   year;
}film_info;
//-------------------------

#endif