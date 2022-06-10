#pragma once
#include "IDsEntidades.h"
#include "Vector2D.h"
#include "GerenciadorGrafico.h"

namespace Jogo
{
	class Ente
	{
	protected:
		IDsEntidades::IDsEntidades id;
		const char* caminho;
		Vector2F posicao;
	public:
		Ente();
		~Ente();
		virtual void executar(float t) = 0;
		void imprimir(const char* caminho, Vector2F posicao);
	};

}

