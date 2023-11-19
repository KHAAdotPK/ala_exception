/* 
   ala_exception/ala_exception.hh
   Written by, Q@khaa.pk 
 */

#include <exception>
//#include "../string/src/String.hh"

/* Custom Exception Types, http://www.drdobbs.com/custom-exception-types/184401913 */
/* Module21a C AND C++ EXCEPTION HANDLINE, http://www.tenouk.com/Module21a.html */

#ifndef	ALA_EXCEPTION_HH
#define	ALA_EXCEPTION_HH

/*
   The following include statement was placed outside the include guards,
   causing problems due to circular dependencies when this header is included in String/String.hh.
   To resolve this issue, we need to refactor the code and move the include statement over here from outside of the include guards.
*/
#include "../string/src/String.hh"

class ala_exception : public std::exception {

   cc_tokenizer::allocator<char> alloc_obj;
   cc_tokenizer::String<char> msg;
      
   public:

      const char* what() /*const throw ()*/
      {
          /*
             Originally it was...
             return msg.c_str(); but the I put that const modifier in the definition of what()
             because I wanted cont modifier in the arguments of the catch() 
           */  
          /*
             Appears to address the const-correctness issue in a safer way.
             By creating a temporary cc_tokenizer::String<char> object named temp with the same data as msg, you can safely return its C-style string representation without modifying the original object.
             This implementation avoids the need for const_cast and returns a const pointer to the internal buffer,
             maintaining const-correctness while providing the C-style string representation of the exception message.
           */  
          /*cc_tokenizer::String<char> temp(msg.data(), msg.size());
          return temp.c_str();*/

          /*char* ptr = alloc_obj.allocate(msg.size() + 1);
          for (cc_tokenizer::string_character_traits<char>::size_type i = 0; i < msg.size(); i++)
          {
              ptr[i] = msg.data()[i];
          }
          ptr[msg.size()] = '\0';
          return ptr;*/
          return msg.c_str(); 
          //return ((class ala_exception*)this)->msg.c_str();
          //return const_cast<class ala_exception*>(this)->msg.c_str();          
      }

      ala_exception(cc_tokenizer::String<char> m) : msg(m) {	      
      }	      

      ~ala_exception() throw() {
      }	      
};

#endif
