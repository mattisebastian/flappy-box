#pragma once

#include "model/game_object.hpp"

namespace model
{
	class TestGameObject : GameObject
	{
	public:

		TestGameObject(const bool dynamic_flag = true, const std::string& name = "untitled GameObject");
		// we need at least one virtual function to be polymorphic.
		virtual ~TestGameObject() { }

	}; // TestGameObject

} // model::