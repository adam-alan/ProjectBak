class Shape {
public:
    virtual double getArea()=0;
    virtual double getPerim()=0;
};

class Rectangle:public Shape{
private:
    double length;
    double width;

public:
    Rectangle(const double & _length,const double & _width);
    virtual double getArea();
    virtual double getPerim();
    ~Rectangle();
};

Rectangle::Rectangle(const double & _length,const double & _width){
    this->length = _length;
    this->width = _width;
}

double Rectangle::getArea(){
    return this->length * this->width;
}

double Rectangle::getPerim(){
    return 2 * (this->length + this->width);
}

Rectangle::~Rectangle(){

}

class Circle:public Shape{
private:

    double radius;
    /* data */
public:
    Circle(const double &_radius);
    virtual double getArea();
    virtual double getPerim();

    ~Circle();
};
Circle::Circle(const double &_radius){
    this->radius = _radius;
}


double Circle::getArea(){
    return this->radius * this->radius * PI;
}

double Circle::getPerim(){
    return 2 * PI * this->radius;
}

Circle::~Circle(){
    
}
