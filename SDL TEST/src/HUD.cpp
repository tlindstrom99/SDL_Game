#include "HUD.h"

HUD::HUD(){
	x_Position = 0;
	y_Position = 0;
	m_Width = 50;
	m_Height = 50;
	lives = 3;
}

HUD::HUD(int life){
	x_Position = 0;
	y_Position = 0;
	m_Width = 50;
	m_Height = 50;
	if (life <= 5)
		lives = life;
	else
		lives = 5;
}


HUD::~HUD(){}


void HUD::Init(GameEngine * ge){
	m_Renderer = ge->GetRenderer();
	std::string path = "res/img/lives.png";
	m_Texture.LoadTexture(path, m_Renderer, { x_Position, y_Position, m_Width, m_Height });
	const char* ttf_file = "./res/scoreFont.ttf";
	TTF_Font *font = TTF_OpenFont(ttf_file, 20);
	char *t;
	std::sprintf(t, "%d", score);
	SDL_Surface *text_surface = TTF_RenderText_Solid(font, t, {0, 0, 0});
	mScore = SDL_CreateTextureFromSurface(m_Renderer, text_surface);
	SDL_FreeSurface(text_surface);
}


void HUD::Render(){

	for (int i = 0; i < lives; i++){
		m_Texture.SetRect({ x_Position + (i * m_Width), y_Position, m_Width, m_Height });
		SDL_RenderCopy(m_Renderer, m_Texture.GetTexture(), NULL, m_Texture.GetRect());
	}
	text.x = 1050;
	text.y = 0;
	int w = 64;
	int h = 20;
	SDL_QueryTexture(mScore, NULL, NULL, &w, &h);
	text.w = 64;
	text.h = 20;
	SDL_RenderCopy(m_Renderer, mScore, nullptr, &text);
}

void HUD::LostLife(){
	if (lives > 0)
		lives--;
}

int HUD::getLives(){
	return lives;
}

void HUD::AddScore(int scoreIncrease){
	score += scoreIncrease;
}

int HUD::getScore(){
	return score;
}
