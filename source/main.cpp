//Name: Phuc Cai
//I affirm that all code given below was written solely by me,Phuc Cai
//and that any help I received adhered to the rules stated for this exam.

#include <iostream>
#include <string>
#include <vector>
#include <windows.h>
#include <typeinfo>

using std::cout;
using std::endl;
using std::string;
using std::vector;

namespace Exam1
{
    class Wheel {
    private:
        int _radius;
    public:
        Wheel(int radius) { _radius = radius; }
    };

    // STEP 1: Complete the implementation of the Vehicle base class
    // as described in the UML diagram
    class Vehicle {
    protected:
        string _color;
        int _topspeed;
        vector<Wheel> wheels;

    public:
        Vehicle(string color) {
        _color = color;
        }

    virtual string Description() = 0;

    };

    // STEP 2: Define the RaceCar, Sedan, and Pickup classes as described
    // in the UML diagram. Make sure to add functionality unique to each kind of class.
    // Be sure to use a separate header file and a CPP file for each class.
    class RaceCar: public Vehicle {
    public:
        RaceCar(string color): Vehicle(color) {
            _topspeed = 250;
            //4 wheels
            for (int i = 1; i <= 4; i++)
                wheels.push_back(Wheel(305));
        }
        //spped up for 1 second and slow down again
        void speedUp(){
            cout << "The car speed up for 1 second to " << _topspeed+50 <<"mph" << endl;
            Sleep(100);
            cout << "The car back to its max speed: " << _topspeed << "mph" << endl;
        }
        string Description(){
            return "I am a "+ _color + " race car with the maximum speed of " + std::to_string(_topspeed) +"mph";
        }
        //Top speed: 250mph
        //Wheel radius: 305mm
    };

    class Sedan: public Vehicle {
    private:
        int number_of_seats;
        int passenger;
    public:
        //Top speed: 95mph
        //Wheel radius: 381mm
        Sedan(string color, int seats): Vehicle(color) {
            number_of_seats = seats;
            _topspeed = 95;
            passenger = 1;
            //4 wheels
            for (int i =0; i < 4; i++)
                wheels.push_back(Wheel(381));
        }

        //add a passenger
        void addPassenger(){
            passenger += 1;
            cout << "A passenger have been added!\n";
        }

        //remove a passenger
        void removePassenger() {
            if (passenger > 0)
                passenger -= 1;
            cout << "A passenger has left!";
        }
        
        //return a description of sedan class
        string Description(){
            return "I am a "+ _color + " sedan with the maximum speed of " + std::to_string(_topspeed) +"mph";
        }
    };

    class Pickup: public Vehicle {
    private:
        int hauling_capacity;
    public:
        //Top speed: 85mph
        //Wheel radius: 432mm
        Pickup(string color, int capacity): Vehicle(color) {
            hauling_capacity = capacity;
            _topspeed = 85;
            //4 wheels
            for (int i=0; i <4; i++)
                wheels.push_back(Wheel(432));
        }

        //return description
        string Description(){
            return "I am a "+ _color + " pickup truck with the maximum speed of " + std::to_string(_topspeed) +"mph";
        }

        //return the hauling capacity of the Pickup
        int getCapacity(){
            return hauling_capacity;
        }

    };
}

int main() {
    Exam1::Vehicle * Garage[3];
    // STEP 3: Assign ONE RaceCar, ONE Sedan, AND ONE Pickup object to each of the elements
    // in the Garage array. Remember the classes are defined in the namespace Exam1.
    Garage[0] = new Exam1::RaceCar("Red");
    Garage[1] = new Exam1::Sedan("Grey", 4);
    Garage[2] = new Exam1::Pickup("White", 50);
    for (int i = 0; i < 3; ++i) {
        // The method Description() should display an output like
        // "I am a red sedan (or racecar/pickup) and I can go 95 (or 250 or 85) mph"
        cout << Garage[i]->Description() << endl;
        // add code to execute the "special" functionality of each class
        if (typeid(Exam1::RaceCar) == typeid(*Garage[i]))
            dynamic_cast<Exam1::RaceCar*>(Garage[i]) -> speedUp();
        if (typeid(Exam1::Sedan) == typeid(*Garage[i]))
            dynamic_cast<Exam1::Sedan*>(Garage[i]) -> addPassenger();
        if (typeid(Exam1::Pickup) == typeid(*Garage[i]))
            cout << "The capacity of the pickup truck is " << (dynamic_cast<Exam1::Pickup*>(Garage[i]) -> getCapacity()) << "kg" << endl;;
    }
}