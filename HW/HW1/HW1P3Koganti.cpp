#include <iostream>
#include <string.h>

using namespace std;

class Movie{
    //private variables
    private:
    string name_;
    string rating_;
    double grossing_; 

    public:
    //defult constructor
    Movie(){
        name_ = " ";
        rating_ = " ";
        grossing_ = 0.0;
    }
    //constructor with input
    Movie(string name, string rating, double grossing){
        name_ = name;
        rating_ = rating;
        grossing_ = grossing;
    }
    //getters
    string name(){
        return name_;
    }

    string rating(){
        return rating_;
    }

    double grossing(){
        return grossing_;
    } 
    //setters
    void setName(string name){
        name_ = name;
    }

    void setRating(string rating){
        rating_ = rating;
    }

    void setGrossing(double grossing){
        grossing_ = grossing;
    }

    //pre: takes in the number of tickets sold
    //post: multiplies the numenr of tickets by 12
    // and set as the new grossing and retruns that 
    //ticket sales
    double movieShowing(int n){
        grossing_ = 12*n;
        return grossing_;
    }
    //pre: takes in the movie we are trying to merge
    //post: compares if the names are the same then
    // add the tickets sales together then comapres
    // the ratings as set to the highest one.
    //merge movies
    Movie mergeMovie(Movie m){
        if(name_.compare(m.name())==0){
            m.setGrossing(grossing_+=m.grossing());
           

            if(rating_.compare("R") || m.rating().compare("R") ){
                m.setRating(rating_);
            }else if(rating_.compare("PG") || m.rating().compare("PG") ){
                m.setRating(rating_);
            }else if(rating_.compare("PG-13") || m.rating().compare("PG-13") ){
                m.setRating(rating_);
            }else if(rating_.compare("G") || m.rating().compare("G") ){
                m.setRating(rating_);
            }else{
                cout<<"error";
            }
            }else{
                m.setName("Could not Combine");
                
            }
            return m;
    }
    

};
//forward declaration
void print(Movie m);
//main
int main(){
    // Movies
    Movie m1;
    m1.setName("Avatar");
    m1.setRating("R");
    m1.setGrossing(1000);
    Movie m2;
    m2.setName("Avatar");
    m2.setRating("PG-13");
    m2.setGrossing(200);
    Movie m3;
    m3.setName("Up");
    m3.setRating("G");
    m3.setGrossing(600);

    //print calls
    print(m1);
    print(m1.mergeMovie(m2));
    print(m1.mergeMovie(m3));



    return 0;
}
//pre: A movie with a name, rating and amout of grossing.
//post: Prints out the name, rating and amoutn grossed on 
//sperate lines.
void print(Movie m){
    cout<< "Name = " << m.name()<<endl;
    cout<< "Rating = " << m.rating()<<endl;
    cout<< "Grossing Amount = $" << m.grossing()<<endl;
}