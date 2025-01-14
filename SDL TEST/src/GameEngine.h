#pragma once
#include "Core.h"
#include "GameObject.h"
#include <vector>
#include <iostream>

class GameObject;

class GameEngine
{
public:
	GameEngine(unsigned int width = 1120, unsigned int height = 630, unsigned int maxFPS = 60);
	~GameEngine();
	void Run();
	void AddGameObject(GameObject* go);	
	/*setters and getters*/
	inline unsigned int GetWidth() const { return m_ScreenWidth; }
	inline unsigned int GetHeight() const { return m_ScreenHeight; }
	inline unsigned int GetMaxFPS() const { return m_MaxFPS; }
	inline void SetMaxFPS(unsigned int maxFPS) { m_MaxFPS = maxFPS; }
	inline SDL_Renderer* GetRenderer() { return m_Renderer; }
	inline unsigned int GetScreenWidth() const { return m_ScreenWidth; }
	inline unsigned int GetScreenHeight() const { return m_ScreenHeight; }
private:
	std::vector<GameObject*>		m_GameObjects;
	/*window*/
	const unsigned int				m_ScreenWidth;
	const unsigned int				m_ScreenHeight;
	SDL_Window*						m_Window;
	SDL_Renderer*					m_Renderer;
	/*input*/
	SDL_Event						m_GameEvent;
	/*FPS*/
	unsigned int					m_MaxFPS;
	/*game variables*/
	bool							m_GameRunning;
	double							m_DeltaTime;
	/*private functions*/
	bool InitWindow();
	void Init();
	void HandleEvents();
	void UpdateMechanics();
	void Render();
};

