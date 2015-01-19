#ifndef CLASP_BINDING_VECTOR2_HPP
#define CLASP_BINDING_VECTOR2_HPP


#include <SFML/System/Vector2.hpp>

#include "/home/flash/dev/clasp-src/src/clbind/clbind.h"

namespace translate
{
  template <typename T> struct from_object<sf::Vector2<T>>
  {
    typedef sf::Vector2<T> DeclareType;
    DeclareType _v;
    from_object(core::T_sp obj)
    {
      if ( core::Cons_sp list = obj.asOrNull<core::Cons_O>() )
      {
	// Translate a CONS list into a Vector
	this->_v.x = oCar(list).as<core::Number_O>()->as_type<T>();
	list = cCdr(list);
	this->_v.y = oCar(list).as<core::Number_O>()->as_type<T>();
      }
      else
      {
	SIMPLE_ERROR(BF("Could not convert %s to sf::Vector2") % core::_rep_(obj));
      }
    }
  };

}; //end namespace translate


#endif //CLASP_BINDING_VECTOR2_HPP
