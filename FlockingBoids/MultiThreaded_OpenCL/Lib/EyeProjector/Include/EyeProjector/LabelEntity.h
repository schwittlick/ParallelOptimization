/**
 * EyeProjector - Label Entity Module.
 *
 * @author		Andy Liebke<coding@andysmiles4games.com>
 * @file		Include/EyeProjector/LabelEntity.h
 * @version 	1.0.0 31-May-13
 * @version		1.1.0 09-Jun-13
 * @version		1.2.0 12-Jul-13
 * @version		1.3.0 10-Aug-13
 * @version		1.4.0 15-Sep-13
 * @version		1.4.1 21-Sep-13
 * @copyright	Copyright (c) 2013 by Andy Liebke. All rights reserved. (http://andysmiles4games.com)
 */
#ifndef __EYE_PROJECTOR_LABEL_ENTITY_H__
#define __EYE_PROJECTOR_LABEL_ENTITY_H__

#include <EyeProjector/BaseEntity.h>
#include <EyeProjector/ColorRGBA.h>
#include <string>

/**
 * EyeProjector Namespace.
 */
namespace EP
{
	/**
	 * Laben Entity Class.
	 */
	class LabelEntity : public BaseEntity
	{
		public:
			/**
			 * Creates new instance of this class.
			 */
			LabelEntity(void);
			
			/**
			 * Creates new instance of this class.
			 *
			 * @param text - new text content for this label
			 */
			LabelEntity(const std::string text);
			
			/**
			 * Creates new instance of this class.
			 *
			 * @param text 		- new text content for this label
			 * @param position	- new position for this label
			 */
			LabelEntity(const std::string text, const Vector2D position);
			
			/**
			 * Creates new instance by copying another instance of this class.
			 *
			 * @param src - reference to the other instance of this class
			 */
			LabelEntity(const LabelEntity &src);
			
			/**
			 * Releases this instance of this class.
			 */
			virtual ~LabelEntity(void);
			
			/**
			 * Renders text of this label.
			 */
			void render(void);
			
			/**
			 * Assigns float value as text content for this label.
			 *
			 * @param value - float value as text content for this label
			 */
			void setText(const TF32 value);
			
			/**
			 * Assigns float value with additinal text description for this label.
			 *
			 * @param value - float value as text content for this label
			 * @param label	- description about that given float value
			 */
			void setText(const TF32 value, const std::string label);
			
			/**
			 * Assigns text content with variable count of parameters.
			 *
			 * This method allows to write placeholders within the text content
			 * and to define the values of those as additinal values.
			 *
			 * Example:
			 *	<code>
			 *		label->setText("New value: %f", 12.34f);
			 *	</code>
			 *
			 * @param text - string including new text content
			 */
			void setText(const std::string text, ...);
			
			/**
			 * Returns text content of this label.
			 *
			 * @return string including text content of this label.
			 */
			std::string getText(void) const
			{
				return this->_text;
			}
			
			/**
			 * Assigns text color to this label.
			 *
			 * @parma color - new color value
			 */
			void setColor(const ColorRGBA color)
			{
				this->_color = color;
			}
			
		protected:
			void _render(void);	
			
		private:
			/**
			 * Stores text content of this label.
			 */
			std::string _text;
			
			/**
			 * Stores text color of this label.
			 */
			ColorRGBA _color;
	};
}

#endif