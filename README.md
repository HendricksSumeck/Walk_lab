# WalkLab 🧩

Um programa escrito inteiramente em linguagem C capaz de plotar labirintos em via Terminal (CLI) e resolvê-los visualmente, computando as rotas mais indicadas de `A` para `B` baseando-se no algoritmo de preenchimento (pesquisa em largura/inundação).  

Este projeto serve não somente como um game de mapas via prompt, mas como um excelente estudo funcional sobre rotinas matemáticas de alocação de memória dinâmica, renderização visual CLI e estruturas de **Filas** na linguagem C.

<img src="./Gif WalkLab.gif" alt="Exibição CLI Labirinto" width="100%" />

## Funcionalidades Principais 🌟
- Leitura dinâmica de matrizes em arquivos de texto localizados em `labirintos/`.
- Algoritmo em tempo real de `Flood Fill` (Inundação), varrendo espaços livres partindo do ponto inicial por propagação baseada na distância computada pelas filas.
- Plotagem visual em ANSI das bordas `(paredes)`, caminhos processados `(inundação em azul)` e a rota traçada ótima `(caminho final em vermelho)`.
- Estruturação modular nativamente C: Headers e Srcs isolados por contexto.
- Configuração Multi-Plataforma: o comando de renderização adapta-se entre ambientes providos de POSIX (macOS, Linux) e `windows.h` (Windows) automaticamente.

---

## Estrutura do Código 📁

O código encontra-se construído utilizando as melhores convenções para um repositório C sólido, separando a lógica bruta de algoritmos das chamadas e dependências que devem ser importadas no arquivo que rege a compilação.
```text
WalkLab/
├── Makefile                # Receita do ambiente de build (Compiler).
├── src/                    # Repositório de códigos fonte lógicos (.c)
│   ├── main.c           # Orquestrador primário. 
│   ├── arquivo.c        # Tratamento do I/O, leitura de textfiles com mapas.
│   ├── labirinto.c      # O motor do game: Processos de alocação de matrizes.
│   ├── fila.c           # Datastructure Fila p/ pathfinding Flood Fill.  
│   ├── menu.c           # Visualização e leitura da tela inicial.
│   ├── personagem.c     # Tratamento de struct player.
│   ├── monstro.c        # Tratamento de struct Monstro.
│   └── batalha.c        # Lógica de lutas RPG-like com struct dependentes.
├── include/                # Repositório de Headers/Assinaturas de métodos (.h)
│   ├── incluir.h        # Coleção única agregando e exportando as standard tools <stdio.h>, modulos POSIX/Win e todos os outros módulos a seguir:
│   ├── labirinto.h
│   ├── arquivo.h
│   ├── fila.h ... etc.
├── img/                    # Painéis em texto puro (ASCII Art).
├── labirintos/             # Mapas configurados em `txt`.
└── obj/                    # Saída dos módulos compilados temporários pelo Makefile (.o).
```

---

## Como Funciona o Algoritmo (Pathfinding) 🤖

Para resolver qualquer labirinto validamente desenhado nos arquivos `.txt`, este projeto usa a união de duas lógicas clássicas de Teoria dos Grafos: **Pesquisa em Largura** (*Breadth-First Search* / *Flood Fill*) para mapear a distância total, e o **Backtracking** (*Retrocesso*) para selecionar a rota mais curta.

### 1. Inundação (A Fila de Espaços Livres)
A mágica começa na função `inundacao()` do motor `labirinto.c`. Ela inicia a análise exatamente nas coordenadas do caractere de Entrada (`E`), rotulando a posição inicial como a semente "1".
   - Utilizamos a nossa estrutura de dados customizada de **Fila** (First In, First Out).
   - O algoritmo investiga os espaços adjacentes (Cima, Baixo, Esquerda, Direita). Se ele achar o espaço livre, insere as coordenadas desta nova fenda na nossa Fila, e define lá dentro uma "poça d'água" com o número incrementado.
   - Os elementos mais antigos vão sendo puxados fora da Fila e analisados repetidamente (com `desenfila()`). Isso garante que todo o percurso se expanda num raio gradual de distância — do menor até os maiores comprimentos —, varrendo exaustivamente todas as saídas ao invés de entrar logo num beco sem saída e travar.
   - O algoritmo desenha essas poças em azul claro (os `printf`s posicionais absolutos via ANSI das macros `PRINT_PATH`), e só desliga quando a onda bate de frente no caractere final (`F`).

### 2. Caminhada e Backtracking (O Fio de Ariadne)
Quando a inundação atinge o Destino, nós temos um mapa preenchido numericamente revelando o quão longe todos os blocos vazios do labirinto estão do Início. 
   - A função `caminha()` encerra o jogo. Em posse dessa matriz, ela brota no Destino (`F`) e olha envolta: "Qual dos bloquinhos vizinhos a mim guarda um número contável menor em -1?".
   - Como toda a água foi dispersada a partir do um, caminhar iterativamente apenas subindo às ladeiras aos degraus que diminuem é matematicamente certo de nos arrastar ladeado até o inicio na menor velocidade possível.
   - Durante essa descida do labirinto a nova macro traça a linha oficial substituindo todos os blocos válidos por "caminho" oficial e re-pintando os vencedores em gráfico vermelho!

---

## Como Compilar e Rodar 🚀

Certifique-se de que dispõe de um compilador C compatível baseado em UNIX ou MSYS (usaremos o nativo `gcc`) instanciado aí em sua respectiva variável de ambiente. Além dele possua acesso às utilidades GNU Make se não preferir compilação engessada e longa.

### Instruções

1. Clone ou Extraia este repositório base para seu computador. Em seguida, acesse-o dentro de seu Shell de preferência:

```sh
cd ./Walk_lab
```

2. Realize o build do projeto rodando nossa receita limpa no GNU Make. O Makefile varrerá seus códigos e buscará nos seus cabeçalhos as declarações, sem erros:

```sh
make
```

3. Pronto, um arquivo executável principal foi concebido (intitulado apenas de `walklab` em Unix e `walklab.exe` no Windows). Interaja com ele:

```sh
# Em caso Linux/macOS
./walklab
```
> O menu carregará mostrando 4 opções originais de labirintos já embutidos no banco `labirintos/lb#.txt`. Apenas utilize uma tecla numérica compatível e observe o espetáculo do terminal!

Ao desejar forçar a limpeza dos executáveis e de todos arquivos remanescentes em `obj`, você pode utilizar: `make clean`.