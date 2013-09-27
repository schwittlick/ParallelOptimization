/**
 * @version 	1.0.0 25-Sep-13
 * @copyright	Copyright (c) 2013 by Andy Liebke. All rights reserved. (http://andysmiles4games.com)
 */
#include <BaseBehavior.h>

BaseBehavior::BaseBehavior(void) :
	_group(NULL)
{
}

BaseBehavior::BaseBehavior(const BaseBehavior &src) :
	_group(new BoidGroup(*src._group))
{
}

BaseBehavior::~BaseBehavior(void)
{
}

BaseBehavior& BaseBehavior::operator = (const BaseBehavior &src)
{
	if(&src != this){
		this->_group = new BoidGroup(*src._group);
	}
	
	return *this;
}