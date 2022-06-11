#include "Fase.h"
#include "stdafx.h"
using namespace std;

namespace Jogo
{
	namespace Fases
	{
		bool Fase::pausado{ false };

		Fase::Fase() :
			gc(&entidades_moveis, &entidades_estaticas),
			vidaui(nullptr),
			pontuacaoui(new PontuacaoUI())
		{
			musica();
		}

		Fase::~Fase()
		{
			entidades_moveis.destruir();
			entidades_estaticas.destruir();
			if (vidaui)
			{
				delete vidaui;
				vidaui = nullptr;

			}
			if (pontuacaoui)
			{
				delete pontuacaoui;
				pontuacaoui = nullptr;
			}
		}
		void Fase::musica()
		{
			
			if (!music.openFromFile("assets/SuperMarioBros.ogg"))
				return;// error
			music.play();
			music.setVolume(4);
		}

		void Fase::carregar_fundo() const
		{
		}

		void Fase::randomizar_inimigos()
		{
			vector<int> inimigos;
			SYSTEMTIME st;
			GetSystemTime(&st);
			srand(st.wSecond);
			int aux = 0;
			int qtd = rand() % 3 + 3;
			while (aux < 3) {
				inimigos.clear();
				aux = 0;
				for (int i = 0; i < qtd; i++)
				{
					inimigos.push_back(rand() % 2 == 1 ? 0 : 1);
				}
				for (int i = 0; i < qtd; i++)
				{
					aux += inimigos[i];
				}
			}
			if (inimigos[0])
			{
				Entidades::Personagens::Goomba* e = new Entidades::Personagens::Goomba(Vector2F(500, 700.0f), Vector2F(0.0f, 0.0f), "assets/goomba.png");
				e->set_lista(entidades_moveis);
				e = nullptr;
			}
			if (inimigos[1])
			{
				Entidades::Personagens::Goomba* e = new Entidades::Personagens::Goomba(Vector2F(700, 700.0f), Vector2F(0.0f, 0.0f), "assets/goomba.png");
				e->set_lista(entidades_moveis);
				e = nullptr;
			}
			if (inimigos[2])
			{
				Entidades::Personagens::Goomba* e = new Entidades::Personagens::Goomba(Vector2F(900, 700.0f), Vector2F(0.0f, 0.0f), "assets/goomba.png");
				e->set_lista(entidades_moveis);
				e = nullptr;
			}
			if (qtd == 4)
			{
				if (inimigos[3])
				{
					Entidades::Personagens::Goomba* e = new Entidades::Personagens::Goomba(Vector2F(1200, 700.0f), Vector2F(0.0f, 0.0f), "assets/goomba.png");
					e->set_lista(entidades_moveis);
					e = nullptr;
				}
			}
			if (qtd == 5)
			{
				if (inimigos[4])
				{
					Entidades::Personagens::Goomba* e = new Entidades::Personagens::Goomba(Vector2F(1500, 700.0f), Vector2F(0.0f, 0.0f), "assets/goomba.png");
					e->set_lista(entidades_moveis);
					e = nullptr;
				}
			}

			Entidades::Personagens::NuvemMal* n = new Entidades::Personagens::NuvemMal(Vector2F(1000, 65.0f), Vector2F(0.0f, 0.0f), "assets/nuvem_malvada.png", static_cast<Fase*> (this));
			n->set_lista(entidades_moveis);
			n = nullptr;
		}

		void Fase::inserir_jogador(Entidades::Personagens::Jogador* j)
		{
			entidades_moveis.inserir(j);
			vidaui = new VidaUI(j);
		}

		void Fase::inicializar_entidades()
		{
			randomizar_inimigos();
			entidades_moveis.inicializar_entidades();
			entidades_estaticas.inicializar_entidades();
		}

		void Fase::reiniciar_entidades(Vector2F pos_jogador)
		{
			entidades_moveis.destruir();
			entidades_estaticas.destruir();
			inicializar_entidades();
		}


		void Fase::executar(float t)
		{
			entidades_moveis.percorrer_executar(t);
			entidades_estaticas.percorrer_executar(t);
			gerenciar_colisoes();
			vidaui->executar();
			pontuacaoui->executar();
		}

		void Fase::gerenciar_colisoes()
		{
			gc.verificar_colisoes();
		}
		void Fase::add_projetil(Entidades::Projetil* proj)
		{
			if (proj)
			{

				proj->set_lista(entidades_moveis);
				proj->inicializar();
			}
		}
	}
}
