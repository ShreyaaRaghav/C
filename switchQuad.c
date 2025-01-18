#include<stdio.h>
#include<math.h> 
void main() {
    float a, b, c, disc, root1, root2, real, img;
    
    printf("Enter coefficients a, b and c: ");
    scanf("%f %f %f", &a, &b, &c);

    disc = b * b -( 4 * a * c);

    switch (disc > 0) 
{
        case 1:  
            root1 = (-b + sqrt(disc)) / (2 * a);
            root2 = (-b - sqrt(disc)) / (2 * a);
            printf("Roots are real and distinct: %.2f and %.2f\n", root1, root2);
            break;

        case 0:              switch (disc == 0) 
{
                case 1:
                    root1 = root2 = -b / (2 * a);
                    printf("Roots are real and equal: %.2f and %.2f\n", root1, root2);
                    break;

                default: 
                    real = -b / (2 * a);
                    img = sqrt(-disc) / (2 * a);
                    printf("Roots are complex and distinct: %.2f + %.2fi and %.2f - %.2fi\n", 
                            real, img, real, img);
                    break;
            }
            break;
    }
}
