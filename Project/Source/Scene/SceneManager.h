#pragma once

enum SceneState {
	SCENE_STATE_INIT,
	SCENE_STATE_LOAD,
	SCENE_STATE_START,
	SCENE_STATE_LOOP,
	SCENE_STATE_FIN,
};

enum Scene {
	SCENE_TITLE,
	SCENE_PLAY,
	SCENE_GAME_CLEAR,
	SCENE_GAME_OVER,
};

void SceneInit();
void SceneStart();
void SceneLoad();
void SceneStep();
void SceneUpdate();
void SceneDraw();
void SceneFin();

void SceneManagerUpdate();

void SceneChange(Scene scene);