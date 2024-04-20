
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
//Declara��es//
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
                printf("Op��o inv�lida. Tente novamente.\n");
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
    
    insereDisciplina(&listas, "C�lculo 1", 60);
    insereDisciplina(&listas, "F�sica", 30);
    insereDisciplina(&listas, "Arte", 40);
    insereDisciplina(&listas, "Bioqu�mica", 50);
    insereDisciplina(&listas, "Qu�mica", 30);
    insereDisciplina(&listas, "Marketing", 60);
    insereDisciplina(&listas, "Programa��o", 60);
    insereDisciplina(&listas, "Redes", 60);
    insereDisciplina(&listas, "C�lculo 2 ", 60);
    insereDisciplina(&listas, "Estrutura de dados", 60);
    
    insereCurso(&listas, "Sistemas de Informa��o");
    insereCurso(&listas, "Administra��o");
    insereCurso(&listas, "Engenharia Civil");
    insereCurso(&listas, "Psicologia");
    insereCurso(&listas, "Medicina");
    insereCurso(&listas, "Direito");
    insereCurso(&listas, "Enfermagem");
    insereCurso(&listas, "Gest�o de pessoas");
    insereCurso(&listas, "Educa��o f�sica");
    
    insereAluno(&listas, "Administra��o", "Alice", 'F');
    insereAluno(&listas, "Sistemas de Informa��o", "Victor", 'M');
    insereAluno(&listas, "Administra��o", "Carla", 'F');
    insereAluno(&listas, "Engenharia Civil", "Daniel", 'M');
    insereAluno(&listas, "Psicologia", "Eva", 'F');
    insereAluno(&listas, "Medicina", "Felipe", 'M');
    insereAluno(&listas, "Direito", "Gabriela", 'F');
    insereAluno(&listas, "Sistemas de Informa��o", "Gabriel", 'M');

    
    
    insereHistorico(&listas, "Victor", "C�lculo 1", 8.5, 80.0, "Aprovado");
    insereHistorico(&listas, "Victor", "Programa��o", 9.5, 90.0, "Aprovado");
    insereHistorico(&listas, "Victor", "Marketing", 6.5, 40.0, "Cursando");
    insereHistorico(&listas, "Victor", "Redes", 8.5, 80.0, "Aprovado");
    insereHistorico(&listas, "Alice", "Marketing", 7.0, 75.0, "Aprovado");
    insereHistorico(&listas, "Alice", "Marketing", 7.0, 75.0, "Aprovado");

    insereHistorico(&listas, "Carla", "C�lculo 1", 9.0, 85.0, "Aprovado");
    insereHistorico(&listas, "Daniel", "F�sica", 5.5, 60.0, "Reprovado");
    insereHistorico(&listas, "Eva", "Bioqu�mica", 7.5, 70.0, "Aprovado");
    insereHistorico(&listas, "Felipe", "Qu�mica", 6.5, 75.0, "Aprovado");
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
    printf("Digite a carga hor�ria da disciplina: ");
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
        printf("Carga Hor�ria: %dHoras\n", atual->cargaHoraria);
        printf("\n");
        atual = atual->prox;
    }
}
//===============================================================================================================================================
void insereCurso(TLista *L, const char *nome) {
    TCurso *novo = (TCurso*)malloc(sizeof(TCurso));

    if (novo == NULL) {
        printf("Erro: mem�ria insuficiente.\n");
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
    string nome; // Altera��o para usar a estrutura de string
    printf("Digite o curso: ");
    fflush(stdin);
    scanf("%39[^\n]", nome); // Especifica o tamanho m�ximo para evitar estouro do buffer
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
void insereAluno(TLista *L, const char *nomeCurso, const char *nome, char sexo) { // Alterado o tipo do par�metro sexo
    TAluno *novoAluno = (TAluno*)malloc(sizeof(TAluno));

    if (novoAluno == NULL) {
        printf("Erro: mem�ria insuficiente.\n");
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

    printf("Curso n�o encontrado.\n");
    free(novoAluno);
}

//=====================================================================================================================================

void cadastraAluno(TLista *L) {
    string nome;
    int escolha;
    char sexo; // Declarado como char
    exibirCursos(&listas);

    printf("Escolha o curso onde deseja inserir o aluno (digite o n�mero correspondente): ");
    scanf("%d", &escolha);
    getchar(); // Limpa o buffer do teclado

    // Encontrar o curso correspondente ao �ndice escolhido pelo usu�rio
    TCurso *cursoAtual = L->inicioC;
    int indice = 1;
    while (cursoAtual != NULL && indice != escolha) {
        cursoAtual = cursoAtual->prox;
        indice++;
    }

    // Verificar se o curso foi encontrado
    if (cursoAtual == NULL) {
        printf("Curso n�o encontrado.\n");
        return;
    }

    printf("Digite o nome do aluno: ");
    fflush(stdin);
    scanf("%[^\n]", nome);
    getchar();
    printf("Digite o sexo do aluno (M/F): ");
    fflush(stdin);
    scanf("%c", &sexo); // Verifique se o sexo est� sendo lido corretamente

    // Insere o aluno no curso escolhido
    insereAluno(L, cursoAtual->nome, nome, sexo); // Verifique se o sexo est� sendo passado corretamente
}



//===============================================================================================================
void exibirAlunos(TLista *L) {
    printf("\n=== Lista de Cursos ===\n\n");
    // Exibir todos os cursos e seus �ndices
    TCurso *cursoAtual = L->inicioC;
    int indice = 1;
    while (cursoAtual != NULL) {
        printf("%d - Curso: %s\n", indice, cursoAtual->nome);
        cursoAtual = cursoAtual->prox;
        indice++;
    }

    // Solicitar ao usu�rio que escolha um curso
    int escolha;
    printf("\nEscolha o curso para visualizar os alunos (digite o n�mero correspondente): ");
    scanf("%d", &escolha);
    getchar();
    // Encontrar o curso correspondente ao �ndice escolhido pelo usu�rio
    cursoAtual = L->inicioC;
    indice = 1;
    while (cursoAtual != NULL && indice != escolha) {
        cursoAtual = cursoAtual->prox;
        indice++;
    }

    // Verificar se o curso foi encontrado
    if (cursoAtual == NULL) {
        printf("Curso n�o encontrado.\n");
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

            // Verificar se o aluno possui hist�rico
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
                if (ant == NULL) { // se o aluno a ser exclu�do for o primeiro da lista
                    cursoAtual->alunos = alunoAtual->prox;
                } else {
                    ant->prox = alunoAtual->prox;
                }
                free(alunoAtual);
                printf("Aluno exclu�do com sucesso.\n");
                return;
            }
            ant = alunoAtual;
            alunoAtual = alunoAtual->prox;
        }
        cursoAtual = cursoAtual->prox;
    }

    printf("Aluno n�o encontrado.\n");
}
//===================================================================================================================================
void insereHistorico(TLista *L, const char *nomeAluno, const char *nomeDisciplina, float nota, float percentualFrequencia, const char *condicao) {
    TCurso *cursoAtual = L->inicioC;
    while (cursoAtual != NULL) {
        TAluno *alunoAtual = cursoAtual->alunos;
        while (alunoAtual != NULL) {
            if (strcmp(alunoAtual->nome, nomeAluno) == 0) {
                // Alocar mem�ria para o novo hist�rico
                THistorico *novoHistorico = (THistorico*)malloc(sizeof(THistorico));
                if (novoHistorico == NULL) {
                    printf("Erro ao alocar mem�ria para o hist�rico.\n");
                    return;
                }

                // Alocar mem�ria para o nome da disciplina e copi�-lo
                novoHistorico->disciplina = (TDisciplina*)malloc(sizeof(TDisciplina));
                if (novoHistorico->disciplina == NULL) {
                    printf("Erro ao alocar mem�ria para o nome da disciplina.\n");
                    free(novoHistorico); // Liberar a mem�ria alocada para o hist�rico
                    return;
                }
                strcpy(novoHistorico->disciplina->nome, nomeDisciplina);

                // Preencher os campos do novo hist�rico com os dados passados como par�metro
                novoHistorico->nota = nota;
                novoHistorico->percentualFrequencia = percentualFrequencia;
                strcpy(novoHistorico->condicao, condicao);
                novoHistorico->prox = NULL;

                // Verificar se o aluno j� possui hist�rico
                if (alunoAtual->historico == NULL) {
                    alunoAtual->historico = novoHistorico;
                } else {
                    // Encontrar o �ltimo hist�rico do aluno e vincular o novo hist�rico a ele
                    THistorico *aux = alunoAtual->historico;
                    while (aux->prox != NULL) {
                        aux = aux->prox;
                    }
                    aux->prox = novoHistorico;
                }

                printf("Hist�rico inserido com sucesso para o aluno %s.\n", nomeAluno);
                return;
            }
            alunoAtual = alunoAtual->prox;
        }
        cursoAtual = cursoAtual->prox;
    }

    printf("Aluno n�o encontrado.\n");
}

void cadastraHistorico(TLista *L){
    
    printf("=== Alunos Cadastrados ===\n");
    exibirAlunos(L);
    
    string nomeAluno;
    printf("Digite o nome do aluno para cadastrar o hist�rico: ");
    scanf("%s", nomeAluno);
    getchar();
    // Solicitar as informa��es adicionais para o hist�rico
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
    printf("Digite o percentual de frequ�ncia: ");
    scanf("%f", &percentualFrequencia);
    getchar();
    printf("Digite a condi��o (Aprovado/Reprovado/Cursando): ");
    scanf("%s", condicao);
    getchar();
    insereHistorico(L, nomeAluno, nomeDisciplina, nota, percentualFrequencia, condicao);
}

void exibirHistorico(TLista *L) {
    string nomeDisciplina;
    exibeDisciplinas(L);
    printf("Digite o nome da disciplina para exibir o hist�rico: ");
    fflush(stdin);
    scanf("%[^\n]", nomeDisciplina);
    getchar();
    // Vari�vel para verificar se h� pelo menos um aluno com o hist�rico da disciplina
    int alunoEncontrado = 0;

    TCurso *cursoAtual = L->inicioC;
    while (cursoAtual != NULL) {
        TAluno *alunoAtual = cursoAtual->alunos;
        while (alunoAtual != NULL) {
            THistorico *aux = alunoAtual->historico;
            while (aux != NULL) {
                // Verifica se o aluno possui hist�rico da disciplina desejada
                if (strcmp(aux->disciplina->nome, nomeDisciplina) == 0) {
                    // Se este � o primeiro aluno encontrado com hist�rico da disciplina
                    if (!alunoEncontrado) {
                        printf("\n=== Hist�rico da Disciplina %s ===\n\n", nomeDisciplina);
                        alunoEncontrado = 1;
                    }
                    printf("Aluno: %s\n", alunoAtual->nome);
                    printf("Nota: %.2f\n", aux->nota);
                    printf("Percentual de Frequ�ncia: %.2f\n", aux->percentualFrequencia);
                    printf("Condi��o: %s\n", aux->condicao);
                    printf("\n");
                    break; // Para evitar a repeti��o do mesmo aluno
                }
                aux = aux->prox;
            }
            alunoAtual = alunoAtual->prox;
        }
        cursoAtual = cursoAtual->prox;
    }

    if (!alunoEncontrado) {
        printf("Nenhum aluno encontrado com hist�rico da disciplina %s.\n", nomeDisciplina);
    }
}

void excluirHistorico(TLista *L) {
    string nomeAluno;
    exibirAlunos(L);
    printf("Digite o nome do aluno para excluir o hist�rico: ");
    fflush(stdin);
    scanf("%[^\n]", nomeAluno);
    getchar();
    // Solicitar o nome da disciplina a ser exclu�da
    string nomeDisciplina;
    printf("Digite o nome da disciplina para excluir o hist�rico: ");
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
                    // Verifica se � a disciplina desejada
                    if (strcmp(atual->disciplina->nome, nomeDisciplina) == 0) {
                        // Remove o hist�rico da disciplina desejada
                        if (anterior == NULL) {
                            alunoAtual->historico = atual->prox;
                        } else {
                            anterior->prox = atual->prox;
                        }
                        free(atual);
                        printf("Hist�rico da disciplina %s do aluno %s exclu�do com sucesso.\n", nomeDisciplina, nomeAluno);
                        return;
                    }
                    anterior = atual;
                    atual = atual->prox;
                }

                // Se chegou aqui, significa que a disciplina n�o foi encontrada no hist�rico do aluno
                printf("O aluno %s n�o possui hist�rico da disciplina %s.\n", nomeAluno, nomeDisciplina);
                return;
            }
            alunoAtual = alunoAtual->prox;
        }
        cursoAtual = cursoAtual->prox;
    }

    printf("Aluno n�o encontrado.\n");
}


//====================================================================================================================================







