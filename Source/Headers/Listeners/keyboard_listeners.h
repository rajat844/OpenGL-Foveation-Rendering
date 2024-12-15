#pragma once
#include <vector>

class KeyboardListener {
public:
    virtual void process_keyboard(float delta_time, std::vector<unsigned int>& pressed_keys) = 0;
};
