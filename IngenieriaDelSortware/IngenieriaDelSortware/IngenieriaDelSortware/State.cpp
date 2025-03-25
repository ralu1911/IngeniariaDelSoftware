#include "State.h"

#include "iostream"

State::State()
{
  stateType = EState::None;
}

State::State(EState _state)
{
  stateType = _state;
}

void State::Enter()
{
  printf("\nEntrando en %i", stateType);
}

void State::Exit()
{
  printf("\nSaliendo de %i", stateType);
}

void State::Update()
{
  
}

bool State::Condition()
{
  return false;
}

void State::SetStateType(EState type)
{
  stateType = type;
}

EState State::GetStateType() const
{
  return stateType;
}
