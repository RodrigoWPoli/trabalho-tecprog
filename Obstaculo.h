#pragma once
#include "Entidade.h"

namespace Jogo
{
    namespace Entidades
    {
        namespace Obstaculos
        {
            class Obstaculo :
                public Entidade
            {
            private:
            public:
                Obstaculo(IDsEntidades::IDsEntidades id = IDsEntidades::obstaculo, Vector2F pos = Vector2F(0.0f, 0.0f), const char* caminho_textura = nullptr);
                ~Obstaculo();
                void executar(float t);
                virtual void colidir(Entidade* ente, Vector2F intersse);
                void inicializar();
                virtual void atualizar(float t);
                virtual void desenhar();

            };

        }
    }
}


