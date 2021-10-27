#ifndef POINT_H
#define POINT_H
#include <iostream>

template <typename T>
class Point{
public:
  Point();
  Point(T ix, T iy);
  T x()const;
  T y()const;
private:
  T x_;
  T y_;
};
template <typename T>
std::ostream & operator <<(std::ostream & out, const Point<T> &p);
//Must be a template function to operate on the template class

//Note:  For template classes, full function definition must be in header file
//see Quick Reference file for explanation.
template<typename T>
Point<T>::Point(){//We enter the scope of the class definition after the ::
  x_=T();           //so the Point before the :: needs a <>, so we need
  y_=T();           //a template header for each method definition
}
template<typename T>
Point<T>::Point(T ix, T iy){
  x_=ix;
  y_=iy;
}
template<typename T>
T Point<T>::x()const{
  return x_;
}
template<typename T>
T Point<T>::y()const{
  return y_;
}
template<typename T>
std::ostream & operator <<(std::ostream & out, const Point<T>& p){
  out<<"("<<p.x()<<","<<p.y()<<")";
  return out;
}


#endif




/*
#ifndef POINint_H
#define POINint_H
#include <iostream>


class Point{
public:
  Point();
  Point(int ix, int iy);
  int x()const;
  int y()const;
private:
  int x_;
  int y_;
};
std::ostream & operator <<(std::ostream & out, const Point &p);
#endif
*/
