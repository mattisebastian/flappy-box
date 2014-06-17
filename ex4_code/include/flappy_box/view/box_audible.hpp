#pragma once

#include "view/al_renderer.hpp";
#include "view/gl_renderer.hpp";

namespace flappy_box
{
	namespace view
	{
		class BoxAudible : public ::view::AlRenderer::Audible
		{
		private:

			const double base_frequency = 400;
			const double target_frequency = 100;

		public:
			BoxAudible();
			~BoxAudible();

			virtual void auralize(::view::AlRenderer&);

		};
	}
}
