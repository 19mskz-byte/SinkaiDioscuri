#include "SceneManager.h"
#include "Play/Play.h"
#include "Title/Title.h"
#include "GameClear/GameClear.h"
#include "GameOver/GameOver.h"


Scene g_NowScene = SCENE_PLAY;
Scene g_NextScene = SCENE_PLAY;

SceneState g_SceneState = SCENE_STATE_INIT;

bool g_IsLoopEnd = false;

void SceneInit()
{
	void(*InitScene[])() = { InitTitleScene,InitPlayScene,InitGameClearScene,InitGameOverScene };

	InitScene[g_NowScene]();
}

void SceneStart()
{
	void(*StartScene[])() = { StartTitleScene,StartPlayScene,StartGameClearScene,StartGameOverScene };
	StartScene[g_NowScene]();
}

void SceneLoad()
{
	void(*LoadScene[])() = { LoadTitleScene,LoadPlayScene,LoadGameClearScene,LoadGameOverScene };
	LoadScene[g_NowScene]();
}

void SceneStep()
{
	void(*StepScene[])() = { StepTitleScene,StepPlayScene,StepGameClearScene,StepGameOverScene };
	StepScene[g_NowScene]();
}

void SceneUpdate()
{
	void(*UpdateScene[])() = { UpdateTitleScene,UpdatePlayScene,UpdateGameClearScene,UpdateGameOverScene };
	UpdateScene[g_NowScene]();
}

void SceneDraw()
{
	void(*DrawScene[])() = { DrawTitleScene,DrawPlayScene,DrawGameClearScene,DrawGameOverScene };
	DrawScene[g_NowScene]();
}

void SceneFin()
{
	void(*FinScene[])() = { FinTitleScene,FinPlayScene,FinGameClearScene,FinGameOverScene };
	FinScene[g_NowScene]();
}

void SceneManagerUpdate()
{
	switch (g_SceneState)
	{
	case SCENE_STATE_INIT:
		SceneInit();

		g_SceneState = SCENE_STATE_LOAD;
		break;

	case SCENE_STATE_LOAD:
		SceneLoad();

		g_SceneState = SCENE_STATE_START;
		break;

	case SCENE_STATE_START:
		SceneStart();

		g_IsLoopEnd = false;

		g_SceneState = SCENE_STATE_LOOP;
		break;

	case SCENE_STATE_LOOP:
		SceneStep();
		SceneUpdate();
		SceneDraw();

		if (g_IsLoopEnd)
		{
			g_SceneState = SCENE_STATE_FIN;
		}
		break;

	case SCENE_STATE_FIN:
		SceneFin();

		g_NowScene = g_NextScene;

		g_SceneState = SCENE_STATE_INIT;
		break;
	}
}

void SceneChange(Scene scene)
{
	g_NextScene = scene;

	g_IsLoopEnd = true;
}

