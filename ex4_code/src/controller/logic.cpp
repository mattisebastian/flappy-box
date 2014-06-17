# include "controller/logic.hpp"

using namespace ::controller;

Logic::Logic( const std::shared_ptr< ::model::Game >& g ) : _model( g ) {}

bool Logic::advance_model( const ::controller::InputEventHandler::keyboard_event& ev )
{
  // TODO 4.3: set current timestamp in model and call delegates
  _model->setTimestamp(_model->timestamp());
  /*
  this->logic_factory().register_module
  logic_factory().register_module<model::TestObject >([](const std::shared_ptr<model::TestObject>&t){return std::make_shared<controller::TestObjectLogic>(t); });
  */

  /*!!*/std::cerr << "!! controller::Logic::advance_model: (PARTS ARE) UNIMPLEMENTED." << std::endl; 
  return false;
}
