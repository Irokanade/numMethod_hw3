//
//  main.c
//  numMethod_hw3
//
//  Created by Michael Leong on 23/09/2022.
//

#include <stdio.h>
#include <math.h>

double f1(double x) {
    return pow(x, 5)+x-1;
}

double f2(double x) {
    return log(x)+(x*x)-3;
}

double f3(double x) {
    return sin(x)-(6*x)-5;
}

double iterateFol(double (*f1)(double x), double x1, double x2) {
    return x1-(f1(x1)*(x1-x2))/(f1(x1)-f1(x2));
}

double secantMethod(double (*f1)(double x), double x0, double x1) {
    double x2 = iterateFol(f1, x0, x1);
    
    do {
        double temp = x2;
        x2 = iterateFol(f1, x1, x2);
        x1 = temp;
        //printf("%lf\n", x2);
    } while(!(fabs(x2-x1) < 0.00001));
    
    return x2;
}

int main(int argc, const char * argv[]) {
    double (*f1_ptr)(double) = &f1;
    double (*f2_ptr)(double) = &f2;
    double (*f3_ptr)(double) = &f3;
    
    printf("f1: %lf\n", secantMethod(f1_ptr, 0, 1));
    printf("f2: %lf\n", secantMethod(f2_ptr, 0.5, 0.6));
    printf("f3: %lf\n", secantMethod(f3_ptr, -0.5, -0.1));
    
    
    
    return 0;
}
