#include <iostream>
#include <string>

#include "swap.hpp"

#define MAX_VAL 750

int main( void ) {

int a = 2;
int b = 3;
::swap( a, b );
std::cout << "a = " << a << ", b = " << b << std::endl;
std::cout << "min( a, b ) = " << ::min( a, b ) << std::endl;
std::cout << "max( a, b ) = " << ::max( a, b ) << std::endl;

std::string c = "chaine1";
std::string d = "chaine2";
::swap(c, d);
std::cout << "c = " << c << ", d = " << d << std::endl;
std::cout << "min( c, d ) = " << ::min( c, d ) << std::endl;
std::cout << "max( c, d ) = " << ::max( c, d ) << std::endl;

float x = 1.5f;
float y = 1.2f;
::swap(x, y);
std::cout << "x = " << x << ", y = " << y << std::endl;
std::cout << "min( x, y ) = " << ::min(x, y) << std::endl;
std::cout << "max( x, y ) = " << ::max(x, y) << std::endl;

char e = 'a';
char f = 'z';
::swap(e, f);
std::cout << "e = " << e << ", f = " << f << std::endl;
std::cout << "min( e, f ) = " << ::min(e, f) << std::endl;
std::cout << "max( e, f ) = " << ::max(e, f) << std::endl;

return 0;
}
