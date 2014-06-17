#include "view/gl_renderer.hpp"
#include "view/glut_window.hpp"
#include "GL/freeglut.h"
// 4.3
#include "model/test_game_object.hpp"

using namespace ::view;

GlRenderer::GlRenderer( std::shared_ptr< model::Game const > const& g )
: _game_model( g )
{

}

std::shared_ptr< ::model::Game const > const& GlRenderer::game_model() const
{
  return _game_model;
}

GlRenderer::delegate_factory_type& GlRenderer::drawable_factory()
{
  return _drawable_factory;
}

GlRenderer::delegate_factory_type const& GlRenderer::drawable_factory() const
{
  return _drawable_factory;
}

void GlRenderer::visualize_model( GlutWindow& w )
{
	// TODO 4.3: initialize OpenGL context, call delegates and swap buffers
	glClearColor(.0f, .0f, .0f, 1.f); // 0.1f, 0.2f, 0.3f, 1.0f
	glClear( GL_DEPTH_BUFFER_BIT | GL_COLOR_BUFFER_BIT );

	glMatrixMode( GL_MODELVIEW ); // GL_PROJECTION is used in resize( )
	glLoadIdentity();
	gluLookAt( 0, -7, 0, 0, 0, 0, 0, 0, 1 );
	
	// call delegates (delegate = explicit Drawable)
	// (1)
	/*
	drawable_factory().register_module< model::TestGameObject >(
		[](const std::shared_ptr < model::TestGameObject>& test_object)
		{
			return std::make_shared<view::GlRenderer::TestDrawable>();
		}
	);
	*/
	/*for (auto obj : game_model()->objects())
		drawable_factory().create_for(obj)->visualize( *this, w );*/

	// (2)
	for (auto obj : game_model()->objects())
	{
		auto delegate = obj->getData< Drawable >();

		// no delegate for this object
		if (delegate == nullptr)
		{
			obj->registerData( drawable_factory().create_for(obj) );
			delegate = obj->getData< Drawable >();
		}

		delegate->visualize( *this, w );
	}

	// (3)
	// im Konstruktor alle Objekte durchlaufen und den Delegate ablegen
	/* KONSTRUKTOR:
	for (auto obj : game_model()->objects())
		obj->registerData(drawable_factory().create_for(obj));*/
	/* VISUALIZE_MODEL: ...*/

	glutSwapBuffers();

	/*!!*/std::cerr << "!! view::GlRenderer::visualize_model: (PARTS ARE) UNIMPLEMENTED." << std::endl; 
}

void GlRenderer::resize( GlutWindow& win ) 
{
  glViewport( 0,0, win.width(), win.height() );
  glMatrixMode( GL_PROJECTION );
  glLoadIdentity(); //Reset the camera
  gluPerspective( 45., win.width() / double( win.height() ), .5, 100. );
}
