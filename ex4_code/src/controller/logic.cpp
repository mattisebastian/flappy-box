# include "controller/logic.hpp"

# include <chrono>

using namespace ::controller;

Logic::Logic( const std::shared_ptr< ::model::Game >& g ) : _model( g ) {}

bool Logic::advance_model( const ::controller::InputEventHandler::keyboard_event& ev )
{
	// TODO 4.3: set current timestamp in model and call delegates
	_model->setTimestamp(std::chrono::steady_clock::now());


	/*!!*/std::cerr << "!! controller::Logic::advance_model: (PARTS ARE) UNIMPLEMENTED." << std::endl; 
	return false;
}
