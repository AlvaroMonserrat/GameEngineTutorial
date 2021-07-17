#ifndef WARRIOR_H
#define WARRIOR_H

#include "Character.h"

class Warrior: public Character
{
    public:
        Warrior(Properties* props);
        virtual void Draw();
        virtual void Update(float dt);
        virtual void Clean();

    private:
        int m_Row, m_Frame, m_FrameCount;
        int m_AnimSpeed;
};

#endif // WARRIOR_H
