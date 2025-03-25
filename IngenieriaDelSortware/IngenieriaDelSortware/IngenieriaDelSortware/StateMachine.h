#pragma once
#include "map"
#include "State.h"
class StateMachine
{

public:
  void ChangeState(EState _state);
  void InitStateMachine(EState _state);
  void UpdateState();

  void AddStates(EState _eState ,State* _state);


private:
  std::map<EState,State*> stateList;

  State* lastState;
  State* currentState;

};

