
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef char string[40];

typedef struct tipoDisciplina {
    string nome;
    int cargaHoraria;
    struct tipoDisciplina *prox;
} TDisciplina;

typedef struct tipoHistorico {
    struct tipoDisciplina *disciplina;
    float nota;
    float percentualFrequencia;
    string condicao; // Aprovado, Reprovado ou Cursando
    struct tipoHistorico *prox;
} THistorico;

typedef struct tipoAluno {
    string nome;
    char sexo;
    struct tipoHistorico *historico;
    struct tipoAluno *prox;
} TAluno;

typedef struct tipoCurso {
    string nome;
    struct tipoAluno *alunos;
    struct tipoCurso *ante, *prox;
} TCurso;

typedef struct tipoLista {
    TCurso *inicioC;
    TCurso *fimC;
    TDisciplina *inicioD;
    TDisciplina *fimD;
} TLista;

TLista listas;
//=====================================================================================================
int menu();
//Declarações//
void inicializa(TLista *L);
void dadosPreDefinidos(TLista *L);
void insereDisciplina(TLista *L, const char *nome, int cargaHoraria);
void cadastraDisciplina(TLista *L);
void exibeDisciplinas(TLista *L);
void insereCurso(TLista *L, const char *nome);
void cadastraCurso(TLista *L);
void exibirCursos(TLista *L);
void insereAluno(TLista *L, const char *nomeCurso, const char *nome,  char sexo);
void cadastraAluno(TLista *L);
void exibirAlunos(TLista *L);
void excluirAluno(TLista *L);
void insereHistorico(TLista *L, const char *nomeAluno, const char *nomeDisciplina, float nota, float percentualFrequencia, const char *condicao);
void cadastraHistorico(TLista *L);
void exibirHistorico(TLista *L);
void excluirHistorico(TLista *L);
//================================================================================================================
int main() {
    int opcao;
    inicializa(&listas);
  
    do {
        opcao = menu();

        switch (opcao) {
            case 0:
                printf("Encerrando o programa...\n");
                break;
            case 1: cadastraDisciplina(&listas); break;
            case 2: exibeDisciplinas(&listas); break;
            case 3: cadastraCurso(&listas); break;
            case 4: exibirCursos(&listas); break;
            case 5: cadastraAluno(&listas); break;
            case 6: exibirAlunos(&listas); break;
            case 7: excluirAluno(&listas); break;
            case 8: cadastraHistorico(&listas);break;
            case 9: exibirHistorico(&listas); break;
            case 10: excluirHistorico(&listas); break;
            default:
                printf("Opção inválida. Tente novamente.\n");
        }
    } while (opcao != 0);

    return 0;
}
//======================================================================================================================================
int menu() {
    
    int opcao;
    
    printf("\n\n\t\t====| MENU |=====\n\n");
    printf("\t0 - Sair (Encerrar a Aplicacao).\n\n");
    printf("\t1 - Inserir DISCIPLINA.\n");
    printf("\t2 - Exibir Todas as DISCIPLINAS.\n\n");
    printf("\t3 - Inserir CURSO.\n");
    printf("\t4 - Exibir Todos os CURSOS.\n\n");
    printf("\t5 - Inserir ALUNO em CURSO.\n");
    printf("\t6 - Exibir Todos os ALUNOS de CURSO especifico.\n");
    printf("\t7 - Excluir ALUNO de CURSO.\n\n");
    printf("\t8 - Inserir HISTORICO para ALUNO.\n");
    printf("\t9 - Exibir HISTORICO de ALUNO.\n");
    printf("\t10 - Excluir HISTORICO de ALUNO.\n\n");
    printf("Escolha uma opcao: ");
    scanf("%d", &opcao);
    fflush(stdin);
    getchar();

    return opcao;
}
//===============================================================================================================================================
void inicializa(TLista *L) {
    L->inicioC = NULL;
    L->fimC = NULL;
    L->inicioD = NULL;
    L->fimD = NULL;
    
    insereDisciplina(&listas, "Cálculo 1", 60);
    insereDisciplina(&listas, "Física", 30);
    insereDisciplina(&listas, "Arte", 40);
    insereDisciplina(&listas, "Bioquímica", 50);
    insereDisciplina(&listas, "Química", 30);
    insereDisciplina(&listas, "Marketing", 60);
    insereDisciplina(&listas, "Programação", 60);
    insereDisciplina(&listas, "Redes", 60);
    insereDisciplina(&listas, "Cálculo 2 ", 60);
    insereDisciplina(&listas, "Estrutura de dados", 60);
    
    insereCurso(&listas, "Sistemas de Informação");
    insereCurso(&listas, "Administração");
    insereCurso(&listas, "Engenharia Civil");
    insereCurso(&listas, "Psicologia");
    insereCurso(&listas, "Medicina");
    insereCurso(&listas, "Direito");
    insereCurso(&listas, "Enfermagem");
    insereCurso(&listas, "Gestão de pessoas");
    insereCurso(&listas, "Educação física");
    
    insereAluno(&listas, "Administração", "Alice", 'F');
    insereAluno(&listas, "Sistemas de Informação", "Victor", 'M');
    insereAluno(&listas, "Administração", "Carla", 'F');
    insereAluno(&listas, "Engenharia Civil", "Daniel", 'M');
    insereAluno(&listas, "Psicologia", "Eva", 'F');
    insereAluno(&listas, "Medicina", "Felipe", 'M');
    insereAluno(&listas, "Direito", "Gabriela", 'F');
    insereAluno(&listas, "Sistemas de Informação", "Gabriel", 'M');

    
    
    insereHistorico(&listas, "Victor", "Cálculo 1", 8.5, 80.0, "Aprovado");
    insereHistorico(&listas, "Victor", "Programação", 9.5, 90.0, "Aprovado");
    insereHistorico(&listas, "Victor", "Marketing", 6.5, 40.0, "Cursando");
    insereHistorico(&listas, "Victor", "Redes", 8.5, 80.0, "Aprovado");
    insereHistorico(&listas, "Alice", "Marketing", 7.0, 75.0, "Aprovado");
    insereHistorico(&listas, "Alice", "Marketing", 7.0, 75.0, "Aprovado");

    insereHistorico(&listas, "Carla", "Cálculo 1", 9.0, 85.0, "Aprovado");
    insereHistorico(&listas, "Daniel", "Física", 5.5, 60.0, "Reprovado");
    insereHistorico(&listas, "Eva", "Bioquímica", 7.5, 70.0, "Aprovado");
    insereHistorico(&listas, "Felipe", "Química", 6.5, 75.0, "Aprovado");
    insereHistorico(&listas, "Gabriela", "Arte", 8.0, 80.0, "Aprovado");
    insereHistorico(&listas, "Gabriel", "Redes", 2.0, 40.0, "Reprovado");


  
}
//===========================================================================================================================================
void insereDisciplina(TLista *L, const char *nome, int cargaHoraria) {
    TDisciplina *novo = (TDisciplina*)malloc(sizeof(TDisciplina));

    strcpy(novo->nome, nome);
    novo->cargaHoraria = cargaHoraria;
    novo->prox = NULL;
    // novo->ante = NULL;
    int flag = 0;

    if (L->inicioD == NULL) {
        L->inicioD = novo;
        L->fimD = novo;
    } else {
        TDisciplina *atual = L->inicioD;
        TDisciplina *anterior = NULL;

        while (atual != NULL) {
            if (strcmp(atual->nome, novo->nome) > 0) {
                flag = 1;
                if (atual == L->inicioD) {
                    novo->prox = atual;
                    L->inicioD = novo;
                } else {
                    novo->prox = anterior->prox;
                    anterior->prox = novo;
                }
                break;
            }
            anterior = atual;
            atual = atual->prox;
        }

        if (!flag) {
            L->fimD->prox = novo;
            L->fimD = novo;
        }
    }
}
//============================================================================================================================================
void cadastraDisciplina(TLista *L) {
    string nome;
    int cargaHoraria;

    printf("Digite o nome da disciplina: ");
    fflush(stdin);
    scanf("%[^\n]", nome);
    printf("Digite a carga horária da disciplina: ");
    scanf("%d", &cargaHoraria);

    insereDisciplina(L, nome, cargaHoraria);
    printf("Disciplina inserida com sucesso.\n");
}
//================================================================================================================================================
void exibeDisciplinas(TLista *L) {
    printf("\n=== Lista de Disciplinas ===\n\n");
    TDisciplina *atual = L->inicioD;
    while (atual != NULL) {
        printf("Nome: %s\n", atual->nome);
        printf("Carga Horária: %dHoras\n", atual->cargaHoraria);
        printf("\n");
        atual = atual->prox;
    }
}
//===============================================================================================================================================
void insereCurso(TLista *L, const char *nome) {
    TCurso *novo = (TCurso*)malloc(sizeof(TCurso));

    if (novo == NULL) {
        printf("Erro: memória insuficiente.\n");
        return;
    }

    strcpy(novo->nome, nome); // Copia o nome para a estrutura
    novo->alunos = NULL;
    novo->prox = NULL;

    if (L->inicioC == NULL) {
        L->inicioC = novo;
        L->fimC = novo;
    } else {
        L->fimC->prox = novo;
        L->fimC = novo;
    }

    printf("Curso inserido com sucesso: %s.\n", novo->nome);
}
//=====================================================================================================================================

void cadastraCurso(TLista *L){
    string nome; // Alteração para usar a estrutura de string
    printf("Digite o curso: ");
    fflush(stdin);
    scanf("%39[^\n]", nome); // Especifica o tamanho máximo para evitar estouro do buffer
    insereCurso(L, nome);
}
//==================================================================================================================================
void exibirCursos(TLista* L) {
    printf("\n=== Lista de Cursos ===\n\n");
    TCurso *cursoAtual = L->inicioC;
    int indice = 1;
    while (cursoAtual != NULL) {
        printf("%d - Curso: %s\n", indice, cursoAtual->nome);
        cursoAtual = cursoAtual->prox;
        indice++;
    }
}
//==============================================================================================================================
void insereAluno(TLista *L, const char *nomeCurso, const char *nome, char sexo) { // Alterado o tipo do parâmetro sexo
    TAluno *novoAluno = (TAluno*)malloc(sizeof(TAluno));

    if (novoAluno == NULL) {
        printf("Erro: memória insuficiente.\n");
        return;
    }

    strcpy(novoAluno->nome, nome);
    novoAluno->sexo = sexo; // Alterado para atribuir diretamente o valor do sexo
    novoAluno->historico = NULL;
    novoAluno->prox = NULL;

    int flag = 0;
    TCurso *cursoAtual = L->inicioC;

    while (cursoAtual != NULL) {
        if (strcmp(cursoAtual->nome, nomeCurso) == 0) {
            flag = 1;
            if (cursoAtual->alunos == NULL) {
                cursoAtual->alunos = novoAluno;
            } else {
                TAluno *aux = cursoAtual->alunos;
                while (aux->prox != NULL) {
                    aux = aux->prox;
                }
                aux->prox = novoAluno;
            }

            printf("Aluno inserido com sucesso no curso %s.\n", nomeCurso);
            return;
        }
        cursoAtual = cursoAtual->prox;
    }

    printf("Curso não encontrado.\n");
    free(novoAluno);
}

//=====================================================================================================================================

void cadastraAluno(TLista *L) {
    string nome;
    int escolha;
    char sexo; // Declarado como char
    exibirCursos(&listas);

    printf("Escolha o curso onde deseja inserir o aluno (digite o número correspondente): ");
    scanf("%d", &escolha);
    getchar(); // Limpa o buffer do teclado

    // Encontrar o curso correspondente ao índice escolhido pelo usuário
    TCurso *cursoAtual = L->inicioC;
    int indice = 1;
    while (cursoAtual != NULL && indice != escolha) {
        cursoAtual = cursoAtual->prox;
        indice++;
    }

    // Verificar se o curso foi encontrado
    if (cursoAtual == NULL) {
        printf("Curso não encontrado.\n");
        return;
    }

    printf("Digite o nome do aluno: ");
    fflush(stdin);
    scanf("%[^\n]", nome);
    getchar();
    printf("Digite o sexo do aluno (M/F): ");
    fflush(stdin);
    scanf("%c", &sexo); // Verifique se o sexo está sendo lido corretamente

    // Insere o aluno no curso escolhido
    insereAluno(L, cursoAtual->nome, nome, sexo); // Verifique se o sexo está sendo passado corretamente
}



//===============================================================================================================
void exibirAlunos(TLista *L) {
    printf("\n=== Lista de Cursos ===\n\n");
    // Exibir todos os cursos e seus índices
    TCurso *cursoAtual = L->inicioC;
    int indice = 1;
    while (cursoAtual != NULL) {
        printf("%d - Curso: %s\n", indice, cursoAtual->nome);
        cursoAtual = cursoAtual->prox;
        indice++;
    }

    // Solicitar ao usuário que escolha um curso
    int escolha;
    printf("\nEscolha o curso para visualizar os alunos (digite o número correspondente): ");
    scanf("%d", &escolha);
    getchar();
    // Encontrar o curso correspondente ao índice escolhido pelo usuário
    cursoAtual = L->inicioC;
    indice = 1;
    while (cursoAtual != NULL && indice != escolha) {
        cursoAtual = cursoAtual->prox;
        indice++;
    }

    // Verificar se o curso foi encontrado
    if (cursoAtual == NULL) {
        printf("Curso não encontrado.\n");
        return;
    }

    // Exibir os alunos do curso escolhido
    printf("\n=== Alunos do Curso de %s ===\n\n", cursoAtual->nome);
    if (cursoAtual->alunos == NULL) {
        printf("Nenhum aluno matriculado neste curso.\n");
    } else {
        TAluno *alunoAtual = cursoAtual->alunos;
        while (alunoAtual != NULL) {
            printf("- Nome: %s\n", alunoAtual->nome);
            printf("  Sexo: %c\n", alunoAtual->sexo);

            // Verificar se o aluno possui histórico
            if (alunoAtual->historico == NULL) {
                printf("  Disciplinas: Nenhuma disciplina registrada\n");
            } else {
                printf("  Disciplinas:\n");
                THistorico *historicoAtual = alunoAtual->historico;
                while (historicoAtual != NULL) {
                    printf("    - %s\n", historicoAtual->disciplina->nome);
                    historicoAtual = historicoAtual->prox;
                }
            }
            alunoAtual = alunoAtual->prox;
        }
    }
}

//======================================================================================================================

void excluirAluno(TLista *L) {
    string nomeAluno;
    exibirAlunos(&listas);    
    
    printf("Digite o nome do aluno que deseja excluir: ");
    fflush(stdin);
    scanf("%[^\n]", nomeAluno);
    
    TCurso *cursoAtual = L->inicioC;
    while (cursoAtual != NULL) {
        TAluno *ant = NULL;
        TAluno *alunoAtual = cursoAtual->alunos;
        while (alunoAtual != NULL) {
            if (strcmp(alunoAtual->nome, nomeAluno) == 0) {
                if (ant == NULL) { // se o aluno a ser excluído for o primeiro da lista
                    cursoAtual->alunos = alunoAtual->prox;
                } else {
                    ant->prox = alunoAtual->prox;
                }
                free(alunoAtual);
                printf("Aluno excluído com sucesso.\n");
                return;
            }
            ant = alunoAtual;
            alunoAtual = alunoAtual->prox;
        }
        cursoAtual = cursoAtual->prox;
    }

    printf("Aluno não encontrado.\n");
}
//===================================================================================================================================
void insereHistorico(TLista *L, const char *nomeAluno, const char *nomeDisciplina, float nota, float percentualFrequencia, const char *condicao) {
    TCurso *cursoAtual = L->inicioC;
    while (cursoAtual != NULL) {
        TAluno *alunoAtual = cursoAtual->alunos;
        while (alunoAtual != NULL) {
            if (strcmp(alunoAtual->nome, nomeAluno) == 0) {
                // Alocar memória para o novo histórico
                THistorico *novoHistorico = (THistorico*)malloc(sizeof(THistorico));
                if (novoHistorico == NULL) {
                    printf("Erro ao alocar memória para o histórico.\n");
                    return;
                }

                // Alocar memória para o nome da disciplina e copiá-lo
                novoHistorico->disciplina = (TDisciplina*)malloc(sizeof(TDisciplina));
                if (novoHistorico->disciplina == NULL) {
                    printf("Erro ao alocar memória para o nome da disciplina.\n");
                    free(novoHistorico); // Liberar a memória alocada para o histórico
                    return;
                }
                strcpy(novoHistorico->disciplina->nome, nomeDisciplina);

                // Preencher os campos do novo histórico com os dados passados como parâmetro
                novoHistorico->nota = nota;
                novoHistorico->percentualFrequencia = percentualFrequencia;
                strcpy(novoHistorico->condicao, condicao);
                novoHistorico->prox = NULL;

                // Verificar se o aluno já possui histórico
                if (alunoAtual->historico == NULL) {
                    alunoAtual->historico = novoHistorico;
                } else {
                    // Encontrar o último histórico do aluno e vincular o novo histórico a ele
                    THistorico *aux = alunoAtual->historico;
                    while (aux->prox != NULL) {
                        aux = aux->prox;
                    }
                    aux->prox = novoHistorico;
                }

                printf("Histórico inserido com sucesso para o aluno %s.\n", nomeAluno);
                return;
            }
            alunoAtual = alunoAtual->prox;
        }
        cursoAtual = cursoAtual->prox;
    }

    printf("Aluno não encontrado.\n");
}

void cadastraHistorico(TLista *L){
    
    printf("=== Alunos Cadastrados ===\n");
    exibirAlunos(L);
    
    string nomeAluno;
    printf("Digite o nome do aluno para cadastrar o histórico: ");
    scanf("%s", nomeAluno);
    getchar();
    // Solicitar as informações adicionais para o histórico
    string nomeDisciplina;
    float nota, percentualFrequencia;
    string condicao;
    exibeDisciplinas(L);
    printf("Digite o nome da disciplina: ");
    fflush(stdin);
    scanf("%[^\n]", nomeDisciplina);
    getchar();
    printf("Digite a nota: ");
    scanf("%f", &nota);
    getchar();
    printf("Digite o percentual de frequência: ");
    scanf("%f", &percentualFrequencia);
    getchar();
    printf("Digite a condição (Aprovado/Reprovado/Cursando): ");
    scanf("%s", condicao);
    getchar();
    insereHistorico(L, nomeAluno, nomeDisciplina, nota, percentualFrequencia, condicao);
}

void exibirHistorico(TLista *L) {
    string nomeDisciplina;
    exibeDisciplinas(L);
    printf("Digite o nome da disciplina para exibir o histórico: ");
    fflush(stdin);
    scanf("%[^\n]", nomeDisciplina);
    getchar();
    // Variável para verificar se há pelo menos um aluno com o histórico da disciplina
    int alunoEncontrado = 0;

    TCurso *cursoAtual = L->inicioC;
    while (cursoAtual != NULL) {
        TAluno *alunoAtual = cursoAtual->alunos;
        while (alunoAtual != NULL) {
            THistorico *aux = alunoAtual->historico;
            while (aux != NULL) {
                // Verifica se o aluno possui histórico da disciplina desejada
                if (strcmp(aux->disciplina->nome, nomeDisciplina) == 0) {
                    // Se este é o primeiro aluno encontrado com histórico da disciplina
                    if (!alunoEncontrado) {
                        printf("\n=== Histórico da Disciplina %s ===\n\n", nomeDisciplina);
                        alunoEncontrado = 1;
                    }
                    printf("Aluno: %s\n", alunoAtual->nome);
                    printf("Nota: %.2f\n", aux->nota);
                    printf("Percentual de Frequência: %.2f\n", aux->percentualFrequencia);
                    printf("Condição: %s\n", aux->condicao);
                    printf("\n");
                    break; // Para evitar a repetição do mesmo aluno
                }
                aux = aux->prox;
            }
            alunoAtual = alunoAtual->prox;
        }
        cursoAtual = cursoAtual->prox;
    }

    if (!alunoEncontrado) {
        printf("Nenhum aluno encontrado com histórico da disciplina %s.\n", nomeDisciplina);
    }
}

void excluirHistorico(TLista *L) {
    string nomeAluno;
    exibirAlunos(L);
    printf("Digite o nome do aluno para excluir o histórico: ");
    fflush(stdin);
    scanf("%[^\n]", nomeAluno);
    getchar();
    // Solicitar o nome da disciplina a ser excluída
    string nomeDisciplina;
    printf("Digite o nome da disciplina para excluir o histórico: ");
    fflush(stdin);
    scanf("%[^\n]", nomeDisciplina);
    getchar();
    TCurso *cursoAtual = L->inicioC;
    while (cursoAtual != NULL) {
        TAluno *alunoAtual = cursoAtual->alunos;
        while (alunoAtual != NULL) {
            if (strcmp(alunoAtual->nome, nomeAluno) == 0) {
                THistorico *atual = alunoAtual->historico;
                THistorico *anterior = NULL;

                while (atual != NULL) {
                    // Verifica se é a disciplina desejada
                    if (strcmp(atual->disciplina->nome, nomeDisciplina) == 0) {
                        // Remove o histórico da disciplina desejada
                        if (anterior == NULL) {
                            alunoAtual->historico = atual->prox;
                        } else {
                            anterior->prox = atual->prox;
                        }
                        free(atual);
                        printf("Histórico da disciplina %s do aluno %s excluído com sucesso.\n", nomeDisciplina, nomeAluno);
                        return;
                    }
                    anterior = atual;
                    atual = atual->prox;
                }

                // Se chegou aqui, significa que a disciplina não foi encontrada no histórico do aluno
                printf("O aluno %s não possui histórico da disciplina %s.\n", nomeAluno, nomeDisciplina);
                return;
            }
            alunoAtual = alunoAtual->prox;
        }
        cursoAtual = cursoAtual->prox;
    }

    printf("Aluno não encontrado.\n");
}


//====================================================================================================================================







