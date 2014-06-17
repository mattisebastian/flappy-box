#include "factory_map.hpp"

#include "model/game.hpp"
#include "view/gl_renderer.hpp"
#include "controller/engine.hpp"
#include "controller/glut_engine.hpp"

# include <iostream>

int main( int argc, char** argv )
{ 
	// TODO 4.3: test factory and delegates here
	std::shared_ptr< model::Game > game = std::make_shared<::model::Game>();

	/*
	std::shared_ptr< ::controller::Engine > game_engine(new ::controller::GlutEngine);

	game_engine->init(argc, argv);
	game_engine->run();
	*/
	/*!!*/std::cerr << "main43: (PARTS ARE) UNIMPLEMENTED" << std::endl;

	return 0;
}
