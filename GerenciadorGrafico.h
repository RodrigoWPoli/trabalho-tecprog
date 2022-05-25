#pragma once
#include "SFML/Graphics.hpp"
#include <map>
#include <iostream>
#include <string>
#include "Vector2D.h"


namespace Game 
{
	class GerenciadorGrafico
	{
	private:
		sf::RenderWindow* janela;
		sf::View camera;
		std::map<const std::string, sf::Texture*> texturas;

	public:
		GerenciadorGrafico();
		~GerenciadorGrafico();
		void mostrar() const;
		void limpar(int r = 0, int g = 0, int b = 0);
		void desenhar(const std::string caminho, const sf::Vector2f pos);
		bool carregar_textura(const std::string caminho);
		void centralizar(const sf::Vector2f centro);
		sf::RenderWindow* get_janela() const { return janela; }
	};

}
