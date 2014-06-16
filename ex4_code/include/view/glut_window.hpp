# pragma once

# include "view/gl_renderer.hpp"
# include "controller/input_event_handler.hpp"

# include <string>

namespace view
{

class GlutWindow
{
public:
    // 4.1: change constructor prototype so it takes
    //           additional pointers to a renderer and a event-handler.
    GlutWindow( const std::string& name, size_t width, size_t height,
		std::shared_ptr<view::GlRenderer>& glRenderPtr, std::shared_ptr<controller::InputEventHandler>& inpEvHanPtr );
    ~GlutWindow();

    unsigned int width() const;
    unsigned int height() const;

    // 4.1: declare getters for event handler and renderer
	std::shared_ptr<view::GlRenderer> getGlRendererPtr() { return _glRenderPtr; };
	void setGlRendererPtr(std::shared_ptr<view::GlRenderer>& rend) { _glRenderPtr = rend; };

	std::shared_ptr<controller::InputEventHandler> getInputEventHandler() { return _inpEvHanPtr; };
	void setInputEventHandler(std::shared_ptr<controller::InputEventHandler>& handler) { _inpEvHanPtr = handler; };

    // Request window redisplay.
    void invalidate();

    // Indicates if window was already closed.
    bool is_closed() const;
    // Allows to manually close the window before the destructor is called.
    void close();
    
private:
    // make sure this Window is the current GLUT Window.
    void ensureCurrent() const;

    static void glutDisplay();
    static void glutReshape( int width, int height );
    static void glutKeyboard( unsigned char glut_key, int mouse_x, int mouse_y );
    static void glutClose();

    std::string _name;
    size_t      _width;
    size_t      _height;
    int         _glut_win_id;

    // 4.1: add member variables for references to event handler and renderer
	std::shared_ptr<view::GlRenderer> _glRenderPtr;
	std::shared_ptr<controller::InputEventHandler> _inpEvHanPtr;

}; // GlutWindow

} // view::

