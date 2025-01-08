# Pipex

## Sobre o Projeto

O **Pipex** é um projeto da 42 que desafia os alunos a implementarem uma versão simplificada da funcionalidade de pipes no Bash. O objetivo principal é consolidar o conhecimento sobre processos, redirecionamento de entrada e saída e comunicação entre processos em sistemas Unix.

---

## Funcionalidades

- Simular o funcionamento do seguinte comando Bash:
  ```bash
  cmd1 < file_in | cmd2 > file_out
  ```
- Suporte ao uso de dois comandos em sequência conectados por um pipe.
- Gerenciamento de arquivos de entrada e saída para redirecionamento correto.
- Tratamento de erros apropriado, como:
  - Arquivos inexistentes ou sem permissão.
  - Comandos inválidos.

---

## Tecnologias e Ferramentas

- **Linguagem**: C
- **Sistema operacional**: Linux
- **Funções POSIX**, como:
  - `pipe()`
  - `dup2()`
  - `execve()`
  - `fork()`

---

## Como Compilar

Para compilar o projeto, certifique-se de ter o compilador **gcc** e o **Make** instalados. Use o seguinte comando:

```bash
make
```

O binário será gerado na raiz do projeto com o nome `pipex`.

---
