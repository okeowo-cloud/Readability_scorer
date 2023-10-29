# Readability Scorer

This project is a Readability Scorer that assesses the readability of a given text based on various readability formulas. It provides insights into how easy or difficult it is to comprehend the text. The project is implemented in C and offers a command-line interface for scoring text files.

## Table of Contents
- [Features](#features)
- [Getting Started](#getting-started)
- [Usage](#usage)
- [Contributing](#contributing)
- [License](#license)

## Features

- Calculate readability scores using different formulas such as:
> [SMOG (Simple Measure of Gobbledygook)](https://en.wikipedia.org/wiki/SMOG)

> [Coleman Liau Index](https://en.wikipedia.org/wiki/Coleman%E2%80%93Liau_index)

> [Flesch-Kincaid Grade level](https://en.wikipedia.org/wiki/Flesch%E2%80%93Kincaid_readability_tests)

> [Automated Readability Index](https://en.wikipedia.org/wiki/Automated_readability_index)

- Command-line interface for easy text analysis.
- Input text from files.
- Lightweight and fast implementation in C.

## Getting Started

### On Linux Machine
To get started with the Readability Scorer, follow these steps:

1. Clone the repository:
```
git clone https://github.com/okeowo-cloud/Readability_scorer.git
```

2. Install dependencies
```
./prereqs.sh
```

3. Build the project using CMake and Make:
```
./build.sh
```

4. Run the program to analyze a text file.
```
./run.sh example.txt
```
5. To Run the program tests.
```
./test.sh
```

### With Docker
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
docker run -it readability-scorer example.txt
```
NB: example.txt file is a static file present within the container for running the program.
To provide a file dynamically for the container to run the program, you need to Mount either a directory containing your files or Mount a file.

To Mount a directory, use code below:
```
docker run -it -v /PATH/TO/YOUR_DIR:/YOUR_DIR readability-scorer /YOUR_DIR/TEXT_FILE.txt
```

To Mount a file, use code below:
```
docker run -it -v /PATH/TO/YOUR_DIR/TEXT_FILE.txt:/TEXT_FILE.txt readability-scorer /TEXT_FILE.txt
```

## Usage

The Readability Scorer accepts a text file as input and provides readability scores. It is an interactive application that requires user's input.
On start of the program, it request for the type of readability measures:
- CL - represents coleman liau index
- AR - represents Automated readability index
- FK - represents Flesch-Kincaid index
- SG - represents SMOG (Simple Measure of Gobbledygook)
- !! - to quit from the program.

## Contributing

We welcome contributions to this project. To contribute, follow these steps:

1. Fork the repository.
2. Create a new branch for your feature or bug fix: `git checkout -b feature/your-feature-name`.
3. Make your changes and commit them: `git commit -m "Add your feature"`.
4. Push your changes to your fork branch: `git push origin feature/your-feature-name`.
5. Create a pull request on the original repository.

## License

This project is licensed under the Skoltech IP(LICENSE).

Feel free to reach out to the project owner, @okeowo-cloud, if you have any questions or need further assistance.
Happy analyzing text readability with Readability Scorer!
