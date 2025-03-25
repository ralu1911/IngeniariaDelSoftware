// IngenieriaDelSortware.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <windows.h> 
#include <WinUser.h>
#define GetKey(X) (!!(GetAsyncKeyState(X) & 0x8000))

#include <iostream>
#include "StateMachine.h"
#include "State.h"

int main()
{
  StateMachine m_stateMachine = StateMachine();
  State Ducking = State(EState::Ducking);
  State Dividing = State(EState::Dividing);
  State Jumping = State(EState::Jumping);
  State Standing = State(EState::Standing);

  m_stateMachine.AddStates(EState::Ducking, &Ducking);
  m_stateMachine.AddStates(EState::Jumping, &Jumping);
  m_stateMachine.AddStates(EState::Standing, &Standing);
  m_stateMachine.AddStates(EState::Dividing, &Dividing);

  m_stateMachine.InitStateMachine(EState::Standing);
  while (!GetKey(VK_ESCAPE)) // Los get Key de abajo deverian de hacerse en una clase hija de state en el update o donde sea, pero el cambio de estado deberia de hacerse en el propio state
  {
    if (GetKey('W'))
    {
      m_stateMachine.ChangeState(EState::Dividing);
    }
    if (GetKey('S'))
    {
      m_stateMachine.ChangeState(EState::Jumping);
    }
    if (GetKey('D'))
    {
      m_stateMachine.ChangeState(EState::Standing);
    }
    if (GetKey('A'))
    {
      m_stateMachine.ChangeState(EState::Ducking);
    }
    Sleep(0.1f);
  }

  printf("hola");
}

// Ejecutar programa: Ctrl + F5 o menú Depurar > Iniciar sin depurar
// Depurar programa: F5 o menú Depurar > Iniciar depuración

// Sugerencias para primeros pasos: 1. Use la ventana del Explorador de soluciones para agregar y administrar archivos
//   2. Use la ventana de Team Explorer para conectar con el control de código fuente
//   3. Use la ventana de salida para ver la salida de compilación y otros mensajes
//   4. Use la ventana Lista de errores para ver los errores
//   5. Vaya a Proyecto > Agregar nuevo elemento para crear nuevos archivos de código, o a Proyecto > Agregar elemento existente para agregar archivos de código existentes al proyecto
//   6. En el futuro, para volver a abrir este proyecto, vaya a Archivo > Abrir > Proyecto y seleccione el archivo .sln
