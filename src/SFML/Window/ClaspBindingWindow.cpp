#include <SFML/Window/Window.hpp>
#include <SFML/Window/Event.hpp>
#include "/home/flash/dev/clasp-src/src/include/clasp.h"
#include "/home/flash/dev/clasp-src/src/core/lispVector.h"
#include "/home/flash/dev/clasp-src/src/core/vectorObjects.h"
#include "/home/flash/dev/clasp-src/src/core/cons.h"
#include "/home/flash/dev/clasp-src/src/core/translators.h"  // assorted translators for string etc
#include "/home/flash/dev/clasp-src/src/core/str.h"

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
  

  template <>
  struct to_object<sf::Event::EventType>
  {
    static core::T_sp convert(sf::Event::EventType v)
    {
      core::Symbol_sp converterSym = core::lisp_intern("SFML","*ENUM-TO-SYMBOL-MAPPER*");
      core::SymbolToEnumConverter_sp converter = converterSym->symbolValue().as<core::SymbolToEnumConverter_O>();
      return converter->symbolForEnum<sf::Event::EventType>(v);
    }
  };

  template <>
  struct from_object<sf::Event::EventType,std::true_type>
  {
    typedef sf::Event::EventType DeclareType;
    DeclareType _v;
    from_object(core::T_sp object)
    {
      if ( core::Symbol_sp sym = object.asOrNull<core::Symbol_O>() ) {
	if ( sym.notnilp() ) {
	  core::Symbol_sp converterSym = core::lisp_intern("SFML","*ENUM-TO-SYMBOL-MAPPER*");
	  core::SymbolToEnumConverter_sp converter = converterSym->symbolValue().as<core::SymbolToEnumConverter_O>();
	  this->_v = converter->enumForSymbol<sf::Event::EventType>(sym);
	  return;
	}
      }
      SIMPLE_ERROR(BF("Cannot convert object %s to sf::Event::EventType") % _rep_(object) );
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

//CLBIND_TRANSLATE_SYMBOL_TO_ENUM(sf::Event::EventType,_sym_STARsfEventEventTypeSTAR)



extern "C" {
    EXPORT
    void CLASP_MAIN()
    {
        using namespace clbind;
	list<string> lnicknames = {"SF"};
	list<string> luse;
	_lisp->makePackage("SFML",lnicknames,luse);
        package("SFML")
	  [class_<sf::Window>("window", no_default_constructor)
	   . def_constructor("make-window",constructor<sf::VideoMode, sf::String>())
	   //overloaded. Need to specify which is called.
	   //. def("create",&sf::Window::create)
	   . def("close",&sf::Window::close)
	   . def("is-open",&sf::Window::isOpen)
	   . def("get-settings",&sf::Window::getSettings)
	   . def("poll-event",&sf::Window::pollEvent)
	   . def("wait-event",&sf::Window::waitEvent)
	   . def("get-position",&sf::Window::getPosition)
	   . def("set-position",&sf::Window::setPosition)
	   . def("get-size",&sf::Window::getSize)
	   . def("set-size",&sf::Window::setSize)
	   . def("set-title",&sf::Window::setTitle)
	   //[unknown error] error: base specifier must name a class , public Alien
	   //	   . def("set-icon",&sf::Window::setIcon)
   	   . def("set-visible",&sf::Window::setVisible)
   	   . def("set-vertical-sync-enabled",&sf::Window::setVerticalSyncEnabled)
	   . def("set-mouse-cursor-visible",&sf::Window::setMouseCursorVisible)
	   . def("set-key-repeat-enabled",&sf::Window::setKeyRepeatEnabled)
	   . def("set-framerate-limit",&sf::Window::setFramerateLimit)
	   //[unknown error] error: base specifier must name a class , public Alien
	   //. def("set-joystick-threshold",&sf::Window::setJoystickThreshold)
	   . def("set-active",&sf::Window::setActive)
	   . def("request-focus",&sf::Window::requestFocus)
	   . def("has-focus",&sf::Window::hasFocus)
	   . def("display",&sf::Window::display)
	   . def("get-system-handle",&sf::Window::getSystemHandle)
	   ,
	   class_<sf::Event>("event")
	   . def_constructor("make-event",constructor<>())
	   //	   . property("type", &sf::Event::type)
	   .def("get-type", &sf::Event::getType)
	   .def("get-size-event", &sf::Event::getSizeEvent)                       
	   .def("get-key-event", &sf::Event::getKeyEvent)                         
	   .def("get-text-event", &sf::Event::getTextEvent)                       
	   .def("get-mouse-move-event", &sf::Event::getMouseMoveEvent)             
	   .def("get-mouse-button-event", &sf::Event::getMouseButtonEvent)         
	   .def("get-mouse-wheel-event", &sf::Event::getMouseWheelEvent)           
	   .def("get-joystick-move-event", &sf::Event::getJoystickMoveEvent)       
	   .def("get-joystick-button-event", &sf::Event::getJoystickButtonEvent)   
	   .def("get-joystick-connect-event", &sf::Event::getJoystickConnectEvent) 
	   .def("get-touch-event", &sf::Event::getTouchEvent)                     
	   .def("get-sensor-event", &sf::Event::getSensorEvent)                      
	   . enum_<sf::Event::EventType>(core::lisp_intern("SFML","*ENUM-TO-SYMBOL-MAPPER*"))
	   [ value("Closed",sf::Event::EventType::Closed) 
	     , value("Resized",sf::Event::EventType::Resized)                
	     , value("LostFocus",sf::Event::EventType::LostFocus)              
	     , value("GainedFocus",sf::Event::EventType::GainedFocus)            
	     , value("TextEntered",sf::Event::EventType::TextEntered)            
	     , value("KeyPressed",sf::Event::EventType::KeyPressed)             
	     , value("KeyReleased",sf::Event::EventType::KeyReleased)            
	     , value("MouseWheelMoved",sf::Event::EventType::MouseWheelMoved)        
	     , value("MouseButtonPressed",sf::Event::EventType::MouseButtonPressed)     
	     , value("MouseButtonReleased",sf::Event::EventType::MouseButtonReleased)    
	     , value("MouseMoved",sf::Event::EventType::MouseMoved)             
	     , value("MouseEntered",sf::Event::EventType::MouseEntered)           
	     , value("MouseLeft",sf::Event::EventType::MouseLeft)              
	     , value("JoystickButtonPressed",sf::Event::EventType::JoystickButtonPressed)  
	     , value("JoystickButtonReleased",sf::Event::EventType::JoystickButtonReleased) 
	     , value("JoystickMoved",sf::Event::EventType::JoystickMoved)          
	     , value("JoystickConnected",sf::Event::EventType::JoystickConnected)      
	     , value("JoystickDisconnected",sf::Event::EventType::JoystickDisconnected)   
	     , value("TouchBegan",sf::Event::EventType::TouchBegan)             
	     , value("TouchMoved",sf::Event::EventType::TouchMoved)             
	     , value("TouchEnded",sf::Event::EventType::TouchEnded)             
	     , value("SensorChanged",sf::Event::EventType::SensorChanged)          
	     , value("Count",sf::Event::EventType::Count)
	   ]
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
