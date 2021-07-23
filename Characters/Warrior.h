#ifndef WARRIOR_H
#define WARRIOR_H

#include "Character.h"
#include "Animation.h"
#include "RigidBody.h"
#include "Collider.h"
#include "Vector2D.h"

#define RUN_FORCE 4.0f;

#define JUMP_TIME 15.0f;
#define JUMP_FORCE 10.0f;
#define ATTACK_TIME 20.0f;

class Warrior: public Character
{
public:
    Warrior(Properties* props);
    virtual void Draw();
    virtual void Update(float dt);
    virtual void Clean();

private:
    void AnimationState();

private:
    bool m_IsRunning;
    bool m_IsJumping;
    bool m_IsFalling;
    bool m_IsGrounded;
    bool m_IsAttacking;
    bool m_IsCrouching;

    float m_JumpTime;
    float m_JumpForce;
    float m_AttackTime;

    Collider* m_Collider;
    Animation* m_Animation;
    RigidBody* m_RigidBody;

    Vector2D m_LastSafePosition;
};

#endif // WARRIOR_H
