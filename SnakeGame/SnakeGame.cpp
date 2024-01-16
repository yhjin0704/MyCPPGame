// SnakeGame.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <ConsoleEngine/EngineCore.h>
#include "Head.h"

int main()
{
    EngineCore EngineCore;
    EngineCore.Init({ 5, 5 });

    {
        // Player* NewObject = new Player();
        Head* NewPlayer = EngineCore.CreateObject<Head>(0);
        NewPlayer->SetPos({ EngineCore.Screen.GetScreenX() / 2, EngineCore.Screen.GetScreenY() - 2 });
    }


    EngineCore.Start();
}
