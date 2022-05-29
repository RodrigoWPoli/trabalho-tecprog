#include "Entidade.h"
#include <iostream>


namespace Game
{

	Entidade::Entidade(Vector2F pos, Vector2F vel, const char* caminho_textura) :
		position(pos),
		v(vel),
		caminho(caminho_textura),
		vivo(vivo)
	{
	}

	Entidade::~Entidade()
	{
	}

	void Entidade::inicializar(GerenciadorGrafico& g)
	{
		g.carregar_textura(caminho);
	}

	void Entidade::atualizar(float t)
	{
		position += v * t;
	}

	void Entidade::desenhar(GerenciadorGrafico &g)
	{
		g.desenhar(caminho, position);
	}
	void Entidade::gravidade()
	{
			if (vivo){ v.y += 0.005f; }
			else{ v.y = 0; }
			if (v.y > 0.2f) { v.y = 0.2f; }
	}
}
