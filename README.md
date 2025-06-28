# 📘 Compiler Design Lab – README

## 🎓 Course: Compiler Design Laboratory

**Branch**: B.Tech CSE  
**Semester**: 6th  
**Subject Code**: UCS06B29  

---

## 📂 Lab Overview

This lab is designed to provide hands-on experience with **lexical analysis**, **file handling**, **token recognition**, **comment extraction**, and **automata theory** using tools like **C language**, **Lex**, and **JFLAP**.

---

## 🧪 Experiment List

### 🔹 **Experiment 1: File Handling & Tokenizing (Using C)**

1. **Count characters, words, and lines**
   - Scan a text file and print total characters, words, and lines.

2. **Store student records in a file**
   - Read student names and marks from user input and write to file.

3. **Delete a specific line from file**
   - Remove a given line number from a text file.

4. **Copy content from one file to another**
   - Basic file I/O operation in C.

5. **Tokenize C program**
   - Read a `.c` file and identify tokens (keywords, identifiers, etc.).

6. **Remove stop words from a story**
   - Read stop words from `stop_words.txt`, remove them from `story.txt`, and write the output to `story_without_stopwords.txt`.

---

### 🔹 **Experiment 2: Lexical Analyzer (Manual C Implementation)**

- Design a lexical analyzer that:
  - Ignores extra spaces, tabs, newlines, and comments.
  - Recognizes tokens like identifiers, keywords, operators, numbers.
  - Creates **separate files for each token type** after lexical analysis.

---

### 🔹 **Experiment 3: Comment Detection in C Code**

- Take a `.c` file as input.
- Identify all **single-line (//)** and **multi-line (/* */)** comments.
- Write all extracted comments to a separate file.

---

### 🔹 **Experiment 4: Lexical Analysis Using Lex (JLex/Flex)**

1. **Check if a character is a vowel**
2. **Find all capital letters**
3. **Count lines, tabs, and spaces**
4. **Clean file content**
   - Remove **extra spaces**, **newlines**, and **tabs** from file and output clean file.

---

### 🔹 **Experiment 5: Operator Validator (C Program)**

- Read symbols and validate whether it is a known operator.
- If valid, print the operator type (e.g., arithmetic, relational, logical).
- Else, print **"Not an operator"**.

---

### 🔹 **Experiment 6: Pattern Recognition using Transition Diagram (C Program)**

- Validate input strings against:
  - `a*`
  - `a*b+`
  - `abb`
- Use DFA-like logic to accept or reject strings.

---

### 🔹 **Experiment 7: DFA Using JFLAP**

- Create **DFA** using JFLAP for a given regular expression.
- Learn how to install JFLAP and JDK:
  - Windows: [JFLAP Setup](https://www.youtube.com/watch?v=naVWdYP8hqg)
  - Linux:
    - Install JDK: [How to Install JDK](https://www.youtube.com/watch?v=ogWKP9Lm-Qo)
    - Run JFLAP: `java -jar JFLAP.jar`

---

## 🛠️ Tools & Technologies Used

- C Programming
- Lex / Flex
- JFLAP (Java-based Finite Automata Tool)
- GCC / Code::Blocks / VS Code
- Linux/Windows Environment

---

## 📄 Output Files (Generated)

| Experiment | Output Files                            |
|------------|----------------------------------------|
| Exp-1.2    | `students.txt`                         |
| Exp-1.3    | `temp.txt`, `modified.txt`             |
| Exp-1.5    | Token categories (optional file)       |
| Exp-1.6    | `story_without_stopwords.txt`          |
| Exp-2      | `identifiers.txt`, `keywords.txt`, etc.|
| Exp-3      | `comments.txt`                         |
| Exp-4.4    | `clean_output.txt`                     |

---

## ✅ Compilation & Execution

To compile C programs:
```bash
gcc filename.c -o output
./output
```

To run Lex programs:
```bash
lex file.l
gcc lex.yy.c -ll
./a.out
```
