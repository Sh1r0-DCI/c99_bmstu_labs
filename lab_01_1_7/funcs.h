#ifndef _FUNCS_H_

#define _FUNCS_H_

#define OK 0
#define INPUT_ERROR 1
#define EPS_INPUT_ERROR 2

double function_f(double x);
double function_s(double x, double eps);
int check_input(int rc, double x, double eps);

#endif