#ifndef CLASP_BINDING_VECTOR2_HPP
#define CLASP_BINDING_VECTOR2_HPP


#include <SFML/System/Vector2.hpp>

#include <clasp/clbind/clbind.h>

namespace translate
{
  template <typename T> struct from_object<sf::Vector2<T>>
  {
    typedef sf::Vector2<T> DeclareType;
    DeclareType _v;
    from_object(core::T_sp obj)
    {
      if ( core::List_sp list = obj.asOrNull<core::List_V>() )
      {
	// Translate a CONS list into a Vector
	this->_v.x = clasp_to_fixnum(gc::As<core::Integer_sp>(oCar(list)));
	list = oCdr(list);
	this->_v.y = clasp_to_fixnum(gc::As<core::Integer_sp>(oCar(list)));
      }
      else
      {
	SIMPLE_ERROR(BF("Could not convert %s to sf::Vector2") % core::_rep_(obj));
      }
    }
  };

}; //end namespace translate


#endif //CLASP_BINDING_VECTOR2_HPP
