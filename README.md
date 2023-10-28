# Readability Scorer

This project is a Readability Scorer that assesses the readability of a given text based on various readability formulas. It provides insights into how easy or difficult it is to comprehend the text. The project is implemented in C and offers a command-line interface for scoring text files.

## Table of Contents
- [Features](#features)
- [Getting Started](#getting-started)
- [Usage](#usage)
- [Contributing](#contributing)
- [License](#license)

## Features

- Calculate readability scores using different formulas such as SMOG (Simple Measure of Gobbledygook).
- Command-line interface for easy text analysis.
- Input text from files or standard input.
- Lightweight and fast implementation in C.

## Getting Started

To get started with the Readability Scorer, follow these steps:

1. Clone the repository:
```
git clone https://github.com/okeowo-cloud/Readability_scorer.git
```
2. Build the project using CMake and Make:
```
cd Readability_scorer
cmake . -B Build
cd Build
make
```
4. Run the program to analyze a text file.
```
chmod a+x run.sh
./run.sh example.txt
```

## Docker
To run the Readability Scorer using Docker, follow these steps:

1. Clone the repository:
```
git clone https://github.com/okeowo-cloud/Readability_scorer.git
```
2. Build the Docker image for the project:
```
cd Readability_scorer
docker build -t readability-scorer .
```
3. Run the program to analyze a text file:
```
chmod a+x run.sh
./run.sh example.txt
```

## Usage

The Readability Scorer accepts a text file as input and provides readability scores. You can run the program by specifying the input file as follows:

./run.sh your_text_file.txt
Replace `your_text_file.txt` with the path to the text file you want to analyze.

## Contributing

We welcome contributions to this project. To contribute, follow these steps:

1. Fork the repository.
2. Create a new branch for your feature or bug fix: `git checkout -b feature/your-feature-name`.
3. Make your changes and commit them: `git commit -m "Add your feature"`.
4. Push your changes to your fork: `git push origin feature/your-feature-name`.
5. Create a pull request on the original repository.

## License

This project is licensed under the Skoltech IP(LICENSE).

Feel free to reach out to the project owner, @okeowo-cloud, if you have any questions or need further assistance.
Happy analyzing text readability with Readability Scorer!

