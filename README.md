*This project has been created as part of the 42 curriculum by swaragay.*

## Description
`get_next_line` は、ファイル記述子（file descriptor）から1行ずつテキストを読み込むC言語の関数です。
このプロジェクトの主な目的は、C言語における**静的変数（static variables）**の概念を理解し、効率的なメモリ管理とバッファ処理を学ぶことにあります。

繰り返しの呼び出し（ループなど）によって、対象のファイルや標準入力から、改行文字（`\n`）が記述されている位置、あるいはファイル末尾（EOF）に達するまで1行ずつ正確に読み出します。

### Algorithm Justification
- `read_buf`: 指定された BUFFER_SIZE ごとにファイル記述子からデータを読み込み、ENDあるいは、EOFがみつかるまでreadし続ける。返り値は読み込んだ文字列。
- `result_str`: static変数に蓄えられた文字列から、最初の改行文字（またはEOF）までの部分を「1行」として切り出し、メモリを割り当てて呼び出し元に返します。
- `ft_strdup`: 切り出した「1行」以降のデータ（次の行以降のデータ）をstatic変数に再保存し、次回の関数呼び出しに備えます。

## Instructions
### Compilation
本プロジェクトは、通常のコンパイルフラグに加え、`read()`関数で使用するバッファサイズを指定する `-D BUFFER_SIZE=n` フラグを付与してコンパイルします。
```bash
cc -Wall -Wextra -Werror -D BUFFER_SIZE=42
```
※BUFFER＿SIZEは任意の値を指定。

### main関数例
```c
#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include "get_next_line.h"

int main(int argc, char **argv)
{
    int     fd;
    char    *line;
    int     count = 1;

    if (argc == 2)
    {
        fd = open(argv[1], O_RDONLY);
        if (fd == -1)
        {
            perror("Error opening file");
            return (1);
        }
    }
    else
    {
        printf("--- Reading from Standard Input (Type something and press Enter) ---\n");
        fd = 0;
    }

    printf("--- Start Reading ---\n");
    while ((line = get_next_line(fd)) != NULL)
    {
        printf("Line [%02d]: |%s|", count++, line);
        free(line);
    }
    printf("\n--- End of Reading ---\n");

    if (fd != 0)
        close(fd);
    return (0);
}
/**
cc -Wall -Wextra -Werror -D BUFFER_SIZE=42 main.c get_next_line.c get_next_line_utils.c
./a.out test.txt
**/
```
### test用txtファイル
```txt
First line is normal.
12345
{The line above was empty}

This line is very long to test if it exceeds BUFFER_SIZE correctly: ABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789
No newline at the end of this file
```



## Resources
*   **超初心者向けプログラミング入門 - static:** (https://programming.pc-note.net/c/static.html)`static変数`.
*   **Project_OKI’s diary - C言語基礎知識34:** (https://project-oki.hatenablog.com/entry/C34_static) `static変数`.
*   **Linux で C/C++ の足固め - 20. read() / write() 関数:** (https://mkguytone.github.io/allocator-navigatable/ch20.html) `read関数`.
###### special thanks AMAKINO ;)

### AI Usage
本プロジェクトでは、以下の点においてAI（Gemini）を利用しました。
ドキュメント作成：カリキュラムのガイドラインに完全に準拠する形で、本README.mdの構成支援、文章作成の支援。
