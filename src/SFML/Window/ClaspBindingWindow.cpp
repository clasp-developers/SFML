#include <CLASP-SFML/Window/Event.hpp>
#include <CLASP-SFML/Window/VideoMode.hpp>

#include <CLASP-SFML/System/String.hpp>

#include <SFML/Window/Window.hpp>

#include "/home/flash/dev/clasp-src/src/include/clasp.h"
#include "/home/flash/dev/clasp-src/src/core/lispVector.h"
#include "/home/flash/dev/clasp-src/src/core/vectorObjects.h"
#include "/home/flash/dev/clasp-src/src/core/cons.h"
#include "/home/flash/dev/clasp-src/src/core/translators.h"  // assorted translators for string etc
#include "/home/flash/dev/clasp-src/src/core/str.h"

#define EXPORT __attribute__((visibility("default")))


//namespace translate {
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
//};

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
	   //. def_readonly("type", &sf::Event::type)
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
