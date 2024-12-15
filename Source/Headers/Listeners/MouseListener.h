#pragma once
class MouseListener {
public:
    bool first_mouse = true;
    float last_x;
    float last_y;

    virtual void process_mouse(float new_x, float new_y) = 0;
};