#pragma once

enum EState
{
  Ducking = 0,
  Standing = 1,
  Jumping = 2,
  Dividing = 3,
  None
};

class State
{
public:

  State();
  State(EState _state);
  virtual void Enter();
  virtual void Exit();
  virtual void Update();
  virtual bool Condition();

  void SetStateType(EState type);

  EState GetStateType() const;
private:
  EState stateType;

};

