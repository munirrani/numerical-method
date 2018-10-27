//
//  main.c
//  Programming
//
//  Created by Munir Mohamad Rani on 16/09/2018.
//  Copyright © 2018 Munir Rani. All rights reserved.
//

#include <stdio.h>
#include <math.h>

float function(float d) {
    float d1;
    d1 = d + log(d);
    return d1;
}

float functionIntegrated(float d) {
    float d1;
    d1 = 1 + 1/d;
    return d1;
}


float bisectionMethod (float a, float b) {
    
     static float c_ai = 1;
     float c,a_i,b_i,c_i;
    
     c = 0.0;
     a_i = 0;
     b_i = 0;
     c_i = c_ai;
     
     int i = 1;
     
     while (c_i != 0) {
         c = (a + b) / 2;
         a_i = function(a);
         b_i = function(b);
         c_i = function(c);
     
         printf("a_i: %f\t", a_i);
         printf("b_i: %f\t", b_i);
         printf("c_i: %f\n", c_i);
     
         if ((b_i * c_i) < 0) {
            a = c; // b kekal
        } else {
            b = c; // a kekal
        }
         i++;
         printf("Number of iterations: %d\n", i); // number of iterations
         if (fabs(c_i) < 0.0000091) {
            break;
        }
     }

     return c;
}

float linearInterpolationMethod (float a, float b) {
    
     static float c_ai = 1;
     float c,a_i,b_i,c_i;
    
     c = 0.0;
     a_i = 0;
     b_i = 0;
     c_i = c_ai;
     
     int i = 0;
     
     while (c_i != 0) {
     
         c = ((a * function(b)) - (b * function(a)) / (function(b) - function(a)));
         a_i = function(a);
         b_i = function(b);
         c_i = function(c);
     
         if ((b_i * c_i) < 0) {
             a = c; // b kekal
         } else {
                b = c; // a kekal
         }
     
         printf("a_i: %f\t", a_i);
         printf("b_i: %f\t", b_i);
         printf("c_i: %f\n", c_i);
     
         i++;
         printf("Number of iterations: %d\n", i);
     
        if (fabs(c_i) < 0.0000005) {
                break;
        }
     }
    
     return c;
}

float newtonRaphson (float a) {
    
    static float a_fa = 1;
    float a_f, b;
    
    a_f = a_fa;
    b = 0.0;
    
    int i = 0;
    
    while (a_f != 0) {
        b = a - (function(a) / functionIntegrated(a));
        printf("b: %f\n", b);
        
        a_f = function(a);
        
        a = b;
        
        i++;
        printf("Number of iterations: %d\n", i);
        
        if (fabs(a_f) < 0.0000005) {
            break;
        }
    }
    return a;
}

int main(int argc, const char * argv[]) {
    
    int selection = 0;
    float firstValue, secondValue;
    float root;
    
    printf("Please select method \n");
    printf("1 - Bisection Method \n");
    printf("2 - Linear Interpolation Method \n");
    printf("3 - Newton Raphson Method \n");
    printf("Selection: ");
    scanf("%d", &selection);
    
    if (selection == 1) { // Bisection
        printf("Enter first value: ");
        scanf("%f", &firstValue);
        printf("Enter second value: ");
        scanf("%f", &secondValue);
        
        root = bisectionMethod(firstValue, secondValue);
        
    } else if (selection == 2) { // Linear Interpolation
        printf("Enter first value: ");
        scanf("%f", &firstValue);
        printf("Enter second value: ");
        scanf("%f", &secondValue);
        
        root = linearInterpolationMethod(firstValue, secondValue);
    } else if (selection == 3) { // Newton Raphson Method
        printf("Enter first value: ");
        scanf("%f", &firstValue);
        
        root = newtonRaphson(firstValue);
    } else {
        printf("Please try again \n");
        root = 0.0;
    }
    printf("The root is %f\n", root);
    
    return 0;
}
