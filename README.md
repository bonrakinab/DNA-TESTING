# DNA Testing — Sequence Comparison with KMP

A console-based C++ project for comparing DNA sequences and searching for characteristic patterns inside a DNA sample. The project uses the **Knuth–Morris–Pratt (KMP)** string-matching algorithm for efficient pattern detection and includes validation for complementary DNA strands.

## What the project does

The program provides two main operations:

1. **Compare two DNA samples** to estimate how much of one sequence is present in another.
2. **Search for a characteristic sequence** inside a DNA sample and report how frequently that pattern appears.

The application also includes a menu-driven interface with About, Instructions, FAQ, Run, and Exit screens.

## Core concepts

### DNA input validation

Each DNA sample is entered as two strands. The program checks whether the bases form valid complementary pairs:

- `A` ↔ `T`
- `C` ↔ `G`

Invalid strand combinations are rejected and the user is asked to enter the sample again.

### Pattern matching with KMP

Characteristic matching is implemented with the **Knuth–Morris–Pratt algorithm**. KMP builds a longest-prefix-suffix (`LPS`) table and uses it to avoid restarting the comparison after a mismatch.

This gives the pattern-search stage a time complexity of approximately:

```text
O(N + M)
```

where `N` is the DNA sequence length and `M` is the characteristic/pattern length.

## Program flow

```text
Start
  │
  ▼
Main Menu
  ├── About
  ├── Instructions
  ├── FAQ
  └── Run
       │
       ├── Compare two DNA samples
       │     └── Validate strands → compare sequences → show percentage
       │
       └── Search for a characteristic
             └── Validate DNA → KMP search → show match percentage
```

## Repository structure

```text
DNA-TESTING/
├── newGene.cpp   # complete C++ implementation
└── README.md     # project documentation
```

## Build and run

The source uses console utilities such as `conio.h` and `system("cls")`, so it is best suited to a Windows-compatible C++ environment.

Using MinGW/G++ where the required headers are available:

```bash
g++ newGene.cpp -o dna-testing
./dna-testing
```

On Windows Command Prompt or PowerShell, run the generated executable instead:

```bash
dna-testing.exe
```

## Implementation highlights

- Menu-driven console application
- Character-array based DNA input
- Complementary-strand validation
- Pairwise DNA sequence comparison
- KMP pattern search
- LPS preprocessing for efficient matching
- Percentage-based result reporting

## Limitations

This is an academic algorithm demonstration rather than a biological analysis tool. The percentage calculations are based on the program's sequence-matching logic and should **not** be interpreted as real genetic similarity, ancestry, phenotype probability, or medical information.

The current implementation also uses fixed-size character arrays and Windows-specific console functions.

## Possible improvements

- Replace fixed-size arrays with `std::string` / `std::vector`
- Add FASTA input support
- Separate UI, validation, and sequence-analysis logic
- Add automated unit tests for DNA validation and KMP matching
- Report exact match positions as well as percentages
- Support cross-platform terminal output

## Tech stack

- **Language:** C++
- **Algorithm:** Knuth–Morris–Pratt (KMP)
- **Concepts:** string matching, arrays, sequence validation, console UI

---

This repository is preserved as an academic implementation demonstrating how classical string-search algorithms can be applied to DNA-like sequence data.
