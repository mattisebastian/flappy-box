#pragma once

#include "view/gl_renderer.hpp";

namespace flappy_box
{
	namespace view
	{
		class BoxDrawable : public ::view::GlRenderer::Drawable
		{
		public:
			BoxDrawable();
			~BoxDrawable();

		private:
		};

	}
}