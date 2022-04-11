#include <stdio.h>
#include <math.h>
#include <stdlib.h>

void solution();
void check_input(double * a, double * b, double * c);
int check_equation_structure(double a, double b, double c);
int double_comparsion(double x1, double x2);
double linear_equation(double b, double c);
double quadratic_equation_check(double a, double b,double c);
double quadratic_equation(double a, double b, double c);
double one_root(double a, double b, double c);
double second_root(double a, double b, double c);
double sqrt(double t);
int main(){
    
    printf("Write the numbers\n");
    solution();
    return 0;
}
// в solution должно быть что-то, отвечающее только за решение без печатания, и что-то, работающее с печатью отдельно 
void solution(){
    //define a, b, c here
    double a, b, c; // init with NAN
    check_input(&a,&b,&c);
    if(check_equation_structure(a,b,c) == 1){ // a == 0 + move all coeff checks to quadratic equation solver
        if (linear_equation(b,c) == 1){ // one call
            printf("Any answer is correct\n");
        }
        if (linear_equation(b,c) == 0){
            printf("There's no answer\n");
        }
        else {
            printf("The answer is %lf\n", linear_equation(b,c));
        }
    }
    else{
        if(quadratic_equation_check(a, b, c) == 0){ // same
            printf("There's no answer\n");
        }
        if(quadratic_equation_check(a, b, c) == 1){
            printf("The answer is %lf\n", one_root(a, b, c) );
        }
        if(quadratic_equation_check(a, b, c) == 2){
            printf("The answer is %lf %lf\n", one_root(a, b, c),second_root(a, b, c));
        }
    }
    
}
void check_input(double * a, double * b, double * c){
    if (scanf("%lf %lf %lf", a, b, c) < 3){// better status, error in main function
        exit(-1);
    }
}
int check_equation_structure(double a, double b, double c){ 
    return a == 0; 
}

int double_comparsion(double x1, double x2){
    if (abs(x1 -x2) < 0.000001){
        return 1;
    }
    return 0;// shorter
}

double linear_equation(double b, double c){ // solve name + return int status & write root to ptr
    if (b == 0){
        if (c == 0){
            return 1;
        }
        else{
            return 0;
        }  
    }
    if (b != 0){ // no checks
        double x;
        x = -c/b;
        return x;
    }  
    return 5;
}

double quadratic_equation_check(double a, double b, double c){ // bad name
    double D = (b*b - 4*a*c);
    if (D < 0){
        return 0;
    }
    else {
        double sqD = sqrt(D);
        double x1 = ((-b +  sqD)/2*a);
        double x2 = ((-b -  sqD)/2*a);
        if (double_comparsion(x1, x2) == 1){
            return 1; // 1 root
        } 
        else {
            return 2; //2 roots
        }
    }
}

double one_root(double a, double b, double c){
    double D = (b*b - 4*a*c);
    double sqD = sqrt(D);
    double x1 = ((-b +  sqD)/2*a);
    double x2 = ((-b - sqD)/2*a);
    if (double_comparsion(x1, x2) == 1){
            return x1; // 1 root
    }
    return x1;
}

double second_root(double a, double b, double c){
    double D = (b*b - 4*a*c);
    double sqD = sqrt(D);
    double x2 = ((-b - sqD)/2*a);
    return x2;
}









        
    