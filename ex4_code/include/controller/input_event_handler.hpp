# pragma once

namespace controller 
{

  class InputEventHandler
  {
    public:

      struct keyboard_event
      {
	char key;
        int modifier_mask;
        double mouse_pos [2];
	enum modifier_mask_enum {SHIFT_ACTIVE=1, CTRL_ACTIVE=2, ALT_ACTIVE=4};
	
      };

    // TODO 4.1: declare pure-virtual handle function and define struct keyboard_event
      virtual bool handle(keyboard_event const&) = 0;

  }; // InputEventHandler

} // controller::
