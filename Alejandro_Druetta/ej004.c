#include <stdio.h>
#include <math.h>

int main(void)
{
    float x1, y1, x2, y2, dx, dy, distancia;

    printf("Punto 1, coordenada x: ");
    scanf("%f", &x1);
    printf("Punto 1, coordenada y: ");
    scanf("%f", &y1);
    printf("Punto 2, coordenada x: ");
    scanf("%f", &x2);
    printf("Punto 2, coordenada y: ");
    scanf("%f", &y1);

    dx = x2 - x1;
    dy = y2 - y1;

    distancia = sqrt(dx * dx + dy *dy);

    printf("La distancia entre los dos puntos es: %f\n", distancia);

    return 0;
}
