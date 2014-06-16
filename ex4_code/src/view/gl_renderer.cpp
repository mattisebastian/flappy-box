#include "view/gl_renderer.hpp"
#include "view/glut_window.hpp"
#include "GL/freeglut.h"
// 4.3
#include "controller/logic.hpp"

using namespace ::view;

GlRenderer::GlRenderer( std::shared_ptr< model::Game const > const& g )
: _game_model( g )
{}

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

	// TODO: call delegates
	// 1.
	//controller::Logic logic( _game_model );

	// 2.

	// 3.

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
