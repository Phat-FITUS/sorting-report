# Sorting Report

## Installation guide

Open the folder you want to download the project and type the following command:

``` bash
git clone https://github.com/Phat-FITUS/sorting-report
cd sorting-report
git checkout name
```

>Where `name` is your last name. For example, my name is Le Tan Phat (9.7 score in Programming Technique) would type `git checkout phat`

## File Structure

- `Algorithms` folder is responsible for storing Sorting Code. You need to create a new Class whose name is the sorting algorithm you have to implement.
- `Definitions` folder is used to save some pre-definitions for implementing sorting algorithm and the measurement.
- `Inputs` folder is where to save the input data.
- `Modes` folder is responsible for performing the Mode handling code.
- `Resources` folder is the place which I save some dependencies of this project.

## Development guide

### Initialization

To ensure that your code is up to date with the Github code, you should type the following command before everything was touched.

```bash
git checkout name
git pull
```

>Where `name` is your last name. For example, my name is Le Tan Phat (9.7 score in Programming Technique) would type `git checkout phat`

Then, let's implement algorithm with full enthusiasm.  

Finally, you can push your code to the Github with the following command

```bash
git add .
git commit -m "what you just do"
git push --set-upstream origin name
```

>Where `name` is your last name. For example, my name is Le Tan Phat (9.7 score in Programming Technique) would type `git checkout phat`

### Sorting Algorithm

- In the `Algorithm` folder, I have created the initial class base for implementing sorting algorithm.
- For the abstract purpose of using and comparing multiple algorithms, you have to inherit the Sort class, using its constructor and override the `Handle` method.
- Then, just increase the `counting_compare` whenever you use logical expression.

>Please note that if you have to create another function for implementing the algorithm, you should put it in the class with the private range.

#### Sample Sorting Algorithm developing implementation

```C++
#ifndef NAMESORT
#define NAMESORT

#include "Sort.cpp"

class NameSort : public Sort {
private:
    //Other required function here

protected:
    void Handle(int &count_compare) {
        //Your implementation here
    }
public:
    using Sort::Sort;
};

#endif
```

> Remember that, you have to replace the `Name` with your algorithm's name.