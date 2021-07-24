#ifndef ENEMY_H
#define ENEMY_H

#include "Character.h"
#include "Collider.h"
#include "Vector2D.h"
#include "RigidBody.h"
#include "SeqAnimation.h"

class Enemy : public Character
{
    public:
        Enemy(Properties* props);
        virtual void Draw();
        virtual void Update(float dt);
        virtual void Clean();

    private:
        Collider* m_Collider;
        SeqAnimation* m_Animation;
        RigidBody* m_RigidBody;
        Vector2D m_LastSafePosition;
};

#endif // ENEMY_H
