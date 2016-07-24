#include <stdio.h>
#include <stdlib.h>
#include <string.h>
 
/* WIP */
typedef struct aluno{
    int mat;
    float cr;
    char nome[31];
}TAluno;
 
typedef struct avp{
    TAluno* alunoNo;
    char cor;
    struct avp *pai, *esq, *dir;
}TAVP;
 
//metodos pedidas pela prof
void modifica_cr(TAluno *aluno, float novoCr);//testado
void modifica_nome(TAluno *aluno, char *novoNome);//testado
void modifica_mat(TAluno *aluno,TAVP *arvore, int novoMat);//retira o aluno e insere de novo //testado
TAVP* insereAluno(TAVP *arvore, int matricula, float cr, char *nome);//testado
TAVP* removeAluno(TAVP *aluno, TAVP *arvore);
void imprimeArvore(TAVP *arvore); //testado
void imprimeAluno(TAluno *aluno); //testado
void destroiArvore(TAVP *arvore);
//-------------------------------
TAluno* inicializaTAluno(int mat, float cr, char *nome);//testado
TAVP* inicializaTAVP(void); //testado
TAVP* busca(TAVP *arvore, int matricula); //testado
TAVP* corrigeInsere(TAVP *arvore, TAVP *no);
TAVP* RSD(TAVP* raiz,TAVP* pai);
TAVP* RSE(TAVP* raiz,TAVP* pai);
TAVP* obtemPai(TAVP* no);
TAVP* obtemIrmao(TAVP* no);
void troca(TAVP* no,TAVP* filho);
void liberacaoRemocao(TAVP* filho);
TAVP* buscaRaiz(TAVP* arvore);
void imprime_debug_AVP(TAVP *a);
void delete_case1(TAVP *n , TAVP *arvore);
void delete_case2(TAVP *n , TAVP *arvore);
void delete_case3(TAVP *n , TAVP *arvore);
void delete_case4(TAVP *n , TAVP *arvore);
void delete_case5(TAVP *n , TAVP *arvore);
void delete_case6(TAVP *n , TAVP *arvore);
TAVP* pretoPreto(TAVP *arvore, TAVP *no);
TAVP* vermelhoPreto(TAVP* arvore,TAVP* n);
TAVP* remocaoFolha(TAVP*n,TAVP*arvore);
 
int main(int argc, char *argv[]) {
	
	TAVP *malfurion = inicializaTAVP();
    imprimeArvore(malfurion);
    printf("\n");
    malfurion = insereAluno(malfurion, 26,10,"raffael"); 
    imprimeArvore(malfurion);
    printf("\n");
    malfurion = insereAluno(malfurion, 17,10,"raffael");
    imprimeArvore(malfurion);
    printf("\n");
    malfurion = insereAluno(malfurion, 14,10,"raffael");
    imprimeArvore(malfurion);
    printf("\n");
    malfurion = insereAluno(malfurion, 10,10,"raffael");//nao
    imprimeArvore(malfurion);
    printf("\n");
    malfurion = insereAluno(malfurion, 7,10,"raffael");
    imprimeArvore(malfurion);
    printf("\n");
    malfurion = insereAluno(malfurion, 3,10,"raffael");
    imprimeArvore(malfurion);
    printf("\n");
    malfurion = insereAluno(malfurion, 11,10,"raffael");
    imprimeArvore(malfurion);
    printf("\n");
    malfurion = insereAluno(malfurion, 16,10,"raffael");
    imprimeArvore(malfurion);
    printf("\n");
    malfurion = insereAluno(malfurion, 15,10,"raffael");
    imprimeArvore(malfurion);
    printf("\n");
    malfurion = insereAluno(malfurion, 21,10,"raffael");
    imprimeArvore(malfurion);
    printf("\n");
    malfurion = insereAluno(malfurion, 23,10,"raffael");//nao // problema da folha
    imprimeArvore(malfurion);
    printf("\n");
    malfurion = insereAluno(malfurion, 25,10,"raffael");
    imprimeArvore(malfurion);
    printf("\n");
    malfurion = insereAluno(malfurion, 2,10,"raffael");
    imprimeArvore(malfurion);
    printf("\n");
    malfurion = insereAluno(malfurion, 1,10,"raffael");
    imprimeArvore(malfurion);
    printf("\n");
    malfurion = insereAluno(malfurion, 12,10,"raffael");
    imprimeArvore(malfurion);
    printf("\n");
    malfurion = insereAluno(malfurion, 13,10,"raffael");
    imprimeArvore(malfurion);
    printf("\n");
    printf("\n");
    imprimeArvore(malfurion);
    printf("\n");
    TAVP* removido = busca(malfurion,1);
    malfurion = removeAluno(removido, malfurion);
    removido = busca(malfurion,12);
    malfurion = removeAluno(removido, malfurion);
    removido = busca(malfurion,13);
    malfurion = removeAluno(removido, malfurion);
    imprime_debug_AVP(malfurion);
	/*
	TAVP *malfurion = inicializaTAVP();

  	int num = 0,numAux, matricula, matriculaNova;
  	char nomeNovo[31];
  	float crNovo;
  	while(num != -1){
	    printf("Digite (1) para adicionar um aluno. (2) para imprimir. (3) para remover, (4) para buscar um aluno e (5) para sair:\n");
	    scanf("%i", &num);
	    if(num == 3){
	    	printf("Modo de remocao\n Digite a matricula:\n");
	    	scanf("%d", &matricula);
	    	TAVP *aluno = busca(malfurion,matricula);
			removeAluno(aluno,malfurion);
	    }
	    else if(num == 5){
		    printf("\n");
		    imprimeArvore(malfurion);
	    	destroiArvore(malfurion);
    		return 0;
	    }
    	else if(num == 2){
			printf("\n");
			imprimeArvore(malfurion);
	    }
    	else if(num == 1){
    		float cr;
    		char nome[31];
    		printf("Modo de insercao\nDigite a matricula, o CR e o nome: \n");
	    	scanf("%i", &matricula);
	    	scanf("%f", &cr);
	    	scanf("%s", &nome);
			malfurion = insereAluno(malfurion,matricula,cr,nome);
		}
		else if(num == 4){
			while(1){
				printf("Modo de Busca de Alunos\nEscolha uma operaÃ§ao:\n(1) Imprimir aluno, (2) Modificar matricula do aluno,(3) Modificar CR do aluno,(4) Modificar nome do aluno,(5) Sair\n");
				scanf("%i", &numAux);
				if(numAux==5) break;
				if(numAux>5){
					printf("Operacao nao existe\n");
					continue;	
				} 
				printf("Matricula do aluno:\n");
				scanf("%i",&matricula);
				TAVP *aluno = busca(malfurion,matricula);
				if(aluno){	
					if(numAux == 1){
						imprimeAluno(aluno->alunoNo);
					}
					else if(numAux == 2){
						printf("Digite a nova matricula do aluno:\n");
						scanf("%i",&matriculaNova);
						modifica_mat(aluno->alunoNo,malfurion,matriculaNova);
					}
					else if(numAux == 3){
						printf("Digite o novo CR do aluno:\n");
						scanf("%f",&crNovo);
						modifica_cr(aluno->alunoNo,crNovo);
					}
					else if(numAux == 4){
						printf("Digite o novo nome do aluno:\n");
						scanf("%s",&nomeNovo);
						modifica_nome(aluno->alunoNo,nomeNovo);
					}
				}
				else{
					printf("Aluno nao encontrado!\n");
				}
			}
		}
		else{
			printf("Operacao nao existe");
		}
    	printf("\n\n");
	}*/
    system("PAUSE");
    return 0;
}
 
//metodos TAluno
TAluno* inicializaTAluno(int mat, float cr, char *nome){
    TAluno *novo = (TAluno*) malloc(sizeof(TAluno));
    novo->mat = mat;
    novo->cr = cr;
    strcpy(novo->nome,nome);
    return novo;
}
 
void modifica_cr(TAluno *aluno, float novoCr){
    aluno->cr = novoCr;
}
 
void modifica_nome(TAluno *aluno, char *novoNome){
    strcpy(aluno->nome,novoNome);
}

void modifica_mat(TAluno *aluno, TAVP *arvore, int novoMat){
	float crAux = aluno->cr;
	char nomeAux[31];
	strcpy(nomeAux,aluno->nome);
	TAVP *alu = busca(arvore,aluno -> mat);
	removeAluno(alu,arvore);
	arvore = insereAluno(arvore,novoMat,crAux,nomeAux);
}
 
void imprimeAluno(TAluno *aluno){
    printf("Nome: %s\n",aluno->nome);
    printf("Matricula: %d\n",aluno->mat);
    printf("CR: %g\n",aluno->cr);
}
 
//metodos TAVP
TAVP* inicializaTAVP(void){
    return NULL;
}
 
void imprimeArvore(TAVP *arvore){ //pre-fixado
    printf("<");
    if(arvore){
        printf("%d-%c",arvore->alunoNo->mat,arvore->cor);
        if((arvore->esq)||(arvore->dir)){
            imprimeArvore(arvore->esq);
            imprimeArvore(arvore->dir);
        }
    }
    printf(">");
}

void imprime_debug_AVP(TAVP *a) {
	if (a) {
		if (a -> esq) printf("(%d) ?", a->esq->alunoNo->mat);
		else printf("( ) ?");

		printf(" [%d-%c] ", a->alunoNo->mat,a->cor);

		if (a -> dir) printf("? (%d)", a->dir->alunoNo->mat);
		else printf("? ( )");

		printf("\n");

		if (a -> esq) imprime_debug_AVP(a -> esq);
		if (a -> dir) imprime_debug_AVP(a -> dir);
	}
}
 
void destroiArvore(TAVP *arvore){
    if(arvore){
        destroiArvore(arvore->esq);
        destroiArvore(arvore->dir);
        free(arvore->alunoNo);
        free(arvore);
    }
}

TAVP* busca (TAVP *arvore, int matricula) {
    if (arvore == NULL || arvore->alunoNo->mat == matricula)
       return arvore;
    if (arvore->alunoNo->mat > matricula)
       return busca (arvore->esq, matricula);
    else
       return busca (arvore->dir, matricula);
}
 
TAVP* obtemPai(TAVP* no){
    if(!no){
        return NULL;
    }
    return no->pai;
}
 
TAVP* RSD(TAVP *raiz,TAVP *pivot){
    TAVP *filhoEsq = pivot->esq;
    pivot->esq = filhoEsq->dir;
    if(pivot->esq != NULL){
        pivot->esq->pai = pivot;
    }
    filhoEsq->pai = pivot->pai;
    if (pivot->pai == NULL){
            raiz = filhoEsq;
    }
    else if (pivot == pivot->pai->esq){
        pivot->pai->esq = filhoEsq;
    }
    else{
        pivot->pai->dir = filhoEsq;
    }
    filhoEsq->dir = pivot;
    pivot->pai = filhoEsq;
    return raiz;
}
 
TAVP* RSE(TAVP *raiz,TAVP *pivot){
    TAVP *filhoDir = pivot->dir;
    pivot->dir = filhoDir->esq;
    if(pivot->dir != NULL){
        pivot->dir->pai = pivot;
    }
    filhoDir->pai = pivot->pai;
    if (pivot->pai == NULL){
            raiz = filhoDir;
    }
    else if (pivot == pivot->pai->esq){
        pivot->pai->esq = filhoDir;
    }
    else{
        pivot->pai->dir = filhoDir;
    }
    filhoDir->esq = pivot;
    pivot->pai = filhoDir;
    return raiz;
}
 
TAVP* insereAluno(TAVP *arvore, int matricula, float cr, char *nome){
    if(busca(arvore,matricula)) return arvore;
    TAVP *novo = (TAVP*)malloc(sizeof(TAVP));
    novo->alunoNo = inicializaTAluno(matricula, cr, nome);
    novo->esq = NULL;
    novo->dir = NULL;
    if(!arvore){
        novo->cor = 'P';
        novo->pai = NULL;
        return novo;
    }
    TAVP *aux1=arvore,*aux2;
    while(aux1){
        aux2 = aux1;
        if(aux1->alunoNo->mat < matricula){
            aux1 = aux1->dir;
        }
        else{
            aux1= aux1->esq;
        }
    }
    if(aux2->alunoNo->mat > matricula){
        aux2->esq = novo;
    }
    else{
        aux2->dir = novo;
    }
    novo->pai = aux2;
    novo->cor = 'V';
    arvore = corrigeInsere(arvore,novo);
    return arvore;
}
 
TAVP* corrigeInsere(TAVP *arvore, TAVP *no){
    TAVP *aux = no, *pai = obtemPai(aux), *avo = obtemPai(pai), *tio;
    while((aux) && (aux!=arvore) && (pai->cor == 'V') && (avo)){
        if(pai == avo->esq){
            tio = avo->dir;
            if((tio) && (tio->cor == 'V')){
                tio->cor = pai->cor = 'P';
                avo->cor = 'V';
                aux = avo;
                pai = obtemPai(aux);
                avo = obtemPai(pai);
            }
            else{
                if(aux == pai->dir){
                    aux = pai;
                    arvore = RSE(arvore,aux);
                    pai = obtemPai(aux);
                    avo = obtemPai(pai);
                }
                pai->cor = 'P';
                avo->cor = 'V';
                arvore = RSD(arvore,avo);
            }
        }
        else{
            tio = avo->esq;
            if((tio) && (tio->cor == 'V')){
                tio->cor = pai->cor = 'P';
                avo->cor = 'V';
                aux = avo;
                pai = obtemPai(aux);
                avo = obtemPai(pai);
            }
            else{
                if(aux == pai->esq){
                    aux = pai;
                    arvore = RSD(arvore,aux);
                    pai = obtemPai(aux);
                    avo = obtemPai(pai);
                }
                pai->cor = 'P';
                avo->cor = 'V';
                arvore = RSE(arvore,avo);
            }
        }
    }
    arvore->cor = 'P';
    return arvore;
}
 /*
TAVP* removeAluno(TAVP *arvore, int matricula){
    TAVP *no = busca(arvore,matricula);
    if(!no)return arvore;
    TAVP *pai = obtemPai(no);
    if(eFolha(no)){
    	if(pai){
		    if(pai -> dir && pai -> dir -> mat == no -> mat){
    		    if(no -> cor == 'V'){
    			    pai -> dir = NULL;
    			    free(no);
    			    return arvore;
    		    }else{
    		    	return corrigePretoPreto(arvore,pai,no,0);
    	    }else{
    	    	if(no -> cor == 'V'){
    	    		pai -> esq = NULL;
    	    		free(no);
    	    		return arvore;
				}else{
					return corrigePretoPreto(arvore,pai,no,0);
				}
			}
		}else{
			return NULL;
		}
	}

AVP* corrigePretoPreto(TAVP *arvore,TAVP *pai,TAVP *no,int case){
    TAVP *irmao = obtemIrmao(no);
    if(!case){	
        if(pai -> cor == 'P'){
		    if(pai -> dir -> mat == no -> mat){
		    	pai -> dir = NULL;
	    		free(no);
			    if(irmao -> cor == 'P'){
	    	        if(eFolha(irmao)){
	    		        irmao -> cor = 'V';
	    		        return arvore;
			        }else{
			    	    if(irmao -> dir && irmao -> esq){
			    		    if(irmao -> dir == 'V' && irmao -> esq == 'V'){
			    		    	
						    }
					    }
			        }
		        }
            }
        }
	}
}
*/
TAVP* removeAluno(TAVP *n, TAVP *arvore){
	TAVP *filho = n;
	int trigger = 1;
	if(!(n->dir)&& !(n -> esq)){	
		return remocaoFolha(n,arvore);
	}
	else{
		filho = n->esq;
		if(filho){
			while(filho->dir){
	        	filho = filho->dir;
	   		}
	   	}
	   	else{
	   		filho = n->dir;
	   		while(filho->esq){
	        	filho = filho->esq;
	   		}
		}
		troca(n,filho); // Programa para aqui <- TESTADO
		printf("passou pela troca\n");
	}
	printf("chegou em remoção\n");
	if (n->cor == 'P') {
		if (filho->cor == 'V'){
		    trigger = 0;
			filho->cor = 'P';
		}
	    else if((!filho->esq)&&(!filho->dir)){
	    	return remocaoFolha(filho,arvore);
		}
		else{
			trigger = 0;
	   		delete_case1(filho,arvore);
	   	}
	}
	if(trigger){
	
		if(filho->cor == 'P'){
			if(filho->dir) filho->dir->cor = 'P';
			if(filho->esq) filho->esq->cor = 'P';			
		}
		if(!obtemPai(n)){
			arvore = buscaRaiz(arvore);
			liberacaoRemocao(filho);
			return arvore;
		}
		else if(n->cor == 'P'&& filho->cor =='P'){
			return pretoPreto(arvore,n);
		}
		else if(n->cor == 'V'&& filho->cor =='P'){
			return pretoPreto(arvore,filho);
		}
	}
	arvore = buscaRaiz(arvore);
	liberacaoRemocao(filho);
	return arvore;
}

void delete_case1(TAVP *n , TAVP *arvore){
	printf("chegou no caso 1\n");
	if (obtemPai(n)) delete_case2(n,arvore);
}

void delete_case2(TAVP *n,TAVP *arvore){
	printf("chegou caso 2\n");
	TAVP *pai = obtemPai(n);
	TAVP *irmao = obtemIrmao(n);
	if (irmao->cor == 'V') {
		pai->cor = 'V';
		irmao->cor = 'P';
		if (n == pai->esq) arvore = RSE(arvore,pai);
		else arvore = RSD(arvore,pai);
	}
	delete_case3(n,arvore);
}

void delete_case3(TAVP *n,TAVP *arvore){
	printf("chegou caso 3\n");
	TAVP *irmao = obtemIrmao(n), *pai = obtemPai(n);
	if ((pai->cor == 'P') &&(irmao->cor == 'P') &&(irmao->esq->cor == 'P') &&(irmao->dir->cor == 'P')) {
		irmao->cor = 'V';
		delete_case1(pai,arvore);
	}
	else delete_case4(n,arvore);
}

void delete_case4(TAVP *n, TAVP *arvore){
	printf("chegou caso 4\n");
	TAVP*irmao = obtemIrmao(n); TAVP*pai = obtemPai(n);
	if((irmao->esq) && (irmao->dir)){
		if ((pai->cor == 'V') && (irmao->cor == 'P') && (irmao->esq->cor == 'P') && (irmao->dir->cor == 'P')) {
			irmao->cor = 'V';
			pai->cor = 'P';
		}
	}
	else delete_case5(n,arvore);
}

void delete_case5(TAVP*n, TAVP*arvore){
	printf("chegou caso5\n");
	TAVP *irmao = obtemIrmao(n); TAVP *pai = obtemPai(n);
	if  (irmao->cor == 'P') {
		if((irmao->esq)&&(irmao->dir)){
			if ((n == pai->esq) && (irmao->dir->cor == 'P') && (irmao->esq->cor == 'V')) { /* this last test is trivial too due to cases 2-4. */
				irmao->cor = 'V';
				irmao->esq->cor = 'P';
				arvore = RSD(arvore,irmao);
			} 
			else if ((n == pai->dir) && (irmao->esq->cor == 'P') && (irmao->dir->cor == 'V')) {/* this last test is trivial too due to cases 2-4. */
				irmao->cor = 'V';
				irmao->dir->cor = 'P';
				arvore = RSE(arvore,irmao);
			}
		}
	}
	delete_case6(n,arvore);
}

void delete_case6(TAVP *n, TAVP *arvore){
	printf("chegou caso 6\n");
	TAVP *irmao = obtemIrmao(n); 
	TAVP* pai = obtemPai(n);
	irmao->cor = pai->cor;
	pai->cor = 'P';
	if((irmao->esq)&&(irmao->dir)){
		if (n == pai->esq) {
			irmao->dir->cor = 'P';
			arvore = RSE(arvore,pai);
		} 
		else {
			irmao->esq->cor = 'P';
			arvore = RSD(arvore,pai);
		}
	}
}

TAVP* remocaoFolha(TAVP*n,TAVP*arvore){
	TAVP* pai = obtemPai(n);
	char remc,succ;
    if(!pai){
      	free(n);
		return NULL;
	}
    remc = n -> cor;
    if(pai->dir){
		if(pai->dir->alunoNo->mat == n->alunoNo->mat){ //segmentation fault (?)
	    	if(remc == 'V'){
	            pai -> dir = NULL;
	            free(n);
	            return arvore;
	        }
	        succ = 'P';
	        return pretoPreto(arvore,n);
	    }
	}
    if(remc == 'V'){
        pai -> esq = NULL;
        free(n);
        return arvore;
    }
    succ = 'P';
    return pretoPreto(arvore,n);
}

TAVP* pretoPreto(TAVP *arvore, TAVP *no){
    printf("Chegou aqui\n");
    TAVP *pai = obtemPai(no); TAVP *irmao = obtemIrmao(no);
    if(no == pai->dir && eFolha(irmao)){
        pai -> esq -> cor = 'V';
        pai -> cor = 'P';
    }else if(no == pai ->esq && eFolha(irmao)){
        pai -> dir -> cor = 'P';
        pai -> cor = 'V';
    }
    else if(no == pai->dir&&(irmao -> esq && irmao->esq->cor=='V')){
        printf("Chegou aqui\n");
        arvore = RSD(arvore,pai);
        irmao -> esq -> cor = 'P';
        pai -> cor = 'P';
        irmao -> cor = 'V';
    }
    else if(no == pai->esq&&(!irmao -> dir || irmao->dir->cor=='P')){
        printf("Chegou aqui\n");
        arvore = RSD(arvore,irmao);
        arvore = RSE(arvore,pai);
        pai -> cor = 'P';
        obtemPai(pai) -> cor = 'V';
        irmao -> cor = 'P';
        if(irmao -> dir)irmao -> dir -> cor = 'V';
    }
    else if(no == pai->esq&&(irmao -> dir && irmao->dir->cor=='V')){
        printf("Chegou aqui\n");
        arvore = RSE(arvore,pai);
        irmao -> dir -> cor = 'P';
        pai -> cor = 'P';
        irmao -> cor = 'V';
    }
    else if(no == pai->dir&&(!irmao -> esq || irmao->esq->cor=='P')){
        printf("Chegou aqui\n");
        arvore = RSE(arvore,irmao);
        arvore = RSD(arvore,pai);
        pai -> cor = 'P';
        obtemPai(pai) -> cor = 'V';
        irmao -> cor = 'P';
        if(irmao -> esq)irmao -> esq -> cor = 'V';
    }
    printf("Chegou aqui\n");
    liberacaoRemocao(no);
    return arvore;
}
 
/*TAVP* vermelhoPreto(TAVP* arvore,TAVP* n){	
	TAVP *pai = obtemPai(n); TAVP *irmao = obtemIrmao(n);
	if(n == pai->esq&&(!irmao -> dir || irmao->dir->cor=='P')){
        printf("Chegou aqui\n");
        arvore = RSD(arvore,irmao);
        arvore = RSE(arvore,pai);
        pai->cor = 'P';
        obtemPai(pai)->cor = 'V';
        irmao->cor = 'P';
        if(irmao->dir) irmao->dir->cor = 'V';
    }
    return arvore;
	
}
*/
TAVP* obtemIrmao(TAVP* no){
	if((!no)||(!obtemPai(no))){
		return NULL;
	}
	if(obtemPai(no)->esq == no){
		return obtemPai(no)->dir;
	}
	return obtemPai(no)->esq;
}

int eFolha(TAVP* no){
	if(no -> dir || no -> esq)return 0;
	return 1;
}

void troca(TAVP* no,TAVP* filho){
	TAluno* aux = no->alunoNo;
	no->alunoNo = filho->alunoNo;
	filho->alunoNo = aux;	
}

TAVP* buscaRaiz(TAVP* arvore){
	if(!obtemPai(arvore)){
		return arvore;
	}
	return buscaRaiz(obtemPai(arvore));	
	
}

void liberacaoRemocao(TAVP* filho){
	TAVP* paizao = obtemPai(filho);
	if(paizao->esq == filho){
		if(filho->esq){
			paizao->esq = filho->esq;
		}
		else{
			paizao->esq = NULL;
		}
	}
	else{
		if(filho->dir){
			paizao->dir = filho->dir;
		}
		else{
			paizao->dir = NULL;
		}
	}
	free(filho);
}

/*void troca(TAVP* filho, TAVP* no){                      //NÃƒO FUNCIONA - TESTADO
	TAVP*pai_no = obtemPai(no),*pai_filho = obtemPai(filho), *aux = inicializaTAVP();
	if(pai_no){
		if(pai_no -> dir == no){
			pai_no -> dir = filho;
			aux -> esq = filho -> esq;
			aux -> dir = filho -> dir;
			filho -> esq = no -> esq;
			filho -> dir = no -> dir;
			no -> esq = aux -> esq;
			no -> dir = aux -> dir;
			if(pai_filho -> dir == filho){
				pai_filho -> dir = no;
			}else{
				pai_filho -> esq = no;
			}
			free(aux);
		}else{
			pai_no -> esq = filho;
			aux -> esq = filho -> esq;
			aux -> dir = filho -> dir;
			filho -> esq = no -> esq;
			filho -> dir = no -> dir;
			no -> esq = aux -> esq;
			no -> dir = aux -> dir;
			if(pai_filho -> dir == filho){
				pai_filho -> dir = no;
			}else{
				pai_filho -> esq = no;
			}
			free(aux);
		}
	}else{
		aux -> esq = filho -> esq;
		aux -> dir = filho -> dir;
		filho -> esq = no -> esq;
		filho -> dir = no -> dir;
		no -> esq = aux -> esq;
		no -> dir = aux -> dir;
		if(pai_filho -> dir == filho){
			pai_filho -> dir = no;
		}else{
			pai_filho -> esq = no;
		}
		free(aux);
	}*/

