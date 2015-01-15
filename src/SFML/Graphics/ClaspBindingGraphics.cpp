#include <CLASP-SFML/System/String.hpp>

#include <CLASP-SFML/Window/Event.hpp>
#include <CLASP-SFML/Window/VideoMode.hpp>

#include <CLASP-SFML/Graphics/Color.hpp>
#include <CLASP-SFML/Graphics/Rect.hpp>


#include <CLASP-SFML/Graphics/BlendMode.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/Drawable.hpp>
#include <SFML/Graphics/Transformable.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Rect.hpp>
#include <SFML/Graphics/RenderStates.hpp>
#include "/home/flash/dev/clasp-src/src/clbind/clbind.h"
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

  // template <> struct from_object<sf::VideoMode>
  // {
  //   typedef sf::VideoMode DeclareType;
  //   DeclareType _v;
  //   from_object(core::T_sp obj)
  //   {
  //     if ( obj.nilp() ) {
  // 	this->_v.width = 800;
  // 	this->_v.height = 600;
  // 	this->_v.bitsPerPixel = 32;
  //     } else if ( core::Cons_sp list = obj.asOrNull<core::Cons_O>() ) {
  // 	// Translate a CONS list into the a VideoMode
  // 	this->_v.width = oCar(list).as<core::Number_O>()->as_int();
  // 	list = cCdr(list);
  // 	this->_v.height = oCar(list).as<core::Number_O>()->as_int();
  // 	list = cCdr(list);
  // 	this->_v.bitsPerPixel = (list.nilp())?
  // 	  32 : oCar(list).as<core::Number_O>()->as_int();
  //     } else {
  // 	SIMPLE_ERROR(BF("Could not convert %s to sf::VideoMode") % core::_rep_(obj));
  //     }
  //   }
  // };

  
  // template <>
  // struct from_object<const sf::String&, std::true_type>
  // {
  //   typedef sf::String DeclareType;
  //   DeclareType _v;
  //   from_object(T_P o) : _v(str_get(o)) {};
  // };

  
  // template <>
  // struct	from_object<sf::String,std::true_type>
  // {
  //   typedef	sf::String		DeclareType;
  //   DeclareType _v;
  //   from_object(T_P o) : _v(str_get(o)) {};
  // };
  
  
  // template <>
  // struct	from_object<sf::String&,std::true_type>
  // {
  //   typedef	sf::String		DeclareType;
  //   DeclareType _v;
  //   from_object(T_P o) : _v(str_get(o)) {};
  // };
  
  // template <>
  // struct	from_object<sf::String&,std::false_type>
  // {
  //   typedef	sf::String		DeclareType;
  //   DeclareType _v;
  //   from_object(T_P o) : _v("") {};
  // };
  

  
  // template <>
  // struct to_object<sf::Event::EventType>
  // {
  //   static core::T_sp convert(sf::Event::EventType v)
  //   {
  //     core::Symbol_sp converterSym = core::lisp_intern("SFML","*ENUM-TO-SYMBOL-MAPPER*");
  //     core::SymbolToEnumConverter_sp converter = converterSym->symbolValue().as<core::SymbolToEnumConverter_O>();
  //     return converter->symbolForEnum<sf::Event::EventType>(v);
  //   }
  // };

  // template <>
  // struct from_object<sf::Event::EventType,std::true_type>
  // {
  //   typedef sf::Event::EventType DeclareType;
  //   DeclareType _v;
  //   from_object(core::T_sp object)
  //   {
  //     if ( core::Symbol_sp sym = object.asOrNull<core::Symbol_O>() ) {
  // 	if ( sym.notnilp() ) {
  // 	  core::Symbol_sp converterSym = core::lisp_intern("SFML","*ENUM-TO-SYMBOL-MAPPER*");
  // 	  core::SymbolToEnumConverter_sp converter = converterSym->symbolValue().as<core::SymbolToEnumConverter_O>();
  // 	  this->_v = converter->enumForSymbol<sf::Event::EventType>(sym);
  // 	  return;
  // 	}
  //     }
  //     SIMPLE_ERROR(BF("Cannot convert object %s to sf::Event::EventType") % _rep_(object) );
  //   }
  // };


  
  template <> struct from_object<const sf::RenderStates&>
  {
    typedef sf::RenderStates DeclareType;
    DeclareType _v;
    from_object(core::T_sp obj)
    {
      if ( obj.nilp() ) {
	_v = sf::RenderStates::Default;
      } else {
      	SIMPLE_ERROR(BF("Could not convert %s to sf::IntRect") % core::_rep_(obj));
      }
    }
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

	   class_<sf::BlendMode>("blend-mode")

	   .enum_<sf::BlendMode::Factor>(core::lisp_intern("SFML", "*BLENDMODE-FACTOR-ENUM-MAPPER*"))
	   [
	   value("blend-mode/factor/zero", sf::BlendMode::Factor::Zero),
	   value("blend-mode/factor/one", sf::BlendMode::Factor::One),
	   value("blend-mode/factor/src-color", sf::BlendMode::Factor::SrcColor),
	   value("blend-mode/factor/one-minus-src-color", sf::BlendMode::Factor::OneMinusSrcColor),
	   value("blend-mode/factor/dst-color", sf::BlendMode::Factor::DstColor),
	   value("blend-mode/factor/one-minus-dst-color", sf::BlendMode::Factor::OneMinusDstColor),
	   value("blend-mode/factor/src-alpha", sf::BlendMode::Factor::SrcAlpha),
	   value("blend-mode/factor/one-minus-src-alpha", sf::BlendMode::Factor::OneMinusSrcAlpha),
	   value("blend-mode/factor/dst-alpha", sf::BlendMode::Factor::DstAlpha),
	   value("blend-mode/factor/one-minus-dst-alpha", sf::BlendMode::Factor::OneMinusDstAlpha)
	   ]

	   .enum_<sf::BlendMode::Equation>(core::lisp_intern("SFML", "*BLENDMODE-EQUATION-ENUM-MAPPER*"))
	   [
	   value("blend-mode/equation/add", sf::BlendMode::Equation::Add),
	   value("blend-mode/equation/subtract", sf::BlendMode::Equation::Subtract)
	   ]

	   .def_constructor("make-blend-mode", constructor<sf::BlendMode::Factor, sf::BlendMode::Factor, sf::BlendMode::Equation>())
	   
	   
	   

	   
	   ,class_<sf::RenderTarget>("render-target", no_default_constructor)
	   . def("clear",&sf::RenderTarget::clear)
	   . def("get-view", &sf::RenderTarget::getView)
	   . def("draw", (void (sf::RenderTarget::*)(const sf::Drawable&, const sf::RenderStates&))&sf::RenderTarget::draw, policies<>(),  "(self drawable &optional (states nil))", "", "Draws the given Drawable onto the RenderTarget")
	   ,
	   class_<sf::RenderWindow,bases<sf::Window,sf::RenderTarget>>("render-window",no_default_constructor )
	   . def_constructor("make-render-window",constructor<sf::VideoMode, sf::String>())
	   . def("get-size",&sf::RenderWindow::getSize)
	   . def("capture",&sf::RenderWindow::capture)
	   ,
	   class_<sf::Texture>("texture")
	   . def_constructor("make-texture", constructor<>())
	   //. def_constructor("make-texture", constructor<const sf::Texture &>())
	   . def("create", &sf::Texture::create)
	   . def("load-from-file", &sf::Texture::loadFromFile, policies<>(), "(self filename &optional (area nil))")
	   // . def("load-from-memory", &sf::Texture::loadFromMemory)
	   // . def("load-from-stream", &sf::Texture::loadFromStream)
	   // . def("load-from-image", &sf::Texture::loadFromImage)
	   // . def("get-size", &sf::Texture::getSize)
	   // . def("copy-to-image", &sf::Texture::copyToImage)
	   //missing definitions here
	   ,
	   class_<sf::Drawable> ("drawable",no_default_constructor)
	   ,
	   class_<sf::Transformable> ("transformable")
	   ,
	   class_<sf::Sprite,sf::Drawable> ("sprite")
	   //. def_constructor("make-sprite", constructor<>())
	   . def_constructor("make-sprite", constructor<const sf::Texture &>())
	   //. def_constructor("make-sprite", constructor<const sf::Texture &, const sf::IntRect &>())
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
