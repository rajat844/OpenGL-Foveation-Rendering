#pragma once
class ScrollListener {
public:
    virtual void process_scroll(float offset) = 0;
};