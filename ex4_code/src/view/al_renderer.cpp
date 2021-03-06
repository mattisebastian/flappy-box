# include "view/al_renderer.hpp"

using namespace ::view;

AlRenderer::AlRenderer( std::shared_ptr< model::Game const > const& g ) 
: _game_model( g ) 
{}

std::shared_ptr< model::Game const > const& AlRenderer::game_model() const
{
  return _game_model;
}

AlRenderer::delegate_factory_type& AlRenderer::audible_factory()
{
  return _audible_factory;
}

AlRenderer::delegate_factory_type const& AlRenderer::audible_factory() const
{
  return _audible_factory;
}

void AlRenderer::auralize_model()
{
	// TODO 4.3: call delegates
	// (2)
	for (auto obj : game_model()->objects())
	{
		auto delegate = obj->getData< Audible >();

		// no delegate for this object
		if (delegate == nullptr)
		{
			obj->registerData(audible_factory().create_for(obj));
			delegate = obj->getData< Audible >();
		}

		delegate->auralize( *this );
	}

	/*!!*/std::cerr << "!! view::AlRenderer::auralize_model: (PARTS ARE) UNIMPLEMENTED." << std::endl; 
}
