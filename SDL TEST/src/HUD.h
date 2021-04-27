#pragma once
#include "GameObject.h"
#include "Vector2.h"
#include "Texture.h"
#include <iostream>
#include "SDL_ttf.h"

class HUD : public GameObject
{
private:

      SDL_Renderer*	m_Renderer;
	    Texture	m_Texture;
      SDL_Texture* mScore;
      SDL_Rect text;

public:
	    int	x_Position;
	    int y_Position;
	    int	m_Width;
	    int	m_Height;
	    int lives;
      int score;

	    HUD();
	    HUD(int life);
	    ~HUD();

      int getLives();
      int getScore();
	    void Init(GameEngine* ge) override;
	    void Render() override;
	    void LostLife();
      void AddScore(int scoreIncrease);
};
