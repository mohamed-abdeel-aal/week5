#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

typedef struct
{
    char type[10];
    union
    {
        struct
        {
            double radius;
        } circle;
        struct
        {
            double side;
        } square;
        struct
        {
            double length, width;
        } rectangle;
    } dimensions;
} Shape;
double calculate_area(Shape *shape)
{
    if (strcmp(shape->type, "circle") == 0)
    {
        return M_PI * pow(shape->dimensions.circle.radius, 2);
    }
    else if (strcmp(shape->type, "square") == 0)
    {
        return pow(shape->dimensions.square.side, 2);
    }
    else if (strcmp(shape->type, "rectangle") == 0)
    {
        return shape->dimensions.rectangle.length * shape->dimensions.rectangle.width;
    }
    else
    {
        printf("Unknown shape type!\n");
        return -1;
    }
}
int main()
{
    Shape shape;


    printf("Enter shape type (circle, square, rectangle): ");
    scanf("%s", shape.type);


    if (strcmp(shape.type, "circle") == 0)
    {
        printf("Enter radius: ");
        scanf("%lf", &shape.dimensions.circle.radius);
    }
    else if (strcmp(shape.type, "square") == 0)
    {
        printf("Enter side length: ");
        scanf("%lf", &shape.dimensions.square.side);
    }
    else if (strcmp(shape.type, "rectangle") == 0)
    {
        printf("Enter length: ");
        scanf("%lf", &shape.dimensions.rectangle.length);
        printf("Enter width: ");
        scanf("%lf", &shape.dimensions.rectangle.width);
    }
    else
    {
        printf("Unknown shape type!\n");
        return 1;
    }


    double area = calculate_area(&shape);
    if (area != -1)
    {
        printf("The area of the %s is: %.2f\n", shape.type, area);
    }

    return 0;
}
