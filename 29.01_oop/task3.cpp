#include <iostream>
#include <cmath>

class Shape
{
public:
    virtual float getPerimeter() const = 0;
    virtual float getArea() const = 0;
    virtual void move(float dx, float dy) = 0;
    virtual void rotate(float angle) = 0;
    virtual void printInfo() const = 0;
    virtual ~Shape() {}
};

class Rectangle : public Shape
{
private:
    float width, height;
    float x, y;

public:
    Rectangle(float w, float h) : width(w), height(h), x(0), y(0) {}

    float getPerimeter() const override
    {
        return 2 * (width + height);
    }

    float getArea() const override
    {
        return width * height;
    }

    void move(float dx, float dy) override
    {
        x += dx;
        y += dy;
    }

    void rotate(float angle) override
    {
    }

    void printInfo() const override
    {
        std::cout << "Прямоугольник: ширина=" << width << ", высота=" << height
                  << ", центр=(" << x << "," << y << "), периметр=" << getPerimeter()
                  << ", площадь=" << getArea() << "\n";
    }
};

class Circle : public Shape
{
private:
    float radius;
    float x, y;

public:
    Circle(float r) : radius(r), x(0), y(0) {}

    float getPerimeter() const override
    {
        return 2 * 3.14159 * radius;
    }

    float getArea() const override
    {
        return 3.14159 * radius * radius;
    }

    void move(float dx, float dy) override
    {
        x += dx;
        y += dy;
    }

    void rotate(float angle) override
    {
    }

    void printInfo() const override
    {
        std::cout << "Круг: радиус=" << radius
                  << ", центр=(" << x << "," << y << "), периметр=" << getPerimeter()
                  << ", площадь=" << getArea() << "\n";
    }
};

int main()
{
    Rectangle r(4, 3);
    Circle c(2);

    r.printInfo();
    c.printInfo();

    r.move(1, 2);
    c.move(-1, 1);

    std::cout << "\nПосле перемещения:\n";
    r.printInfo();
    c.printInfo();

    return 0;
}