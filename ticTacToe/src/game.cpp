/*
 * game.cpp
 *
 *  Created on: Dec 12, 2019
 *      Author: marcobarion
 */

class Game{
	// Constructor
	Game();
	// Instance
	static Game* instance;

public:
	static Game* getInstance();
	~Game();
};




/*
 *  SINGLETON EXAMPLE
 *
 *  class Singleton
{
   public:
       static Singleton* getInstance( );
       ~Singleton( );
   private:
       Singleton( );
       static Singleton* instance;
};
 */
