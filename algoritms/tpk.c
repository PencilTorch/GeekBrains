#include <stdio.h>
#include <math.h>

double f ( double x) {
return (sqrt(fabs(x)) + 5.0 * pow(x, 3.0));
}

void tpk(double arr[]) {
    for(int i = 10; i >= 0; --i){
        double y = f(arr[i]);
        if(y > 400.0) {
            printf("%d TOO LARGE \n" , i+1);
        }
        else {
            printf("%d %f \n" , i+1, y);
        }
    }
}

int main() {
double P[11];
printf("Enter 11 numbers:\n");
for(int i = 0; i < 11; ++i){
    printf("Number %d : ", i+1);
    scanf("%f", &P[i]);
}

tpk(P);

return 0;
}