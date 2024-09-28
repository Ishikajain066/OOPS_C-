// Understand the basics of c++ library, vadiables , data tybe, input and output write a program to find the area of rectangle and 
// the perimeter of the triangle.



#include<iostream> 
using namespace std;
int main (){
float len, br, a, b,c;
 float area, peri;

cout<<" Enter length of rectangle:";
 cin >> len;
cout<<"enter breadth of rectangle:" ;
 cin>> br;
area = len * br;
cout<< "Area of rectango is: " <<len* br;
 cout<< "enter thale sides of tolangle:"; 
 cin >>a;
cin>> b;
cin>>c;
peri= a+b+c;

cout<<"perimeter of triangle is "<<peri;
}