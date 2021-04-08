#include "lib/image.h"
#include <fstream>
#include <iostream>
#include <string>
#include "deque.hpp"


struct coordinates
{
  coordinates()
  {

  }
  int rows, columns;

  coordinates(int row_input, int column_input)
  {
      rows = row_input;
      columns = column_input;
  }
};

int main(int argc, char *argv[])
{
  Image<Pixel> input;

  Deque<coordinates> deque_test;

  std::vector<std::vector<bool>> assessed; //vector to store pixels that have been read

  std::ifstream infile(argv[1]);

  //check if file exists
  if(!infile)
  {
    std::cout<< "Invalid input file";
    return EXIT_FAILURE;
  }

  std::string outfile = argv[2];

  //check if outfile is a png file
  if(outfile.substr(outfile.length()-4, 4) != ".png")
  {
    std::cout<< "Invalid output file";
    return EXIT_FAILURE;
  }

  input = readFromFile(argv[1]); //read in png file

  //store maze height and maze width
  std::size_t height, width;
  height = input.height();
  width = input.width();

  assessed.resize(height); //resize the vector
  for(int i=0; i<height; i++)
  {
    assessed[i].resize(width);
    for(int j=0; j<width; j++)
    {
       assessed[i][j] = false;
    }
  }

  int newRow, newCol, count = 0;

  for (int i=0; i<width; i++)
  {
    for (int j=0; j<height; j++)
    {
      if(input(i,j) == RED) //Locate the starting point
      {
          newRow = i;
          newCol = j;
          count++;
      }
    }
  }
  //Check if there is more than one starting point
  if(count > 1)
  {
    std::cout<< "Error. More than one starting point";
    return EXIT_FAILURE;
  }

  deque_test.pushBack({newRow, newCol});

  //This variable stores whether or not there is a solution for the maze
  bool answer = false; 
  

  while(!deque_test.isEmpty())
  {
    newRow = deque_test.front().rows;
    newCol = deque_test.front().columns;
    deque_test.popFront(); //pop the front element from deque

    //Checks the colors of the pixels
    if(input(newRow, newCol) != BLACK && input(newRow, newCol) != WHITE && input(newRow, newCol) != RED)
    {
      std::cout << "Error! Invalid pixel color.";
      return EXIT_FAILURE;
    }

    //function that makes the pixel green if you find the solution
    if(input(newRow, newCol) == WHITE && (newCol == 0 || newRow == 0 || newCol == height - 1 || newRow == width - 1))
    {
      input(newRow, newCol) = GREEN;
      answer = true; //a solution was found
      break;
    }

    //check if you can move to the next pixel and that the pixel was not visited
    if(input(newRow-1, newCol) == WHITE && assessed[newRow-1][newCol] == false)
    {
      deque_test.pushBack({newRow-1, newCol});
      assessed[newRow-1][newCol] = true;
    }
    if(input(newRow+1, newCol) == WHITE && assessed[newRow+1][newCol] == false)
    {
      deque_test.pushBack({newRow+1, newCol});
      assessed[newRow+1][newCol] = true;
    }
    if(input(newRow, newCol-1) == WHITE && assessed[newRow][newCol-1] == false)
    {
      deque_test.pushBack({newRow, newCol-1});
      assessed[newRow][newCol-1] = true;
    }
    if(input(newRow, newCol+1) == WHITE && assessed[newRow][newCol+1] == false)
    {
      deque_test.pushBack({newRow, newCol+1});
      assessed[newRow][newCol+1] = true;
    }
  
  }

    //write image to output
    writeToFile(input, argv[2]);
    if(answer)
    {
      std::cout<< "An answer was found!";
      return EXIT_SUCCESS;
    }
    else
    {
      std::cout<< "No answer was found.";
      return EXIT_FAILURE;
    }
    

}
