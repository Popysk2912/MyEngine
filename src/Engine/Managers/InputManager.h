#pragma once
#include <unordered_map>
#include <string>
#include <SFML/Graphics.hpp>

struct Axis
{
	Axis() : negativeKey(0), positiveKey(0), value(0.0f) { }
	Axis(int minus, int add) : negativeKey(minus), positiveKey(add), value(0.0f) { }
	Axis(const Axis& other) : positiveKey(other.positiveKey), negativeKey(other.negativeKey), value(other.value) { }
	Axis& operator=(const Axis& other)
	{
		if (this != &other) {
			positiveKey = other.positiveKey;
			negativeKey = other.negativeKey;
			value = other.value;
		}
		return *this;
	}
	int positiveKey;
	int negativeKey;
	float value;
};

class InputManager
{
private:
	static std::unordered_map<int, bool> keys;
	static std::unordered_map<std::string, Axis> axes;
public:
	static void updateKeys(sf::Event e);
	static bool isKeyDown(int keyCode);
	static void createAxis(int minus, int add, std::string name);
	static float getAxis(std::string name);
};