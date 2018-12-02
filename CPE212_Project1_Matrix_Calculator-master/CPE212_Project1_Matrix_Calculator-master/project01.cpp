/*
===========================================
==============Project01.cpp================
===========================================
Author: Evan Stewart
prupose: functions for main.cpp in project01 to manipulate a 2d array
*/


//loads the 2d array into image[][]
void LoadImage(ifstream& inFile, int image[MAXROWS][MAXCOLS]){
  for (int x = 0; x < MAXROWS; x++)
  {
    for (int y = 0; y < MAXCOLS; y++)
    {
      inFile >> image[x][y];
    }
  }
}

void FlipHorizontal(int image[MAXROWS][MAXCOLS]){

  for (int x = 0; x < MAXROWS; x++)
  {

    int MAX_count = MAXCOLS-1;      //=10 and is decremented to grab last num
    int INIT_count = 0;           //=0 and is inc to grab first num
    int iterations = MAXCOLS / 2; //=5 and is the # of times to loop
    int holderVar = 0;            //temp value to hold last #

    for (int y = 0; y < iterations; y++)
    {
      holderVar = image[x][MAX_count];
      image[x][MAX_count] = image[x][INIT_count];
      image[x][INIT_count] = holderVar;

      MAX_count--;
      INIT_count++;
    }
  }
}

void FlipVertical(int image[MAXROWS][MAXCOLS]){

  for (int x = 0; x < MAXCOLS; x++)
  {

    int MAX_count = MAXCOLS-1;      //=10 and is decremented to grab last num
    int INIT_count = 0;           //=0 and is inc to grab first num
    int iterations = MAXCOLS / 2; //=5 and is the # of times to loop
    int holderVar = 0;            //temp value to hold last #

    for (int y = 0; y < iterations; y++)
    {
      holderVar = image[MAX_count][x];            //stores last
      image[MAX_count][x] = image[INIT_count][x]; //replaces last with first
      image[INIT_count][x] = holderVar;           //replaces first with last

      MAX_count--;                                //decrement for next iteration
      INIT_count++;                               //increment for next iteration
    }
  }
}

void RotateCW(int image[MAXROWS][MAXCOLS]){
  for (int x = 0; x < MAXCOLS/2; x++) {
    for (int y = x; y < MAXCOLS - x - 1; y++) {

      int holderVar = image[x][y];                                            //store top left into holderVar

      image[x][y] = image[MAXCOLS - 1 - y][x];                                //move bottom left into top left

      image[MAXCOLS - 1 - y][x] = image[MAXCOLS - 1 - x][MAXCOLS - 1 - y];    //move bottom right into bottom left

      image[MAXCOLS - 1 - x][MAXCOLS - 1 - y] = image[y][MAXCOLS - 1 - x];    //move top right to bottom right

      image[y][MAXCOLS - 1 - x] = holderVar;                                  //top left to top right

    }
  }
}

//rotates 2D array Counterclockwise
//commmented code is for debugging purposes

void RotateCCW(int image[MAXROWS][MAXCOLS]){
  for (int x = 0; x < MAXCOLS / 2; x++)
  {
    for (int y = x; y < MAXCOLS - x - 1; y++)
    {
      int holderVar = image[x][y];

      //cout << x << ',' << y << " into holderVar ";

      image[x][y] = image[y][MAXCOLS - 1 - x];

      // cout << y << "," << MAXCOLS-1-x << " into " << x << ',' << y << " ";

      image[y][MAXCOLS - 1 - x] = image[MAXCOLS - 1 - x][MAXCOLS - 1 - y];

      // cout << MAXCOLS - 1 - x << ',' << MAXCOLS - 1 - y << " into " << y << "," << MAXCOLS - 1 - x << " ";

      image[MAXCOLS - 1 - x][MAXCOLS - 1 - y] = image[MAXCOLS - 1 - y][x];

      // cout << MAXCOLS-1-y << ',' << x << " into " << MAXCOLS - 1 - x << "," << MAXCOLS - 1 - y << " ";

      image[MAXCOLS - 1 - y][x] = holderVar;

      // cout << x << ',' << y << " into " << MAXCOLS - 1 - y << ',' << x << endl;
    }
    // cout << endl;
  }
}

void Transpose(int image[MAXROWS][MAXCOLS]){

  //middle man array to store transpose of image
  int holderArray[MAXROWS][MAXCOLS];

  //transposes image into holderArray
  for (int x = 0; x < MAXROWS; x++)
  {
    for (int y = 0; y < MAXCOLS; y++)
    {
      holderArray[x][y] = image[y][x];
    }
  }

  //copies holder into image
  for (int x = 0; x < MAXROWS; x++)
  {
    for (int y = 0; y < MAXCOLS; y++)
    {
      image[x][y] = holderArray[x][y];
    }
  }
}
