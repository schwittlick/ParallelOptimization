/**
 * FlockingBoids - Flocking Boid Application Scene Module.
 *
 * @author		Andy Liebke<coding@andysmiles4games.com>
 * @file		Source/FlockingBoidScene.h
 * @version		1.0.0 25-Sep-13
 * @copyright	Copyright (c) 2013 by Andy Liebke. All rights reserved. (http://andysmiles4games.com)
 */
#ifndef __FLOCKING_BOID_SCENE_H__
#define __FLOCKING_BOID_SCENE_H__

#include <EyeProjector/IScene.h>
#include <EyeProjector/IReceivableKeyBoardInput.h>
#include <EyeProjector/TriangleEntity.h>
#include <EyeProjector/LabelEntity.h>
#include <BoidEntity.h>
#include <vector>

class BoidGroup;

typedef std::vector<BoidGroup*> TListBoidGroups;

/**
 * Flocking Boid Application Scene Class.
 */
class FlockingBoidScene : public EP::IScene, public EP::IReceivableKeyboardInput
{
	public:
		/**
		 * Creates new instance of this class.
		 */
		FlockingBoidScene(void);
		
		/**
		 * Creates new instance by copying another instance of this class.
		 *
		 * @param src - reference to the other instance of this class
		 */
		FlockingBoidScene(const FlockingBoidScene &src);
		
		/**
		 * Releases this instance of this class.
		 */
		virtual ~FlockingBoidScene(void);
		
		/**
		 * Assigns data by another instance of this class.
		 *
		 * @param src - reference to the other instance of this class
		 * @return reference to this instance of this class
		 */
		FlockingBoidScene& operator = (const FlockingBoidScene &src);
		
		/**
		 * Initilizes this scene.
		 */
		void init(void);
		
		/**
		 * Updates all scene entities.
		 */
		void update(void);
		
		/**
		 * Renders all scene entities.
		 */
		void render(void);
		
		/**
		 * Releases all reserved memory.
		 */
		void release(void);
		
		/**
		 * Handles pressed key event from the keyboard.
		 */
		void handlePressedKey(const int keyCode);
		
	private:
		/**
		 * Adds a boid to the scene.
		 */
		void _addBoid(void);	
		
	private:
		/**
		 * Stores boid group.
		 */
		BoidGroup* _currBoidGroup;
		
		/**
		 * Stores label to display current count of boids in the scene.
		 */
		EP::LabelEntity* _countLabel;
		
		EP::LabelEntity* _profilerLabel;
		EP::LabelEntity* _countThreadsLabel;
		
		static EP::TUInt32 _countBoids;
		
		TListBoidGroups _listBoidGroups;
};

#endif