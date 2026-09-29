#!/usr/bin/env bash
# Compila todos os .c do repositorio (com -Werror) e executa os exemplos.
# Compiles every .c file in the repository (with -Werror) and runs the examples.
# Uso:  bash scripts/verificar_tudo.sh [--sanitize]
#   --sanitize : compila com AddressSanitizer/UBSan (detecta vazamentos e acessos invalidos)
#                compiles with AddressSanitizer/UBSan (detects leaks and invalid accesses)
# No Windows, rode pelo Git Bash ou WSL. / On Windows, run it from Git Bash or WSL.

RAIZ="$(cd "$(dirname "${BASH_SOURCE[0]}")/.." && pwd)"
FLAGS="-Wall -Wextra -pedantic -std=c11 -Werror"
[ "$1" = "--sanitize" ] && FLAGS="$FLAGS -g -fsanitize=address,undefined"

TMP="$(mktemp -d)"
trap 'rm -rf "$TMP"' EXIT

ok=0; falhas=0

for src in $(find "$RAIZ" -name '*.c' | sort); do
    rel="${src#$RAIZ/}"
    exe="$TMP/prog"

    if ! gcc $FLAGS "$src" -o "$exe" 2> "$TMP/erros.txt"; then
        echo "FALHA (compilacao): $rel"
        cat "$TMP/erros.txt"
        falhas=$((falhas + 1))
        continue
    fi

    # Executa dentro de pasta temporaria (arquivos gerados nao poluem o repositorio).
    # Runs inside a temp folder (generated files don't pollute the repo).
    # Entrada vazia: programas interativos devem tratar o fim da entrada sem travar.
    # Empty input: interactive programs must handle end-of-input without hanging.
    ( cd "$TMP" && "$exe" < /dev/null > /dev/null 2> "$TMP/exec_err.txt" )
    codigo=$?
    if [ $codigo -ge 2 ]; then
        echo "FALHA (execucao, codigo $codigo): $rel"
        head -5 "$TMP/exec_err.txt"
        falhas=$((falhas + 1))
    else
        echo "ok: $rel"
        ok=$((ok + 1))
    fi
done

echo
echo "Resultado: $ok ok, $falhas falha(s)"
[ $falhas -eq 0 ]
