#include<studio.h>

int main() {
int x = 20, y = 0x400, z = 0;
int* p = &x;

/* the '*' in the line and the next 3 lines eman 4 different thing! */
int* pointer_type = &y; /*The '*' indicates this is a pointer type*/
*pointer_type = 0x400; /* the '*' is the de-reference operator */
x =10 * 2; /*The '*' is the multiplication operator */
int * k = *p * 10; /* intializing a pointer called k and instaiating it to pointer times 10*/ 

printf("x: %10d, %p, %lu\n", x, void *) &x, sizeof(x));
printf("x: %10d, %p, %lu\n", y, void *) &y, sizeof(y));
printf("x: %10d, %p, %lu\n", z, void *) &z, sizeof(z));
printf("p: %10d, %p, %lu (value of *p = %d)\n",( void *) &p,( void *) p, sizeof(p),*p);
printf("\n p++ makes p point to the next integer\n");
p++;
printf("p: %10d, %p, %lu (value of *p = %d)\n",( void *) &p,( void *) &p, sizeof(p),*p);



