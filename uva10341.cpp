#include <stdio.h>
#include <math.h>
 
#define EPS 1e-7
 
int p,q,r,s,t,u;
 
double f(double x){
  return p*exp(-x) + q*sin(x) + r*cos(x) + s*tan(x) + t*x*x + u;
}
 
double bisection(){
  double lo = 0, hi = 1;
  while (lo + EPS < hi){
    double x = (lo+hi)/2;
    if (f(lo) * f(x) <= 0){
      hi = x;
    } else {
      lo = x;
    }
  }
  return (lo+hi)/2;
}

double secant(){
  if (f(0)==0) return 0;
  for (double x0=0, x1=1; ; ){               // initial guess for x0 and x1
    double d = f(x1)*(x1-x0)/(f(x1)-f(x0));  // compute delta
    if (fabs(d) < EPS) return x1;            // the guess is accurate enough
    x0 = x1;
    x1 = x1 - d;
  }
}
double fd(double x){ // the derivative of function f
  return -p*exp(-x) + q*cos(x) - r*sin(x) + s/(cos(x)*cos(x)) + 2*t*x;
}
 
double newton(){
  if (f(0)==0) return 0;
  for (double x=0.5; ;){             // initial guess x = 0.5
    double x1 = x - f(x)/fd(x);      // x1 = next guess
    if (fabs(x1-x) < EPS) return x;  // the guess is accurate enough
    x = x1;
  }
}
int main(){
	 while (scanf("%d %d %d %d %d %d",&p,&q,&r,&s,&t,&u)!=EOF){
    if (f(0) * f(1) > 0){
      puts("No solution");
    } else {
      printf("%.4lf\n", newton());
    }
  }
}