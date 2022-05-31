#pragma once
#include <iostream>

class Device {
public:
    std::string type;
    Device(const std::string& type) : type(type) {}
    virtual void On() {
        std::cout << type << " is on" << std::endl;
    }
    virtual void Off() {
        std::cout << type << " is off" << std::endl;
    }
};
class MediaPlayer : public Device {
private:
    std::string currentMovie;
public:
    MediaPlayer(const std::string& type) : Device(type) {}
    void play(std::string newMovie) {
        currentMovie = newMovie;
        std::cout << "Movie " << currentMovie << " started" << std::endl;
    }
};
class Amplifier : public Device {
    Device* streamingPLayer;
    int volume;
public:
    Amplifier(const std::string& type) : Device(type), volume(0) {}
    void setStreamingPlayer(Device* d) {
        streamingPLayer = d;
        std::cout << "Streaming player is " << d->type << std::endl;
    }
    void setSurroundSound() {
        std::cout << "Surround Sound Mode" << std::endl;
    };
    void setVolume(int v) {
        volume = v;
    }
};
class Projector : public Device {
private:
    Amplifier* _amplifier;
    Device* _input;
public:
    Projector(const std::string& type) : Device(type) {}
    void setInput(Device* d) {
        _input = d;
        std::cout << "Projector input is " << d->type << std::endl;
    }
    void wideScreenMode() {
        std::cout << "Wide Screen Mode" << std::endl;
    };
};
class Tuner {
private:
    Amplifier* _amplifier;
public:
    void on() {
        std::cout << "Tuner on" << std::endl;
    }
    void off() {
        std::cout << "Tuner off" << std::endl;
    }
};
class Popper : public Device {
public:
    Popper(const std::string& type) : Device(type) {}
    void pop() {
        std::cout << "Popcorn will be ready soon" << std::endl;
    }
};
class Lights : public Device {
private:
    int currentLight;
public:
    Lights(const std::string& type) : Device(type), currentLight(100) {}
    void dim(int light) {
        currentLight = light;
    }
};
class Screen : public Device {
public:
    Screen(const std::string& type) : Device(type) {}
    void down() {
        std::cout << "Screen is down" << std::endl;
    };
    void up() {
        std::cout << "Screen is up" << std::endl;
    };
};

class Facade {
public:
    Facade() {
        _mp = new MediaPlayer("media player");
        _popper = new Popper("popper");
        _lights = new Lights("light");
        _projector = new Projector("projector");
        _screen = new Screen("screen");
        _amp = new Amplifier("Amplifier");
    }
    ~Facade(){
        delete _mp;
        delete _popper;
        delete _lights;
        delete _projector;
        delete _screen;
        delete _amp;
    }
    void EnableMovie(const std::string& movie) {
        _popper->On();
        _popper->pop();
        _lights->dim(0);
        _screen->down();
        _projector->On();
        _projector->setInput(_mp);
        _projector->wideScreenMode();
        _amp->On();
        _amp->setStreamingPlayer(_mp);
        _amp->setSurroundSound();
        _amp->setVolume(5);
        _mp->On();
        _mp->play(movie);
    }
    void DisableMovie() {
        _mp->Off();
        _amp->Off();
        _projector->Off();
        _screen->up();
        _lights->dim(100);
        _popper->Off();
    }
private:
    MediaPlayer* _mp;
    Amplifier* _amp;
    Projector* _projector;
    Popper* _popper;
    Lights* _lights;
    Screen* _screen;
    Tuner* _tuner = nullptr;
};