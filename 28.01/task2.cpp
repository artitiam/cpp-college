#include <iostream>
#include <cmath>

class Circle
{
private:
    float radius;

public:
    Circle() : radius(1.0) {}

    Circle(float r)
    {
        setRadius(r);
    }

    void setRadius(float r)
    {
        if (r <= 0)
        {
            std::cerr << "Радиус должен быть положительным числом\n";
            radius = 1.0;
        }
        else
        {
            radius = r;
        }
    }

    float getRadius() const
    {
        return radius;
    }

    float area() const
    {
        return M_PI * radius * radius;
    }

    float perimeter() const
    {
        return 2.0 * M_PI * radius;
    }
};

int main()
{
    Circle c1;
    std::cout << "Круг 1:\n";
    std::cout << "Радиус: " << c1.getRadius() << "\n";
    std::cout << "Площадь: " << c1.area() << "\n";
    std::cout << "Периметр: " << c1.perimeter() << "\n\n";

    Circle c2(5.0);
    std::cout << "Круг 2:\n";
    std::cout << "Радиус: " << c2.getRadius() << "\n";
    std::cout << "Площадь: " << c2.area() << "\n";
    std::cout << "Периметр: " << c2.perimeter() << "\n\n";

    c2.setRadius(-3.0);
    std::cout << "После попытки установить отрицательный радиус:\n";
    std::cout << "Радиус: " << c2.getRadius() << "\n";

    return 0;
}