#include <CLASP-SFML/translators.hpp>

#include <CLASP-SFML/System/String.hpp>

#include <CLASP-SFML/Window/Event.hpp>
#include <CLASP-SFML/Window/VideoMode.hpp>

#include <CLASP-SFML/Graphics/Color.hpp>
#include <CLASP-SFML/Graphics/Rect.hpp>

#include <CLASP-SFML/Graphics/BlendMode.hpp>

#include <SFML/Graphics/CircleShape.hpp>
#include <SFML/Graphics/ConvexShape.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/Drawable.hpp>
#include <SFML/Graphics/Transformable.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Rect.hpp>
#include <SFML/Graphics/RenderStates.hpp>
#include <SFML/Graphics/Shape.hpp>
#include <SFML/Graphics/Transformable.hpp>
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
	   
	   
	   ,class_<sf::Drawable>("drawable", no_default_constructor)

	   ,class_<sf::Transformable>("transformable", no_default_constructor)
	   .def_constructor("make-transformable", constructor<>())

	   .def("set-position", (void (sf::Transformable::*)(const sf::Vector2f&))&sf::Transformable::setPosition,
		policies<>(), "", "",
		R"**(\brief set the position of the object

		This function completely overwrites the previous position.
		See the move function to apply an offset based on the previous position instead.
		The default position of a transformable object is (0, 0).

		\param position New position

		\see move, getPosition)**")

	   .def("set-rotation", &sf::Transformable::setRotation,
		policies<>(), "", "",
		R"**(\brief set the orientation of the object

		This function completely overwrites the previous rotation.
		See the rotate function to add an angle based on the previous rotation instead.
		The default rotation of a transformable object is 0.

		\param angle New rotation, in degrees

		\see rotate, getRotation)**")

	   .def("set-scale", (void (sf::Transformable::*)(const sf::Vector2f&))&sf::Transformable::setScale,
		policies<>(), "", "",
		R"**(\brief set the scale factors of the object

		This function completely overwrites the previous scale.
		See the scale function to add a factor based on the previous scale instead.
		The default scale of a transformable object is (1, 1).

		\param factors New scale factors

		\see scale, getScale)**")

	   .def("set-origin", (void (sf::Transformable::*)(const sf::Vector2f&))&sf::Transformable::setOrigin,
		policies<>(), "", "",
		R"**(\brief set the local origin of the object

		The origin of an object defines the center point for
		all transformations (position, scale, rotation).
		The coordinates of this point must be relative to the
		top-left corner of the object, and ignore all
		transformations (position, scale, rotation).
		The default origin of a transformable object is (0, 0).

		\param origin New origin

		\see getOrigin)**")

	   .def("get-position", &sf::Transformable::getPosition,
		policies<>(), "", "",
		R"**(\brief get the position of the object

		\return Current position

		\see setPosition)**")

	   .def("get-rotation", &sf::Transformable::getRotation,
		policies<>(), "", "",
		R"**(\brief get the orientation of the object

		The rotation is always in the range [0, 360].

		\return Current rotation, in degrees

		\see setRotation)**")

	   .def("get-scale", &sf::Transformable::getScale,
		policies<>(), "", "",
		R"**(\brief get the current scale of the object

		\return Current scale factors

		\see setScale)**")

	   .def("get-origin", &sf::Transformable::getOrigin,
		policies<>(), "", "",
		R"**(\brief get the local origin of the object

		\return Current origin

		\see setOrigin)**")

	   .def("move", (void (sf::Transformable::*)(const sf::Vector2f&))&sf::Transformable::move,
		policies<>(), "", "",
		R"**(\brief Move the object by a given offset

		This function adds to the current position of the object,
		unlike setPosition which overwrites it.
		Thus, it is equivalent to the following code:
		\code
		object.setPosition(object.getPosition() + offset);
		\endcode

		\param offset Offset

		\see setPosition)**")

	   .def("rotate", &sf::Transformable::rotate,
		policies<>(), "", "",
		R"**(\brief Rotate the object

		This function adds to the current rotation of the object,
		unlike setRotation which overwrites it.
		Thus, it is equivalent to the following code:
		\code
		object.setRotation(object.getRotation() + angle);
		\endcode

		\param angle Angle of rotation, in degrees)**")

	   .def("scale", (void (sf::Transformable::*)(const sf::Vector2f&))&sf::Transformable::scale,
		policies<>(), "", "",
		R"**(\brief Scale the object

		This function multiplies the current scale of the object,
		unlike setScale which overwrites it.
		Thus, it is equivalent to the following code:
		\code
		sf::Vector2f scale = object.getScale();
		object.setScale(scale.x * factor.x, scale.y * factor.y);
		\endcode

		\param factor Scale factors

		\see setScale)**")

	   .def("get-transform", &sf::Transformable::getTransform,
		policies<>(), "", "",
		R"**(\brief get the combined transform of the object

		\return Transform combining the position/rotation/scale/origin of the object

		\see getInverseTransform)**")

	   .def("get-inverse-transform", &sf::Transformable::getInverseTransform,
		policies<>(), "", "",
		R"**(\brief get the inverse of the combined transform of the object

		\return Inverse of the combined transformations applied to the object

		\see getTransform)**")

	   ,class_<sf::Shape, bases<sf::Drawable, sf::Transformable>>("shape", no_default_constructor)

	   .def("set-texture", &sf::Shape::setTexture,
		policies<>(), "", "",
		R"**(\brief Change the source texture of the shape

		The \a texture argument refers to a texture that must
		exist as long as the shape uses it. Indeed, the shape
		doesn't store its own copy of the texture, but rather keeps
		a pointer to the one that you passed to this function.
		If the source texture is destroyed and the shape tries to
		use it, the behavior is undefined.
		\a texture can be NULL to disable texturing.
		If \a resetRect is true, the TextureRect property of
		the shape is automatically adjusted to the size of the new
		texture. If it is false, the texture rect is left unchanged.

		\param texture   New texture
		\param resetRect Should the texture rect be reset to the size of the new texture?

		\see getTexture, setTextureRect)**")

	   .def("set-texture-rect", &sf::Shape::setTextureRect,
		policies<>(), "", "",
		R"**(\brief Set the sub-rectangle of the texture that the shape will display

		The texture rect is useful when you don't want to display
		the whole texture, but rather a part of it.
		By default, the texture rect covers the entire texture.

		\param rect Rectangle defining the region of the texture to display

		\see getTextureRect, setTexture)**")

	   .def("set-fill-color", &sf::Shape::setFillColor,
		policies<>(), "", "",
		R"**(\brief Set the fill color of the shape

		This color is modulated (multiplied) with the shape's
		texture if any. It can be used to colorize the shape,
		or change its global opacity.
		You can use sf::Color::Transparent to make the inside of
		the shape transparent, and have the outline alone.
		By default, the shape's fill color is opaque white.

		\param color New color of the shape

		\see getFillColor, setOutlineColor)**")

	   .def("set-outline-color", &sf::Shape::setOutlineColor,
		policies<>(), "", "",
		R"**(\brief Set the outline color of the shape

		By default, the shape's outline color is opaque white.

		\param color New outline color of the shape

		\see getOutlineColor, setFillColor)**")

	   .def("set-outline-thickness", &sf::Shape::setOutlineThickness,
		policies<>(), "", "",
		R"**(\brief Set the thickness of the shape's outline

		Note that negative values are allowed (so that the outline
		expands towards the center of the shape), and using zero
		disables the outline.
		By default, the outline thickness is 0.

		\param thickness New outline thickness

		\see getOutlineThickness)**")

	   .def("get-texture", &sf::Shape::getTexture,
		policies<>(), "", "",
		R"**(\brief Get the source texture of the shape

		If the shape has no source texture, a NULL pointer is returned.
		The returned pointer is const, which means that you can't
		modify the texture when you retrieve it with this function.

		\return Pointer to the shape's texture

		\see setTexture)**")

	   .def("get-texture-rect", &sf::Shape::getTextureRect,
		policies<>(), "", "",
		R"**(\brief Get the sub-rectangle of the texture displayed by the shape

		\return Texture rectangle of the shape

		\see setTextureRect)**")

	   .def("get-fill-color", &sf::Shape::getFillColor,
		policies<>(), "", "",
		R"**(\brief Get the fill color of the shape

		\return Fill color of the shape

		\see setFillColor)**")

	   .def("get-outline-color", &sf::Shape::getOutlineColor,
		policies<>(), "", "",
		R"**(\brief Get the outline color of the shape

		\return Outline color of the shape

		\see setOutlineColor)**")

	   .def("get-outline-thickness", &sf::Shape::getOutlineThickness,
		policies<>(), "", "",
		R"**(\brief Get the outline thickness of the shape

		\return Outline thickness of the shape

		\see setOutlineThickness)**")

	   .def("get-point-count", &sf::Shape::getPointCount,
		policies<>(), "", "",
		R"**(\brief Get the total number of points of the shape

		\return Number of points of the shape

		\see getPoint)**")

	   .def("get-point", &sf::Shape::getPoint,
		policies<>(), "", "",
		R"**(\brief Get a point of the shape

		The returned point is in local coordinates, that is,
		the shape's transforms (position, rotation, scale) are
		not taken into account.
		The result is undefined if \a index is out of the valid range.

		\param index Index of the point to get, in range [0 .. getPointCount() - 1]

		\return index-th point of the shape

		\see getPointCount)**")

	   .def("get-local-bounds", &sf::Shape::getLocalBounds,
		policies<>(), "", "",
		R"**(\brief Get the local bounding rectangle of the entity

		The returned rectangle is in local coordinates, which means
		that it ignores the transformations (translation, rotation,
		scale, ...) that are applied to the entity.
		In other words, this function returns the bounds of the
		entity in the entity's coordinate system.

		\return Local bounding rectangle of the entity)**")

	   .def("get-global-bounds", &sf::Shape::getGlobalBounds,
		policies<>(), "", "",
		R"**(\brief Get the global bounding rectangle of the entity

		The returned rectangle is in global coordinates, which means
		that it takes in account the transformations (translation,
		rotation, scale, ...) that are applied to the entity.
		In other words, this function returns the bounds of the
		sprite in the global 2D world's coordinate system.

		\return Global bounding rectangle of the entity)**")

	   ,class_<sf::CircleShape, sf::Shape>("circle-shape", no_default_constructor)
	   .def_constructor("make-circle-shape", constructor<float, unsigned int>())

	   .def("set-radius", &sf::CircleShape::setRadius,
		policies<>(), "", "",
		R"**(\brief Set the radius of the circle

		\param radius New radius of the circle

		\see getRadius)**")

	   .def("get-radius", &sf::CircleShape::getRadius,
		policies<>(), "", "",
		R"**(\brief Get the radius of the circle

		\return Radius of the circle

		\see setRadius)**")

	   .def("set-point-count", &sf::CircleShape::setPointCount,
		policies<>(), "", "",
		R"**(\brief Set the number of points of the circle

		\param count New number of points of the circle

		\see getPointCount)**")

	   .def("get-point-count", &sf::CircleShape::getPointCount,
		policies<>(), "", "",
		R"**(\brief Get the number of points of the circle

		\return Number of points of the circle

		\see setPointCount)**")

	   .def("get-point", &sf::CircleShape::getPoint,
		policies<>(), "", "",
		R"**(\brief Get a point of the circle

		The returned point is in local coordinates, that is,
		the shape's transforms (position, rotation, scale) are
		not taken into account.
		The result is undefined if \a index is out of the valid range.

		\param index Index of the point to get, in range [0 .. getPointCount() - 1]

		\return index-th point of the shape)**")

	   //FIXME: Add Color translator

	   ,class_<sf::ConvexShape, sf::Shape>("convex-shape", no_default_constructor)
	   .def_constructor("make-convex-shape", constructor<unsigned int>())

	   .def("set-point-count", &sf::ConvexShape::setPointCount,
		policies<>(), "", "",
		R"**(\brief Set the number of points of the polygon

		\a count must be greater than 2 to define a valid shape.

		\param count New number of points of the polygon

		\see getPointCount)**")

	   .def("get-point-count", &sf::ConvexShape::getPointCount,
		policies<>(), "", "",
		R"**(\brief Get the number of points of the polygon

		\return Number of points of the polygon

		\see setPointCount)**")

	   .def("set-point", &sf::ConvexShape::setPoint,
		policies<>(), "", "",
		R"**(\brief Set the position of a point

		Don't forget that the polygon must remain convex, and
		the points need to stay ordered!
		setPointCount must be called first in order to set the total
		number of points. The result is undefined if \a index is out
		of the valid range.

		\param index Index of the point to change, in range [0 .. getPointCount() - 1]
		\param point New position of the point

		\see getPoint)**")

	   .def("get-point", &sf::ConvexShape::getPoint,
		policies<>(), "", "",
		R"**(\brief Get the position of a point

		The returned point is in local coordinates, that is,
		the shape's transforms (position, rotation, scale) are
		not taken into account.
		The result is undefined if \a index is out of the valid range.

		\param index Index of the point to get, in range [0 .. getPointCount() - 1]

		\return Position of the index-th point of the polygon

		\see setPoint)**")

	   
	   

	   

	   

	   

	   
	   ,class_<sf::RenderTarget>("render-target", no_default_constructor)
	   . def("clear",&sf::RenderTarget::clear)
	   . def("get-view", &sf::RenderTarget::getView)
	   . def("draw", (void (sf::RenderTarget::*)(const sf::Drawable&, const sf::RenderStates&))&sf::RenderTarget::draw, policies<>(),  "(self drawable &optional (states nil))", "", "Draws the given Drawable onto the RenderTarget")
	   ,
	   class_<sf::RenderWindow,bases<sf::Window,sf::RenderTarget>>("render-window", no_default_constructor)
	   . def_constructor("make-render-window", constructor<>())
	   . def_constructor("make-render-window-vs", constructor<sf::VideoMode, sf::String>())
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
