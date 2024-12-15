#pragma once
#include <GLFW/glfw3.h>
#include <iostream>
#include <string>
#include <vector>

#include "Listeners/keyboard_listeners.h"
#include "Listeners/MouseListener.h"
#include "Listeners/ScrollListener.h"
#include "camera.h"

enum InputType {
    KEYBOARD,
    MOUSE,
    SCROLL
};

class InputEvent {
public:
    InputType type;
    float x, y;
    float delta_time;
    std::vector<unsigned int> pressed_keys;
};

class InputManager {
    std::vector<KeyboardListener*> keyboard_listeners;
    std::vector<MouseListener*> mouse_listeners;
    std::vector<ScrollListener*> scroll_listeners;

public:

    void add_keyboard_listener(KeyboardListener& kl) {
        keyboard_listeners.push_back(&kl);
    }

    void add_mouse_listener(MouseListener& ml) {
        mouse_listeners.push_back(&ml);
    }

    void add_scroll_listener(ScrollListener& sl) {
        scroll_listeners.push_back(&sl);
    }

    void process(InputEvent event) {
        switch (event.type) {
        case KEYBOARD:
            for (auto& listener : keyboard_listeners) {
                listener->process_keyboard(event.delta_time, event.pressed_keys);
            }
            break;
        case MOUSE:
            for (auto& listener : mouse_listeners) {
                listener->process_mouse(event.x, event.y);
            }
            break;
        case SCROLL:
            for (auto& listener : scroll_listeners) {
                listener->process_scroll(event.y);
            }
            break;
        }
    }
};

