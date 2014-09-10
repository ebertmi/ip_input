#include <stdio.h>

int main(void) {
    
    float zahl = 4.5f;
		int b = 8;
    
    printf("Zahl: %+*.2f\n", 5, zahl);
    printf("Zahl: %5.1f\n", zahl);
    printf("Zahl: %-5.1f\n", zahl);
    printf("Zahl: %f %%\n", zahl);
		printf("Zahl: %o \n", b);
    
    return 0;
}
