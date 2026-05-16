#include <iostream>
#include <iomanip>

using namespace std;

const double Pi = 3.14159;

class Rectangle {
private:
    double length;
    double width;

public:
    Rectangle(double l, double w) {
        if (l > 0) {
            length = l;
        } else {
            length = 1;
        }

        if (w > 0) {
            width = w;
        } else {
            width = 1;
        }
    }
    double getLength() const;
    double getWidth() const;
    void setLength(double l) {
        if (l > 0) {
            length = l;
        }
    }
    void setWidth(double w) {
        if (w > 0) {
            width = w;
        }
    }
    double area() const;
    void area(double& result) const;
    Rectangle& resize(double factor) {
        if (factor > 0) {
            this->length *= factor;
            this->width *= factor;
        }
        return *this;
    }
};

class Circle {
private:
    double radius;

public:
    Circle(double r) {
        if (r > 0) {
            radius = r;
        } else {
            radius = 1;
        }
    }
    void setRadius(double r) {
        if (r > 0) {
            radius = r;
        }
    }
    double area() const {
        return Pi * radius * radius;
    }
    double circumference() const {
        return 2 * Pi * radius;
    }
    void print() const;
    void print(bool detailed) const;
};

double Rectangle::getLength() const {
    return length;
}

double Rectangle::getWidth() const {
    return width;
};

double Rectangle::area() const {
    return length * width;
};

void Rectangle::area(double& result) const {
    result = length * width;
};

void Circle::print() const {
    cout << "Radius: " << radius << endl;
    cout << "Area: " << area() << endl;
    cout << "Circumference: " << circumference() << endl;
};

void Circle::print(bool detailed) const {
    if (detailed) {
        cout << "Radius: " << radius << endl;
        cout << "Area = Pi * radius * radius = " << Pi << " * " << radius << " * " << radius << " = " << area() << endl;
        cout << "Circumference = 2 * Pi * radius = " << "2 * " << Pi << " * " << radius << " = " << circumference() << endl;
    } else {
        print();
    }
};


int main() {

    cout << fixed << setprecision(2);

    Rectangle rect1(5.0, 3.0);
    Circle circle1(4.0);
    const Circle constCircle(2.5);

    double result;
    double newLength;
    double newWidth;
    double newRadius;

    cout << "Rectangle" << endl;
    cout << "----------------------" << endl;
    cout << "Length: " << rect1.getLength() << endl;
    cout << "Width: " << rect1.getWidth() << endl;
    cout << "Area (returned): " << rect1.area() << endl;

    rect1.area(result);
    cout << "Area (reference parameter): " << result << endl;

    cout << endl;
    cout << "Enter a new length for the rectangle: ";
    cin >> newLength;
    rect1.setLength(newLength);

    cout << "Enter a new width for the rectangle: ";
    cin >> newWidth;
    rect1.setWidth(newWidth);

    cout << "Updated rectangle dimensions:" << endl;
    cout << "Length: " << rect1.getLength() << endl;
    cout << "Width: " << rect1.getWidth() << endl;
    cout << "Area: " << rect1.area() << endl;

    rect1.resize(2.0).resize(0.5);
    cout << "After chaining resize(2.0).resize(0.5):" << endl;
    cout << "Length: " << rect1.getLength() << endl;
    cout << "Width: " << rect1.getWidth() << endl;
    cout << "Area: " << rect1.area() << endl;

    cout << endl;
    cout << "Circle" << endl;
    cout << "-----------------" << endl;
    cout << "Area: " << circle1.area() << endl;
    cout << "Circumference: " << circle1.circumference() << endl;

    cout << "Enter a new radius for the circle: ";
    cin >> newRadius;
    circle1.setRadius(newRadius);

    cout << "Updated circle:" << endl;
    circle1.print();

    cout << endl;
    cout << "Full circle details:" << endl;
    circle1.print(true);

    cout << endl;
    cout << "Resize" << endl;
    cout << "------------------" << endl;
    cout << "Area: " << constCircle.area() << endl;
    cout << "Circumference: " << constCircle.circumference() << endl;

    return 0;
}