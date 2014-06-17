#pragma once

#include "game.hpp"

namespace model
{
	class Game;

	class TestGameObject : public ::model::GameObject
	{
	public:

		TestGameObject(const bool dynamic_flag = true, const std::string& name = "untitled TestGameObject");
		// we need at least one virtual function to be polymorphic.
		virtual ~TestGameObject() {}

	}; // GameObject

} // model::

