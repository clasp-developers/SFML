#include <SFML/Graphics/RenderWindow.hpp>
#include "/home/flash/dev/clasp-src/src/include/clasp.h"
#include "/home/flash/dev/clasp-src/src/core/lispVector.h"
#include "/home/flash/dev/clasp-src/src/core/vectorObjects.h"
#include "/home/flash/dev/clasp-src/src/core/cons.h"
#include "/home/flash/dev/clasp-src/src/core/translators.h"  // assorted translators for string etc


#define EXPORT __attribute__((visibility("default")))


namespace translate {
    // template <> struct to_object<const vector<double>&>
    // {
    //     static core::T_sp convert(const vector<double>& v)
    //     {
    //         core::VectorObjects_sp vec;
    //         vec->adjust(_Nil<core::T_O>(),_Nil<core::Cons_O>(),v.size());
    //         printf("%s:%d fill the vec here\n", __FILE__, __LINE__ );
    //         return vec;
    //     }
    // };

  template <> struct from_object<sf::VideoMode>
  {
    typedef sf::VideoMode DeclareType;
    DeclareType _v;
    from_object(core::T_sp obj)
    {
      if ( obj.nilp() ) {
	this->_v.width = 800;
	this->_v.width = 600;
	this->_v.width = 32;
      } else if ( core::Cons_sp list = obj.asOrNull<core::Cons_O>() ) {
	// Translate a CONS list into the a VideoMode
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

  
  template <> struct from_object<sf::Color>
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
  
  template <>
  struct from_object<const sf::String&, std::true_type>
  {
    typedef sf::String DeclareType;
    DeclareType _v;
    from_object(T_P o) : _v(str_get(o)) {};
  };

  
  template <>
  struct	from_object<sf::String,std::true_type>
  {
    typedef	sf::String		DeclareType;
    DeclareType _v;
    from_object(T_P o) : _v(str_get(o)) {};
  };
  
  
  template <>
  struct	from_object<sf::String&,std::true_type>
  {
    typedef	sf::String		DeclareType;
    DeclareType _v;
    from_object(T_P o) : _v(str_get(o)) {};
  };
  
  template <>
  struct	from_object<sf::String&,std::false_type>
  {
    typedef	sf::String		DeclareType;
    DeclareType _v;
    from_object(T_P o) : _v("") {};
  };
  
 
  
  // template <> struct from_object<sf::String>
  // {
  //   typedef sf::String DeclareType;
  //   DeclareType _v;
  //   from_object(core::T_sp obj)
  //   {
  //     if ( obj.nilp() ) {
  // 	this->_v = "Initiated with nil";
  //     } else if ( core::Cons_sp list = obj.asOrNull<core::Cons_O>() ) {
  // 	// Translate a CONS list into a String, which doesn't make sense.
  // 	this->_v = "Initiated with cons";
  //     } else {
  // 	this->_v = "Initiated with unkown object type";
  //     }
  //   }
  // };
};

//DECLARE_ENUM_SYMBOL_TRANSLATOR(sf::Event::EventType,core::lisp_intern("event-type"))


extern "C" {
    EXPORT
    void CLASP_MAIN()
    {
        using namespace clbind;
        package("SF")
	  [
	   // class_<sf::RenderTarget>("render-target", no_default_constructor)
	   // . def("clear",&sf::RenderTarget::clear)
	   // ,
	   class_<sf::RenderWindow,sf::Window,sf::RenderTarget,sf::RenderTarget>("render-window",no_default_constructor )
	   . def_constructor("make-render-window",constructor<sf::VideoMode, sf::String>())
	   . def("get-size",&sf::RenderWindow::getSize)
	   . def("capture",&sf::RenderWindow::capture)
	   // . def("clear",&sf::RenderWindow::clear)
   	   // . def("set-view",&sf::RenderWindow::setView)
	   // . def("get-view",&sf::RenderWindow::getView)
	   // . def("get-default-view",&sf::RenderWindow::getDefaultView)
	   // . def("get-viewport",&sf::RenderWindow::getViewport)
	   // . def("map-pixel-to-coords",&sf::RenderWindow::mapPixelToCoords)
	   // . def("map-pixel-to-coords",&sf::RenderWindow::mapPixelToCoords)
	   // . def("map-coords-to-pixel",&sf::RenderWindow::mapCoordsToPixel)
	   // . def("map-coords-to-pixel",&sf::RenderWindow::mapCoordsToPixel)
	   // . def("draw",&sf::RenderWindow::draw)
	   // . def("draw",&sf::RenderWindow::draw)
	   // . def("push-gl-states",&sf::RenderWindow::pushGLStates)
	   // . def("pop-gl-states",&sf::RenderWindow::popGLStates)
	   // . def("reset-gl-states",&sf::RenderWindow::resetGLStates)
	  ];
    }
}

//example for enum exposing:

//  . enum_<clang::TemplateArgument::ArgKind>(asttooling::_sym_STARclangTemplateArgumentArgKindSTAR)[
// value("Type",clang::TemplateArgument::ArgKind::Type)
// , value("Null",clang::TemplateArgument::ArgKind::Null)
// , value("Declaration",clang::TemplateArgument::ArgKind::Declaration)
// , value("NullPtr",clang::TemplateArgument::ArgKind::NullPtr)
// , value("Integral",clang::TemplateArgument::ArgKind::Integral)
// , value("Template",clang::TemplateArgument::ArgKind::Template)
// , value("TemplateExpansion",clang::TemplateArgument::ArgKind::TemplateExpansion)
// , value("Expression",clang::TemplateArgument::ArgKind::Expression)
// , value("Pack",clang::TemplateArgument::ArgKind::Pack) 
