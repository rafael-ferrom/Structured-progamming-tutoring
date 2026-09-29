🌐 **Português** · [English](README.en.md)

# 📚 Programação Estruturada — Monitoria (Linguagem C)

Repositório de apoio à monitoria de **Programação Estruturada** (Engenharia de Computação), organizado de acordo com o **Plano de Aprendizagem** da disciplina.

Para cada tópico você encontra:

- 📖 **Conteúdo** — teoria resumida e direta
- 💻 **Código comentado** — `exemplo.c` pronto para compilar e rodar
- ✍️ **Exercícios teóricos** e 🛠️ **exercícios práticos**
- ✅ **Gabarito** de ambos (teórico comentado + soluções em C testadas)

> 🌐 O repositório é bilíngue: cada arquivo `.md` tem versão em português (`arquivo.md`) e em inglês (`arquivo.en.md`), e os comentários dos códigos em C estão nos dois idiomas.  
> **Obs.:** os identificadores (`soma`, `troca`, `Aluno`...) e as mensagens impressas pelos programas ficam em português (idioma da disciplina), sem acentos para aparecerem corretamente em qualquer terminal.

---

## 🎯 Objetivo

Ajudar os alunos a dominarem lógica de programação e a linguagem C: funções, ponteiros, alocação dinâmica, estruturas e arquivos.

## 🗺️ Mapa do conteúdo programático

| Tópico do plano | Módulo |
|-----------------|--------|
| Funções | [01 · Funções](01-funcoes) |
| Endereço de Variáveis · Ponteiros | [02 · Endereços e ponteiros](02-enderecos-e-ponteiros) |
| Chamada por Referência | [03 · Chamada por referência](03-chamada-por-referencia) |
| Strings (revisão) · Strings e Ponteiros · Matriz de Ponteiros para Strings | [04 · Strings e ponteiros](04-strings-e-ponteiros) |
| Alocação Dinâmica de Memória | [05 · Alocação dinâmica](05-alocacao-dinamica) |
| Estruturas · Matriz de Estruturas | [06 · Estruturas](06-estruturas) |
| Ponteiros e Estruturas · Estruturas e Alocação Dinâmica | [07 · Ponteiros e estruturas](07-ponteiros-e-estruturas) |
| Arquivos em I/O · Operações com Arquivos | [08 · Arquivos](08-arquivos) |
| Acesso Aleatório · Estruturas e Arquivos em I/O | [09 · Acesso aleatório e binários](09-acesso-aleatorio-e-arquivos-binarios) |

## 📅 Módulos × cronograma de aulas

| Módulo | Aula(s) do cronograma |
|--------|-----------------------|
| 01 Funções | Aula 2 (10/08) |
| 02 Endereços e ponteiros | Aula 3 (17/08) |
| 03 Chamada por referência | Aula 5 (24/08) |
| 05 Alocação dinâmica | Aula 5 (24/08) · Aula 7 (14/09) |
| 04 Strings e ponteiros | Aula 7 (14/09) |
| 06 Estruturas | Aulas 8 (21/09) e 10 (28/09) |
| 07 Ponteiros e estruturas | Aula 11 (05/10) |
| 08 Arquivos | Aula 13 (26/10) · Aulas 14 (09/11) e 16 (23/11) |
| 09 Acesso aleatório | Aula 13 (26/10) · Aulas 14 e 16 |

## 📝 Avaliações do semestre

| Avaliação | Data | Onde estudar |
|-----------|------|--------------|
| AC1 — Prova teórica | 31/08/2026 | Módulos 01 a 03 e 05 |
| AC1 — Prova prática | 14/09/2026 | Módulos 01 a 05 |
| AG — Teste de Progresso | 07/10/2026 | Conforme orientações institucionais |
| AC2 — Prova teórica | 19/10/2026 | Módulos 05 a 07 (Estruturas e Alocação) |
| AC2 — Prova prática | 26/10/2026 | Módulos 05 a 07 (Estruturas e Alocação) |
| AF — Avaliação Final (teórica) | 30/11/2026 | **Todo o conteúdo** |
| AS — Substitutiva (teórica) | 14/12/2026 | **Todo o conteúdo** |

> Confirme sempre as datas no Canvas: o calendário pode ser ajustado pela instituição.

---

## 📂 Estrutura do repositório

```
/programacao-estruturada-monitoria
│
├── /Instrucoes
│   ├── configurar-ambiente(.en).md  Instalar gcc e configurar o VS Code
│   └── erros-comuns(.en).md         Erros de compilação e execução mais frequentes
│
├── /01-funcoes
├── /02-enderecos-e-ponteiros
├── /03-chamada-por-referencia
├── /04-strings-e-ponteiros
├── /05-alocacao-dinamica
├── /06-estruturas
├── /07-ponteiros-e-estruturas
├── /08-arquivos
├── /09-acesso-aleatorio-e-arquivos-binarios
│   │
│   ├── README(.en).md              📖 Teoria do módulo
│   ├── exemplo.c                   💻 Código comentado
│   ├── /exercicios
│   │   ├── teorico(.en).md         ✍️ Questões teóricas
│   │   └── pratico(.en).md         🛠️ Exercícios práticos
│   └── /gabarito
│       ├── teorico(.en).md         ✅ Respostas comentadas
│       └── /pratico                ✅ Soluções em C (ex01_*.c, ex02_*.c, ...)
│
├── /scripts
│   └── verificar_tudo.sh           Compila e testa todos os códigos
├── /.vscode
│   └── tasks.json                  Atalho de compilação (Ctrl+Shift+B)
└── .gitignore
```

(`(.en)` indica que existe o arquivo em português, `nome.md`, e em inglês, `nome.en.md`.)

---

## ▶️ Como compilar e executar

Dentro da pasta do módulo:

### Linux / macOS

```bash
gcc -Wall -Wextra -std=c11 exemplo.c -o exemplo
./exemplo
```

### Windows (PowerShell)

```powershell
gcc -Wall -Wextra -std=c11 exemplo.c -o exemplo.exe
.\exemplo.exe
```

### No VS Code

Abra o arquivo `.c` e pressione **Ctrl+Shift+B** (usa o `.vscode/tasks.json` deste repositório). Detalhes em [`Instrucoes/configurar-ambiente.md`](Instrucoes/configurar-ambiente.md).

> 💡 Sempre compile com `-Wall -Wextra`: os avisos do compilador apontam a maioria dos erros de iniciantes.

## 🧠 Método de estudo recomendado

1. Leia a teoria (`README.md` do módulo)
2. Compile e execute o `exemplo.c`; **modifique** o código e observe o que muda
3. Resolva os **exercícios teóricos** no papel
4. Resolva os **exercícios práticos** no computador **sem olhar o gabarito**
5. Compare com o gabarito; se a solução for diferente e estiver correta, ótimo!
6. Refaça os exercícios que errou alguns dias depois

## 🔎 Para o monitor: verificando o repositório

```bash
bash scripts/verificar_tudo.sh              # compila tudo com -Werror e executa os exemplos
bash scripts/verificar_tudo.sh --sanitize   # idem, com AddressSanitizer (detecta vazamentos e acessos inválidos)
```

## 🤝 Contribuições

Sugestões de novos exercícios, correções e melhorias são bem-vindas — abra uma *issue* ou um *pull request*.

Possíveis próximos passos:

- Listas de exercícios extras por módulo (nível desafio)
- Soluções alternativas e comentários sobre complexidade
- Projeto integrador (cadastro completo com structs, alocação dinâmica e arquivos)
- Introdução a TADs e listas encadeadas (continuação em Estrutura de Dados)

## 👨‍💻 Autoria

Material de monitoria criado por **Rafael Machado**, monitor de Programação Estruturada.
