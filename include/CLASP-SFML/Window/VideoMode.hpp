#ifndef CLASP_BINDING_VIDEO_MODE_HPP
#define CLASP_BINDING_VIDEO_MODE_HPP

#include <SFML/Window/VideoMode.hpp>

#include "/home/flash/dev/clasp-src/src/clbind/clbind.h"

namespace translate
{
  template <> struct from_object<sf::VideoMode>
  {
    typedef sf::VideoMode DeclareType;
    DeclareType _v;
    from_object(core::T_sp obj)
    {
      if ( obj.nilp() )	{
	this->_v.width = 800;
	this->_v.width = 600;
	this->_v.width = 32;
      } else if ( core::Cons_sp list = obj.asOrNull<core::Cons_O>() ) {
	// Translate a CONS list into a VideoMode
	this->_v.width = oCar(list).as<core::Number_O>()->as_int();
	list = cCdr(list);
	this->_v.height = oCar(list).as<core::Number_O>()->as_int();
	list = cCdr(list);
	this->_v.bitsPerPixel = (list.nilp())?
	  32 : oCar(list).as<core::Number_O>()->as_int();
      } else {
	SIMPLE_ERROR(BF("Could not convert %s to sf::VideoMode") % core::_rep_(obj));
      }
    }
  };

}; //end namespace translate

#endif //CLASP_BINDING_VIDEO_MODE_HPP
