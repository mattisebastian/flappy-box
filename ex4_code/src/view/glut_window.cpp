# include "view/glut_window.hpp"

# include <GL/freeglut.h>

# include <iostream>

using namespace ::view;

GlutWindow::GlutWindow( const std::string& name, size_t width, size_t height, std::shared_ptr<view::GlRenderer>& glRenderPtr,
			std::shared_ptr<controller::InputEventHandler>& inpEvHanPtr)
: _name( name )
, _width( width )
, _height( height )
, _glRenderPtr( glRenderPtr )
, _inpEvHanPtr( inpEvHanPtr )
{
  // TODO 4.1: assign input event handler and renderer
  /*!!*/std::cerr << "!! view::GlutWindow::GlutWindow: (PARTS ARE) UNIMPLEMENTED." << std::endl; 

  // GLUT GlutWindow Initialization:
  glutInitWindowSize( width, height );
  glutInitDisplayMode( GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH );

  _glut_win_id = glutCreateWindow( name.c_str() );
  if( is_closed() ) 
    throw std::logic_error( "::view::GlutWindow::GlutWindow: Could not create GLUT window." );

  glutSetWindowData( this );

  // setup callbacks
  glutDisplayFunc( glutDisplay );
  glutReshapeFunc( glutReshape );
  glutKeyboardFunc( glutKeyboard );
  glutCloseFunc( glutClose );
}

GlutWindow::~GlutWindow()
{
  close();
}

void GlutWindow::invalidate()
{
  if( is_closed() )
  {
    std::clog << "view::GlutWindow::ensureCurrent: Window was already closed." << std::endl;
    return;
  }
  ensureCurrent();
  glutPostRedisplay();
}

void GlutWindow::ensureCurrent() const
{
  if( is_closed() )
  {
    std::clog << "view::GlutWindow::ensureCurrent: Window was already closed." << std::endl;
    return;
  }
  if( _glut_win_id != glutGetWindow() ) 
  {
    std::clog << "view::GlutWindow::ensureCurrent: Switching to window " << _name << " with id " << _glut_win_id << "…" << std::endl;
    glutSetWindow( _glut_win_id );
  }
}

unsigned int GlutWindow::width() const
{
  return _width;
}

unsigned int GlutWindow::height() const
{
  return _height;
}

bool GlutWindow::is_closed() const
{
  return _glut_win_id <= 0;
}

void GlutWindow::close()
{
  if( is_closed() )
  {
    std::clog << "view::GlutWindow::close: Window was already closed." << std::endl;
    return;
  }
  glutDestroyWindow( _glut_win_id );
  _glut_win_id = -1;
}

void GlutWindow::glutDisplay() 
{
  GlutWindow* win = reinterpret_cast< GlutWindow* >( glutGetWindowData() );
  if( ! win )
    throw std::out_of_range( "view::GlutWindow::glutDisplay: Could not get pointer to GlutWindow." );

  // TODO 4.1: use renderer to draw the model
  win->getGlRendererPtr()->visualize_model(*win); 
  /*!!*/std::cerr << "!! view::GlutWindow::glutDisplay: (PARTS ARE) UNIMPLEMENTED." << std::endl; 
}

void GlutWindow::glutReshape( int width, int height )
{
  GlutWindow* win = reinterpret_cast< GlutWindow* >( glutGetWindowData() );
  if( ! win ) 
    throw std::out_of_range( "view::GlutWindow::glutReshape: Could not get pointer to GlutWindow." );

  win->_width = width;
  win->_height= height;

  // TODO 4.1: use renderer to resize the view
  win->getGlRendererPtr()->resize(*win);
  /*!!*/std::cerr << "!! view::GlutWindow::glutReshape: (PARTS ARE) UNIMPLEMENTED." << std::endl; 
}

void GlutWindow::glutKeyboard( unsigned char glut_key, int mouse_x, int mouse_y )
{
  GlutWindow* win = reinterpret_cast< GlutWindow* >( glutGetWindowData() );
  if( ! win )
    throw std::out_of_range( "view::GlutWindow::glutKeyboard: Could not get pointer to GlutWindow." );

  if( !win->getInputEventHandler() )
    std::clog << "view::GlutWindow::glutKeyboard: no InputEventHandler attached (which could handle the event)." << std::endl;

  // TODO 4.1:  create keyboard-event data structure and forward it to the event handler
  controller::InputEventHandler::keyboard_event kE;
  kE.key = glut_key;
  kE.mouse_pos[0] = static_cast<double>(mouse_x);
  kE.mouse_pos[1] = static_cast<double>(mouse_y);
  win->getInputEventHandler()->handle(kE);
  
  /*!!*/std::cerr << "!! view::GlutWindow::glutKeyboard: (PARTS ARE) UNIMPLEMENTED." << std::endl; 
}

void GlutWindow::glutClose() 
{ 
  GlutWindow* win = reinterpret_cast< GlutWindow* >( glutGetWindowData() );
  if( ! win )
    throw std::out_of_range( "view::GlutWindow::glutClose: Could not get pointer to GlutWindow." );

  if( win->is_closed() )
  {
    std::clog << "view::GlutWindow::glutClose: Window was already closed." << std::endl;
    return;
  }

  win->_glut_win_id = -1;
}
