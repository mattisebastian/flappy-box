#ifndef BOXAUDIBLE_H
#define BOXAUDIBLE_H

# include "al_renderer.hpp";
# include "gl_renderer.hpp";

class BoxAudible : public view::AlRenderer::Audible
{
private:
  
    const double base_frequency = 400;
    const double target_frequency = 100;
  
public:
    
    BoxAudible();
    
    virtual void auralize(AlRenderer&);

};

#endif // BOXAUDIBLE_H