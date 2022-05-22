#pragma once

enum class Colors {
	RED,
	ORANGE,
	YELLOW,
	GREEN,
	CYAN,
	BLUE,
	VIOLET,
	WHITE
};
class Light {
public:
	Light() :state(false), color(Colors::WHITE) {};
	void On() {
		if (!state) {
			state = true;
		}
	};
	void Off() {
		if (state) {
			state = false;
		}
	};
	void changeColor(Colors newColor) {
		color = newColor;
	}
	bool getState() const {
		return state;
	}
private:
	bool state;
	Colors color;
};