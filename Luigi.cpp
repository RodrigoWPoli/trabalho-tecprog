#include "Luigi.h"
#include "Fase.h"

namespace Jogo
{
	namespace Entidades
	{
		namespace Personagens
		{
			Luigi::Luigi(Vector2F pos ):
				Jogador(pos, "assets/luigi.png", "assets/luigi_e.png")
			{

			}
			Luigi::~Luigi()
			{
			}
			void Luigi::tratar_eventos()
			{
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
				{
					andar(false);//anda com falso para esquerda
				}
				else if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
				{
					andar(true);
				}
				
				else
				{
					andando = false;
				}
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
				{
					pular();
				}
			}
		}
	}
}