#ifndef INPUT_H
#define INPUT_H

#include "SDL2/SDL.h"
#include "Point.h"

enum Axis{HORIZONTAL, VERTICAL};

class Input
{

public:
    static Input* GetInstance()
    {
        return s_Instance = (s_Instance != nullptr) ? s_Instance : new Input();
    }

    void Listen();
    bool GetKeyDown(SDL_Scancode key);
    bool GetMousePressLeft();

    int GetAxisKey(Axis axis);
    Point GetPoint();

private:
    Input();
    void KeyUP();
    void KeyDown();
    void MotionMouse(int x, int y);

    Point m_MouseXY;
    const Uint8* m_KeyStates;
    Uint32 m_MouseStates;

    static Input* s_Instance;
};

#endif // INPUT_H
