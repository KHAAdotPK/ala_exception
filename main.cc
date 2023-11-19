/* main.cc */

#include "ala_exception.hh"

int foo(void) throw(ala_exception) 
{
   throw ala_exception("Hello World");
   return 0;
}

int main(int argc, char* argv[]) 
{
    try 
    {
        foo();
    }
    catch (ala_exception& e)
    {
        std::cout<<e.what()<<std::endl;
    }

    return 0;
}
