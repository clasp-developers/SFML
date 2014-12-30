#ifndef CLASP_BINDING_COLOR_HPP
#define CLASP_BINDING_COLOR_HPP

#include <SFML/Graphics/Color.hpp>

#include "/home/flash/dev/clasp-src/src/clbind/clbind.h"

namespace translate
{
  
  template <> struct from_object<const sf::Color &>
  {
    typedef sf::Color DeclareType;
    DeclareType _v;
    from_object(core::T_sp obj)
    {
      if ( obj.nilp() ) {
      	this->_v.r = 0;
      	this->_v.g = 0;
      	this->_v.b = 0;
      	this->_v.a = 255;
      } else if ( core::Cons_sp list = obj.asOrNull<core::Cons_O>() ) {
      	// Translate a CONS list into the a VideoMode
      	this->_v.r = oCar(list).as<core::Number_O>()->as_int();
      	list = cCdr(list);
      	this->_v.g = oCar(list).as<core::Number_O>()->as_int();
      	list = cCdr(list);
      	this->_v.b = oCar(list).as<core::Number_O>()->as_int();
      	list = cCdr(list);
      	this->_v.a = (list.nilp())?
      	  255 : oCar(list).as<core::Number_O>()->as_int();
      } else {
      	SIMPLE_ERROR(BF("Could not convert %s to sf::Color") % core::_rep_(obj));
      }
    }
  };

}; //end namespace translate

#endif //CLASP_BINDING_COLOR_HPP
