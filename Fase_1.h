#pragma once
#include "Fase.h"
#include "Fogo.h"
#include "Gosma.h"
#include "Pedra.h"
namespace Jogo
{
	namespace Fases
	{
		class Fase_1 :
			public Fase
		{
		private:
			Entidades::Obstaculos::Obstaculo* o1;
			Entidades::Obstaculos::Obstaculo* o2;
			Entidades::Obstaculos::Obstaculo* o3;
			Entidades::Obstaculos::Obstaculo* o4;
			Entidades::Obstaculos::Obstaculo* o5;
			Entidades::Obstaculos::Obstaculo* o6;
			Entidades::Obstaculos::Obstaculo* o7;
			Entidades::Obstaculos::Obstaculo* o8;
			Entidades::Obstaculos::Obstaculo* o9;
			Entidades::Obstaculos::Obstaculo* o10;
			Entidades::Obstaculos::Obstaculo* o11;
			Entidades::Obstaculos::Obstaculo* o12;
			Entidades::Obstaculos::Obstaculo* o13;
			Entidades::Obstaculos::Obstaculo* o14;
			Entidades::Obstaculos::Fogo* fogo;
			Entidades::Obstaculos::Fogo* fogo1;
			Entidades::Obstaculos::Fogo* fogo2;
			Entidades::Obstaculos::Pedra* pedra;
			Entidades::Obstaculos::Pedra* pedra2;
			Entidades::Obstaculos::Obstaculo* chefao;
			Entidades::Obstaculos::Gosma* gosma1;
			Entidades::Obstaculos::Obstaculo* bandeira;

			const char* fundo_fase_1;
		public:
			Fase_1();
			~Fase_1();

			void inicializar_entidades();
			void carregar_fundo() const;
		};
	}
}
