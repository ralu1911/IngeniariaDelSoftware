#include "StateMachine.h"

void StateMachine::ChangeState(EState _state)
{
  if (_state != currentState->GetStateType())
  {
    currentState->Exit();
    lastState = currentState;
    currentState = stateList.find(_state)->second;
    currentState->Enter();
  }
}

void StateMachine::InitStateMachine(EState  _state)
{
  currentState = stateList.find(_state)->second;
  currentState->Enter();
}

void StateMachine::UpdateState()
{
  currentState->Update();
}

void StateMachine::AddStates(EState _eState,State* _state)
{
  stateList.insert(std::pair<EState, State*>(_eState, _state));
}
