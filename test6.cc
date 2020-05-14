#include <iostream>

/*
 *  ООП
 *  - Инкапсуляция
 *       Агрегация
 *  - Наследование
 *  - Полиморфизм
 *
 *
 *
 * Точка на плоскости
 * Состояние:
 *      координаты
 * Поведение:
 *      поместить в новые координаты
 *      переместить на смещение
 *
 *      
 */

class Point2D
{
public:
    double x { 0. };
    double y { 0. };

    void set(double nx, double ny) { x = nx; y = ny; }
    void move(double dx, double dy);

    // Конструктор по умолчанию
    Point2D() = default;

    // Конструктор копирования
    Point2D(const Point2D & p): x(p.x), y(p.y) {}

    // Конвертирующие конструкторы
    // (здесь он не нужен)
    // Point2D(const Hamster &);
    
    // Пользовательские конструктоы
    Point2D(double px, double py): x(px), y(py) {}
};

void Point2D::move(double dx, double dy)
{
    x += dx;
    y += dy;
}

class Vector2D: public Point2D
{
public:
    Vector2D(): Point2D() {}
    Vector2D(const Vector2D & v): Point2D(v) {}
    Vector2D(double vx, double vy): Point2D(vx, vy) {}

    void move(double dx, double dy) = delete;
};

Vector2D operator +(const Vector2D & l, const Vector2D & r)
{
    return Vector2D(l.x + r.x, l.y + r.y);
}


std::ostream & operator << (std::ostream & out, const Point2D & p)
{
    out << '(' << p.x << ';' << p.y << ')';
    return out;
}

std::ostream & operator << (std::ostream & out, const Vector2D & p)
{
    out << '{' << p.x << ';' << p.y << '}';
    return out;
}

void print(const Point2D & p)
{
    std::cout << "Точка имеет координаты " << p << std::endl;
}

void print(const Vector2D & v)
{
    std::cout << "Вектор имеет координаты " << v << std::endl;
}

int main()
{
    Point2D p1 {2., 3.}, p2 {5., 5.};

    print(p1);
    print(p2);

    p2.move(1., -1.);

    print(p2);

    Vector2D v1 { 6., 7.};
    Vector2D v2 { 3., -2.};

    Vector2D v3;

    v3 = v1 + v2;

    print(v3);

	return 0;
}

