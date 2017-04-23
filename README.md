# assignment-4-announcement-and-discussion
Repo for assignment 4 announcement and discussion.

## Filename format
As we have only 3 programs in this assignment, please name you file as:
- `Prog-1-encode.c(pp)`
- `Prog-1-decode.c(pp)`
- `Prog-2.c(pp)`

## Commit requirement
Please **at least** commit each program for **two** commits, don't do them all in a single commit.

## Input / Output

### Prog-1-encode:

- Input:
Input for Huffman encoder contains N characters (N <= 2048), end by `EOF`.

Sample input:
```
abcdefg
```

- Output:
First 256 lines represents Huffman code of each ASCII character (from code 0 to 255)

After that, output encoded document by `0` and `1`

Sample output:
```c
// ... first 96 code ...
00  // a
1101  // b
011  // c
010  // d
101  // e
100  // f
111  // g
110000000011110
110000001
1100000000110
110001
11000000000
11000001
1100000000111111111110
// ... other encoded code ...
001101011010101100111  // encoded data
```

### Prog-1-decode:

- Input:

Read input from encoder you wrote.

- Output:

Decoded article.

### Prog-2:

- Input:

Given by original document, format:

```
<number of vertices (2 ≤ V ≤ 10)>
<number of edges (1 ≤ E ≤ 20)>
<endpoint 1> <endpoint 2> <weight (1 ≤ W1 ≤ 1000)>
<endpoint 1> <endpoint 2> <weight (1 ≤ W2 ≤ 1000)>
<Vehicle Range (0 < VR)>
<Vehicle Speed (0 < VS)>
<Source City (0 ≤ SC ≤ V-1)>
<Destination City (0 ≤ DC ≤ V-1)>
```

Sample input:
```
5
7
0 1 130
0 2 60
0 3 120
1 3 50
1 4 10
2 3 50
3 4 20
130
50
0
1
```

- Output:
```
Route: 0 2 3 4 1
Total distance: 140
Estimation time: 2.8
```

## Q & A
Please open issue here: https://github.com/NCTU-CSE-Introduction-to-Algorithms/assignment-4-announcement-and-discussion/issues for your questions, TAs will do the best to answer your question or discuss with you.

## Notes
Please ["Watch"](https://github.com/NCTU-CSE-Introduction-to-Algorithms/assignment-4-announcement-and-discussion/subscription) this repository to get the latest discussion or announcement about the programming assignment 3.

## Misc

Read all characters from standard input (C++)

```cpp
#include<iostream>
using namespace std;

int main() {
    char buf[2048];
    int i = 0;
    while(!cin.eof()) {
        buf[i++] = cin.get();
    }
    buf[i] = '\0';
    // do something.....
    return 0;
}
```

Read all characters from starndard input (C)

```c
#include<stdio.h>
int main() {
    char buf[2048];
    char c;
    int i = 0;
    while(scanf("%c", &c) != EOF) {
        buf[i++] = c;
    }
    buf[i] = '\0';
    // do something.....
    return 0;
}
```

Redirect file to standard input of a program:

```bash
$ ./your_program < input_file > output_file
```
