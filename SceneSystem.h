#pragma once
#include "Scene.h"

#include <vector>
#include <iostream>
using namespace std;

class SceneSystem
{
public:
	static void openScene(Scene scene);
	static void closeScene(Scene scene);
	static void pauseScene();
	static void changeScene(Scene scene);

private:
	static vector<Scene> SceneList;
};

