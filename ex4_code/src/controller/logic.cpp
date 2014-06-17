# include "controller/logic.hpp"

# include <chrono>

using namespace ::controller;

Logic::Logic( const std::shared_ptr< ::model::Game >& g ) : _model( g ) {}

bool Logic::advance_model( const ::controller::InputEventHandler::keyboard_event& ev )
{
	// TODO 4.3: set current timestamp in model and call delegates
	_model->setTimestamp(std::chrono::steady_clock::now());

	bool flag = true;
	// (2) (für 1 und 3 siehe gl_renderer.cpp)
	for (auto obj : game_model()->objects())
	{
		auto delegate = obj->getData< ObjectLogic >();

		// no delegate for this object
		if (delegate == nullptr)
		{
			obj->registerData(logic_factory().create_for(obj));
			delegate = obj->getData< ObjectLogic >();
		}
		
		// TODO
		// i don't know! if advance would fail once advance_model will return false
		if (!delegate->advance(*this, ev))
			flag = false;
	}

	/*!std::cerr << "!! controller::Logic::advance_model: (PARTS ARE) UNIMPLEMENTED." << std::endl; !*/
	return flag;
}
