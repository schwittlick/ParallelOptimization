/**
 * @author		Andy Liebke<coding@andysmiles4games.com>
 * @version 	1.0.0 25-Sep-13
 * @copyright	Copyright (c) 2013 by Andy Liebke. All rights reserved. (http://andysmiles4games.com)
 */
#include <BoidGroup.h>
#include <BoidEntity.h>
#include <BaseBehavior.h>

BoidGroup::BoidGroup(void) :
	_listBoids(new TListBoids()),
	_behavior(NULL)
{
	this->_listBoids = new TListBoids();
}

BoidGroup::BoidGroup(const BoidGroup &src) :
	_listBoids(new TListBoids(*src._listBoids)),
	_behavior(NULL)
{
}

BoidGroup::~BoidGroup(void)
{
}

BoidGroup& BoidGroup::operator = (const BoidGroup &src)
{
	this->_listBoids = new TListBoids(*src._listBoids);
	
	return *this;
}

void BoidGroup::setBehavior(BaseBehavior* behavior)
{
	this->_behavior = behavior;
	this->_behavior->setBoidGroup(this);
}

void BoidGroup::update(void)
{
	this->_behavior->update();
}

void BoidGroup::render(void)
{
	for(TListBoids::iterator it=this->_listBoids->begin();it != this->_listBoids->end();++it){
		(*it)->render();
	}
}

void BoidGroup::add(BoidEntity* boid)
{
	this->_listBoids->push_back(boid);
}

void BoidGroup::release(void)
{
	for(TListBoids::iterator it=this->_listBoids->begin();it != this->_listBoids->end();++it){
		MEMORY_DELETE((*it));
	}
	
	this->_listBoids->clear();
	
	delete this->_listBoids;
	this->_listBoids = NULL;
}