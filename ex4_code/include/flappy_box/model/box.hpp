#pragma once

#include "math.hpp"

namespace flappy_box
{
	namespace model
	{
		class Box
		{
		public:
			Box();
			~Box();

			vec3_type getAngleVec() { return angleVec; };
			void setAngleVec(vec3_type av) { angleVec = av; };

			vec3_type getPositionVec() { return positionVec; };
			void setPositionVec(vec3_type pv) { positionVec = pv; };

			vec3_type getSpeedVec() { return speedVec; };
			void setSpeedVec(vec3_type sv) { speedVec = sv; };

			vec3_type getAccelerationVec() { return accelerationVec; };
			void setAccelerationVec(vec3_type acv) { accelerationVec = acv; };

		private:

			vec3_type angleVec = vec3_type(0.0, 0.0, 0.0);
			vec3_type positionVec = vec3_type(0.0, 0.0, 0.0);
			vec3_type speedVec = vec3_type(0.0, 0.0, 0.0);
			vec3_type accelerationVec = vec3_type(0.0, 0.0, 0.0);

		};
	}
}
